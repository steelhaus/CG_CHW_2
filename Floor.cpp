#include "common_header.h"
#include "Floor.h"

void CFloor::loadTextures(){
	//loading textures
	string sPath = "data\\textures\\";
	tTextures[0].LoadTexture2D(sPath + "water.jpg", true);
	tTextures[1].LoadTexture2D(sPath + "grass.png", true);

	FOR(i, 2)
	{
		tTextures[i].SetFiltering(TEXTURE_FILTER_MAG_BILINEAR, TEXTURE_FILTER_MIN_BILINEAR_MIPMAP);
	}

	glGenVertexArrays(1, &uiVAO); 
	glBindVertexArray(uiVAO);
	vboFloor.CreateVBO();
	vboFloor.BindVBO();

	glm::vec3 vWaterVert[4] = {
		glm::vec3(-1000, 0, -1000), glm::vec3(-1000, 0, 1000), glm::vec3(1000, 0, -1000), glm::vec3(1000, 0, 1000)
	};
	glm::vec2 vWaterTexCoords[4] = {
		glm::vec2(0.0f,50.0f), glm::vec2(0.0f,0.0f), glm::vec2(50.0f,50.0f), glm::vec2(50.0f,0.0f)
	};
	glm::vec3 vWaterNormal(0.0f,1.0f,0.0f);
	FOR(i, sizeof(vWaterVert)/sizeof(glm::vec3)){
		vboFloor.AddData(&vWaterVert[i], sizeof(glm::vec3));
		vboFloor.AddData(&vWaterTexCoords[i], sizeof(glm::vec2));
		vboFloor.AddData(&vWaterNormal, sizeof(glm::vec3));
	}

	vboFloor.UploadDataToGPU(GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)sizeof(glm::vec3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 2*sizeof(glm::vec3)+sizeof(glm::vec2), (void*)( sizeof(glm::vec3)+sizeof(glm::vec2) ));
}

void CFloor::renderFloor(){
	glBindVertexArray(uiVAO);
	tTextures[0].BindTexture();
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void CFloor::release(){
	FOR(i,2){
		tTextures[i].DeleteTexture();
	}
	glDeleteVertexArrays(1, &uiVAO);
	vboFloor.DeleteVBO();
}