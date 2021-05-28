#pragma once
#include "Protagonista.h"
#include "EscenarioTiles.h"
#include "Caja.h"
#include "ListaObstaculos.h"

class Mundo
{
private:
	float z_ojo;
	Vector2D posicion_ojo, velocidad_ojo;
	Protagonista protagonista;
	EscenarioTiles escenariotiles;
	ListaObstaculos listaobstaculos;
	Caja caja;

	public:
		Mundo(float x=0);
		void dibObstaculos();
		void inicializa();
		//void rotarOjo();
		void mueve();
		void dibuja();
		void tecla(unsigned char key);
		void teclaEspecial(unsigned char key);
		void teclaEspecialUp(unsigned char key);
		void setPos(float x, float y);
		void CambioCamara();
		virtual ~Mundo();
};

