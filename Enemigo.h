#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "stats.h"
#include "Protagonista.h"
#include <math.h>

using ETSIDI::SpriteSequence;

class Enemigo :public ObjetosMovimiento, public stats
{
private:
	char direccion;
	int tipo;
	int bioma;
	bool flagDist;
public:
	Enemigo(float x, float y, int b=1, int t=1);
	virtual ~Enemigo();
	SpriteSequence spriteRD{ "imagenes/duende/GoblinSlingerRightRun.png", 6 };
	SpriteSequence spriteLD{ "imagenes/duende/GoblinSlingerLeftRun.png", 6 };
	SpriteSequence spriteUpD{ "imagenes/duende/GoblinSlingerUpRun.png", 6 };
	SpriteSequence spriteDownD{ "imagenes/duende/GoblinSlingerDownRun.png", 6 };

	SpriteSequence spriteRK{ "imagenes/kamikaze/PossesedRightWalk.png", 6 };
	SpriteSequence spriteLK{ "imagenes/kamikaze/PossesedLeftWalk.png", 6 };
	SpriteSequence spriteUpK{ "imagenes/kamikaze/PossesedRightWalk.png", 6 };
	SpriteSequence spriteDownK{ "imagenes/kamikaze/PossesedDownWalk.png", 6 };

	SpriteSequence spriteRE{ "imagenes/esqueleto/SkeletonWithSwordRightRun.png", 6 };
	SpriteSequence spriteLE{ "imagenes/esqueleto/SkeletonWithSwordLefttRun.png", 6 };
	SpriteSequence spriteUpE{ "imagenes/esqueleto/SkeletonWithSwordUpWalk.png", 6 };
	SpriteSequence spriteDownE{ "imagenes/esqueleto/SkeletonWithSwordDownWalk.png", 6 };

	SpriteSequence spriteRD1{ "imagenes/duende/GoblinSlingerRightRun1.png", 6 };
	SpriteSequence spriteLD1{ "imagenes/duende/GoblinSlingerLeftRun1.png", 6 };
	SpriteSequence spriteUpD1{ "imagenes/duende/GoblinSlingerUpRun1.png", 6 };
	SpriteSequence spriteDownD1{ "imagenes/duende/GoblinSlingerDownRun1.png", 6 };

	SpriteSequence spriteRK1{ "imagenes/kamikaze/PossesedRightWalk1.png", 6 };
	SpriteSequence spriteLK1{ "imagenes/kamikaze/PossesedLeftWalk1.png", 6 };
	SpriteSequence spriteUpK1{ "imagenes/kamikaze/PossesedRightWalk1.png", 6 };
	SpriteSequence spriteDownK1{ "imagenes/kamikaze/PossesedDownWalk1.png", 6 };

	SpriteSequence spriteRE1{ "imagenes/esqueleto/SkeletonWithSwordRightRun1.png", 6 };
	SpriteSequence spriteLE1{ "imagenes/esqueleto/SkeletonWithSwordLefttRun1.png", 6 };
	SpriteSequence spriteUpE1{ "imagenes/esqueleto/SkeletonWithSwordUpWalk1.png", 6 };
	SpriteSequence spriteDownE1{ "imagenes/esqueleto/SkeletonWithSwordDownWalk1.png", 6 };

	SpriteSequence spriteRD2{ "imagenes/duende/GoblinSlingerRightRun2.png", 6 };
	SpriteSequence spriteLD2{ "imagenes/duende/GoblinSlingerLeftRun2.png", 6 };
	SpriteSequence spriteUpD2{ "imagenes/duende/GoblinSlingerUpRun2.png", 6 };
	SpriteSequence spriteDownD2{ "imagenes/duende/GoblinSlingerDownRun2.png", 6 };

	SpriteSequence spriteRK2{ "imagenes/kamikaze/PossesedRightWalk2.png", 6 };
	SpriteSequence spriteLK2{ "imagenes/kamikaze/PossesedLeftWalk2.png", 6 };
	SpriteSequence spriteUpK2{ "imagenes/kamikaze/PossesedRightWalk2.png", 6 };
	SpriteSequence spriteDownK2{ "imagenes/kamikaze/PossesedDownWalk2.png", 6 };

	SpriteSequence spriteRE2{ "imagenes/esqueleto/SkeletonWithSwordRightRun2.png", 6 };
	SpriteSequence spriteLE2{ "imagenes/esqueleto/SkeletonWithSwordLefttRun2.png", 6 };
	SpriteSequence spriteUpE2{ "imagenes/esqueleto/SkeletonWithSwordUpWalk2.png", 6 };
	SpriteSequence spriteDownE2{ "imagenes/esqueleto/SkeletonWithSwordDownWalk2.png", 6 };

	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	int getTipo() { return tipo; }
	void setTipo(int t) { tipo = t; }
	void Dibuja();
	int getBioma() { return bioma; }
	void setBioma(int b) { bioma = b; }
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void Perseguir(Protagonista p);
	friend class Interaccion;
	bool getFlagDist() { return flagDist; }
	void setFlagDist(bool i) { flagDist = i; }
	void distProta(Protagonista p);
};

