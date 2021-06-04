#include "Protagonista.h"
#include "ETSIDI.h"


Protagonista::Protagonista()
{
	setDir('d');
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	posicion.x = 50;posicion.y = 109;velocidad = 0;velocidad = 0;
}

void Protagonista::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.01);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
//gestion de direccion y animacion
	if (velocidad.x > 0.01)spriteR.draw();
	if (velocidad.x < -0.01)spriteL.draw();
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))sprite.draw();
	glPopMatrix();
}

void Protagonista::Mueve(float t)
{
	ObjetosMovimiento::mueve(t);
	sprite.loop();
	spriteR.loop();
	spriteL.loop();
}

void Protagonista::setTam(float anchura, float altura)
{
	sprite.setCenter(1, 0);
	sprite.setSize(anchura, altura);
	spriteR.setCenter(1, 0);
	spriteR.setSize(anchura, altura);
	spriteL.setCenter(1, 0);
	spriteL.setSize(anchura, altura);
}

void Protagonista::FuncionTeletransporte()
{
	Teletransporte(44, 109, 110, 66); //pozo
	Teletransporte(115, 54, 103, 50); //cueva de tierra a montaña
	Teletransporte(103, 52, 115, 52); //cueva de montaña a tierra
	Teletransporte(110, 71, 109, 76); //entrar tienda
	for (int i = 108;i <= 111;i++)Teletransporte(i, 75, 110, 70); //salir tienda
	for (int i = 88;i <= 89;i++)Teletransporte(114, i, 112, 93); //subir tienda
	for (int i = 92;i <= 93;i++)Teletransporte(114, i, 117, 87);; //bajar tienda
}

void Protagonista::Teletransporte(float inicio_x, float inicio_y, float final_x, float final_y)
{
	if ((((inicio_x + 0.3) <= posicion.x) && (posicion.x <= (inicio_x + 1.8f))) && (((inicio_y - 0.9f) <= posicion.y) && (posicion.y <= (inicio_y + 0.9f))))
	{
		setPos(final_x+1, final_y);
	}
}