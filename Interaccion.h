#pragma once
#include "ETSIDI.h"
#include "Protagonista.h"
#include "Obstaculos.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Interaccion
{

public:
	static bool colision(Protagonista p, Obstaculos &o);
};

