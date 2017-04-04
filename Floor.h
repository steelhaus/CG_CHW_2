#pragma once

#include "vertexBufferObject.h"
#include "texture.h"

class CFloor{
private:
	UINT uiVAO;
	CVertexBufferObject vboFloor;
	CTexture tTextures[2];
public: 
	void loadTextures();
	void renderFloor();
	void release();
};