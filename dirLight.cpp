#include "common_header.h"

#include "dirLight.h"
#include <minmax.h>

CDirectionalLight::CDirectionalLight()
{
	vColor = glm::vec3(1.0f, 1.0f, 1.0f);
	vDirection = glm::vec3(0.0f, -1.0f, 0.0f);
	fAmbient = 0.5f;
	fMaxAmbient = 0.5f;
	fMaxColor = 1.0f;
	fAngle = 0.0f;
	updateLightProperties();
}
CDirectionalLight::CDirectionalLight(glm::vec3 a_vColor, glm::vec3 a_vDirection, float a_fAmbient, float a_fAngle)
{
	vColor = a_vColor;
	vDirection = a_vDirection;

	fAmbient = a_fAmbient;
	fMaxAmbient = 0.5f;
	fMaxColor = 1.0f;
	fAngle = a_fAngle;
	updateLightProperties();
}

// Sets all directional light data.
// spProgram - shader program
// sLightVarName - name of directional light variable
void CDirectionalLight::SetUniformData(CShaderProgram *spProgram, std::string sLightVarName)
{
	spProgram->SetUniform(sLightVarName+".vColor", vColor);
	spProgram->SetUniform(sLightVarName+".vDirection", vDirection);

	spProgram->SetUniform(sLightVarName+".fAmbient", fAmbient);
}

void CDirectionalLight::updateLightProperties(){
	float PI = float(atan(1.0)*4.0);
	float fCosine = cos(fAngle * PI / 180.0f);
	float fSone = sin(fAngle * PI / 180.0f);
	float ambDelta = fMaxAmbient/pow(1.5f,0.5f);
	float colDelta = fMaxColor/pow(1.5f,2.0f);

	fAmbient = max(fMaxAmbient - pow(-1*fCosine+1,0.5f) * ambDelta, 0.0f);
	float fCommonColor = max(fMaxColor - pow(-1*fCosine+1,2.0f) * colDelta, 0.0f);
	vColor = glm::vec3(fCommonColor, fCommonColor, fCommonColor);
}
