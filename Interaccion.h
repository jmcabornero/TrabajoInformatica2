#pragma once
#include "ETSIDI.h"
#include "Protagonista.h"
#include "Obstaculos.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Enemigo.h"
#include "Disparo.h"
#include "Caja.h"
#include "Moneda.h"
#include "Cofres.h"

using namespace std;

class Interaccion
{

public:
	static bool colision(Protagonista p, Obstaculos &o);
	static bool colision(Enemigo e, Obstaculos& o);
	static bool colisionpinchos(Protagonista p, Obstaculos& o);
	static bool colisionpinchos(Enemigo e, Obstaculos& o);
	static bool colision(Disparo &d, Enemigo &e);
	static bool colision(Disparo& d, Obstaculos &o);
	static bool colision(Protagonista p, Moneda& m);
	static bool colision(Protagonista p, Cofres& c);
	static bool colision(Disparo& d, Protagonista& e);
	static bool colision(Enemigo &e, Protagonista& p);
	static bool colision(Enemigo& e, Obstaculos& 0);
};

