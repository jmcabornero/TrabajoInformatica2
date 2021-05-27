#include "EscenarioTiles.h"
#include <windows.h>

EscenarioTiles::EscenarioTiles(int x, int y)
{
	x = coordenada_x; y= coordenada_y;
}
/*void EscenarioTiles::Dibuja()
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
}*/


void EscenarioTiles::mapa()
	{
	string line;
	ifstream myfile; //myfile es el fichero (puntero)
	myfile.open("imagenes/estrellas.csv");
	if (myfile.is_open())
	{
		//cout << "putamadre";
		int i = 0, j, num;
		while (getline(myfile, line)) // line es una str con la siguiente linea
		{
			std::string delimiter = ",";
			size_t pos = 0;
			std::string token;
			j = 0;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				token = line.substr(0, pos);
				num = stoi(token);
				glEnable(GL_TEXTURE_2D);
				if (num == 478)
				{
					//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HierbaAux.png").id);
					//if (num == 1763);
					listaobstaculos.Agregar(new Obstaculos(j,i));
					/*glDisable(GL_LIGHTING);
					glBegin(GL_POLYGON);
					glColor3f(1, 1, 1);
					glTexCoord2d(0, 1); glVertex2f(j, i); //abajo izq
					glTexCoord2d(1, 1); glVertex2f(j + 1, i);	//abajo drcha
					glTexCoord2d(1, 0); glVertex2f(j + 1, i + 1);	//arriba drcha
					glTexCoord2d(0, 0); glVertex2f(j, i + 1);	//arriba izq
					glEnd();
					glEnable(GL_LIGHTING);
					glDisable(GL_TEXTURE_2D);*/
				}
					

				line.erase(0, pos + delimiter.length());
				j++;
			}
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";


	
	/*ifstream myfile; //myfile es el fichero (puntero)
	myfile.open("imagenes/MapaPrueba.csv");
	while (myfile.good())
	{
		string line;
		int i = 0, j, num;
		 // line es una str con la siguiente linea
			
			getline(myfile, line, ',');
			cout << line << endl;

			
			
			/*while ((pos = line.find(delimiter)) != std::string::npos) {
				j = 0;
				token = line.substr(0, pos);
				num = stoi(token);
				glEnable(GL_TEXTURE_2D);
				if (num == 365)
					glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/RocaClara.png").id);
				if (num == 297)
					glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
				if (num == 298)
					glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/RocaOscura.png").id);
				if (num == 319)
					glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/lava.png").id);
				glDisable(GL_LIGHTING);
				glBegin(GL_POLYGON);
				glColor3f(1, 1, 1);
				glTexCoord2d(0, 1); glVertex2f(j, i); //abajo izq
				glTexCoord2d(1, 1); glVertex2f(j + 1, i);	//abajo drcha
				glTexCoord2d(1, 0); glVertex2f(j + 1, i + 1);	//arriba drcha
				glTexCoord2d(0, 0); glVertex2f(j, i + 1);	//arriba izq
				glEnd();
				glEnable(GL_LIGHTING);
				glDisable(GL_TEXTURE_2D);

				line.erase(0, pos + delimiter.length());
				j++;
			}
		}
		myfile.close();*/
	}

	
