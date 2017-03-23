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

	/*Добавить лестницу*/
	void addLadders();
	/*Добавить кубоид*/
	void addBalk(float fTranslateX, float fTranslateY, float fTranslateZ,
			 float fYaw, float fPitch, float fRoll, 
			 float fWidth, float fLength, float fHeight,
			 glm::vec2* texCoords, unsigned int texCoordsCount, float fTexScale, glm::vec2 fTexTransform);
	/*Добавить парус*/
	void addSail(float fTranslateX, float fTranslateY, float fTranslateZ,
				   float fYaw, float fPitch, float fRoll, //rotate
                      float fAngle, float fScale, float fFullWidth, int iSubDiv);
	/*Добавить мачту*/
	void addMast(float fTranslateX, float fTranslateY, float fTranslateZ, //translate
                    float fYaw, float fPitch, float fRoll, //rotate
                    float fRadius, float fullHeight, int iSubDiv,
					float fTexScale, glm::vec2 fTubeTexOffset, glm::vec2 fCoverTexOffset); //scale
    /*Формирование данных для мачты с парусами*/
	void addBoatMastWithSails(
						    float fMastBottomY, //Расположение нижней части мачты по oy
							float fMastRadius, //Радиус мачты
							float fMastHeight, //Высота мачты
							float fMastZPos, //Расположение центра мачты по oz
							float fMastToBeamRadius, //Соотношение радиуса мачты к радиусу перекладины
							float fBeam1YPosTop, //Расположение верхней перекладины верхнего паруса по oy, где 0 - макушка мачты, ось направлена вниз
							float fBeam2YPosTop, //Расположение нижней перекладины верхнего паруса по oy, где 0 - макушка мачты, ось направлена вниз
							float fBeam3YPosTop, //Расположение верхней перекладины нижнего паруса по oy, где 0 - макушка мачты, ось направлена вниз
							float fBeam4YPosTop, //Расположение нижней перекладины нижнего паруса по oy, где 0 - макушка мачты, ось направлена вниз
							float sail1Width, //Ширина верхнего паруса
							float sail2Width //Ширина нижнего паруса
						  );
	/*Точка вызова генерации мачт с парусами*/
	void addBoatSails();
    /*текущий индекс в iBoatIndices*/
	unsigned int currentIndex;

	/*Вспомогательные функции, добавляющие индексы в iBoatIndices
	quadCount - количество квадратов
	trinagleCount - количество треугольников
	two_sided - метка, показывающая, необходимо ли двустороннее отображение
	*/
	void addIndicesForQuad(unsigned int quadCount, bool two_sided);
	void addIndicesForTriangle(unsigned int triangleCount, bool two_sided);

};

