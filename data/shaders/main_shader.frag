#version 330

smooth in vec2 vTexCoord;
smooth in vec3 vNormal;
smooth in vec3 vEyeSpacePos;
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

void main()
{
	vec3 vNormalized = normalize(vNormal);
	
	vec4 vTexColor = texture2D(gSampler, vTexCoord);
	vec4 vMixedColor = vTexColor*vColor;
	vec4 vDirLightColor = getDirectionalLightColor(sunLight, vNormal);
	vec4 vSpotlightColor = GetSpotLightColor(spotLight, vWorldPos);
	vec4 vPointlightColor = vec4(0.0,0.0,0.0,0.0);
	for(int i = 0; i < lightsNumber; ++i){
		vPointlightColor += getPointLightColor(pointLight[i], vWorldPos, vNormalized);
	}
	outputColor = vMixedColor*(vDirLightColor+vSpotlightColor+vPointlightColor);
}