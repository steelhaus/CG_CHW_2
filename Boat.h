#pragma once

#include "vertexBufferObject.h"
#include <glm\gtc\matrix_transform.hpp>

class Boat{
public:
	Boat();
	void addBoat(CVertexBufferObject &vboDest);
	
	unsigned int *getBoatIndices();
	unsigned int getBoatIndicesSize();
private:
	//Boat skeleton
	vector<glm::vec3> vBoatVertices;
	vector<glm::vec2> vBoatTexCoords;
	vector<glm::vec3> vBoatNormals;
	vector<unsigned int> iBoatIndices;

	void generateWheel(float fFullRadius, float fWheelRadius, int iSubDivAround, int iSubDivTube, float fTranslateX, float fTranslateY, float fTranslateZ);

	/*�������� ��������*/
	void addLadders();
	/*�������� ������*/
	void addBalk(float fTranslateX, float fTranslateY, float fTranslateZ,
			 float fYaw, float fPitch, float fRoll, 
			 float fWidth, float fLength, float fHeight,
			 glm::vec2* texCoords, unsigned int texCoordsCount, float fTexScale, glm::vec2 fTexTransform);
	/*�������� �����*/
	void addSail(float fTranslateX, float fTranslateY, float fTranslateZ,
				   float fYaw, float fPitch, float fRoll, //rotate
                      float fAngle, float fScale, float fFullWidth, int iSubDiv);
	/*�������� �����*/
	void addMast(float fTranslateX, float fTranslateY, float fTranslateZ, //translate
                    float fYaw, float fPitch, float fRoll, //rotate
                    float fRadius, float fullHeight, int iSubDiv,
					float fTexScale, glm::vec2 fTubeTexOffset, glm::vec2 fCoverTexOffset); //scale
    /*������������ ������ ��� ����� � ��������*/
	void addBoatMastWithSails(
						    float fMastBottomY, //������������ ������ ����� ����� �� oy
							float fMastRadius, //������ �����
							float fMastHeight, //������ �����
							float fMastZPos, //������������ ������ ����� �� oz
							float fMastToBeamRadius, //����������� ������� ����� � ������� �����������
							float fBeam1YPosTop, //������������ ������� ����������� �������� ������ �� oy, ��� 0 - ������� �����, ��� ���������� ����
							float fBeam2YPosTop, //������������ ������ ����������� �������� ������ �� oy, ��� 0 - ������� �����, ��� ���������� ����
							float fBeam3YPosTop, //������������ ������� ����������� ������� ������ �� oy, ��� 0 - ������� �����, ��� ���������� ����
							float fBeam4YPosTop, //������������ ������ ����������� ������� ������ �� oy, ��� 0 - ������� �����, ��� ���������� ����
							float sail1Width, //������ �������� ������
							float sail2Width //������ ������� ������
						  );
	/*����� ������ ��������� ���� � ��������*/
	void addBoatSails();
    /*������� ������ � iBoatIndices*/
	unsigned int currentIndex;

	/*��������������� �������, ����������� ������� � iBoatIndices
	quadCount - ���������� ���������
	trinagleCount - ���������� �������������
	two_sided - �����, ������������, ���������� �� ������������ �����������
	*/
	void addIndicesForQuad(unsigned int quadCount, bool two_sided);
	void addIndicesForTriangle(unsigned int triangleCount, bool two_sided);

};

