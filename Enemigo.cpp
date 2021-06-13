#include "Enemigo.h"
#include "ETSIDI.h"
#include <math.h>

Enemigo::~Enemigo(){}


Enemigo::Enemigo(float x, float y, int b, int t)
{
	setDir('d');

	spriteRD.setCenter(1.5, 0);
	spriteRD.setSize(2, 2);
	spriteLD.setCenter(1.5, 0);
	spriteLD.setSize(2, 2);
	spriteUpD.setCenter(1.5, 0);
	spriteUpD.setSize(2, 2);
	spriteDownD.setCenter(1.5, 0);
	spriteDownD.setSize(2, 2);

	spriteRK.setCenter(1.5, 0);
	spriteRK.setSize(2, 2);
	spriteLK.setCenter(1.5, 0);
	spriteLK.setSize(2, 2);
	spriteUpK.setCenter(1.5, 0);
	spriteUpK.setSize(2, 2);
	spriteDownK.setCenter(1.5, 0);
	spriteDownK.setSize(2, 2);

	spriteRE.setCenter(1.5, 0);
	spriteRE.setSize(2, 2);
	spriteLE.setCenter(1.5, 0);
	spriteLE.setSize(2, 2);
	spriteUpE.setCenter(1.5, 0);
	spriteUpE.setSize(2, 2);
	spriteDownE.setCenter(1.5, 0);
	spriteDownE.setSize(2, 2);

	spriteRD1.setCenter(1.5, 0);
	spriteRD1.setSize(2, 2);
	spriteLD1.setCenter(1.5, 0);
	spriteLD1.setSize(2, 2);
	spriteUpD1.setCenter(1.5, 0);
	spriteUpD1.setSize(2, 2);
	spriteDownD1.setCenter(1.5, 0);
	spriteDownD1.setSize(2, 2);

	spriteRK1.setCenter(1.5, 0);
	spriteRK1.setSize(2, 2);
	spriteLK1.setCenter(1.5, 0);
	spriteLK1.setSize(2, 2);
	spriteUpK1.setCenter(1.5, 0);
	spriteUpK1.setSize(2, 2);
	spriteDownK1.setCenter(1.5, 0);
	spriteDownK1.setSize(2, 2);

	spriteRE1.setCenter(1.5, 0);
	spriteRE1.setSize(2, 2);
	spriteLE1.setCenter(1.5, 0);
	spriteLE1.setSize(2, 2);
	spriteUpE1.setCenter(1.5, 0);
	spriteUpE1.setSize(2, 2);
	spriteDownE1.setCenter(1.5, 0);
	spriteDownE1.setSize(2, 2);

	spriteRD2.setCenter(1.5, 0);
	spriteRD2.setSize(2, 2);
	spriteLD2.setCenter(1.5, 0);
	spriteLD2.setSize(2, 2);
	spriteUpD2.setCenter(1.5, 0);
	spriteUpD2.setSize(2, 2);
	spriteDownD2.setCenter(1.5, 0);
	spriteDownD2.setSize(2, 2);

	spriteRK2.setCenter(1.5, 0);
	spriteRK2.setSize(2, 2);
	spriteLK2.setCenter(1.5, 0);
	spriteLK2.setSize(2, 2);
	spriteUpK2.setCenter(1.5, 0);
	spriteUpK2.setSize(2, 2);
	spriteDownK2.setCenter(1.5, 0);
	spriteDownK2.setSize(2, 2);

	spriteRE2.setCenter(1.5, 0);
	spriteRE2.setSize(2, 2);
	spriteLE2.setCenter(1.5, 0);
	spriteLE2.setSize(2, 2);
	spriteUpE2.setCenter(1.5, 0);
	spriteUpE2.setSize(2, 2);
	spriteDownE2.setCenter(1.5, 0);
	spriteDownE2.setSize(2, 2);

	posicion.x = x; posicion.y = y; velocidad = 0; velocidad = 0;
	setFlag(0);
	setTipo(t);
	setBioma(b);
	setFlagDist(0);

	vel = 1;
	switch (getBioma())
	{
	case 1:
		switch (getTipo())
		{
		case 1:
			break;
			setCoolDown(4.0);
		case 2:
			setDef(0.5);
			modVel(1);
			break;
		case 3:
			setDef(0.25);
			setAttack(0.75);
			setCoolDown(4.0);
			modVel(0.75);
			break;
		}
		break;
	case 2:
		switch (getTipo())
		{
		case 1:
			setDef(1.5);
			setAttack(1.5);
			setCoolDown(4.0);
			break;
		case 2:
			setDef(0.75);
			modVel(1.25);
			break;
		case 3:
			setDef(0.5);
			setAttack(1);
			modVel(1.25);
			setCoolDown(4.0);
			break;
		}
		break;
	case 3:
		switch (getTipo())
		{
		case 1:
			setDef(2.5);
			setAttack(2.5);
			setCoolDown(4.0);
			break;
		case 2:
			setDef(1);
			modVel(1.5);
			break;
		case 3:
			setDef(0.75);
			setAttack(1.5);
			setCoolDown(4.0);
			break;
		}
		break;
	}
}

void Enemigo::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	if (velocidad.x > 0.001) {
		setDir('d');
		switch (getBioma())
		{
		case 1:
			switch (getTipo())
			{
			case 1:
				spriteRD.draw();
				break;
			case 2:
				spriteRK.draw();
				break;
			case 3:
				spriteRE.draw();
				break;
			}
			break;
		case 2:
			switch (getTipo())
			{
			case 1:
				spriteRD1.draw();

				break;
			case 2:
				spriteRK1.draw();

				break;
			case 3:
				spriteRE1.draw();

				break;
			}
			break;
		case 3:
			switch (getTipo())
			{
			case 1:
				spriteRD2.draw();

				break;
			case 2:
				spriteRK2.draw();

				break;
			case 3:
				spriteRE2.draw();
				break;
			}
			break;
		}
		//cout << "sprite D" << endl;
	}
	if (velocidad.x < -0.001) {
		setDir('a');
		switch (getBioma())
		{
		case 1:
			switch (getTipo())
			{
			case 1:
				spriteLD.draw();
				break;

			case 2:
				spriteLK.draw();

				break;
			case 3:
				spriteLE.draw();
				break;
			}
			break;
		case 2:
			switch (getTipo())
			{
			case 1:
				spriteLD1.draw();

				break;
			case 2:
				spriteLK1.draw();

				break;
			case 3:
				spriteLE1.draw();

				break;
			}
			break;
		case 3:
			switch (getTipo())
			{
			case 1:
				spriteLD2.draw();

				break;
			case 2:
				spriteLK2.draw();

				break;
			case 3:
				spriteLE2.draw();
				break;
			}
			break;
		}
		//cout << "sprite A" << endl;
	}
	if ((velocidad.y > 0.001) && (velocidad.x < 0.001) && (velocidad.x > -0.001)) {
		setDir('w');
		switch (getBioma())
		{
		case 1:
			switch (getTipo())
			{
			case 1:
				spriteUpD.draw();
				break;

			case 2:
				spriteUpK.draw();

				break;
			case 3:
				spriteUpE.draw();
				break;
			}
			break;
		case 2:
			switch (getTipo())
			{
			case 1:
				spriteUpD1.draw();

				break;
			case 2:
				spriteUpK1.draw();

				break;
			case 3:
				spriteUpE1.draw();

				break;
			}
			break;
		case 3:
			switch (getTipo())
			{
			case 1:
				spriteUpD2.draw();

				break;
			case 2:
				spriteUpK2.draw();

				break;
			case 3:
				spriteUpE2.draw();
				break;
			}
			break;
		}
		//cout << "sprite W" << endl;
	}
	if ((velocidad.y < -0.001) && (velocidad.x < 0.001) && (velocidad.x > -0.001)) {
		setDir('s');
		switch (getBioma())
		{
		case 1:
			switch (getTipo())
			{
			case 1:
				spriteDownD.draw();
				break;

			case 2:
				spriteDownK.draw();

				break;
			case 3:
				spriteDownE.draw();
				break;
			}
			break;
		case 2:
			switch (getTipo())
			{
			case 1:
				spriteDownD1.draw();

				break;
			case 2:
				spriteDownK1.draw();

				break;
			case 3:
				spriteDownE1.draw();

				break;
			}
			break;
		case 3:
			switch (getTipo())
			{
			case 1:
				spriteDownD2.draw();

				break;
			case 2:
				spriteDownK2.draw();

				break;
			case 3:
				spriteDownE2.draw();
				break;
			}
			break;
		}
		//cout << "sprite S" << endl;
	}

	if ((velocidad.x < 0.001) && (velocidad.x > -0.001) && (velocidad.y < 0.001) && (velocidad.y > -0.001)) {
		switch (direccion) {
		case 'a':
			switch (getBioma())
			{
			case 1:
				switch (getTipo())
				{
				case 1:
					spriteLD.setState(1, false);
					spriteLD.draw();
					break;
				case 2:
					spriteLK.setState(1, false);
					spriteLK.draw();
					break;
				case 3:
					spriteLE.setState(1, false);
					spriteLE.draw();
					break;
				}
				break;
			case 2:
				switch (getTipo())
				{
				case 1:
					spriteLD1.setState(1, false);
					spriteLD1.draw();
					break;
				case 2:
					spriteLK1.setState(1, false);
					spriteLK1.draw();
					break;
				case 3:
					spriteLE1.setState(1, false);
					spriteLE1.draw();
					break;
				}
				break;
			case 3:
				switch (getTipo())
				{
				case 1:
					spriteLD2.setState(1, false);
					spriteLD2.draw();
					break;
				case 2:
					spriteLK2.setState(1, false);
					spriteLK2.draw();
					break;
				case 3:
					spriteLE2.setState(1, false);
					spriteLE2.draw();
					break;
				}
				break;
			}
			
			break;
		case 'd':
			switch (getBioma())
			{
			case 1:
				switch (getTipo())
				{
				case 1:
					spriteRD.setState(1, false);
					spriteRD.draw();
					break;
				case 2:
					spriteRK.setState(1, false);
					spriteRK.draw();
					break;
				case 3:
					spriteRE.setState(1, false);
					spriteRE.draw();
					break;
				}
				break;
			case 2:
				switch (getTipo())
				{
				case 1:
					spriteRD1.setState(1, false);
					spriteRD1.draw();
					break;
				case 2:
					spriteRK1.setState(1, false);
					spriteRK1.draw();
					break;
				case 3:
					spriteRE1.setState(1, false);
					spriteRE1.draw();
					break;
				}
				break;
			case 3:
				switch (getTipo())
				{
				case 1:
					spriteRD2.setState(1, false);
					spriteRD2.draw();
					break;
				case 2:
					spriteRK2.setState(1, false);
					spriteRK2.draw();
					break;
				case 3:
					spriteRE2.setState(1, false);
					spriteRE2.draw();
					break;
				}
				break;
			}

			break;
		case 'w':
			switch (getBioma())
			{
			case 1:
				switch (getTipo())
				{
				case 1:
					spriteUpD.setState(1, false);
					spriteUpD.draw();
					break;
				case 2:
					spriteUpK.setState(1, false);
					spriteUpK.draw();
					break;
				case 3:
					spriteUpE.setState(1, false);
					spriteUpE.draw();
					break;
				}
				break;
			case 2:
				switch (getTipo())
				{
				case 1:
					spriteUpD1.setState(1, false);
					spriteUpD1.draw();
					break;
				case 2:
					spriteUpK1.setState(1, false);
					spriteUpK1.draw();
					break;
				case 3:
					spriteUpE1.setState(1, false);
					spriteUpE1.draw();
					break;
				}
				break;
			case 3:
				switch (getTipo())
				{
				case 1:
					spriteUpD2.setState(1, false);
					spriteUpD2.draw();
					break;
				case 2:
					spriteUpK2.setState(1, false);
					spriteUpK2.draw();
					break;
				case 3:
					spriteUpE2.setState(1, false);
					spriteUpE2.draw();
					break;
				}
				break;
			}

			break;
		case 's':
			switch (getBioma())
			{
			case 1:
				switch (getTipo())
				{
				case 1:
					spriteDownD.setState(1, false);
					spriteDownD.draw();
					break;
				case 2:
					spriteDownK.setState(1, false);
					spriteDownK.draw();
					break;
				case 3:
					spriteDownE.setState(1, false);
					spriteDownE.draw();
					break;
				}
				break;
			case 2:
				switch (getTipo())
				{
				case 1:
					spriteDownD1.setState(1, false);
					spriteDownD1.draw();
					break;
				case 2:
					spriteDownK1.setState(1, false);
					spriteDownK1.draw();
					break;
				case 3:
					spriteDownE1.setState(1, false);
					spriteDownE1.draw();
					break;
				}
				break;
			case 3:
				switch (getTipo())
				{
				case 1:
					spriteDownD2.setState(1, false);
					spriteDownD2.draw();
					break;
				case 2:
					spriteDownK2.setState(1, false);
					spriteDownK2.draw();
					break;
				case 3:
					spriteDownE2.setState(1, false);
					spriteDownE2.draw();
					break;
				}
				break;
			}
			break;
		}
	}
	glPopMatrix();
	//std::cout << "velocidad: ( " << velocidad.x << " , " << velocidad.y << " )" << std::endl;
	//std::cout << "direccion: " << direccion << std::endl;
}

void Enemigo::Mueve(float t)
{
	ObjetosMovimiento::mueve(t);
	spriteRD.loop();
	spriteLD.loop();
	spriteUpD.loop();
	spriteDownD.loop();

	spriteRK.loop();
	spriteLK.loop();
	spriteUpK.loop();
	spriteDownK.loop();

	spriteRE.loop();
	spriteLE.loop();
	spriteUpE.loop();
	spriteDownE.loop();

	spriteRD1.loop();
	spriteLD1.loop();
	spriteUpD1.loop();
	spriteDownD1.loop();

	spriteRK1.loop();
	spriteLK1.loop();
	spriteUpK1.loop();
	spriteDownK1.loop();

	spriteRE1.loop();
	spriteLE1.loop();
	spriteUpE1.loop();
	spriteDownE1.loop();

	spriteRD2.loop();
	spriteLD2.loop();
	spriteUpD2.loop();
	spriteDownD2.loop();

	spriteRK2.loop();
	spriteLK2.loop();
	spriteUpK2.loop();
	spriteDownK2.loop();

	spriteRE2.loop();
	spriteLE2.loop();
	spriteUpE2.loop();
	spriteDownE2.loop();
}

void Enemigo::setTam(float anchura, float altura)
{
	spriteRD.setCenter(1.5, 0);
	spriteRD.setSize(anchura, altura);
	spriteLD.setCenter(1.5, 0);
	spriteLD.setSize(anchura, altura);
	spriteUpD.setCenter(1.5, 0);
	spriteUpD.setSize(anchura, altura);
	spriteDownD.setCenter(1.5, 0);
	spriteDownD.setSize(anchura, altura);

	spriteRK.setCenter(1.5, 0);
	spriteRK.setSize(anchura, altura);
	spriteLK.setCenter(1.5, 0);
	spriteLK.setSize(anchura, altura);
	spriteUpK.setCenter(1.5, 0);
	spriteUpK.setSize(anchura, altura);
	spriteDownK.setCenter(1.5, 0);
	spriteDownK.setSize(anchura, altura);

	spriteRE.setCenter(1.5, 0);
	spriteRE.setSize(anchura, altura);
	spriteLE.setCenter(1.5, 0);
	spriteLE.setSize(anchura, altura);
	spriteUpE.setCenter(1.5, 0);
	spriteUpE.setSize(anchura, altura);
	spriteDownE.setCenter(1.5, 0);
	spriteDownE.setSize(anchura, altura);

	spriteRD1.setCenter(1.5, 0);
	spriteRD1.setSize(anchura, altura);
	spriteLD1.setCenter(1.5, 0);
	spriteLD1.setSize(anchura, altura);
	spriteUpD1.setCenter(1.5, 0);
	spriteUpD1.setSize(anchura, altura);
	spriteDownD1.setCenter(1.5, 0);
	spriteDownD1.setSize(anchura, altura);

	spriteRK1.setCenter(1.5, 0);
	spriteRK1.setSize(anchura, altura);
	spriteLK1.setCenter(1.5, 0);
	spriteLK1.setSize(anchura, altura);
	spriteUpK1.setCenter(1.5, 0);
	spriteUpK1.setSize(anchura, altura);
	spriteDownK1.setCenter(1.5, 0);
	spriteDownK1.setSize(anchura, altura);

	spriteRE1.setCenter(1.5, 0);
	spriteRE1.setSize(anchura, altura);
	spriteLE1.setCenter(1.5, 0);
	spriteLE1.setSize(anchura, altura);
	spriteUpE1.setCenter(1.5, 0);
	spriteUpE1.setSize(anchura, altura);
	spriteDownE1.setCenter(1.5, 0);
	spriteDownE1.setSize(anchura, altura);

	spriteRD2.setCenter(1.5, 0);
	spriteRD2.setSize(anchura, altura);
	spriteLD2.setCenter(1.5, 0);
	spriteLD2.setSize(anchura, altura);
	spriteUpD2.setCenter(1.5, 0);
	spriteUpD2.setSize(anchura, altura);
	spriteDownD2.setCenter(1.5, 0);
	spriteDownD2.setSize(anchura, altura);

	spriteRK2.setCenter(1.5, 0);
	spriteRK2.setSize(anchura, altura);
	spriteLK2.setCenter(1.5, 0);
	spriteLK2.setSize(anchura, altura);
	spriteUpK2.setCenter(1.5, 0);
	spriteUpK2.setSize(anchura, altura);
	spriteDownK2.setCenter(1.5, 0);
	spriteDownK2.setSize(anchura, altura);

	spriteRE2.setCenter(1.5, 0);
	spriteRE2.setSize(anchura, altura);
	spriteLE2.setCenter(1.5, 0);
	spriteLE2.setSize(anchura, altura);
	spriteUpE2.setCenter(1.5, 0);
	spriteUpE2.setSize(anchura, altura);
	spriteDownE2.setCenter(1.5, 0);
	spriteDownE2.setSize(anchura, altura);
}

void Enemigo::Perseguir(Protagonista p)
{
	Vector2D pos_p = p.GetPos();
	Vector2D pos_e = GetPos();
	Vector2D delta = pos_p - pos_e;
	float angulo = atan2(delta.y, delta.x);
	float distancia = delta.modulo();
	if (distancia <= 4)
		setVel(vel * cos(angulo), vel * sin(angulo));
		
	else
		setVel(0, 0);
	spriteRD.loop();
	spriteLD.loop();
	spriteUpD.loop();
	spriteDownD.loop();

	spriteRK.loop();
	spriteLK.loop();
	spriteUpK.loop();
	spriteDownK.loop();

	spriteRE.loop();
	spriteLE.loop();
	spriteUpE.loop();
	spriteDownE.loop();

	spriteRD1.loop();
	spriteLD1.loop();
	spriteUpD1.loop();
	spriteDownD1.loop();

	spriteRK1.loop();
	spriteLK1.loop();
	spriteUpK1.loop();
	spriteDownK1.loop();

	spriteRE1.loop();
	spriteLE1.loop();
	spriteUpE1.loop();
	spriteDownE1.loop();

	spriteRD2.loop();
	spriteLD2.loop();
	spriteUpD2.loop();
	spriteDownD2.loop();

	spriteRK2.loop();
	spriteLK2.loop();
	spriteUpK2.loop();
	spriteDownK2.loop();

	spriteRE2.loop();
	spriteLE2.loop();
	spriteUpE2.loop();
	spriteDownE2.loop();
}


void Enemigo::distProta(Protagonista p)
{
	Vector2D pos_p = p.GetPos();
	Vector2D pos_e = GetPos();
	Vector2D dir = pos_p - pos_e;
	float dist = dir.modulo();
	float ang = atan2(dir.y, dir.x);
	setAngulo(ang);

	if (dist < 15)
		setFlagDist(1);
	else
		setFlagDist(0);
}