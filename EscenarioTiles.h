#pragma once
#include "ETSIDI.h"
class EscenarioTiles
{
private:
	int coordenada_x, coordenada_y;
	int MatrizMapa[5][5] = {
		{1,1,1,1,1},
		{1,1,1,1,2},
		{1,1,1,1,2},
		{1,1,1,1,2},
		{1,1,1,1,1} };

public:
	void Dibuja();
};


