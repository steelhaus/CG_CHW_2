#pragma warning(disable:4996)
#include "common_header.h"

#include "win_OpenGLApp.h"

#include "shaders.h"
#include "texture.h"
#include "vertexBufferObject.h"

#include "flyingCamera.h"

#include "spotLight.h"
#include "dirLight.h"
#include "pointLight.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Boat.h"
#include "particle_system.h"
#include "freeTypeFont.h"
#include "skybox.h"
#include "Floor.h"
#include "Fog.h"
#include "time.h"
#include "ObjModel.h"


#define NUMTEXTURES 8

/* One VBO, where all static data are stored now,
in this tutorial vertex is stored as 3 floats for
position, 2 floats for texture coordinate and
3 floats for normal vector. */

CVertexBufferObject vboSceneObjects;
UINT uiVAOs[2]; //rendersceneobjects + boat

CVertexBufferObject vboBoat;//, vboBoatInd;
Boat *boat1;
glm::vec3 boatPos; //перемещение
float fBoatPitch; //вращение по y
float fBoatSpeed; //скорость
glm::vec3 vBoatForward; //вектор направления движения (по носу)
int iBoatMoving; //-1 for backward moving, 0 for idle, 1 for forward moving


CTexture tTextures[NUMTEXTURES];
CFlyingCamera cCamera;

CDirectionalLight dlSun;
float fDlSunAngle = 0.0f;
CSpotLight slFlashLight;
CPointLight plLightWhite, plLightRed, plLightGreen, plLightBlue;
CPointLight *currentPosessedLight = &plLightWhite;
CTime tmInnerTime;
CObjModel houseModel, fountainModel;
CFog cfWorldFog;

CFreeTypeFont ftFont;

Cskybox CSskybox;
CFloor cfFloor;

CParticleSystemTransformFeedback psSingingFountain;
glm::vec3 currentFountainColor(1.0f, 0.0f, 0.0f);
bool renderFountain = true;

#define FNT_RED 0
#define FNT_GREEN 1
#define FNT_BLUE 2

int fntCurrentColorUp = FNT_GREEN;

glm::vec3 particleColors[] = {
	glm::vec3(0.0f,0.0f,1.0f),
	glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(1.0f,0.0f,0.0f)
};
int currentParticleColor = 0;
int iFontSize = 24;
bool renderParticles;
bool enableDayNightSelfAlternation = false;
#include "static_geometry.h"

#define plumeSpreadAngle 70.0f
#define plumeMaxLifeTime 3.0f
CParticleSystemTransformFeedback psPlume; //шлейф за кораблем
void updatePlumePosition(bool forwardMoving){
	float fPositionMult = -7.5f;//-35.0f : -35.0f;//20.0f;
	psPlume.SetGeneratorPosition(boatPos - glm::vec3(0.0f,48.0f,0.0f) + vBoatForward * fPositionMult);
}

void updatePlumeRotation(float fSpreadAngle, bool forwardMoving){
	float PI = float(atan(1.0)*4.0);
	float fMainAngle = fBoatPitch + (forwardMoving ? 180.0f : 0.0f);
	float fRightSpread = fMainAngle + fSpreadAngle;
	float fLeftSpread = fMainAngle - fSpreadAngle;
	float fMainSine = sin(fMainAngle/180.0f*PI);
	float fMainCosine = cos(fMainAngle/180.0f*PI);
	float fRightSine = sin(fRightSpread/180.0f*PI);
	float fRightCosine = cos(fRightSpread/180.0f*PI);
	float fLeftSine = sin(fLeftSpread/180.0f*PI);
	float fLeftCosine = cos(fLeftSpread/180.0f*PI);
	float fFwdSpeed = 25.0f;
	float fSpreadSpeed = 20.0f;
	glm::vec3 mainVec = glm::vec3(fMainSine, 0.0f, fMainCosine) * fFwdSpeed;
	glm::vec3 rightVec = mainVec + glm::vec3(fRightSine, 0.0f, fRightCosine) * fSpreadSpeed;
	glm::vec3 leftVec = mainVec + glm::vec3(fLeftSine, 0.2f, fLeftCosine) * fSpreadSpeed;
	glm::vec3 minVel = glm::vec3(min(rightVec.x,leftVec.x),min(rightVec.y,leftVec.y),min(rightVec.z,leftVec.z));
	glm::vec3 maxVel = glm::vec3(max(rightVec.x,leftVec.x),max(rightVec.y,leftVec.y),max(rightVec.z,leftVec.z));
	psPlume.setGenVelocity(rightVec, leftVec);
}

// Initializes OpenGL features that will be used.
// lpParam - Pointer to anything you want.
void InitScene(LPVOID lpParam)
{
	float PI = float(atan(1.0)*4.0);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	tmInnerTime = CTime();
	cfWorldFog = CFog(0.023f, 10.0f, 75.0f, glm::vec4(0.7f, 0.7f, 0.7f, 1.0f), FOG_TYPE_EXP2, FOG_ENABLED_FALSE);

	// Prepare all scene objects
	vboSceneObjects.CreateVBO();
	glGenVertexArrays(2, uiVAOs);
	glBindVertexArray(uiVAOs[0]);

	vboSceneObjects.BindVBO();

	AddSceneObjects(vboSceneObjects);

	vboSceneObjects.UploadDataToGPU(GL_STATIC_DRAW);

	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), 0);
	// Texture coordinates
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)sizeof(glm::vec3));
	// Normal vectors
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)(sizeof(glm::vec3)+sizeof(glm::vec2)));


	glBindVertexArray(uiVAOs[1]);
	vboBoat.CreateVBO();
	vboBoat.BindVBO();
	boat1 = new Boat();	
	boat1->addBoat(vboBoat);	
	vboBoat.UploadDataToGPU(GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec3) + sizeof(glm::vec2), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec3) + sizeof(glm::vec2), (void*)sizeof(glm::vec3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec3) + sizeof(glm::vec2), (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));
	boatPos = glm::vec3(20.0f, 49.0f, 150.0f);
	fBoatPitch = 0.0f;
	fBoatSpeed = 30.0f;
	iBoatMoving = 0.0f;
	vBoatForward = glm::vec3(0.0f,0.0f,1.0f);

	if(!PrepareShaderPrograms())
	{
		PostQuitMessage(0);
		return;
	}
	// Load textures

	string sTextureNames[] = {"grass.png", "met_wall01a.jpg", "tower.jpg", "box.jpg", "ground.jpg", "particle.bmp", "ship_texture.jpg", "water.jpg"};

	FOR(i, NUMTEXTURES)
	{
		tTextures[i].LoadTexture2D("data\\textures\\"+sTextureNames[i], true);
		tTextures[i].SetFiltering(TEXTURE_FILTER_MAG_BILINEAR, TEXTURE_FILTER_MIN_BILINEAR_MIPMAP);
	}

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	
	cCamera = CFlyingCamera(glm::vec3(0.0f, 10.0f, 120.0f), glm::vec3(0.0f, 10.0f, 119.0f), glm::vec3(0.0f, 1.0f, 0.0f), 45.0f, 0.001f);
	cCamera.SetMovingKeys('W', 'S', 'A', 'D');
	//dlSun = CDirectionalLight(glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f,0.0f,0.0f), 0.5f, tmInnerTime.getSunAngle());
	dlSun = CDirectionalLight(glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f,0.0f,0.0f), 0.5f, tmInnerTime.getSunAngle());
	dlSun.fAmbient = 0.0f;
	dlSun.vDirection = glm::vec3(0.0f,0.0f,-1.0f);
	dlSun.vColor = glm::vec3(1.0f,1.0f,1.0f);
	// Creating spotlight, position and direction will get updated every frame, that's why zero vectors
	slFlashLight = CSpotLight(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1, 15.0f, 0.017f);
	slFlashLight.bOn = false;
	plLightWhite = CPointLight(glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f,30.0f,0.0f),0.15f,0.3f,0.007f,0.00008f,0);
	plLightRed = CPointLight(glm::vec3(1.0f,0.0f,0.0f), glm::vec3(20.0f,30.0f,0.0f),0.15f,0.3f,0.007f,0.00008f,0);
	plLightGreen = CPointLight(glm::vec3(0.0f,1.0f,0.0f), glm::vec3(40.0f,30.0f,0.0f),0.15f,0.3f,0.007f,0.00008f,0);
	plLightBlue = CPointLight(glm::vec3(0.0f,0.0f,1.0f), glm::vec3(60.0f,30.0f,0.0f),0.15f,0.3f,0.007f,0.00008f,0);

	psPlume.InitalizeParticleSystem(); 
	psPlume.SetGeneratorProperties( 
		glm::vec3(0.0f, 0.0f, 0.0f), //location (calculate after)
		glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), // min and max velocity (calculate after)
		glm::vec3(0, -1, 0), // gravity
		glm::vec3(0.0f, 0.5f, 1.0f), // color
		1.5f, plumeMaxLifeTime, //lifetime min to max
		0.75f, // Rendered size
		0.02f, // Spawn every 0.05 seconds
		30); // spawn 30 particles
	psPlume.StopGenParticles();
	//updatePlumePosition(true);
	updatePlumeRotation(plumeSpreadAngle, true);
	
	renderParticles = true;

	ftFont.loadSystemFont("comic.ttf", 32);
	ftFont.setShaderProgram(&spFont2D);

	psSingingFountain.InitalizeParticleSystem(); 

	psSingingFountain.SetGeneratorProperties( 
      glm::vec3(0.0f, 45.0f, -100.0f), // location
      glm::vec3(-15, 10, -15), // Minimal velocity
      glm::vec3(15, 20, 15), // Maximal velocity
      glm::vec3(0, -40, 0), // Gravity force applied to particles
	  currentFountainColor,
      1.5f, // Minimum lifetime in seconds
      3.0f, // Maximum lifetime in seconds
      0.75f, // Rendered size
      0.02f, // Spawn every 0.05 seconds
      30); // And spawn 30 particles

   CSskybox.loadTextures("data\\skybox\\", "jajlands_ft.jpg", "jajlands_bk.jpg", "jajlands_lf.jpg", "jajlands_rt.jpg", "jajlands_up.jpg", "jajlands_dn.jpg");
   cfFloor.loadTextures();
   houseModel.LoadModel("data\\models\\house\\house.obj", "house.mtl");
   fountainModel.LoadModel("data\\models\\fountain\\fountain.obj", "fountain.mtl");
}
float fGlobalAngle;

#include "ftPrinter.h"
// Renders whole scene.
// lpParam - Pointer to anything you want.
void RenderScene(LPVOID lpParam)
{
	// Typecast lpParam to COpenGLControl pointer
	COpenGLControl* oglControl = (COpenGLControl*)lpParam;
	oglControl->ResizeOpenGLViewportFull();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glm::mat4 mModelMatrix, mView;
	mView = cCamera.Look();
	mModelMatrix = glm::translate(glm::mat4(1.0f), cCamera.vEye);

	//Render skybox
	spSkybox.UseProgram();
	spSkybox.SetUniform("matrices.projMatrix", oglControl->GetProjectionMatrix());
	spSkybox.SetUniform("matrices.viewMatrix", &mView);
	spSkybox.SetUniform("matrices.modelMatrix", &mModelMatrix);
	spSkybox.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
	spSkybox.SetUniform("vColor", tmInnerTime.getSkyboxColor());
	spSkybox.SetUniform("gSampler", 0);	
	//Fog
	cfWorldFog.updateFog(appMain.sof(1.0f));
	cfWorldFog.setUniformVariables(&spSkybox, "fogParams");
	spSkybox.SetUniform("avrgSkyboxDistance", 150);
	CSskybox.renderSkybox();
	//End render skybox

	//Main
	spMain.UseProgram();
	spMain.SetUniform("matrices.projMatrix", oglControl->GetProjectionMatrix());
	spMain.SetUniform("matrices.viewMatrix", &mView);
	spMain.SetUniform("matrices.modelMatrix", &mModelMatrix);
	spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mView*mModelMatrix)));
	spMain.SetUniform("gSamplers[0]", 0);
	spMain.SetUniform("gSamplers[1]", 1);
	//Set spotlight parameters
	glm::vec3 vSpotLightPos = cCamera.vEye;
	glm::vec3 vCameraDir = glm::normalize(cCamera.vView-cCamera.vEye);
	// Move down a little
	vSpotLightPos.y -= 3.2f;
	// Spotlight direction
	glm::vec3 vSpotLightDir = (vSpotLightPos+vCameraDir*75.0f)-vSpotLightPos;
	vSpotLightDir = glm::normalize(vSpotLightDir);
	// Find vector of horizontal offset
	glm::vec3 vHorVector = glm::cross(cCamera.vView-cCamera.vEye, cCamera.vUp);
	vSpotLightPos += vHorVector*3.3f;
	slFlashLight.vPosition = vSpotLightPos;
	slFlashLight.vDirection = vSpotLightDir;	
	slFlashLight.SetUniformData(&spMain, "spotLight");
	plLightWhite.SetUniformData(&spMain, "pointLight[0]");
	plLightRed.SetUniformData(&spMain, "pointLight[1]");
	plLightGreen.SetUniformData(&spMain, "pointLight[2]");
	plLightBlue.SetUniformData(&spMain, "pointLight[3]");
	dlSun.SetUniformData(&spMain, "sunLight");
	//Fog
	cfWorldFog.setUniformVariables(&spMain, "fogParams");

	//Scene objects	
	spMain.SetUniform("vColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	spMain.SetUniform("matrices.modelMatrix", glm::mat4(1.0f));
	spMain.SetUniform("matrices.normalMatrix", glm::mat4(1.0f));
	// Render ground
	cfFloor.renderFloor(spMain);


	//tTextures[7].BindTexture();
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(uiVAOs[0]);
	// Render cubes
	glm::mat4 mModelToCamera;

	tTextures[3].BindTexture();
	float PI = float(atan(1.0)*4.0);

	FOR(j, 2)
	FOR(i, 16)
	{
		glm::vec3 vPos = glm::vec3(30.0f, 24.0f + 8.0f*j, 0.0f);
		mModelMatrix = glm::mat4(1.0f);
		mModelMatrix = glm::translate(mModelMatrix, glm::vec3(0.0f,0.0f,-100.0f));
		mModelMatrix = glm::rotate(mModelMatrix, PI/8*i + PI/16*j, glm::vec3(0.0f, 1.0f, 0.0f));
		mModelMatrix = glm::translate(mModelMatrix, vPos);
		mModelMatrix = glm::scale(mModelMatrix, glm::vec3(8.0f, 8.0f, 8.0f));
		// We need to transform normals properly, it's done by transpose of inverse matrix of rotations and scales
		spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
		spMain.SetUniform("matrices.modelMatrix", mModelMatrix);
		glDrawArrays(GL_TRIANGLES, 6, 36);
	}

	glm::vec3 housePos = glm::vec3(80.0f,20.0f,-100.0f);
	mModelMatrix = glm::mat4(1.0f);
	mModelMatrix = glm::translate(mModelMatrix, housePos);
	mModelMatrix = glm::scale(mModelMatrix, glm::vec3(10.0f,10.0f,10.0f));
	spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
	spMain.SetUniform("matrices.modelMatrix", mModelMatrix);
	houseModel.RenderModel();


	// Render boat
	glEnable(GL_CULL_FACE);
	tTextures[6].BindTexture();
	glBindVertexArray(uiVAOs[1]);
	mModelMatrix = glm::mat4(1.0f);
	mModelMatrix = glm::translate(mModelMatrix, boatPos);
	mModelMatrix = glm::rotate(mModelMatrix, fBoatPitch/180.0f*PI, glm::vec3(0.0f,1.0f,0.0f));
	mModelMatrix = glm::scale(mModelMatrix, glm::vec3(50.0f, 50.0f, 50.0f));
	spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
	spMain.SetUniform("matrices.modelMatrix", &mModelMatrix);
	glDrawArrays(GL_TRIANGLES, 0, boat1->getBoatIndicesSize());
	glDisable(GL_CULL_FACE);

	// render torus
	glBindVertexArray(uiVAOs[0]);
	tTextures[1].BindTexture();
	// Now it's gonna float in the air
	glm::vec3 vPos = glm::vec3(80.0f, 30.0, -100.0f);
	mModelMatrix = glm::translate(glm::mat4(1.0), vPos);
	mModelMatrix = glm::rotate(mModelMatrix, fGlobalAngle, glm::vec3(0.0f, 1.0f, 0.0f));
	spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
	spMain.SetUniform("matrices.modelMatrix", &mModelMatrix);
	glDrawArrays(GL_TRIANGLES, 42, iTorusFaces * 3);

	tTextures[2].BindTexture();
	mModelMatrix = glm::translate(glm::mat4(1.0), vPos);
	mModelMatrix = glm::rotate(mModelMatrix, fGlobalAngle, glm::vec3(1.0f, 0.0f, 0.0f));
	spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
	spMain.SetUniform("matrices.modelMatrix", &mModelMatrix);
	glDrawArrays(GL_TRIANGLES, 42 + iTorusFaces * 3, iTorusFaces2 * 3);


	//torus for each light
	tTextures[2].BindTexture();
	FOR(j,4){
		CPointLight currentPL = j == 0 ? plLightWhite : j == 1 ? plLightRed : j == 2 ? plLightGreen : plLightBlue;
		float scale = 0.5f;
		FOR(i,3){
			float newScale = i == 1 ? scale - 0.001f : i == 2 ? scale - 0.002f : scale;
			mModelMatrix = glm::translate(glm::mat4(1.0), currentPL.vPosition);
			if (i == 1) mModelMatrix = glm::rotate(mModelMatrix, 0.5f * PI, glm::vec3(0.0f, 1.0f, 0.0f));
			if (i == 2) mModelMatrix = glm::rotate(mModelMatrix, 0.5f * PI, glm::vec3(1.0f, 0.0f, 0.0f));
			mModelMatrix = glm::scale(mModelMatrix, glm::vec3(newScale,newScale,newScale));
			spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
			spMain.SetUniform("matrices.modelMatrix", &mModelMatrix);
			spMain.SetUniform("vColor", glm::vec4(currentPL.vColor, 1.0f));
			glDrawArrays(GL_TRIANGLES, 42 + iTorusFaces * 3, iTorusFaces2 * 3);
		}
	}
	//return color to normal
	spMain.SetUniform("vColor", glm::vec4(1.0f,1.0f,1.0f,1.0f));

	//moving boat
	bool fwd = Keys::Key(VK_UP);
	bool bwd = Keys::Key(VK_DOWN);
	bool rght = Keys::Key(VK_RIGHT);
	bool lft = Keys::Key(VK_LEFT);
	int iNewMoving = 0;
	if(fwd || bwd) //узнаем, движется ли лодка сейчас
		iNewMoving = fwd && bwd ? 0 : fwd? 1 : -1;

	if(iBoatMoving != iNewMoving){ //состояние лодки изменилось
		switch (iNewMoving){
		case -1: //начала движение назад
			psPlume.ContinueGenParticles();
			updatePlumeRotation(plumeSpreadAngle, false);
			break;
		case 0: //остановилась
			psPlume.StopGenParticles();
			break;
		case 1: //начала движение вперед
			psPlume.ContinueGenParticles();
			updatePlumeRotation(plumeSpreadAngle, true);
			break;
		}
	}
	iBoatMoving = iNewMoving;

	if(iBoatMoving != 0){ //если движется, то можем ее поворачивать и зименять расположение
		if (lft){
			fBoatPitch += appMain.sof(40);
			float fSine = sin(fBoatPitch/180.0f*PI);
			float fCosine = cos(fBoatPitch/180.0f*PI);
			vBoatForward = glm::vec3(fSine,0.0f,fCosine);
		}
		if (rght){
			fBoatPitch -= appMain.sof(40);
			float fSine = sin(fBoatPitch/180.0f*PI);
			float fCosine = cos(fBoatPitch/180.0f*PI);
			vBoatForward = glm::vec3(fSine,0.0f,fCosine);
		}
		boatPos += (float)iBoatMoving * vBoatForward * fBoatSpeed * appMain.sof(1);
		if (lft || rght) updatePlumeRotation(plumeSpreadAngle, iBoatMoving == 1);
		updatePlumePosition(iBoatMoving == 1);
	}

	if (renderParticles){
		tTextures[5].BindTexture();
		psPlume.SetMatrices(oglControl->GetProjectionMatrix(), cCamera.vEye, cCamera.vView, cCamera.vUp);
		psPlume.UpdateParticles(appMain.sof(1.0f));
		psPlume.RenderParticles();
	}

	/*if (renderFountain){
		tTextures[5].BindTexture();
		psSingingFountain.SetMatrices(oglControl->GetProjectionMatrix(), cCamera.vEye, cCamera.vView, cCamera.vUp);
		psSingingFountain.UpdateParticles(appMain.sof(1.0f));
		psSingingFountain.RenderParticles();

		//обновление цвета поющего фонтана
		float colorDelta = appMain.sof(0.1f);
		switch (fntCurrentColorUp){
		case FNT_GREEN:
			currentFountainColor.x = max(0.0f, currentFountainColor.x - colorDelta);
			currentFountainColor.y = min(1.0f, currentFountainColor.y + colorDelta);
			if (currentFountainColor.x == 0) fntCurrentColorUp = FNT_BLUE;
			break;
		case FNT_BLUE:
			currentFountainColor.y = max(0.0f, currentFountainColor.y - colorDelta);
			currentFountainColor.z = min(1.0f, currentFountainColor.z + colorDelta);
			if (currentFountainColor.y == 0) fntCurrentColorUp = FNT_RED;
			break;
		case FNT_RED:
			currentFountainColor.z = max(0.0f, currentFountainColor.z - colorDelta);
			currentFountainColor.x = min(1.0f, currentFountainColor.x + colorDelta);
			if (currentFountainColor.z == 0) fntCurrentColorUp = FNT_GREEN;
			break;
		}
		psSingingFountain.SetGenColor(currentFountainColor);
	}*/



	cCamera.Update();
	
	//вывод информации
	ftPrintAllInfo(oglControl);
	ftCheckKeyPressing();

	//смена дня и ночи
	if (enableDayNightSelfAlternation){ 
		tmInnerTime.addTime(appMain.sof(1.0f));
		dlSun.fAngle = tmInnerTime.getSunAngle();
		dlSun.updateLightProperties();
	}

	if(Keys::Onekey(VK_ESCAPE))PostQuitMessage(0);
	fGlobalAngle += appMain.sof(1.0f);
	
	oglControl->SwapBuffers();
}

// Releases OpenGL scene.
// lpParam - Pointer to anything you want.
void ReleaseScene(LPVOID lpParam)
{
	FOR(i, NUMTEXTURES)tTextures[i].DeleteTexture();

	spMain.DeleteProgram();
	FOR(i, NUMSHADERS)shShaders[i].DeleteShader();

	CSskybox.deleteSkybox();

	glDeleteVertexArrays(2, uiVAOs);
	vboSceneObjects.DeleteVBO();
}
