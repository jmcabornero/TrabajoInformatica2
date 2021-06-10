#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "stats.h"
#include "HUD.h"

using ETSIDI::SpriteSequence;

class Protagonista:public ObjetosMovimiento, public stats
{
private:
	char direccion;
	float velabs;
	HUD hud, hud_stats;
public:
	Protagonista();
	SpriteSequence spriteR{ "imagenes/Player_derecha.png", 3 };
	SpriteSequence spriteL{ "imagenes/Player_izquierda.png", 3 };
	SpriteSequence spriteUp{ "imagenes/Player_arriba.png", 3 };
	SpriteSequence spriteDown{ "imagenes/Player_abajo.png", 3 };
	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void FuncionTeletransporte();
	bool MensajeBuda(float inicio_x, float final_x, float inicio_y);
	void Teletransporte(float inicio_x, float inicio_y, float final_x, float final_y);
	float GetVelAbs();
	void dibujaHUD();
	void dibujaStats(float camara_x, float camara_y);
	std::string stringStats();
	void SetVelAbs(float vel);
};