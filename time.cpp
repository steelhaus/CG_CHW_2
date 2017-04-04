#include "common_header.h"
#include "time.h"

float fFullDay = 86400.0f;
float fHalfADay = 43200.0f;
float fGradPerSecond = 360.0f / fFullDay;

float PI = float(atan(1.0)*4.0);
float fStartGrayShade = 1.0f; //������������. � 12:00 �� � ����������
float fEndGrayShade = 0.1f; //�����������, �� 24:00
float fDelta = (fStartGrayShade - fEndGrayShade)/pow(2.0f,2.0);

CTime::CTime(){
	fSecond = 43200.0f; //12:00
	fSecondsInRealSecond = 2880.0f; //1 day in 30 real seconds
}

CTime::CTime(float a_fSecond, float a_fSecondsInRealSecond){
	fSecond = a_fSecond;
	fSecondsInRealSecond = a_fSecondsInRealSecond;
}

void CTime::addTime(float fDeltaRealSecond){
	fSecond += fDeltaRealSecond * fSecondsInRealSecond;
	if (fSecond >= fFullDay) { //���� ������ ��������� ����
		fSecond -= fFullDay; 
	} else if (fSecond < 0) { //���� ������ ���������� ���� (����� ��������� �������� ����� �����?)
		fSecond = fFullDay;
	}
}

void CTime::addInnerTime(float fDeltaSecond){
	fSecond += fDeltaSecond;
	if (fSecond >= fFullDay) { //���� ������ ��������� ����
		fSecond -= fFullDay; 
	} else if (fSecond < 0) { //���� ������ ���������� ���� (����� ��������� �������� ����� �����?)
		fSecond = fFullDay;
	}
}

int CTime::getFullHours(){
	return fSecond / 3600;
}

int CTime::getFullMinutes(){
	return (int)fSecond % 3600 / 60;
}

int CTime::getFullSeconds(){
	return (int)fSecond % 60;
}

float CTime::getSunAngle(){
	return (fSecond - fHalfADay) * fGradPerSecond;
}

glm::vec4 CTime::getSkyboxColor(){	
	//� 12:00 ���� 1.0, ����� � 24:00 ������� �� 0.05
	//�� 12 �� 24 cos ���� ������ �������� �� 1 �� -1. ��������� � {0;2}
	float fCosine = cos(getSunAngle() * PI / 180.0f);
	float k = -1 * fCosine + 1; //1 -> 0; 0 -> 1; -1 -> 2
	float fShade = fStartGrayShade - pow(k,2.0f) * fDelta;
	return glm::vec4(fShade, fShade, fShade, 1.0f);
}