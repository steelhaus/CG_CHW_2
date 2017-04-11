#include "common_header.h"
#include "Boat.h"

/*--------------------------------------skeleton --------------------------------------*/
glm::vec3 vSkeletonVertices[] = {
	//boat bottom
	glm::vec3(-0.0625f,-1.0f,-0.6875f), glm::vec3(-0.125f,-1.0f,-0.625f), glm::vec3(0.0625f,-1.0f,-0.6875f), glm::vec3(0.125f,-1.0f,-0.625f), 
	glm::vec3(-0.125f,-1.0f,-0.625f), glm::vec3(-0.15625,-1.0f,-0.51875f), glm::vec3(0.125f,-1.0f,-0.625f), glm::vec3(0.15625,-1.0f,-0.51875f), 
	glm::vec3(-0.15625,-1.0f,-0.51875f), glm::vec3(-0.1875f,-1.0f,-0.0625f), glm::vec3(0.15625,-1.0f,-0.51875f), glm::vec3(0.1875f,-1.0f,-0.0625f), 
	glm::vec3(-0.1875f,-1.0f,-0.0625f), glm::vec3(-0.1875f,-1.0f,0.125f), glm::vec3(0.1875f,-1.0f,-0.0625f), glm::vec3(0.1875f,-1.0f,0.125f), 
	glm::vec3(-0.1875f,-1.0f,0.125f), glm::vec3(-0.125f,-1.0f,0.2625f), glm::vec3(0.1875f,-1.0f,0.125f), glm::vec3(0.125f,-1.0f,0.2625f), 
	glm::vec3(-0.125f,-1.0f,0.2625f), glm::vec3(-0.015f,-1.0f,0.3625f), glm::vec3(0.125f,-1.0f,0.2625f), glm::vec3(0.015f,-1.0f,0.3625f), 
	//boat left 1
	glm::vec3(0.0f,-1.0f,-0.6875f), glm::vec3(0.0f,-0.925f,-0.7375f), glm::vec3(-0.0625f,-1.0f,-0.6875f), glm::vec3(-0.08125f,-0.925f,-0.7375f), 
	glm::vec3(-0.0625f,-1.0f,-0.6875f), glm::vec3(-0.08125f,-0.925f,-0.7375f), glm::vec3(-0.125f,-1.0f,-0.625f), glm::vec3(-0.15625f,-0.925f,-0.675f), 
	glm::vec3(-0.125f,-1.0f,-0.625f), glm::vec3(-0.15625f,-0.925f,-0.675f), glm::vec3(-0.15625,-1.0f,-0.51875f), glm::vec3(-0.20625f,-0.925f,-0.53125f), 
	glm::vec3(-0.15625,-1.0f,-0.51875f), glm::vec3(-0.20625f,-0.925f,-0.53125f), glm::vec3(-0.1875f,-1.0f,-0.0625f), glm::vec3(-0.23125f,-0.925f,-0.05f), 
	glm::vec3(-0.1875f,-1.0f,-0.0625f), glm::vec3(-0.23125f,-0.925f,-0.05f), glm::vec3(-0.1875f,-1.0f,0.125f), glm::vec3(-0.23125f,-0.925f,0.1375f), 
	glm::vec3(-0.1875f,-1.0f,0.125f), glm::vec3(-0.23125f,-0.925f,0.1375f), glm::vec3(-0.125f,-1.0f,0.2625f), glm::vec3(-0.175,-0.925f,0.3125f), 
	glm::vec3(-0.125f,-1.0f,0.2625f), glm::vec3(-0.175,-0.925f,0.3125f), glm::vec3(-0.015f,-1.0f,0.3625f), glm::vec3(-0.015f,-0.925f,0.4375f),
	glm::vec3(-0.015f,-1.0f,0.3625f), glm::vec3(-0.015f,-0.925f,0.4375f), glm::vec3(0.0f,-1.0f,0.3625f), glm::vec3(0.0f,-0.925f,0.4375f), 
	//boat right 1
	glm::vec3(0.0625f,-1.0f,-0.6875f), glm::vec3(0.08125f,-0.925f,-0.7375f), glm::vec3(0.0f,-1.0f,-0.6875f), glm::vec3(0.0f,-0.925f,-0.7375f), 
	glm::vec3(0.125f,-1.0f,-0.625f), glm::vec3(0.15625f,-0.925f,-0.675f), glm::vec3(0.0625f,-1.0f,-0.6875f), glm::vec3(0.08125f,-0.925f,-0.7375f),
	glm::vec3(0.15625,-1.0f,-0.51875f), glm::vec3(0.20625f,-0.925f,-0.53125f), glm::vec3(0.125f,-1.0f,-0.625f), glm::vec3(0.15625f,-0.925f,-0.675f),
	glm::vec3(0.1875f,-1.0f,-0.0625f), glm::vec3(0.23125f,-0.925f,-0.05f), glm::vec3(0.15625,-1.0f,-0.51875f), glm::vec3(0.20625f,-0.925f,-0.53125f),
	glm::vec3(0.1875f,-1.0f,0.125f), glm::vec3(0.23125f,-0.925f,0.1375f), glm::vec3(0.1875f,-1.0f,-0.0625f), glm::vec3(0.23125f,-0.925f,-0.05f),
	glm::vec3(0.125f,-1.0f,0.2625f), glm::vec3(0.175,-0.925f,0.3125f), glm::vec3(0.1875f,-1.0f,0.125f), glm::vec3(0.23125f,-0.925f,0.1375f),
	glm::vec3(0.015f,-1.0f,0.3625f), glm::vec3(0.015f,-0.925f,0.4375f), glm::vec3(0.125f,-1.0f,0.2625f), glm::vec3(0.175,-0.925f,0.3125f),
	glm::vec3(0.0f,-1.0f,0.3625f), glm::vec3(0.0f,-0.925f,0.4375f), glm::vec3(0.015f,-1.0f,0.3625f), glm::vec3(0.015f,-0.925f,0.4375f),
	//boat left 2
	glm::vec3(0.0f,-0.925f,-0.7375f), glm::vec3(0.0f,-0.850f,-0.76875f), glm::vec3(-0.08125f,-0.925f,-0.7375f), glm::vec3(-0.1f,-0.850f,-0.76875f),
	glm::vec3(-0.08125f,-0.925f,-0.7375f), glm::vec3(-0.1f,-0.850f,-0.76875f), glm::vec3(-0.11875,-0.925f,-0.70625f), glm::vec3(-0.1875f,-0.850f,-0.7625f),
	glm::vec3(-0.11875,-0.925f,-0.70625f), glm::vec3(-0.1875f,-0.850f,-0.7625f), glm::vec3(-0.15625f,-0.925f,-0.675f), glm::vec3(-0.23125f,-0.850f,-0.6875f),
	glm::vec3(-0.15625f,-0.925f,-0.675f), glm::vec3(-0.23125f,-0.850f,-0.6875f), glm::vec3(-0.20625f,-0.925f,-0.53125f), glm::vec3(-0.26875f,-0.850f,-0.53125f),
	glm::vec3(-0.20625f,-0.925f,-0.53125f), glm::vec3(-0.26875f,-0.850f,-0.53125f), glm::vec3(-0.23125f,-0.925f,-0.05f), glm::vec3(-0.271875f,-0.850f,-0.025f),
	glm::vec3(-0.23125f,-0.925f,-0.05f), glm::vec3(-0.271875f,-0.850f,-0.025f), glm::vec3(-0.23125f,-0.925f,0.1375f), glm::vec3(-0.271875f,-0.850f,0.1375f),
	glm::vec3(-0.23125f,-0.925f,0.1375f), glm::vec3(-0.271875f,-0.850f,0.1375f), glm::vec3(-0.175,-0.925f,0.3125f), glm::vec3(-0.2f,-0.850f,0.31875f),
	glm::vec3(-0.175,-0.925f,0.3125f), glm::vec3(-0.2f,-0.850f,0.31875f), glm::vec3(-0.015f,-0.925f,0.4375f), glm::vec3(-0.015f,-0.850f,0.5f),
	glm::vec3(-0.015f,-0.925f,0.4375f), glm::vec3(-0.015f,-0.850f,0.5f), glm::vec3(0.0f,-0.925f,0.4375f),  glm::vec3(0.0f,-0.850f,0.5f),
	//boat right 2
	glm::vec3(0.08125f,-0.925f,-0.7375f), glm::vec3(0.1f,-0.850f,-0.76875f), glm::vec3(0.0f,-0.925f,-0.7375f), glm::vec3(0.0f,-0.850f,-0.76875f), 
	glm::vec3(0.11875,-0.925f,-0.70625f), glm::vec3(0.1875f,-0.850f,-0.7625f), glm::vec3(0.08125f,-0.925f,-0.7375f), glm::vec3(0.1f,-0.850f,-0.76875f), 
	glm::vec3(0.15625f,-0.925f,-0.675f), glm::vec3(0.23125f,-0.850f,-0.6875f), glm::vec3(0.11875,-0.925f,-0.70625f), glm::vec3(0.1875f,-0.850f,-0.7625f), 
	glm::vec3(0.20625f,-0.925f,-0.53125f), glm::vec3(0.26875f,-0.850f,-0.53125f), glm::vec3(0.15625f,-0.925f,-0.675f), glm::vec3(0.23125f,-0.850f,-0.6875f), 
	glm::vec3(0.23125f,-0.925f,-0.05f), glm::vec3(0.271875f,-0.850f,-0.025f), glm::vec3(0.20625f,-0.925f,-0.53125f), glm::vec3(0.26875f,-0.850f,-0.53125f), 
	glm::vec3(0.23125f,-0.925f,0.1375f), glm::vec3(0.271875f,-0.850f,0.1375f), glm::vec3(0.23125f,-0.925f,-0.05f), glm::vec3(0.271875f,-0.850f,-0.025f), 
	glm::vec3(0.175,-0.925f,0.3125f), glm::vec3(0.2f,-0.850f,0.31875f), glm::vec3(0.23125f,-0.925f,0.1375f), glm::vec3(0.271875f,-0.850f,0.1375f), 
	glm::vec3(0.015f,-0.925f,0.4375f), glm::vec3(0.015f,-0.850f,0.5f), glm::vec3(0.175,-0.925f,0.3125f), glm::vec3(0.2f,-0.850f,0.31875f), 
	glm::vec3(0.0f,-0.925f,0.4375f),  glm::vec3(0.0f,-0.850f,0.5f), glm::vec3(0.015f,-0.925f,0.4375f), glm::vec3(0.015f,-0.850f,0.5f), 
	//boat left 3
	glm::vec3(0.0f,-0.850f,-0.76875f), glm::vec3(0.0f,-0.775f,-0.76875f), glm::vec3(-0.1f,-0.850f,-0.76875f), glm::vec3(-0.1f,-0.775f,-0.76875f),
	glm::vec3(-0.1f,-0.850f,-0.76875f), glm::vec3(-0.1f,-0.775f,-0.76875f), glm::vec3(-0.1875f,-0.850f,-0.7625f), glm::vec3(-0.1875f,-0.775f,-0.7625f),
	glm::vec3(-0.1875f,-0.850f,-0.7625f), glm::vec3(-0.1875f,-0.775f,-0.7625f), glm::vec3(-0.23125f,-0.850f,-0.6875f), glm::vec3(-0.23125f,-0.775f,-0.6875f),
	glm::vec3(-0.23125f,-0.850f,-0.6875f), glm::vec3(-0.23125f,-0.775f,-0.6875f), glm::vec3(-0.26875f,-0.850f,-0.53125f), glm::vec3(-0.26875f,-0.775f,-0.53125f),
	glm::vec3(-0.26875f,-0.850f,-0.53125f), glm::vec3(-0.26875f,-0.775f,-0.53125f), glm::vec3(-0.271875f,-0.850f,-0.025f), glm::vec3(-0.271875f,-0.775f,-0.025f),
	glm::vec3(-0.271875f,-0.850f,-0.025f), glm::vec3(-0.271875f,-0.775f,-0.025f), glm::vec3(-0.271875f,-0.850f,0.1375f), glm::vec3(-0.271875f,-0.775f,0.1375f),
	glm::vec3(-0.271875f,-0.850f,0.1375f), glm::vec3(-0.271875f,-0.775f,0.1375f), glm::vec3(-0.2f,-0.850f,0.31875f), glm::vec3(-0.2f,-0.775f,0.31875f),
	glm::vec3(-0.2f,-0.850f,0.31875f), glm::vec3(-0.2f,-0.775f,0.31875f), glm::vec3(-0.015f,-0.850f,0.5f), glm::vec3(-0.015f,-0.775f,0.5f),
	glm::vec3(-0.015f,-0.850f,0.5f), glm::vec3(-0.015f,-0.775f,0.5f), glm::vec3(0.0f,-0.850f,0.5f),  glm::vec3(0.0f,-0.775f,0.5f),
	//boat right 3
	glm::vec3(0.1f,-0.850f,-0.76875f), glm::vec3(0.1f,-0.775f,-0.76875f), glm::vec3(0.0f,-0.850f,-0.76875f), glm::vec3(0.0f,-0.775f,-0.76875f), 
	glm::vec3(0.1875f,-0.850f,-0.7625f), glm::vec3(0.1875f,-0.775f,-0.7625f), glm::vec3(0.1f,-0.850f,-0.76875f), glm::vec3(0.1f,-0.775f,-0.76875f), 
	glm::vec3(0.23125f,-0.850f,-0.6875f), glm::vec3(0.23125f,-0.775f,-0.6875f), glm::vec3(0.1875f,-0.850f,-0.7625f), glm::vec3(0.1875f,-0.775f,-0.7625f), 
	glm::vec3(0.26875f,-0.850f,-0.53125f), glm::vec3(0.26875f,-0.775f,-0.53125f), glm::vec3(0.23125f,-0.850f,-0.6875f), glm::vec3(0.23125f,-0.775f,-0.6875f), 
	glm::vec3(0.271875f,-0.850f,-0.025f), glm::vec3(0.271875f,-0.775f,-0.025f), glm::vec3(0.26875f,-0.850f,-0.53125f), glm::vec3(0.26875f,-0.775f,-0.53125f), 
	glm::vec3(0.271875f,-0.850f,0.1375f), glm::vec3(0.271875f,-0.775f,0.1375f), glm::vec3(0.271875f,-0.850f,-0.025f), glm::vec3(0.271875f,-0.775f,-0.025f), 
	glm::vec3(0.2f,-0.850f,0.31875f), glm::vec3(0.2f,-0.775f,0.31875f), glm::vec3(0.271875f,-0.850f,0.1375f), glm::vec3(0.271875f,-0.775f,0.1375f), 
	glm::vec3(0.015f,-0.850f,0.5f), glm::vec3(0.015f,-0.775f,0.5f), glm::vec3(0.2f,-0.850f,0.31875f), glm::vec3(0.2f,-0.775f,0.31875f), 
	glm::vec3(0.0f,-0.850f,0.5f),  glm::vec3(0.0f,-0.775f,0.5f), glm::vec3(0.015f,-0.850f,0.5f), glm::vec3(0.015f,-0.775f,0.5f), 	
	//boat stern
	glm::vec3(-0.0f,-0.775f,-0.76875f), glm::vec3(-0.0f,-0.67f,-0.76875f), glm::vec3(-0.1f,-0.775f,-0.76875f), glm::vec3(-0.1f,-0.67f,-0.76875f), 
	glm::vec3(-0.1f,-0.775f,-0.76875f), glm::vec3(-0.1f,-0.67f,-0.76875f), glm::vec3(-0.1875f,-0.775f,-0.7625f), glm::vec3(-0.1875f,-0.67f,-0.7625f),
	glm::vec3(-0.1875f,-0.775f,-0.7625f), glm::vec3(-0.1875f,-0.67f,-0.7625f), glm::vec3(-0.23125f,-0.775f,-0.6875f), glm::vec3(-0.23125f,-0.67f,-0.6875f), 
    glm::vec3(-0.23125f,-0.775f,-0.6875f), glm::vec3(-0.23125f,-0.67f,-0.6875f), glm::vec3(-0.26875f,-0.775f,-0.53125f), glm::vec3(-0.26875f,-0.67f,-0.53125f),
	glm::vec3(0.1f,-0.775f,-0.76875f), glm::vec3(0.1f,-0.67f,-0.76875f), glm::vec3(0.0f,-0.775f,-0.76875f), glm::vec3(0.0f,-0.67f,-0.76875f), 
	glm::vec3(0.1875f,-0.775f,-0.7625f), glm::vec3(0.1875f,-0.67f,-0.7625f), glm::vec3(0.1f,-0.775f,-0.76875f), glm::vec3(0.1f,-0.67f,-0.76875f), 
	glm::vec3(0.23125f,-0.775f,-0.6875f), glm::vec3(0.23125f,-0.67f,-0.6875f), glm::vec3(0.1875f,-0.775f,-0.7625f), glm::vec3(0.1875f,-0.67f,-0.7625f), 
    glm::vec3(0.26875f,-0.775f,-0.53125f), glm::vec3(0.26875f,-0.67f,-0.53125f), glm::vec3(0.23125f,-0.775f,-0.6875f), glm::vec3(0.23125f,-0.67f,-0.6875f), 
	glm::vec3(-0.26875f,-0.775f,-0.53125f), glm::vec3(-0.26875f,-0.67f,-0.53125f), glm::vec3(0.26875f,-0.775f,-0.53125f), glm::vec3(0.26875f,-0.67f,-0.53125f),
	//boat front mast 
	glm::vec3(0.015f, -0.74f, 0.5f), glm::vec3(0.0025f, -0.55f, 0.95f), glm::vec3(-0.015f, -0.74f, 0.5f), glm::vec3(-0.0025f, -0.55f, 0.95f),
	glm::vec3(-0.015f, -0.74f, 0.5f), glm::vec3(-0.0025f, -0.55f, 0.95f), glm::vec3(-0.015f, -0.775f, 0.5f), glm::vec3(-0.0025f, -0.555f, 0.95f),
	glm::vec3(-0.015f, -0.775f, 0.5f), glm::vec3(-0.0025f, -0.555f, 0.95f), glm::vec3(0.015f, -0.775f, 0.5f), glm::vec3(0.0025f, -0.555f, 0.95f),
	glm::vec3(0.015f, -0.775f, 0.5f), glm::vec3(0.0025f, -0.555f, 0.95f), glm::vec3(0.015f, -0.74f, 0.5f), glm::vec3(0.0025f, -0.55f, 0.95f),
	glm::vec3(-0.0025f, -0.555f, 0.95f), glm::vec3(-0.0025f, -0.55f, 0.95f), glm::vec3(0.0025f, -0.555f, 0.95f), glm::vec3(0.0025f, -0.55f, 0.95f),
};
glm::vec2 vSkeletonTexCoords[] = {
	//boat bottom
	glm::vec2(0.0f, 0.7f), glm::vec2(0.0f,0.4f), glm::vec2(1.0f,0.7f), glm::vec2(1.0f,0.4f),
	glm::vec2(0.0f, 1.0f), glm::vec2(0.0f,0.7f), glm::vec2(1.0f,1.0f), glm::vec2(1.0f,0.7f),
	glm::vec2(0.0f, 0.0f), glm::vec2(0.0f,1.0f), glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f),
	glm::vec2(0.0f, 1.0f), glm::vec2(0.0f,0.7f), glm::vec2(1.0f,1.0f), glm::vec2(1.0f,0.7f),
	glm::vec2(0.0f, 0.7f), glm::vec2(0.0f,0.4f), glm::vec2(1.0f,0.7f), glm::vec2(1.0f,0.4f),
	glm::vec2(0.0f, 0.4f), glm::vec2(0.45f,0.2f), glm::vec2(1.0f,0.4f), glm::vec2(0.55f,0.2f),
	//boat left 1
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f), glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f),
	glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f), glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f),
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f), glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f),
	glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f), glm::vec2(0.4f,0.0f), glm::vec2(0.4f,0.4f),
	//boat right 1
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f), glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f),
	glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f), glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f),
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f), glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f),
	glm::vec2(1.0f,0.0f), glm::vec2(1.0f,0.4f), glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f),
	glm::vec2(0.5f,0.0f), glm::vec2(0.5f,0.4f), glm::vec2(0.4f,0.0f), glm::vec2(0.4f,0.4f),
	//boat left 2
	glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(0.3f,0.4f), glm::vec2(0.0f,0.8f),
	glm::vec2(0.3f,0.4f), glm::vec2(0.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f),
	glm::vec2(0.0f,0.4f), glm::vec2(0.0f,0.8f), glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f),
	glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(0.0f,0.4f), glm::vec2(0.0f,0.8f),
	glm::vec2(0.0f,0.4f), glm::vec2(0.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(0.55f,0.4f), glm::vec2(0.55f,0.8f),
	//boat right 2
	glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(0.3f,0.4f), glm::vec2(0.0f,0.8f),
	glm::vec2(0.3f,0.4f), glm::vec2(0.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f),
	glm::vec2(0.0f,0.4f), glm::vec2(0.0f,0.8f), glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f),
	glm::vec2(1.0f,0.4f), glm::vec2(1.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(0.0f,0.4f), glm::vec2(0.0f,0.8f),
	glm::vec2(0.0f,0.4f), glm::vec2(0.0f,0.8f), glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f),
	glm::vec2(0.5f,0.4f), glm::vec2(0.5f,0.8f), glm::vec2(0.55f,0.4f), glm::vec2(0.55f,0.8f),
	//boat left 3
	glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f), glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f),
	glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f), glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f),
	glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f), glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f),
	glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f), glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f),
	glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f), glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f), 
	glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f), glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f),
	glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f), glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f),
	glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f), glm::vec2(0.8f,0.75f), glm::vec2(0.8f,0.35f),
	glm::vec2(0.8f,0.75f), glm::vec2(0.8f,0.35f), glm::vec2(0.85f,0.75f), glm::vec2(0.85f,0.35f),
	//boat right 3
	glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f), glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f),
	glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f), glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f),
	glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f), glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f),
	glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f), glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f),
	glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f), glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f), 
	glm::vec2(1.0f,0.75f), glm::vec2(1.0f,0.35f), glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f),
	glm::vec2(0.5f,0.75f), glm::vec2(0.5f,0.35f), glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f),
	glm::vec2(0.0f,0.75f), glm::vec2(0.0f,0.35f), glm::vec2(0.8f,0.75f), glm::vec2(0.8f,0.35f),
	glm::vec2(0.8f,0.75f), glm::vec2(0.8f,0.35f), glm::vec2(0.85f,0.75f), glm::vec2(0.85f,0.35f),
	//stern
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,1.0f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f), glm::vec2(1.0f,0.325f), glm::vec2(1.0f,1.0f),
	glm::vec2(1.0f,0.325f), glm::vec2(1.0f,1.0f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f), glm::vec2(0.0f,0.325f), glm::vec2(0.0f,1.0f),
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,1.0f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f), glm::vec2(1.0f,0.325f), glm::vec2(1.0f,1.0f),
	glm::vec2(1.0f,0.325f), glm::vec2(1.0f,1.0f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,1.0f), glm::vec2(0.0f,0.325f), glm::vec2(0.0f,1.0f),
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,1.0f), glm::vec2(1.0f,0.325f), glm::vec2(1.0f,1.0f),
	//boat front mast  (nose?)
	glm::vec2(0.0f,0.2f), glm::vec2(1.0f,0.1025f), glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0975f),
	glm::vec2(0.0f,0.135f), glm::vec2(1.0f,0.05f), glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f),
	glm::vec2(0.0f,0.2f), glm::vec2(1.0f,0.1025f), glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0975f),
	glm::vec2(0.0f,0.135f), glm::vec2(1.0f,0.05f), glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f),
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,0.05f), glm::vec2(0.05f,0.0f), glm::vec2(0.05f,0.05f)
};
glm::vec3 vSkeletonNormals[] = {
	glm::vec3(0.0f, 0.0f, 1.0f),
};


/*--------------------------------------skeleton borts --------------------------------------*/
glm::vec3 vSkeletonBortsVertices[] = {	   
    glm::vec3(-0.271875f,-0.775f,-0.025f), glm::vec3(-0.271875f,-0.74f,-0.025f), glm::vec3(-0.26875f,-0.775f,-0.53125f), glm::vec3(-0.26875f,-0.74f,-0.53125f),
    glm::vec3(-0.271875f,-0.775f,0.1375f), glm::vec3(-0.271875f,-0.74f,0.1375f), glm::vec3(-0.271875f,-0.775f,-0.025f), glm::vec3(-0.271875f,-0.74f,-0.025f),
    glm::vec3(-0.2f,-0.775f,0.31875f), glm::vec3(-0.2f,-0.74f,0.31875f), glm::vec3(-0.271875f,-0.775f,0.1375f), glm::vec3(-0.271875f,-0.74f,0.1375f),
    glm::vec3(-0.015f,-0.775f,0.5f), glm::vec3(-0.015f,-0.74f,0.5f), glm::vec3(-0.2f,-0.775f,0.31875f), glm::vec3(-0.2f,-0.74f,0.31875f),
    glm::vec3(-0.0f,-0.775f,0.5f),  glm::vec3(-0.0f,-0.74f,0.5f), glm::vec3(-0.015f,-0.775f,0.5f), glm::vec3(-0.015f,-0.74f,0.5f),

	glm::vec3(0.271875f,-0.775f,-0.025f), glm::vec3(0.271875f,-0.74f,-0.025f), glm::vec3(0.26875f,-0.775f,-0.53125f), glm::vec3(0.26875f,-0.74f,-0.53125f),
	glm::vec3(0.271875f,-0.775f,0.1375f), glm::vec3(0.271875f,-0.74f,0.1375f), glm::vec3(0.271875f,-0.775f,-0.025f), glm::vec3(0.271875f,-0.74f,-0.025f),
	glm::vec3(0.2f,-0.775f,0.31875f), glm::vec3(0.2f,-0.74f,0.31875f), glm::vec3(0.271875f,-0.775f,0.1375f), glm::vec3(0.271875f,-0.74f,0.1375f),
	glm::vec3(0.015f,-0.775f,0.5f), glm::vec3(0.015f,-0.74f,0.5f), glm::vec3(0.2f,-0.775f,0.31875f), glm::vec3(0.2f,-0.74f,0.31875f),
	glm::vec3(0.0f,-0.775f,0.5f),  glm::vec3(0.0f,-0.74f,0.5f), glm::vec3(0.015f,-0.775f,0.5f), glm::vec3(0.015f,-0.74f,0.5f),

	glm::vec3(-0.1f,-0.67f,-0.76875f), glm::vec3(-0.1f,-0.635f,-0.76875f), glm::vec3(-0.0f,-0.67f,-0.76875f), glm::vec3(-0.0f,-0.635f,-0.76875f),
	glm::vec3(-0.1875f,-0.67f,-0.7625f), glm::vec3(-0.1875f,-0.635f,-0.7625f), glm::vec3(-0.1f,-0.67f,-0.76875f), glm::vec3(-0.1f,-0.635f,-0.76875f),
	glm::vec3(-0.23125f,-0.67f,-0.6875f), glm::vec3(-0.23125f,-0.635f,-0.6875f), glm::vec3(-0.1875f,-0.67f,-0.7625f), glm::vec3(-0.1875f,-0.635f,-0.7625f),
	glm::vec3(-0.26875f,-0.67f,-0.53125f), glm::vec3(-0.26875f,-0.635f,-0.53125f), glm::vec3(-0.23125f,-0.67f,-0.6875f), glm::vec3(-0.23125f,-0.635f,-0.6875f),

    glm::vec3(0.0f,-0.67f,-0.76875f), glm::vec3(0.0f,-0.635f,-0.76875f), glm::vec3(0.1f,-0.67f,-0.76875f), glm::vec3(0.1f,-0.635f,-0.76875f), 
    glm::vec3(0.1f,-0.67f,-0.76875f), glm::vec3(0.1f,-0.635f,-0.76875f), glm::vec3(0.1875f,-0.67f,-0.7625f), glm::vec3(0.1875f,-0.635f,-0.7625f), 
    glm::vec3(0.1875f,-0.67f,-0.7625f), glm::vec3(0.1875f,-0.635f,-0.7625f), glm::vec3(0.23125f,-0.67f,-0.6875f), glm::vec3(0.23125f,-0.635f,-0.6875f), 
    glm::vec3(0.23125f,-0.67f,-0.6875f), glm::vec3(0.23125f,-0.635f,-0.6875f), glm::vec3(0.26875f,-0.67f,-0.53125f), glm::vec3(0.26875f,-0.635f,-0.53125f),     
};
glm::vec2 vSkeletonBortsTexCoords[] = {
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,0.55f), glm::vec2(1.0f,0.325f), glm::vec2(1.0f,0.55f),
	glm::vec2(1.0f,0.325f), glm::vec2(1.0f,0.55f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f), glm::vec2(0.0f,0.325f), glm::vec2(0.0f,0.55f),
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,0.55f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f), glm::vec2(0.55f,0.325f), glm::vec2(0.55f,0.55f),
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,0.55f), glm::vec2(1.0f,0.325f), glm::vec2(1.0f,0.55f),
	glm::vec2(1.0f,0.325f), glm::vec2(1.0f,0.55f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f), glm::vec2(0.0f,0.325f), glm::vec2(0.0f,0.55f),
	glm::vec2(0.0f,0.325f), glm::vec2(0.0f,0.55f), glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f),
	glm::vec2(0.5f,0.325f), glm::vec2(0.5f,0.55f), glm::vec2(0.55f,0.325f), glm::vec2(0.55f,0.55f),

	glm::vec2(0.0f,0.5f), glm::vec2(0.0f,0.725f), glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f),
	glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f), glm::vec2(1.0f,0.5f), glm::vec2(1.0f,0.725f),
	glm::vec2(1.0f,0.5f), glm::vec2(1.0f,0.725f), glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f),
	glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f), glm::vec2(0.0f,0.5f), glm::vec2(0.0f,0.725f),
	glm::vec2(0.0f,0.5f), glm::vec2(0.0f,0.725f), glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f),
	glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f), glm::vec2(1.0f,0.5f), glm::vec2(1.0f,0.725f),
	glm::vec2(1.0f,0.5f), glm::vec2(1.0f,0.725f), glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f),
	glm::vec2(0.5f,0.5f), glm::vec2(0.5f,0.725f), glm::vec2(0.0f,0.5f), glm::vec2(0.0f,0.725f),
};
glm::vec3 vSkeletonBortsNormals[] = {
	glm::vec3(1.0f,1.0f,1.0f),
};

/*--------------------------------------skeleton deck --------------------------------------*/
glm::vec3 vSkeletonDeckVertices[] = {
	//boat top low
	glm::vec3(-0.26875f,-0.775f,-0.53125f),glm::vec3(0.26875f,-0.775f,-0.53125f),glm::vec3(-0.271875f,-0.775f,-0.025f),glm::vec3(0.271875f,-0.775f,-0.025f),
	glm::vec3(-0.271875f,-0.775f,-0.025f),glm::vec3(0.271875f,-0.775f,-0.025f),glm::vec3(-0.271875f,-0.775f,0.1375f),glm::vec3(0.271875f,-0.775f,0.1375f),
	glm::vec3(-0.271875f,-0.775f,0.1375f),glm::vec3(0.271875f,-0.775f,0.1375f),glm::vec3(-0.2f,-0.775f,0.31875f),glm::vec3(0.2f,-0.775f,0.31875f),
	glm::vec3(-0.2f,-0.775f,0.31875f),glm::vec3(0.2f,-0.775f,0.31875f),glm::vec3(-0.015f,-0.775f,0.5f),glm::vec3(0.015f,-0.775f,0.5f),
	//boat top stern
	glm::vec3(-0.1f,-0.67f,-0.76875f),glm::vec3(0.1f,-0.67f,-0.76875f),glm::vec3(-0.1875f,-0.67f,-0.7625f),glm::vec3(0.1875f,-0.67f,-0.7625f),
	glm::vec3(-0.1875f,-0.67f,-0.7625f),glm::vec3(0.1875f,-0.67f,-0.7625f),glm::vec3(-0.23125f,-0.67f,-0.6875f),glm::vec3(0.23125f,-0.67f,-0.6875f),
	glm::vec3(-0.23125f,-0.67f,-0.6875f),glm::vec3(0.23125f,-0.67f,-0.6875f),glm::vec3(-0.26875f,-0.67f,-0.53125f),glm::vec3(0.26875f,-0.67f,-0.53125f),
};
glm::vec2 vSkeletonDeckTexCoords[] = {
	glm::vec2(0.0f,0.0f), glm::vec2(0.0f,1.0f), glm::vec2(0.98f,0.0f), glm::vec2(0.98f,1.0f),
	glm::vec2(0.98f,0.0f), glm::vec2(0.98f,1.0f), glm::vec2(0.6f,0.0f), glm::vec2(0.6f,1.0f),
	glm::vec2(0.6f,0.0f), glm::vec2(0.6f,1.0f), glm::vec2(0.3f,0.13f), glm::vec2(0.3f,0.87f),
	glm::vec2(0.3f,0.13f), glm::vec2(0.3f,0.87f), glm::vec2(0.0f,0.46f), glm::vec2(0.0f,0.54f),

	glm::vec2(0.435f,0.32f), glm::vec2(0.435f,0.68f), glm::vec2(0.45f,0.15f), glm::vec2(0.45f,0.85f),
	glm::vec2(0.45f,0.15f), glm::vec2(0.45f,0.85f), glm::vec2(0.6f,0.07f), glm::vec2(0.6f,0.93f),
	glm::vec2(0.6f,0.07f), glm::vec2(0.6f,0.93f), glm::vec2(0.98,0.0f), glm::vec2(0.98f,1.0f),
};
glm::vec3 vSkeletonDeckNormals[] = {
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
	glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),
};


//Constructor
Boat::Boat(){
	currentIndex = 0;
	glm::vec2 vDefaultTexCoord(0.0f,0.0f);
	glm::vec3 vDefaultNorm(1.0f,1.0f,1.0f);
	//колесо
	generateWheel(0.04f,0.005f,30,30,0.0f,-0.59f,-0.58f);
	addMast(0.0f,-0.59f,-0.58f,
		0.0f,0.0f,0.0f,0.0025f,0.11f,20,0.5f,glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	addMast(0.0f,-0.59f,-0.58f,
		45.0f,0.0f,0.0f,0.0025f,0.11f,20,0.5f,glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	addMast(0.0f,-0.59f,-0.58f,
		90.0f,0.0f,0.0f,0.0025f,0.11f,20,0.5f,glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	addMast(0.0f,-0.59f,-0.58f,
		-45.0f,0.0f,0.0f,0.0025f,0.11f,20,0.5f,glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));		

	//Пихаем данные о скелете
	int vertVectorSize = sizeof(vSkeletonVertices) / sizeof(glm::vec3); //vert
	int texVectorSize = sizeof(vSkeletonTexCoords) / sizeof(glm::vec2); //tex
	int normVectorSize = sizeof(vSkeletonNormals) / sizeof(glm::vec3); //norm
	float fScale = 0.5f; //четверть текстуры
	glm::vec2 vTexShift(0.0f, 0.5f); //сдвиг (верхняя левая часть)
	FOR(i, vertVectorSize){
		vBoatVertices.push_back(vSkeletonVertices[i]);
		vBoatTexCoords.push_back(i < texVectorSize ? vSkeletonTexCoords[i] * fScale + vTexShift : vDefaultTexCoord);
		vBoatNormals.push_back(i < normVectorSize ? vSkeletonNormals[i] : vDefaultNorm);
	}
	addIndicesForQuad(vertVectorSize / 4, false);

	//Пихаем данные о бортах
	vTexShift = glm::vec2(0.0f, 0.5f);
	vertVectorSize = sizeof(vSkeletonBortsVertices) / sizeof(glm::vec3);
	texVectorSize = sizeof(vSkeletonBortsTexCoords) / sizeof(glm::vec2);
	normVectorSize = sizeof(vSkeletonBortsNormals) / sizeof(glm::vec3);
	FOR(i, vertVectorSize){
		vBoatVertices.push_back(vSkeletonBortsVertices[i]);
		vBoatTexCoords.push_back(i < texVectorSize ? vSkeletonBortsTexCoords[i] * fScale + vTexShift : vDefaultTexCoord);
		vBoatNormals.push_back(i < normVectorSize ? vSkeletonBortsNormals[i] : vDefaultNorm);
	}
	addIndicesForQuad(vertVectorSize / 4, true); //add two sided bort

	//Пихаем данные о палубе
	vTexShift = glm::vec2(0.5f, 0.5f);
	vertVectorSize = sizeof(vSkeletonDeckVertices) / sizeof(glm::vec3);
	texVectorSize = sizeof(vSkeletonDeckTexCoords) / sizeof(glm::vec2);
	normVectorSize = sizeof(vSkeletonDeckNormals) / sizeof(glm::vec3);
	FOR(i, vertVectorSize){
		vBoatVertices.push_back(vSkeletonDeckVertices[i]);
		vBoatTexCoords.push_back(i < texVectorSize ? vSkeletonDeckTexCoords[i] * fScale + vTexShift : vDefaultTexCoord);
		vBoatNormals.push_back(i < normVectorSize ? vSkeletonDeckNormals[i] : vDefaultNorm);
	}
	addIndicesForQuad(vertVectorSize / 4, false);

	//Пихаем данные о лесенках
	addLadders();
	addBoatSails();
}

void Boat::generateWheel(
	float fFullRadius, float fWheelRadius, int iSubDivAround, int iSubDivTube, float fTranslateX, float fTranslateY, float fTranslateZ)
{
	float fAddAngleAround = 360.0f/(float)iSubDivAround;
	float fAddAngleTube = 360.0f/(float)iSubDivTube;

	float fCurAngleAround = 0.0f;
	int iStepsAround = 1;
	const float PI = float(atan(1.0)*4.0);

	while(iStepsAround <= iSubDivAround)
	{
		float fSineAround = sin(fCurAngleAround/180.0f*PI);
		float fCosineAround = cos(fCurAngleAround/180.0f*PI);
		glm::vec3 vDir1(fSineAround, fCosineAround, 0.0f);
		float fNextAngleAround = fCurAngleAround+fAddAngleAround;
		float fNextSineAround = sin(fNextAngleAround/180.0f*PI);
		float fNextCosineAround = cos(fNextAngleAround/180.0f*PI);
		glm::vec3 vDir2(fNextSineAround, fNextCosineAround, 0.0f);
		float fCurAngleTube = 0.0f;
		int iStepsTube = 1;
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(fTranslateX,fTranslateY,fTranslateZ));
		while(iStepsTube <= iSubDivTube)
		{
			float fSineTube = sin(fCurAngleTube/180.0f*PI);
			float fCosineTube = cos(fCurAngleTube/180.0f*PI);
			float fNextAngleTube = fCurAngleTube+fAddAngleTube;
			float fNextSineTube = sin(fNextAngleTube/180.0f*PI);
			float fNextCosineTube = cos(fNextAngleTube/180.0f*PI);
			glm::vec3 vMid1 = vDir1*(fFullRadius-fWheelRadius/2), vMid2 = vDir2*(fFullRadius-fWheelRadius/2);
			glm::vec3 vQuadPoints[] = 
			{
				
				/*vMid1 + glm::vec3(0.0f, 0.0f, -fNextSineTube*fWheelRadius) + vDir1*fNextCosineTube*fWheelRadius,
				vMid1 + glm::vec3(0.0f, 0.0f, -fSineTube*fWheelRadius) + vDir1*fCosineTube*fWheelRadius,
				vMid2 + glm::vec3(0.0f, 0.0f, -fSineTube*fWheelRadius) + vDir2*fCosineTube*fWheelRadius,
				vMid2 + glm::vec3(0.0f, 0.0f, -fNextSineTube*fWheelRadius) + vDir2*fNextCosineTube*fWheelRadius*/
				glm::vec3(transform * glm::vec4(vMid1 + glm::vec3(0.0f, 0.0f, -fNextSineTube*fWheelRadius) + vDir1*fNextCosineTube*fWheelRadius, 1.0f)),
				glm::vec3(transform * glm::vec4(vMid1 + glm::vec3(0.0f, 0.0f, -fSineTube*fWheelRadius) + vDir1*fCosineTube*fWheelRadius, 1.0f)),
				glm::vec3(transform * glm::vec4(vMid2 + glm::vec3(0.0f, 0.0f, -fSineTube*fWheelRadius) + vDir2*fCosineTube*fWheelRadius, 1.0f)),
				glm::vec3(transform * glm::vec4(vMid2 + glm::vec3(0.0f, 0.0f, -fNextSineTube*fWheelRadius) + vDir2*fNextCosineTube*fWheelRadius, 1.0f))
			};

			glm::vec3 vNormals[] = 
			{
				glm::vec3(0.0f, 0.0f, -fNextSineTube) + vDir1*fNextCosineTube,
				glm::vec3(0.0f, 0.0f, -fSineTube) + vDir1*fCosineTube,
				glm::vec3(0.0f, 0.0f, -fSineTube) + vDir2*fCosineTube,
				glm::vec3(0.0f, 0.0f, -fNextSineTube) + vDir2*fNextCosineTube
			};
			float fTexScale = 0.5f;
			glm::vec2 fTexTransform(0.0f,0.5f);
			glm::vec2 vTexCoords[] = 
			{
				glm::vec2(fCurAngleAround/360.0f, fNextAngleTube/360.0f) * fTexScale + fTexTransform,
				glm::vec2(fCurAngleAround/360.0f, fCurAngleTube/360.0f) * fTexScale + fTexTransform,
				glm::vec2(fNextAngleAround/360.0f, fCurAngleTube/360.0f) * fTexScale + fTexTransform,
				glm::vec2(fNextAngleAround/360.0f, fNextAngleTube/360.0f) * fTexScale + fTexTransform
			};
			int iIndices[] = {2, 1, 0, 0, 3, 2};
			FOR(i, 6)
			{
				int index = iIndices[i];
				vBoatVertices.push_back(vQuadPoints[index]);
				vBoatTexCoords.push_back(vTexCoords[index]);
				vBoatNormals.push_back(vNormals[index]);
			}
			addIndicesForTriangle(2,false);
			fCurAngleTube += fAddAngleTube;
			iStepsTube++;
		}
		fCurAngleAround += fAddAngleAround;
		iStepsAround++;
	}
}


void Boat::addLadders(){
	float fStepLengthToHeightRatio = 1.3f;
	float fWidth = 0.14f;
	float fStartZ = -0.53125f;
	float fStartY = -0.67f;
	float fLeftX = -0.26f;
	float fRightX = fLeftX * -1.0f;
	float fEndY = -0.775f;
	unsigned int divCount = 10;	
	
	float fStepHeight = (fStartY - fEndY);
	float fYDelta = fStepHeight / (float) divCount;
	float fStepLength = fYDelta * fStepLengthToHeightRatio;

	float fCurrentXLeft = fLeftX + fWidth / 2.0f;
	float fCurrentXRight = fRightX - fWidth / 2.0f;
	float fCurrentZ = fStartZ + fStepLength / 2.0f;

	float fTextureBottom = 0.275f;
	float fTextureTop = 0.95f;
	float fTextureDeltaY = (fTextureTop-fTextureBottom) / (float) divCount;
	float fTextureBack = 0.1f;
	float fTextureFront = 0.8f;
	float fTextureDeltaZ = (fTextureFront-fTextureBack) / (float) divCount;
	
	glm::vec2* texCoords = new glm::vec2[24];
	texCoords[0] = glm::vec2(0.0f,fTextureBottom); texCoords[1] = glm::vec2(0.0f,fTextureTop); texCoords[2] = glm::vec2(0.5f,fTextureBottom); texCoords[3] = glm::vec2(0.5f,fTextureTop); //front
	texCoords[4] = glm::vec2(0.0f,0.0f); texCoords[5] = glm::vec2(0.0f,0.0f); texCoords[6] = glm::vec2(0.0f,0.0f); texCoords[7] = glm::vec2(0.0f,0.0f); //back
	texCoords[8] = glm::vec2(0.0f,0.0f); texCoords[9] = glm::vec2(0.0f,0.0f); texCoords[10] = glm::vec2(0.0f,0.0f); texCoords[11] = glm::vec2(0.0f,0.0f); //right
	texCoords[12] = glm::vec2(0.0f,0.0f); texCoords[13] = glm::vec2(0.0f,0.0f); texCoords[14] = glm::vec2(0.0f,0.0f); texCoords[15] = glm::vec2(0.0f,0.0f); //left
	texCoords[16] = glm::vec2(0.0f,0.07f); texCoords[17] = glm::vec2(0.0f,0.07f + fTextureDeltaY * fStepLengthToHeightRatio); texCoords[18] = glm::vec2(0.5f,0.07f); texCoords[19] = glm::vec2(0.5f,0.07f + fTextureDeltaY * fStepLengthToHeightRatio); //top
	texCoords[20] = glm::vec2(0.0f,0.0f); texCoords[21] = glm::vec2(0.0f,0.0f); texCoords[22] = glm::vec2(0.0f,0.0f); texCoords[23] = glm::vec2(0.0f,0.0f); //bottom


	FOR(i,divCount){
		float fCurrentY = fEndY + fStepHeight / 2.0f;
		//for front:
		texCoords[0] = glm::vec2(0.0f,fTextureBottom); texCoords[2] = glm::vec2(0.5f,fTextureBottom);
		//for left and right:
		texCoords[12] = texCoords[10] = glm::vec2(fTextureBottom, fTextureBack);
		texCoords[13] = texCoords[11] = glm::vec2(fTextureTop, fTextureBack);
		texCoords[14] = texCoords[8] = glm::vec2(fTextureBottom, fTextureBack + fTextureDeltaZ);
		texCoords[15] = texCoords[9] = glm::vec2(fTextureTop, fTextureBack + fTextureDeltaZ);
		addBalk(fCurrentXLeft, fCurrentY, fCurrentZ, 0.0f, 0.0f, 0.0f, fWidth, fStepLength, fStepHeight, texCoords, 24, 0.5f, glm::vec2(0.0f,0.5f));
		addBalk(fCurrentXRight, fCurrentY, fCurrentZ, 0.0f, 0.0f, 0.0f, fWidth, fStepLength, fStepHeight, texCoords, 24, 0.5f, glm::vec2(0.0f,0.5f));
		fCurrentZ += fStepLength;
		fStepHeight -= fYDelta;
		fTextureBottom += fTextureDeltaY;
		fTextureBack += fTextureDeltaZ;
	}
}

void Boat::addIndicesForQuad(unsigned int quadCount, bool two_sided){
	FOR(i,quadCount){
		iBoatIndices.push_back(currentIndex);
		iBoatIndices.push_back(currentIndex + 3);
		iBoatIndices.push_back(currentIndex + 1);
		iBoatIndices.push_back(currentIndex);
		iBoatIndices.push_back(currentIndex + 2);
		iBoatIndices.push_back(currentIndex + 3);
        if (two_sided){
            iBoatIndices.push_back(currentIndex);
            iBoatIndices.push_back(currentIndex + 1);
            iBoatIndices.push_back(currentIndex + 3);
            iBoatIndices.push_back(currentIndex);
            iBoatIndices.push_back(currentIndex + 3);
            iBoatIndices.push_back(currentIndex + 2);
        }
		currentIndex += 4;
	}
}

void Boat::addIndicesForTriangle(unsigned int triangleCount, bool two_sided){
	FOR(i,triangleCount){
		iBoatIndices.push_back(currentIndex);
		iBoatIndices.push_back(currentIndex + 2);
		iBoatIndices.push_back(currentIndex + 1);
        if (two_sided){
            iBoatIndices.push_back(currentIndex);
            iBoatIndices.push_back(currentIndex + 1);
            iBoatIndices.push_back(currentIndex + 2);
        }
		currentIndex += 3;
	}
}

unsigned int *Boat::getBoatIndices(){
	return &iBoatIndices[0];
}

unsigned int Boat::getBoatIndicesSize(){
	return iBoatIndices.size();
}


void Boat::addBoat(CVertexBufferObject &vboDest){
	FOR(i,iBoatIndices.size()){
		vboDest.AddData(&vBoatVertices[iBoatIndices[i]], sizeof(glm::vec3));
		vboDest.AddData(&vBoatTexCoords[iBoatIndices[i]], sizeof(glm::vec2));
		vboDest.AddData(&vBoatNormals[iBoatIndices[i]], sizeof(glm::vec3));
	}
	/*FOR(i,vBoatVertices.size()){
		vboDest.AddData(&vBoatVertices[i], sizeof(glm::vec3));
		vboDest.AddData(&vBoatTexCoords[i], sizeof(glm::vec2));
		vboDest.AddData(&vBoatNormals[i], sizeof(glm::vec3));
	}	*/
}

void Boat::addSail(float fTranslateX, float fTranslateY, float fTranslateZ,
				   float fYaw, float fPitch, float fRoll, //rotate
                      float fAngle, float fScale, float fFullWidth, int iSubDiv){
	float fAddAngle = fAngle*2.0f/(float)iSubDiv;
    float fHalfWidth = fFullWidth / 2.0f;
	int iStep = 0;
	const float PI = float(atan(1.0)*4.0);
	float fStartAngle = 90.0f - fAngle;
	float fRadius = 1.0f / cos(fStartAngle/180.0f*PI);
	float fCenterCircleZ = 0.0f - sin(fStartAngle/180.0f*PI) * fRadius;
	float fDivTex = 1.0f/float(iSubDiv);
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, glm::vec3(fTranslateX,fTranslateY,fTranslateZ));
	transform = glm::rotate(transform, fYaw/180.0f*PI, glm::vec3(0.0f,0.0f,1.0f));
	transform = glm::rotate(transform, fPitch/180.0f*PI, glm::vec3(0.0f,1.0f,0.0f));
	transform = glm::rotate(transform, fRoll/180.0f*PI, glm::vec3(1.0f,0.0f,0.0f));
	transform = glm::scale(transform, glm::vec3(1.0f,fScale,fScale));
	while (iStep < iSubDiv){
		float fCurrAngle = fStartAngle + iStep * fAddAngle;
		float fNextAngle = fCurrAngle + fAddAngle;
		float fCurrSine =  sin(fCurrAngle/180.0f*PI);
		float fNextSine =  sin(fNextAngle/180.0f*PI);
		float fCurrCosine = cos(fCurrAngle/180.0f*PI);
		float fNextCosine = cos(fNextAngle/180.0f*PI);

		float fCurrZ = fCenterCircleZ + fCurrSine * fRadius;
		float fNextZ = fCenterCircleZ + fNextSine * fRadius;
		float fCurrY = fCurrCosine * fRadius;
		float fNextY = fNextCosine * fRadius;

		/*float fCurrZ = fCenterCircleZ + sin(fCurrAngle/180.0f*PI) * fRadius;
		float fNextZ = fCenterCircleZ + sin(fNextAngle/180.0f*PI) * fRadius;
		float fCurrY = cos(fCurrAngle/180.0f*PI) * fRadius;
		float fNextY = cos(fNextAngle/180.0f*PI) * fRadius;*/
		float fTexScale = 0.5f;
		glm::vec2 fTexTransform(0.0f, 0.0f);
		glm::vec3 vQuadPoints[] = 
		{
			glm::vec3(transform * glm::vec4(fHalfWidth,fCurrY,fCurrZ,1.0f)),
			glm::vec3(transform * glm::vec4(fHalfWidth,fNextY,fNextZ,1.0f)),
			glm::vec3(transform * glm::vec4(-1.0f * fHalfWidth,fCurrY,fCurrZ,1.0f)),
			glm::vec3(transform * glm::vec4(-1.0f * fHalfWidth,fNextY,fNextZ,1.0f))
		};
		glm::vec2 vTexPoints[] = 
		{
			glm::vec2(0,fDivTex * iStep) * fTexScale + fTexTransform,
			glm::vec2(0,fDivTex * iStep + fDivTex) * fTexScale + fTexTransform,
			glm::vec2(1,fDivTex * iStep) * fTexScale + fTexTransform,
			glm::vec2(1,fDivTex * iStep + fDivTex) * fTexScale + fTexTransform,
		};
		glm::vec3 vNormals[] = 
		{
			glm::vec3(0.0f, fCurrCosine, fCurrSine),
			glm::vec3(0.0f, fNextCosine, fNextSine),
			glm::vec3(0.0f, fCurrCosine, fCurrSine),
			glm::vec3(0.0f, fNextCosine, fNextSine),
		};
		FOR(i,4){
			vBoatVertices.push_back(vQuadPoints[i]);
			vBoatTexCoords.push_back(vTexPoints[i]);
			vBoatNormals.push_back(vNormals[i]);
		}
		++iStep;
        addIndicesForQuad(1, true);
	}
}


void Boat::addBalk(float fTranslateX, float fTranslateY, float fTranslateZ,
			 float fYaw, float fPitch, float fRoll, 
			 float fWidth, float fLength, float fHeight,
			 glm::vec2* texCoords, unsigned int texCoordsCount, float fTexScale, glm::vec2 fTexTransform){
	const float PI = float(atan(1.0)*4.0);
	glm::mat4 transformMatrix = glm::mat4(1.0f);
    transformMatrix = glm::translate(transformMatrix, glm::vec3(fTranslateX, fTranslateY, fTranslateZ));
    transformMatrix = glm::rotate(transformMatrix, fYaw / 180.0f * PI, glm::vec3(0.0f,0.0f,1.0f));
    transformMatrix = glm::rotate(transformMatrix, fPitch / 180.0f * PI, glm::vec3(0.0f,1.0f,0.0f));
    transformMatrix = glm::rotate(transformMatrix, fRoll / 180.0f * PI, glm::vec3(1.0f,0.0f,0.0f));
	glm::vec3 vQuadVertices[] = {
		glm::vec3(transformMatrix * glm::vec4(fWidth / -2.0f, fHeight / -2.0f, fLength / 2.0f, 1.0f)), //face	
		glm::vec3(transformMatrix * glm::vec4(fWidth / -2.0f, fHeight / 2.0f, fLength / 2.0f, 1.0f)), //face
		glm::vec3(transformMatrix * glm::vec4(fWidth / 2.0f, fHeight / -2.0f, fLength / 2.0f, 1.0f)), //face	
		glm::vec3(transformMatrix * glm::vec4(fWidth / 2.0f, fHeight / 2.0f, fLength / 2.0f, 1.0f)), //face		
		glm::vec3(transformMatrix * glm::vec4(fWidth / 2.0f, fHeight / -2.0f, fLength / -2.0f, 1.0f)), //back
		glm::vec3(transformMatrix * glm::vec4(fWidth / 2.0f, fHeight / 2.0f, fLength / -2.0f, 1.0f)), //back
		glm::vec3(transformMatrix * glm::vec4(fWidth / -2.0f, fHeight / -2.0f, fLength / -2.0f, 1.0f)), //back
		glm::vec3(transformMatrix * glm::vec4(fWidth / -2.0f, fHeight / 2.0f, fLength / -2.0f, 1.0f)), //back
	};
	glm::vec2 vDefaultQuadTexCoords[] = {
		glm::vec2(0.0f, 0.0f) * fTexScale + fTexTransform, 
		glm::vec2(0.0f, 1.0f) * fTexScale + fTexTransform, 
		glm::vec2(1.0f, 0.0f) * fTexScale + fTexTransform, 
		glm::vec2(1.0f, 1.0f) * fTexScale + fTexTransform
	};
	glm::vec3 vQuadNormals[] = {
		glm::vec3(0.0f,0.0f,1.0f), //front
		glm::vec3(0.0f,0.0f,-1.0f), //back
		glm::vec3(1.0f,1.0f,0.0f), //right
		glm::vec3(-1.0f,0.0f,0.0f), //left
		glm::vec3(0.0f,1.0f,0.0f), //top
		glm::vec3(0.0f,-1.0f,0.0f), //bottom
	};
	unsigned int loadOrder[] = {
		0, 1, 2, 3, 4, 5, 6, 7, //front, back
		2, 3, 4, 5, 6, 7, 0, 1, //right, left
		1, 7, 3, 5, 6, 0, 4, 2, //up, bottom
	};
	int verticesCount = sizeof(loadOrder) / sizeof(unsigned int);
	FOR(i, verticesCount){
		vBoatVertices.push_back(vQuadVertices[loadOrder[i]]);
		vBoatTexCoords.push_back(i < texCoordsCount ? texCoords[i] * fTexScale + fTexTransform : vDefaultQuadTexCoords[i % 4]);
		vBoatNormals.push_back(vQuadNormals[i / 4]);
	}
	addIndicesForQuad(6, false);
}

void Boat::addMast(float fTranslateX, float fTranslateY, float fTranslateZ, //translate
                      float fYaw, float fPitch, float fRoll, //rotate
                      float fRadius, float fullHeight, int iSubDiv,
					  float fTexScale, glm::vec2 fTubeTexOffset, glm::vec2 fCoverTexOffset
					  ){ //scale
	const float PI = float(atan(1.0)*4.0);
	float fAddAngle = 360.0f / (float)iSubDiv;
	int iStep = 0;
	float fAddTexCoord = 1.0f / (float)iSubDiv;
    float halfHight = fullHeight / 2.0f;
    glm::mat4 transformMatrix = glm::mat4(1.0f);
    transformMatrix = glm::translate(transformMatrix, glm::vec3(fTranslateX, fTranslateY, fTranslateZ));
    transformMatrix = glm::rotate(transformMatrix, fYaw / 180.0f * PI, glm::vec3(0.0f,0.0f,1.0f));
    transformMatrix = glm::rotate(transformMatrix, fPitch / 180.0f * PI, glm::vec3(0.0f,1.0f,0.0f));
    transformMatrix = glm::rotate(transformMatrix, fRoll / 180.0f * PI, glm::vec3(1.0f,0.0f,0.0f));
	glm::mat4 normalMatrix = glm::transpose(glm::inverse(transformMatrix));
	while (iStep < iSubDiv) {
		float fCurrAngle = iStep * fAddAngle;
		float fNextAngle = fCurrAngle + fAddAngle;
        float fCurrCos = cos(fCurrAngle / 180.0f*PI);
        float fCurrSin = sin(fCurrAngle / 180.0f*PI);
        float fNextCos = cos(fNextAngle / 180.0f*PI);
        float fNextSin = sin(fNextAngle / 180.0f*PI);
		float fCurrZ = fCurrCos * fRadius;
		float fCurrX = -1.0f * fCurrSin * fRadius;
		float fNextZ = fNextCos * fRadius;
		float fNextX = -1.0f * fNextSin * fRadius;
		float fCurrTex = iStep * fAddTexCoord;
		float fNextTex = fCurrTex + fAddTexCoord;
        //quads for tube
		glm::vec3 vQuadPointsTube[] = {
            glm::vec3(transformMatrix * glm::vec4(fCurrX,halfHight,fCurrZ,1.0f)),
			glm::vec3(transformMatrix * glm::vec4(fCurrX,-1.0f * halfHight,fCurrZ,1.0f)),
			glm::vec3(transformMatrix * glm::vec4(fNextX,halfHight,fNextZ,1.0f)),
			glm::vec3(transformMatrix * glm::vec4(fNextX,-1.0f * halfHight,fNextZ,1.0f))
		};
        glm::vec2 vTexPointsTube[] = {
			glm::vec2(0.0f, fCurrTex) * fTexScale + fTubeTexOffset,
			glm::vec2(1.0f, fCurrTex) * fTexScale + fTubeTexOffset,
			glm::vec2(0.0f, fNextTex) * fTexScale + fTubeTexOffset,
			glm::vec2(1.0f, fNextTex) * fTexScale + fTubeTexOffset,
		};		
		glm::vec3 vNormalsTube[] = {
			glm::normalize(glm::vec3(normalMatrix * glm::vec4(-fCurrSin, 0.0f, fCurrCos, 1.0f))),
			glm::normalize(glm::vec3(normalMatrix * glm::vec4(-fCurrSin, 0.0f, fCurrCos, 1.0f))),
			glm::normalize(glm::vec3(normalMatrix * glm::vec4(-fNextSin, 0.0f, fNextCos, 1.0f))),
			glm::normalize(glm::vec3(normalMatrix * glm::vec4(-fNextSin, 0.0f, fNextCos, 1.0f))),
		};
        //triangles for tube sides
        glm::vec3 vTrianglePointsTube[] = {
            glm::vec3(transformMatrix * glm::vec4(0.0f, halfHight, 0.0f,1.0f)),
            glm::vec3(transformMatrix * glm::vec4(fCurrX,halfHight,fCurrZ,1.0f)),
            glm::vec3(transformMatrix * glm::vec4(fNextX,halfHight,fNextZ,1.0f)),
            glm::vec3(transformMatrix * glm::vec4(0.0f, -1.0f * halfHight, 0.0f,1.0f)),
            glm::vec3(transformMatrix * glm::vec4(fNextX,-1.0f * halfHight,fNextZ,1.0f)),
            glm::vec3(transformMatrix * glm::vec4(fCurrX,-1.0f * halfHight,fCurrZ,1.0f))
        };
        glm::vec2 vTriangleTexPoints[] = {
			glm::vec2(0.5f,0.5f) * fTexScale + fCoverTexOffset,
            glm::vec2(0.5f+fCurrCos/2.0f, 0.5f+fCurrSin/2.0f) * fTexScale + fCoverTexOffset,
            glm::vec2(0.5f+fNextCos/2.0f, 0.5f+fNextSin/2.0f) * fTexScale + fCoverTexOffset,
			glm::vec2(0.5f,0.5f) * fTexScale + fCoverTexOffset,
            glm::vec2(0.5f+fNextCos/2.0f, 0.5f+fNextSin/2.0f) * fTexScale + fCoverTexOffset,
			glm::vec2(0.5f+fCurrCos/2.0f, 0.5f+fCurrSin/2.0f) * fTexScale + fCoverTexOffset,
        };
		glm::vec3 vTriangleNormals[] = {
			glm::normalize(glm::vec3(normalMatrix * glm::vec4(0.0f,1.0f,0.0f,1.0f))),
			glm::normalize(glm::vec3(normalMatrix * glm::vec4(0.0f,-1.0f,0.0f,1.0f)))
		};
        //push new surfaces
        FOR(i, 4) {
			vBoatVertices.push_back(vQuadPointsTube[i]);
			vBoatTexCoords.push_back(vTexPointsTube[i]);
			vBoatNormals.push_back(vNormalsTube[i]);
		}
		FOR(i, 6) {
			vBoatVertices.push_back(vTrianglePointsTube[i]);
			vBoatTexCoords.push_back(vTriangleTexPoints[i]);
			vBoatNormals.push_back(vTriangleNormals[i/3]);
		}
		addIndicesForQuad(1, false);
		addIndicesForTriangle(2, false);
		++iStep;
	}
}

void Boat::addBoatMastWithSails( 
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
						  ){
	float fMastYPos = fMastBottomY + fMastHeight / 2.0f;
	float fMastBeamRadius = fMastRadius / fMastToBeamRadius;
	float fMastBeamZPos = fMastZPos + fMastRadius + fMastBeamRadius;
	addMast(/*transl*/ 0.0f, fMastYPos, fMastZPos, /*rot*/ 0.0f, 0.0f, 0.0f, /*radius*/ fMastRadius, /*height*/ fMastHeight, /*sub div*/ 20, 0.5f, glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	//first sail (upper) with two beams
	float fBeam1YPos = fMastYPos + (fMastHeight / 2.0f) - fMastBeamRadius - fBeam1YPosTop;
	addMast(/*transl*/ 0.0f, fBeam1YPos, fMastBeamZPos, /*rot*/ 90.0f, 0.0f, 0.0f, /*radius*/ fMastBeamRadius, /*height*/ sail1Width, /*sub div*/ 10, 0.5f, glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	float fBeam2YPos = fMastYPos + (fMastHeight / 2.0f) - fMastBeamRadius - fBeam2YPosTop;
	addMast(/*transl*/ 0.0f, fBeam2YPos, fMastBeamZPos, /*rot*/ 90.0f, 0.0f, 0.0f, /*radius*/ fMastBeamRadius, /*height*/ sail1Width, /*sub div*/ 10, 0.5f, glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	float fSailHeight = fBeam1YPos - fBeam2YPos;
	float fSailScale = fSailHeight / 2.0f;
	float fSailYPos = fBeam1YPos - fSailScale;
	addSail(/*transl*/ 0.0f, fSailYPos, fMastBeamZPos + fMastBeamRadius, /*rot*/ 0.0f, 0.0f, 0.0f, /*angle*/ 30.0f, /*scale*/ fSailScale, /*width*/ sail1Width, /*sub div*/ 20);
	//second sail (lower) with two beams
	fBeam1YPos = fMastYPos + (fMastHeight / 2.0f) - fMastBeamRadius - fBeam3YPosTop;
	addMast(/*transl*/ 0.0f, fBeam1YPos, fMastBeamZPos, /*rot*/ 90.0f, 0.0f, 0.0f, /*radius*/ fMastBeamRadius, /*height*/ sail2Width, /*sub div*/ 10, 0.5f, glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	fBeam2YPos = fMastYPos + (fMastHeight / 2.0f) - fMastBeamRadius - fBeam4YPosTop;
	addMast(/*transl*/ 0.0f, fBeam2YPos, fMastBeamZPos, /*rot*/ 90.0f, 0.0f, 0.0f, /*radius*/ fMastBeamRadius, /*height*/ sail2Width, /*sub div*/ 10, 0.5f, glm::vec2(0.0f,0.5f), glm::vec2(0.5f,0.5f));
	fSailHeight = fBeam1YPos - fBeam2YPos;
	fSailScale = fSailHeight / 2.0f;
	fSailYPos = fBeam1YPos - fSailScale;
	addSail(/*transl*/ 0.0f, fSailYPos, fMastBeamZPos + fMastBeamRadius, /*rot*/ 0.0f, 0.0f, 0.0f, /*angle*/ 45.0f, /*scale*/ fSailScale, /*width*/ sail2Width, /*sub div*/ 20);
}


void Boat::addBoatSails(){
	//мачта 1
	addBoatMastWithSails(-0.775f, 0.02f, 1.1f, 0.2f, 4.0f, 0.05f, 0.35f, 0.4f, 0.8f, 0.58f, 0.65f);
	//мачта 2
	addBoatMastWithSails(-0.775f, 0.02f, 1.2f, -0.27f, 4.0f, 0.05f, 0.4f, 0.45f, 0.9f, 0.6f, 0.7f);
}