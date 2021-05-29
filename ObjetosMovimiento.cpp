#include "ObjetosMovimiento.h"

void ObjetosMovimiento::mueve(float t) {
	posicion = posicion + velocidad * t;
}