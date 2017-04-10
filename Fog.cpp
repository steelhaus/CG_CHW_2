#include "common_header.h"
#include "Fog.h"

CFog::CFog(float p_fDensity, float p_fStart, float p_fEnd, glm::vec4 p_vFogColor, int p_iFogEquation, int p_bFogEnabled){
	fFogMaxDensity = p_fDensity;
	fDensity = 0.0f;
	fStart = p_fStart;
	fEnd = p_fEnd;
	vFogColor = p_vFogColor;
	iFogEquation = p_iFogEquation;
	bFogEnabled = p_bFogEnabled;
	bFogEnabled_view = p_bFogEnabled == FOG_ENABLED_TRUE;
	sUniformDensity = "fDensity";
	sUniformStart = "fStart";
	sUniformEnd = "fEnd";
	sUniformFogColor = "vFogColor";
	sUniformFogEquation = "iEquation";
	sUniformFogEnabled = "bFogEnabled";

	bGraduallyFogChanging = true;
	fogStatus = FOG_STATUS_STABLE;
	fFogSecondsForChange = 5.0f;
	fFogDensityDeltaPerSecond = fFogMaxDensity / fFogSecondsForChange;
}
CFog::CFog(){
	fDensity = 0.0f;
	fFogMaxDensity = 0.04f;
	fStart = 10.0f;
	fEnd = 75.0f;
	bFogEnabled = FOG_ENABLED_FALSE;
	bFogEnabled_view = false;
	vFogColor = glm::vec4(0.7f, 0.7f, 0.7f, 1.0f);
	iFogEquation = FOG_TYPE_EXP2;
	sUniformDensity = "fDensity";
	sUniformStart = "fStart";
	sUniformEnd = "fEnd";
	sUniformFogColor = "vFogColor";
	sUniformFogEquation = "iEquation";
	sUniformFogEnabled = "bFogEnabled";

	bGraduallyFogChanging = true;
	fogStatus = FOG_STATUS_STABLE;
	fFogSecondsForChange = 5.0f;
	fFogDensityDeltaPerSecond = fFogMaxDensity / fFogSecondsForChange;
}

void CFog::addDensity(float fDeltaDensity){
	fFogMaxDensity += fDeltaDensity;
	fFogDensityDeltaPerSecond = fFogMaxDensity / fFogSecondsForChange;
}
void CFog::addStart(float fDeltaStart){
	fStart += fDeltaStart;
}
void CFog::addEnd(float fDeltaEnd){
	fEnd += fDeltaEnd;
}
void CFog::setColor(glm::vec4 p_vFogColor){
	vFogColor = p_vFogColor;
}
void CFog::setEquationType(int p_iFogEquation){
	iFogEquation = p_iFogEquation;
}
void CFog::setUniformVariables(CShaderProgram* spProgram, string sFogParamsName){
	spProgram->SetUniform(sFogParamsName + "." + sUniformFogEnabled, bFogEnabled);
	if (bFogEnabled == FOG_ENABLED_FALSE) {
		return; //не нужны параметры, если туман отключен
	}
	spProgram->SetUniform(sFogParamsName + "." + sUniformFogEquation, iFogEquation);
	spProgram->SetUniform(sFogParamsName + "." + sUniformFogColor, vFogColor);
	if (iFogEquation == FOG_TYPE_LINEAR) {
		spProgram->SetUniform(sFogParamsName + "." + sUniformStart, fStart);
		spProgram->SetUniform(sFogParamsName + "." + sUniformEnd, fEnd);
		//постепенный туман реализован для экспоненциального типа, и метка bFogEnabled устанавливается в 0 только после 
		//окончательного затухания. Для линейного тумана это не нужно, поэтому берем метку _view, которая используется для отображения информации
		//и показывает крайний статус текущего состояния
		spProgram->SetUniform(sFogParamsName + "." + sUniformFogEnabled, bFogEnabled_view ? FOG_ENABLED_TRUE : FOG_ENABLED_FALSE);
	} else if (iFogEquation == FOG_TYPE_EXP || iFogEquation == FOG_TYPE_EXP2){
		spProgram->SetUniform(sFogParamsName + "." + sUniformDensity, fDensity);
	}
}

void CFog::setUniformVariablesNames(string sDensity, string sStart, string sEnd, string sFogColor, string sFogEquation){
	sUniformDensity = sDensity;
	sUniformStart = sStart;
	sUniformEnd = sEnd;
	sUniformFogColor = sFogColor;
	sUniformFogEquation = sFogEquation;
}

int CFog::getFogEquationType(){
	return iFogEquation;
}
float CFog::getDensity(){
	return fFogMaxDensity;
}
float CFog::getCurrentDensity(){
	return fDensity;
}
float CFog::getStart(){
	return fStart;
}
float CFog::getEnd(){
	return fEnd;
}

void CFog::updateFog(float fDeltaTime){
	if (fogStatus == FOG_STATUS_STABLE) return; //либо достиг max, либо 0
	float fFogDensityDelta = fDeltaTime * fFogDensityDeltaPerSecond;
	if (fogStatus == FOG_STATUS_INCREASING){ 
		fDensity = bGraduallyFogChanging ? min(fDensity + fFogDensityDelta, fFogMaxDensity) : fFogMaxDensity;
		if (fDensity == fFogMaxDensity) { //увеличиваем до тех пор, пока не станет максимальным, тогда останавливаем
			fogStatus = FOG_STATUS_STABLE; 
		}
	} else if (fogStatus == FOG_STATUS_DECREASING){
		fDensity = bGraduallyFogChanging ? max(fDensity - fFogDensityDelta, 0.0f) : 0.0f;
		if (fDensity == 0) { //уменьшаем до тех пор, пока не станет минимальным, тогда останавливаем
			fogStatus = FOG_STATUS_STABLE;
			bFogEnabled = FOG_ENABLED_FALSE;
		}
	}
}