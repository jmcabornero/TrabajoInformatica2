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
	void TeclaEspecial(int key);
	void TeclaEspecialUp(int key);

protected:
	enum Estado { INICIO, JUEGO, INSTRUCCIONES, HISTORIA, EXITO, PAUSA, GAMEOVER };
	Estado estado;
	Mundo mundo;
	int ContadorHisoria;
};

