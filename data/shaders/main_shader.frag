#version 330

smooth in vec2 vTexCoord;
smooth in vec3 vNormal;
smooth in vec4 vEyeSpacePos;
smooth in vec3 vWorldPos;
out vec4 outputColor;

uniform sampler2D gSamplers[2];
uniform vec4 vColor;

uniform int numTextures;
uniform int textureTransitionRatio;

#include "dirLight.frag"
#include "spotLight.frag"
#include "pointLight.frag"
#include "fog.frag"

#define lightsNumber 4

uniform DirectionalLight sunLight;
uniform SpotLight spotLight;
uniform PointLight pointLight[lightsNumber];
uniform FogParameters fogParams;

void main()
{
	float m1 = vTexCoord.y / textureTransitionRatio;
	float m2 = 1 - vTexCoord.y / textureTransitionRatio;
	vec3 vNormalized = normalize(vNormal);
	vec4 vTexColor = texture2D(gSamplers[0], vTexCoord);
	if (numTextures > 1){
		vec4 vTexColor2 = texture2D(gSamplers[1], vTexCoord);
		vTexColor = vTexColor * m1 + vTexColor2 * m2;
	}

	vec4 vDirLightColor = getDirectionalLightColor(sunLight, vNormal);
	vec4 vSpotlightColor = GetSpotLightColor(spotLight, vWorldPos);
	vec4 vPointlightColor = vec4(0.0,0.0,0.0,0.0);
	for(int i = 0; i < lightsNumber; ++i){
		vPointlightColor += getPointLightColor(pointLight[i], vWorldPos, vNormalized);
	}
	vec4 vMixedColor = vTexColor*vColor*(vDirLightColor+vSpotlightColor+vPointlightColor);
	
	//here fog goes
	
	if (fogParams.bFogEnabled == 0){
		outputColor = vMixedColor;
	} else {
		float fFogCoord = abs(vEyeSpacePos.z/vEyeSpacePos.w);
		outputColor = mix(vMixedColor, fogParams.vFogColor, getFogFactor(fogParams, fFogCoord));
	
	}	
}