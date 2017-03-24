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
#include "particle_system_tf.h"
#include "freeTypeFont.h"

#define NUMTEXTURES 7

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
CSpotLight slFlashLight;
CPointLight plLight, plLight2;

CFreeTypeFont ftFont;

CParticleSystemTransformFeedback psMainParticleSystem2;
glm::vec3 particleColors[] = {
	glm::vec3(0.0f,0.0f,1.0f),
	glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(1.0f,0.0f,0.0f)
};
int currentParticleColor = 0;
int iFontSize = 24;
bool renderParticles;

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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

	string sTextureNames[] = {"grass.png", "met_wall01a.jpg", "tower.jpg", "box.jpg", "ground.jpg", "particle.bmp", "ship_texture.jpg"};

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

	dlSun = CDirectionalLight(glm::vec3(0.13f, 0.13f, 0.13f), glm::vec3(sqrt(2.0f) / 2, -sqrt(2.0f) / 2, 0), 1.0f);
	// Creating spotlight, position and direction will get updated every frame, that's why zero vectors
	slFlashLight = CSpotLight(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1, 15.0f, 0.017f);
	//plLight = CPointLight(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 10.0f, 0.0f), 0.15f, 0.3f, 0.007f, 0.00008f);
	plLight = CPointLight(glm::vec3(1.0f,0.0f,0.0f), glm::vec3(0.0f,10.0f,0.0f),0.15f,0.3f,0.007f,0.00008f);
	plLight2 = CPointLight(glm::vec3(0.0f,0.0f,1.0f), glm::vec3(0.0f,10.0f,30.0f),0.15f,0.3f,0.007f,0.00008f);
	
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

   psMainParticleSystem2.InitalizeParticleSystem(); 

   psMainParticleSystem2.SetGeneratorProperties( 
      glm::vec3(0.0f, 27.5f, 50.0f), // Where the particles are generated
      glm::vec3(-50, 0, -50), // Minimal velocity
      glm::vec3(50, 40, 50), // Maximal velocity
      glm::vec3(0, -50, 0), // Gravity force applied to particles
	  particleColors[currentParticleColor], // Color (light blue)
      1.5f, // Minimum lifetime in seconds
      3.0f, // Maximum lifetime in seconds
      0.75f, // Rendered size
      0.02f, // Spawn every 0.05 seconds
      30); // And spawn 30 particles

   
}

float fGlobalAngle;

#define FOG_EQUATION_LINEAR		0
#define FOG_EQUATION_EXP		1
#define FOG_EQUATION_EXP2		2
#define FOG_DISABLED			3

namespace FogParameters
{
	float fDensity = 0.04f;
	float fStart = 10.0f;
	float fEnd = 75.0f;
	glm::vec4 vFogColor = glm::vec4(0.7f, 0.7f, 0.7f, 1.0f);
	int iFogEquation = FOG_EQUATION_EXP; // 0 = linear, 1 = exp, 2 = exp2, 3 = none
};

// Renders whole scene.
// lpParam - Pointer to anything you want.
void RenderScene(LPVOID lpParam)
{
	// Typecast lpParam to COpenGLControl pointer
	COpenGLControl* oglControl = (COpenGLControl*)lpParam;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	spMain.UseProgram();

	glm::mat4 mModelMatrix, mView;

	// Set spotlight parameters

	glm::vec3 vSpotLightPos = cCamera.vEye;
	glm::vec3 vCameraDir = glm::normalize(cCamera.vView-cCamera.vEye);
	// Move down a little
	vSpotLightPos.y -= 3.2f;
	// Find direction of spotlight
	glm::vec3 vSpotLightDir = (vSpotLightPos+vCameraDir*75.0f)-vSpotLightPos;
	vSpotLightDir = glm::normalize(vSpotLightDir);
	// Find vector of horizontal offset
	glm::vec3 vHorVector = glm::cross(cCamera.vView-cCamera.vEye, cCamera.vUp);
	vSpotLightPos += vHorVector*3.3f;
	// Set it
	slFlashLight.vPosition = vSpotLightPos;
	slFlashLight.vDirection = vSpotLightDir;
	
	slFlashLight.SetUniformData(&spMain, "spotLight");

	plLight.SetUniformData(&spMain, "pointLight[0]");
	plLight2.SetUniformData(&spMain, "pointLight[1]");

	oglControl->ResizeOpenGLViewportFull();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	spMain.UseProgram();
	spMain.SetUniform("fogParams.iEquation", FogParameters::iFogEquation);
	spMain.SetUniform("fogParams.vFogColor", FogParameters::vFogColor);

	if(FogParameters::iFogEquation == FOG_EQUATION_LINEAR)
	{
		spMain.SetUniform("fogParams.fStart", FogParameters::fStart);
		spMain.SetUniform("fogParams.fEnd", FogParameters::fEnd);
	}
	else
		spMain.SetUniform("fogParams.fDensity", FogParameters::fDensity);


	spMain.SetUniform("matrices.projMatrix", oglControl->GetProjectionMatrix());
	spMain.SetUniform("gSampler", 0);

	mView = cCamera.Look();
	spMain.SetUniform("matrices.viewMatrix", &mView);

	mModelMatrix = glm::translate(glm::mat4(1.0f), cCamera.vEye);
	
	spMain.SetUniform("matrices.modelMatrix", &mModelMatrix);
	spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mView*mModelMatrix)));

	glBindVertexArray(uiVAOs[0]);

	dlSun.SetUniformData(&spMain, "sunLight");

	spMain.SetUniform("vColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	spMain.SetUniform("matrices.modelMatrix", glm::mat4(1.0f));
	spMain.SetUniform("matrices.normalMatrix", glm::mat4(1.0f));

	// Render ground

	tTextures[0].BindTexture();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
	// Render cubes
	glm::mat4 mModelToCamera;

	tTextures[3].BindTexture();
	float PI = float(atan(1.0)*4.0);

	FOR(j, 2)
	FOR(i, 16)
	{
		//glm::vec3 vPos = glm::vec3(cos(PI/4 * i) * 30.0f, 4.0f, sin(PI/4*i) * 30.0f);
		glm::vec3 vPos = glm::vec3(30.0f, 4.0f + 8.0f*j, 0.0f);
		mModelMatrix = glm::mat4(1.0f);
		mModelMatrix = glm::rotate(mModelMatrix, PI/8*i + PI/16*j, glm::vec3(0.0f, 1.0f, 0.0f));
		mModelMatrix = glm::translate(mModelMatrix, vPos);
		mModelMatrix = glm::scale(mModelMatrix, glm::vec3(8.0f, 8.0f, 8.0f));
		// We need to transform normals properly, it's done by transpose of inverse matrix of rotations and scales
		spMain.SetUniform("matrices.normalMatrix", glm::transpose(glm::inverse(mModelMatrix)));
		spMain.SetUniform("matrices.modelMatrix", mModelMatrix);
		glDrawArrays(GL_TRIANGLES, 6, 36);
	}

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

	glBindVertexArray(uiVAOs[0]);
	// render torus
	tTextures[1].BindTexture();
	// Now it's gonna float in the air
	glm::vec3 vPos = glm::vec3(0.0f, 10.0, 0.0f);
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

		//psMainParticleSystem2.SetMatrices(oglControl->GetProjectionMatrix(), cCamera.vEye, cCamera.vView, cCamera.vUp);
		//psMainParticleSystem2.UpdateParticles(appMain.sof(1.0f));
		//psMainParticleSystem2.RenderParticles();
	}
	cCamera.Update();

	if(Keys::Onekey('F'))
		slFlashLight.bOn = 1-slFlashLight.bOn;

	/*if(Keys::Onekey('Z')){
		int colorsSize = sizeof(particleColors) / sizeof(glm::vec3);
		currentParticleColor = currentParticleColor == 0 ? colorsSize - 1 : currentParticleColor - 1;
		psMainParticleSystem2.SetGenColor(particleColors[currentParticleColor]);
	}
	if(Keys::Onekey('X')){
		int colorsSize = sizeof(particleColors) / sizeof(glm::vec3);
		currentParticleColor = (currentParticleColor + 1) % colorsSize;
		psMainParticleSystem2.SetGenColor(particleColors[currentParticleColor]);
	}*/

	//glEnable(GL_DEPTH_TEST);


	glDisable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	spFont2D.UseProgram();
	spFont2D.SetUniform("vColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	spFont2D.SetUniform("projectionMatrix", oglControl->GetOrthoMatrix());

	int width = oglControl->GetViewportWidth(), 
		height = oglControl->GetViewportHeight();
	ftFont.printFormatted(20, height-30, 24, "Z for activate exp fog equation, X for exp2, C for Linear and V for Vende.. I mean, disabled fog");
	ftFont.printFormatted(20, height-60, 24, "Current fog type: %s", FogParameters::iFogEquation == 0 ? "Linear" : (FogParameters::iFogEquation == 1 ? "Exp" : (FogParameters::iFogEquation == 2 ? "Exp2" : "None")));
	ftFont.printFormatted(20, height-90, 24, "For linear: fog start is %.4f (G and T to change), fog end is %.4f (H and Y to change)", FogParameters::fStart, FogParameters::fEnd);
	ftFont.printFormatted(20, height-120, 24, "For exp: fog density is %.4f (J and U to change)", FogParameters::fDensity);
	if (Keys::Key('Z')) FogParameters::iFogEquation = 1; if (Keys::Key('X')) FogParameters::iFogEquation = 2;
	if (Keys::Key('C')) FogParameters::iFogEquation = 0; if (Keys::Key('V')) FogParameters::iFogEquation = 3;
	if (Keys::Key('G')) FogParameters::fStart -= appMain.sof(15.0f);
	if (Keys::Key('R')) FogParameters::fStart += appMain.sof(15.0f);
	if (Keys::Key('H')) FogParameters::fEnd -= appMain.sof(15.0f);
	if (Keys::Key('Y')) FogParameters::fEnd += appMain.sof(15.0f);
	if (Keys::Key('J')) FogParameters::fDensity -= appMain.sof(0.01f);
	if (Keys::Key('U')) FogParameters::fDensity += appMain.sof(0.01f);
	
	ftFont.print("Tochilin Anatoly, group 132", 20, 20, 24);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);


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

	glDeleteVertexArrays(1, uiVAOs);
	vboSceneObjects.DeleteVBO();
}