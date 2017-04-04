#pragma once


class CTime{
private:
	float fSecond;
public:
	float fSecondsInRealSecond;

	CTime();
	CTime(float a_fSecond, float a_fSecondsInRealSecond);

	void addTime(float fDeltaRealSecond);
	void addInnerTime(float fDeltaSecond);
	int getFullHours();
	int getFullMinutes();
	int getFullSeconds();

	float getSunAngle();
	glm::vec4 getSkyboxColor();
};