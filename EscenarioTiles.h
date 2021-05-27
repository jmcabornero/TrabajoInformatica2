#pragma once
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListaObstaculos.h"
#include "Obstaculos.h"
using namespace std;
//using ETSIDI::SpriteSequence;

class EscenarioTiles
{
private:
	ListaObstaculos listaobstaculos;
	Obstaculos obstaculo;
	int coordenada_x, coordenada_y;

public:
	EscenarioTiles(int x=0, int y=0);
	//void Dibuja();
	void mapa();
	//SpriteSequence loco{ "C:/Users/Usuario/source/repos/Juego/bin/imagenes/terrain.png", 21, 23 };
};


