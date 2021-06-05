#pragma once
#include "Mundo.h"
class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
	void Mueve();

protected:
	Mundo mundo;

	enum Estado { INICIO, JUEGO, GAMEOVER, EXITO, PAUSA, DIFICULTAD, HISTORIA };
	Estado estado;
};

//vicen perro