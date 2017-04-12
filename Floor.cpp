#include "common_header.h"
#include "Floor.h"


void CFloor::loadTextures(){
	//loading textures
	string sPath = "data\\textures\\";
	tTextures[0].LoadTexture2D(sPath + "water.jpg", true);
	tTextures[1].LoadTexture2D(sPath + "sand.jpg", true);
	tTextures[2].LoadTexture2D(sPath + "light_grass.jpg", true);

	FOR(i, 2)
	{
		tTextures[i].SetFiltering(TEXTURE_FILTER_MAG_BILINEAR, TEXTURE_FILTER_MIN_BILINEAR_MIPMAP);
	}

	glGenVertexArrays(1, &uiVAO); 
	glBindVertexArray(uiVAO);
	vboFloor.CreateVBO();
	vboFloor.BindVBO();

	glm::vec3 vWaterVert[4] = {
		glm::vec3(-1000, 0, 0), glm::vec3(-1000, 0, 1000), glm::vec3(1000, 0, 0), glm::vec3(1000, 0, 1000)
	};
	glm::vec2 vWaterTexCoords[4] = {
		glm::vec2(0.0f,25.0f), glm::vec2(0.0f,0.0f), glm::vec2(50.0f,25.0f), glm::vec2(50.0f,0.0f)
	};
	glm::vec3 vWaterNormal(0.0f,1.0f,0.0f);
	FOR(i, sizeof(vWaterVert)/sizeof(glm::vec3)){
		vboFloor.AddData(&vWaterVert[i], sizeof(glm::vec3));
		vboFloor.AddData(&vWaterTexCoords[i], sizeof(glm::vec2));
		vboFloor.AddData(&vWaterNormal, sizeof(glm::vec3));
	}

	glm::vec3 vSandVert[4] = {
		glm::vec3(-1000, 20, -50), glm::vec3(-1000, -5, 50), glm::vec3(1000, 20, -50), glm::vec3(1000, -5, 50)
	};
	glm::vec2 vSandTex[4] = {
		glm::vec2(0.0f,5.0f), glm::vec2(0.0f,0.0f), glm::vec2(50.0f,5.0f), glm::vec2(50.0f,0.0f)
	};
	glm::vec3 vSandNormal = glm::normalize(glm::vec3(0.0f,4.0f,1.0f));
	FOR(i, sizeof(vSandVert)/sizeof(glm::vec3)){
		vboFloor.AddData(&vSandVert[i], sizeof(glm::vec3));
		vboFloor.AddData(&vSandTex[i], sizeof(glm::vec2));
		vboFloor.AddData(&vSandNormal, sizeof(glm::vec3));
	}

	glm::vec3 vFloorVert[4] = {
		glm::vec3(-1000, 20, -1000), glm::vec3(-1000, 20, -50), glm::vec3(1000, 20, -1000), glm::vec3(1000, 20, -50)
	};
	glm::vec2 vFloorTex[4] = {
		glm::vec2(0.0f,25.0f), glm::vec2(0.0f,0.0f), glm::vec2(50.0f,25.0f), glm::vec2(50.0f,0.0f)
	};
	glm::vec3 vFloorNormal(0.0f,1.0f,0.0f);
	FOR(i, sizeof(vFloorVert)/sizeof(glm::vec3)){
		vboFloor.AddData(&vFloorVert[i], sizeof(glm::vec3));
		vboFloor.AddData(&vFloorTex[i], sizeof(glm::vec2));
		vboFloor.AddData(&vFloorNormal, sizeof(glm::vec3));
	}

	vboFloor.UploadDataToGPU(GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)sizeof(glm::vec3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)( sizeof(glm::vec3)+sizeof(glm::vec2) ));
}

void CFloor::renderFloor(CShaderProgram spProgram){
	glBindVertexArray(uiVAO);
	spProgram.SetUniform("numTextures", 1);
	tTextures[0].BindTexture(0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	spProgram.SetUniform("numTextures", 2);
	spProgram.SetUniform("textureTransitionRatio", 5);
	tTextures[2].BindTexture(0);
	tTextures[1].BindTexture(1);
	glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);
	spProgram.SetUniform("numTextures", 1);
	glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
}

void CFloor::release(){
	FOR(i,2){
		tTextures[i].DeleteTexture();
	}
	glDeleteVertexArrays(1, &uiVAO);
	vboFloor.DeleteVBO();
}