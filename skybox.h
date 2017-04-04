#pragma once

#include "vertexBufferObject.h"
#include "texture.h"

class Cskybox{
private:
	UINT uiVAO;
	CVertexBufferObject vboSkybox;
	CTexture tSkyboxTextures[6];
public:
	void loadTextures(string sPath, string sFront, string sBack, string sLeft, string sRight, string sTop, string sBottom);
	void renderSkybox();
	void deleteSkybox();
};