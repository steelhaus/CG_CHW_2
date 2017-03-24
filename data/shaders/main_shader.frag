#version 330

smooth in vec2 vTexCoord;
smooth in vec3 vNormal;
smooth in vec4 vEyeSpacePos;
smooth in vec3 vWorldPos;
out vec4 outputColor;

uniform sampler2D gSampler;
uniform vec4 vColor;

#include "dirLight.frag"
#include "spotLight.frag"
#include "pointLight.frag"

#define lightsNumber 2

uniform DirectionalLight sunLight;
uniform SpotLight spotLight;
uniform PointLight pointLight[lightsNumber];

uniform struct FogParameters
{
	vec4 vFogColor; // Fog color
	float fStart; // This is only for linear fog
	float fEnd; // This is only for linear fog
	float fDensity; // For exp and exp2 equation
	int iEquation; // 0 = linear, 1 = exp, 2 = exp2, 3 = none
} fogParams;

float getFogFactor(FogParameters params, float fFogCoord)
{
	float fResult = 0.0;
	if(params.iEquation == 0)
		fResult = (params.fEnd-fFogCoord)/(params.fEnd-params.fStart);
	else if(params.iEquation == 1)
		fResult = exp(-params.fDensity*fFogCoord);
	else if(params.iEquation == 2)
		fResult = exp(-pow(params.fDensity*fFogCoord, 2.0));
		
	fResult = 1.0-clamp(fResult, 0.0, 1.0);
	
	return fResult;
}

void main()
{
	vec3 vNormalized = normalize(vNormal);
	
	vec4 vTexColor = texture2D(gSampler, vTexCoord);
	vec4 vDirLightColor = getDirectionalLightColor(sunLight, vNormal);
	vec4 vSpotlightColor = GetSpotLightColor(spotLight, vWorldPos);
	vec4 vPointlightColor = vec4(0.0,0.0,0.0,0.0);
	for(int i = 0; i < lightsNumber; ++i){
		vPointlightColor += getPointLightColor(pointLight[i], vWorldPos, vNormalized);
	}
	vec4 vMixedColor = vTexColor*vColor*(vDirLightColor+vSpotlightColor+vPointlightColor);
	
	//here fog goes
	
	if (fogParams.iEquation == 3){
		outputColor = vMixedColor;
	} else {
		float fFogCoord = abs(vEyeSpacePos.z/vEyeSpacePos.w);
		outputColor = mix(vMixedColor, fogParams.vFogColor, getFogFactor(fogParams, fFogCoord));
	}	
}