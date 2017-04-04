#pragma once

#include "vertexBufferObject.h"
#include "texture.h"
#include "shaders.h"

class CFloor{
private:
	UINT uiVAO;
	CVertexBufferObject vboFloor;
	CTexture tTextures[3];
public: 
	void loadTextures();
	void renderFloor(CShaderProgram spProgram);
	void release();
};