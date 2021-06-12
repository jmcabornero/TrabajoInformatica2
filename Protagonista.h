#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "stats.h"

using ETSIDI::SpriteSequence;

class Protagonista:public ObjetosMovimiento, public stats
{
private:
	char direccion;
	float velabs;
	int Tdis;
public:
	Protagonista();
	SpriteSequence spriteR{ "imagenes/Player/WarriorRightWalk.png", 8 };
	SpriteSequence spriteL{ "imagenes/Player/WarriorLeftWalk.png", 8 };
	SpriteSequence spriteUp{ "imagenes/Player/WarriorUpWalk.png", 8 };
	SpriteSequence spriteDown{ "imagenes/Player/WarriorDownWalk.png", 8 };
	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void FuncionTeletransporte();
	bool MensajeBuda(float inicio_x, float final_x, float inicio_y);
	void Teletransporte(float inicio_x, float inicio_y, float final_x, float final_y);
	float GetVelAbs();
	int getTdis() { return Tdis; }
	void setTdis(int t=1) { Tdis = t; }
	void SetVelAbs(float vel);
};