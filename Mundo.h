#pragma once
#include "Protagonista.h"
#include "Caja.h"
#include "ListaObstaculos.h"
#include "ListaDisparos.h"
#include "Enemigo.h"
#include "ListaEnemigos.h"
#include "ListaMonedas.h"
#include "HUD.h"
#include "ListaCofres.h"
#include "ETSIDI.h"

class Mundo
{
private:
	float z_ojo;
	bool flagfinal;
	Vector2D posicion_ojo, velocidad_ojo;
	Protagonista protagonista;
	ListaObstaculos listaobstaculos, listapinchos;
	Caja caja;
	ListaDisparos disparos;
	ListaEnemigos enemigos;
	ListaMonedas monedas;
	ListaCofres listacofres;
	HUD mensaje1, mensaje2, mensaje3, mensaje4, mensaje5, mensajelibro, mensajestienda;
	HUD hud, hud_stats, hud_cons;
	HUD hud_enem;

	public:
		Mundo(float x=0, bool y=false);
		void dibObstaculos(int n); //si n=1, se refiere a obstaculos. Si n=2, se refiere a pinchos
		void dibEnemigos();
		void inicializa();
		//void rotarOjo();
		void mueve();
		void dibuja();
		void tecla(unsigned char key);
		void teclaEspecial(unsigned char key);
		void teclaEspecialUp(unsigned char key);
		void setPos(float x, float y);
		void CambioCamara();
		void DibujaMensajes();
		virtual ~Mundo();
		float GetVidas();
		int GetVidasBoss();
};
