#pragma once
#define FOG_TYPE_LINEAR		0
#define FOG_TYPE_EXP		1
#define FOG_TYPE_EXP2		2

#define FOG_ENABLED_TRUE		1
#define FOG_ENABLED_FALSE		0

#define FOG_STATUS_INCREASING			0
#define FOG_STATUS_DECREASING			1
#define FOG_STATUS_STABLE				2

#include "shaders.h"

class CFog{
public:
	CFog(float p_fDensity, float p_fStart, float p_fEnd, glm::vec4 p_vFogColor, int p_iFogEquation, int a_bFogEnabled);
	CFog();
	void addDensity(float fDeltaDensity);
	void addStart(float fDeltaStart); //for linear
	void addEnd(float fDeltaEnd); //for linear
	void setColor(glm::vec4 p_vFogColor);
	void setEquationType(int p_iFogEquation);
	void setUniformVariables(CShaderProgram* spProgram, string sFogParamsName);
	void setUniformVariablesNames(string sDensity, string sStart, string sEnd, string sFogColor, string sFogEquation);

	int getFogEquationType();
	float getDensity();
	float getCurrentDensity();
	float getStart();
	float getEnd();

	void updateFog(float fDeltaTime);
	int fogStatus; //статус изменения интенесивности (0 - возрастает, 1 - убывает, 2 - не изменяется)
	bool bGraduallyFogChanging; //необходимо ли изменять туман постепенно
	int bFogEnabled; //метка для шейдера. 
	
	/*метка для внешней программы. Для отображения в информации.
	  туман может быть включен, но убывать, если установлено постепенно изменение
	*/
	bool bFogEnabled_view; 
	

private:
	float fDensity;
	float fStart;
	float fEnd;
	glm::vec4 vFogColor;
	int iFogEquation; // 0 = linear, 1 = exp, 2 = exp2
	string sUniformDensity, sUniformStart, sUniformEnd, sUniformFogColor, sUniformFogEquation, sUniformFogEnabled;

	float fFogMaxDensity;
	float fFogSecondsForChange;
	float fFogStartDeltaPerSecond; //not used for now
	float fFogEndDeltaPerSecond; //not used for now
	float fFogDensityDeltaPerSecond;
};