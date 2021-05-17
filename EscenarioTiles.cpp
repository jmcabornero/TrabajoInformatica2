#include "EscenarioTiles.h"

void EscenarioTiles::Dibuja()
{
	int filas = (sizeof(MatrizMapa) / sizeof(MatrizMapa[0]));
	int columnas = (sizeof(MatrizMapa[0]) / sizeof(MatrizMapa[0][0]));
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			glEnable(GL_TEXTURE_2D);
			if (MatrizMapa[i][j]==1)
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/RocaClara.png").id);
			if (MatrizMapa[i][j] == 2)
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex2f(j, i); //abajo izq
			glTexCoord2d(1, 1); glVertex2f(j+1, i);	//abajo drcha
			glTexCoord2d(1, 0); glVertex2f(j+1, i+1);	//arriba drcha
			glTexCoord2d(0, 0); glVertex2f(j, i+1);	//arriba izq
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
	}
}