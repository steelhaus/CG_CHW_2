#version 330

smooth in vec2 vTexCoord;
smooth in vec4 vEyeSpacePos;
smooth in vec3 vWorldPos;
out vec4 outputColor;

#include "fog.frag"

uniform sampler2D gSampler;
uniform vec4 vColor;
uniform FogParameters fogParams;
uniform int avrgSkyboxDistance;

void main(){
	vec4 vTexColor = texture2D(gSampler, vTexCoord);
	vec4 vMixedColor = vTexColor*vColor;

	if (fogParams.bFogEnabled == 0){
		outputColor = vMixedColor;
	} else {
		float fFogCoord = abs(vEyeSpacePos.z/vEyeSpacePos.w);
		outputColor = mix(vMixedColor, fogParams.vFogColor, getFogFactor(fogParams, avrgSkyboxDistance));
	}	
}