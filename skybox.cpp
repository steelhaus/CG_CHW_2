#include "common_header.h"
#include "skybox.h"

void Cskybox::loadTextures(string sPath, string sFront, string sBack, string sLeft, string sRight, string sTop, string sBottom){
	//loading textures
	tSkyboxTextures[0].LoadTexture2D(sPath + sFront);
	tSkyboxTextures[1].LoadTexture2D(sPath + sBack);
	tSkyboxTextures[2].LoadTexture2D(sPath + sLeft);
	tSkyboxTextures[3].LoadTexture2D(sPath + sRight);
	tSkyboxTextures[4].LoadTexture2D(sPath + sTop);
	tSkyboxTextures[5].LoadTexture2D(sPath + sBottom);

	FOR(i, 6)
	{
		tSkyboxTextures[i].SetFiltering(TEXTURE_FILTER_MAG_BILINEAR, TEXTURE_FILTER_MIN_BILINEAR);
		tSkyboxTextures[i].SetSamplerParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		tSkyboxTextures[i].SetSamplerParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

	glGenVertexArrays(1, &uiVAO); 
	glBindVertexArray(uiVAO);
	vboSkybox.CreateVBO(); 
	vboSkybox.BindVBO();
	glm::vec3 vBoxVert[8] = {
		glm::vec3(100.0f,100.0f,100.0f), glm::vec3(100.0f,-100.0f,100.0f), glm::vec3(-100.0f,100.0f,100.0f), glm::vec3(-100.0f,-100.0f,100.0f), //front
		glm::vec3(-100.0f,100.0f,-100.0f), glm::vec3(-100.0f,-100.0f,-100.0f), glm::vec3(100.0f,100.0f,-100.0f), glm::vec3(100.0f,-100.0f,-100.0f), //back
	};
	glm::vec3 vSkyboxVert[24] = {
		vBoxVert[0], vBoxVert[1], vBoxVert[2], vBoxVert[3], //front
		vBoxVert[4], vBoxVert[5], vBoxVert[6], vBoxVert[7], //back
		vBoxVert[2], vBoxVert[3], vBoxVert[4], vBoxVert[5], //left
		vBoxVert[6], vBoxVert[7], vBoxVert[0], vBoxVert[1], //right
		vBoxVert[4], vBoxVert[6], vBoxVert[2], vBoxVert[0], //top
		vBoxVert[7], vBoxVert[5], vBoxVert[1], vBoxVert[3] //botton
	};
	glm::vec2 vSkyboxTex[4] = {
		glm::vec2(0.0f,1.0f), glm::vec2(0.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(1.0f,0.0f)
	};
	glm::vec3 vSkyboxNorm[6] ={
		glm::vec3(0.0f,0.0f,-1.0f), glm::vec3(0.0f,0.0f,1.0f), //front, back
		glm::vec3(1.0f,0.0f,0.0f), glm::vec3(-1.0f,0.0f,0.0f), //left, right (рассматриваю скайбокс со стороны задней стороны по направлению Z, поэтому сторона, названная левой, располагается в плоскости x = 100
		glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f) //top, bottom
	};
	FOR(i, sizeof(vSkyboxVert)/sizeof(glm::vec3)){
		vboSkybox.AddData(&vSkyboxVert[i], sizeof(glm::vec3));
		vboSkybox.AddData(&vSkyboxTex[i%4], sizeof(glm::vec2));
		vboSkybox.AddData(&vSkyboxNorm[i/4], sizeof(glm::vec3));
	}

	vboSkybox.UploadDataToGPU(GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)sizeof(glm::vec3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)( sizeof(glm::vec3)+sizeof(glm::vec2) ));
}

void Cskybox::renderSkybox(){
	glDepthMask(0);
	glBindVertexArray(uiVAO);
	FOR(i,6){
		tSkyboxTextures[i].BindTexture();
		glDrawArrays(GL_TRIANGLE_STRIP, i*4, 4);
	}
	glDepthMask(1);
}

void Cskybox::deleteSkybox(){
	FOR(i,6){
		tSkyboxTextures[i].DeleteTexture();
	}
	glDeleteVertexArrays(1, &uiVAO);
	vboSkybox.DeleteVBO();
}