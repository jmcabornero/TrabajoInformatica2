#include "HUD.h"
#include "freeglut.h"
#include <string.h>

#define capa1 0.03f
#define capa2 0.04f
#define capa3 0.05f

HUD::HUD() {
	setAlto(4);
	setAncho(18.5);
	setPos(3.5, 13.5);
}

HUD::~HUD() {

}

void displayText(float x, float y, float z, int r, int g, int b, const char* string) {
	int j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos3f(x, y, z);
	for (int i = 0; i < j; i++) {
		if (string[i] == '\n')
		{
			y=y-0.6;
			glRasterPos3f(x, y, z);
			continue;
		}
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void HUD::dibuja(char* mensaje) {
	float marco = 0.2;
	float h = getAlto();
	float a = getAncho();
	Vector2D p = getPos();
	glBegin(GL_POLYGON);
	glColor3f(255, 255, 255);
	glVertex3d(marco + p.x + a / 2, marco + p.y + h / 2, capa1);
	glVertex3d(marco + p.x + a / 2, -1*marco + p.y - h / 2, capa1);
	glVertex3d(-1*marco + p.x - a / 2, -1*marco + p.y - h / 2, capa1);
	glVertex3d(-1*marco + p.x - a / 2, marco + p.y + h / 2, capa1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(p.x + a / 2, p.y + h / 2, capa2);
	glVertex3d(p.x + a / 2, p.y - h / 2, capa2);
	glVertex3d(p.x - a / 2, p.y - h / 2, capa2);
	glVertex3d(p.x - a / 2, p.y + h / 2, capa2);
	glEnd();
	displayText(p.x - a/2 + marco, p.y + h/2 - 4*marco, capa3, 255, 255, 255, mensaje);
}





void HUD::mueve() {

}



