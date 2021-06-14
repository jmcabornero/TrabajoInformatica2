#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
	ContadorHisoria = 1;
	ETSIDI::playMusica("sonidos/No Place For Straw Cowboys.mp3", TRUE);
};

Coordinador::~Coordinador()
{

};

void Coordinador::Inicializa()
{

};

void Coordinador::Dibuja()
{
	if (estado == INICIO) {

		gluLookAt(0.0, 7.5, 30.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -4, -0.1); //raul bien
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/valuoldcaps.ttf", 34);
		ETSIDI::printxy("JUEGO SUPER CHULO", -9, 14);

		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSE LA TECLA: -H- PARA VER LA HISTORIA", -9, 1);
		ETSIDI::printxy("                 -I-  PARA LEER LAS INSTRUCCIONES", -8, 0);
		ETSIDI::printxy("                 -E- PARA JUGAR DIRECTAMENTE", -8, -1);
		ETSIDI::printxy("                 -S- PARA SALIR DEL JUEGO", -8, -2);
		//ETSIDI::printxy("                 -S- PARA SALIR DEL JUEGO", -8, -3);
	}

	else if (estado == JUEGO) {
		//mundo.inicializa();
		mundo.dibuja();


	}

	else if (estado == PAUSA) {
		//mundo.dibuja();

		gluLookAt(0.0, 7.5, 35,  //22
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pausa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 0); glVertex2f(10, 15);
		glTexCoord2d(0, 0); glVertex2f(-10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSE LA TECLA: -M- PARA SALIR AL MENU DE INICIO", -8, -1);
		ETSIDI::printxy("                 -S- PARA SALIR DEL JUEGO", -7, -2);
		ETSIDI::printxy("                 -J- PARA	VOLVER AL JUEGO", -7, -3);

	}

	else if (estado == INSTRUCCIONES) {

		gluLookAt(0.0, 7.5, 30.5,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_inst.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/valuoldcaps.ttf", 34);
		ETSIDI::printxy("INSTRUCCIONES", -9, 14);

		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PARA MOVERTE:    CON LAS FLECHAS DEL TECLADO", -9, 8);

		ETSIDI::printxy("PARA DISPARAR:    CON LA BARRA ESPACIADORA", -9, 5);

		ETSIDI::printxy("PARA PAUSAR EL JUEGO PULSE LA TECLA 'ESC'", -9, 2);
		ETSIDI::printxy("PARA VOLVER AL MENU PRINCIPAL PULSE LA TECLA M", -9, -1);

	}

	else if (estado == HISTORIA && ContadorHisoria == 1) {

		gluLookAt(0.0, 7.5, 35.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/carta.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Cardinal.ttf", 34);
		ETSIDI::printxy("HISTORIA", -6, 14);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/ThrowMyHandsUpintheAir.ttf", 14);
		ETSIDI::printxy("PARA AVANZAR Y VOLVER EN LA HISTORIA", -9, 8);
		ETSIDI::printxy("PULSE LAS FLECHAS IZQ Y DCH", -9, 7);
		//ETSIDI::printxy("                 -I-  PARA LEER LAS INSTRUCCIONES", -8, 0);
		ETSIDI::printxy("PARA OMITIR LA HISTORIA PULSE LA TECLA S", -9, 5);
		//ETSIDI::printxy("                 -S- PARA SALIR DEL JUEGO", -8, -2);
		
	}

	else if (estado == HISTORIA && ContadorHisoria == 2) {

		gluLookAt(0.0, 7.5, 35.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/carta.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Cardinal.ttf", 34);
		ETSIDI::printxy("HISTORIA", -6, 14);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/ThrowMyHandsUpintheAir.ttf", 14);
		ETSIDI::printxy("Erase una vez, en un mundo muy muy lejano, un reino en paz ", -9, 8);
		ETSIDI::printxy("gobernado por un rey bueno, piadoso. Un dia, el reino fue atacado ", -9, 6);
		ETSIDI::printxy("por una horda de esqueletos, duendes y criaturas perversas", -9, 4);
		ETSIDI::printxy("lideradas por un malvado lider. Este ser se hace llamar Tiburon.", -9, 2);
	}

	else if (estado == HISTORIA && ContadorHisoria == 3) {

		gluLookAt(0.0, 7.5, 35.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/carta.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Cardinal.ttf", 34);
		ETSIDI::printxy("HISTORIA", -6, 14);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/ThrowMyHandsUpintheAir.ttf", 14);
		ETSIDI::printxy("El Reino de los Tres Biomas, como los aldeanos lo solian llamar,", -9, 8);
		ETSIDI::printxy("fue invadido y su rey muerto en combate.De los aldeanos", -9, 6);
		ETSIDI::printxy("supervivientes, solo quedan pequenas casas alejadas unas de otras", -9, 4);
		ETSIDI::printxy("y sus habitantes, prefieren no hablar ni abrir la puerta a nadie.", -9, 2);
	}

	else if (estado == HISTORIA && ContadorHisoria == 4) {

		gluLookAt(0.0, 7.5, 35.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/carta.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Cardinal.ttf", 34);
		ETSIDI::printxy("HISTORIA", -6, 14);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/ThrowMyHandsUpintheAir.ttf", 14);
		ETSIDI::printxy("Ahora el reino espera un heroe para ver derrotado al malvado", -9, 8);
		ETSIDI::printxy("Tiburon y por fin coronar un rey que traiga paz a la tierra.Lucha", -9, 6);
		ETSIDI::printxy("contra sus subditos, mejora tu equipamiento y prueba suerte en", -9, 4);
		ETSIDI::printxy("esta epoca de miseria.Quien sabe si podras coronarte rey del reino...", -9, 2);
	}

	else if (estado == HISTORIA && ContadorHisoria == 5) {

		gluLookAt(0.0, 7.5, 35.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/carta.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Cardinal.ttf", 34);
		ETSIDI::printxy("FIN HISTORIA", -6, 14);

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/ThrowMyHandsUpintheAir.ttf", 14);
		ETSIDI::printxy("PARA EMPEZAR A JUGAR PULSAR LA TECLA J", -9, 8);
		//ETSIDI::printxy("PULSE LAS FLECHAS IZQ Y DCH", -9, 7);

		ETSIDI::printxy("PARA VOLVER AL MENÚ PRINCIPAL PULSAR LA TECLA M", -9, 5);

	}

	else if (estado == GAMEOVER) {

		gluLookAt(0.0, 7.5, 30.5,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/game_over_PNG1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 0); glVertex2f(10, 15);
		glTexCoord2d(0, 0); glVertex2f(-10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);


		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSA LA TECLA M PARA IR AL MENU PRINCIPAL", -9, 2);

		ETSIDI::printxy("PULSA LA TECLA S PARA SALIR DEL JUEGO", -9, 0);

	}

	else if (estado == EXITO) {

	gluLookAt(0.0, 7.5, 38.5,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/victoria.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-10, 0);
	glTexCoord2d(1, 1); glVertex2f(10, 0);
	glTexCoord2d(1, 0); glVertex2f(10, 15);
	glTexCoord2d(0, 0); glVertex2f(-10, 15);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


	ETSIDI::setTextColor(1, 0, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
	ETSIDI::printxy("PULSA LA TECLA M PARA IR AL MENU PRINCIPAL", -9, -2);

	ETSIDI::printxy("PULSA LA TECLA S PARA SALIR DEL JUEGO", -9, -4);


	}
};

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		mundo.mueve();

		if (mundo.GetVidas() <= 0)
		{

			estado = GAMEOVER;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/gameover.mp3");
		}

		/*if (mundo.GetVidasBoss() <= 0)
		{

			estado = EXITO;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Victory sound effect.mp3");
		}*/
	}
}
void Coordinador::Tecla(unsigned char key)
{
	if (estado == INICIO) {

		switch (key) {
		case 'H':
		case 'h':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Spring Village.mp3", TRUE);
			estado = HISTORIA;
			break;
		case 'I':
		case 'i':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Flutes for Misha.mp3", TRUE);
			estado = INSTRUCCIONES;
			break;
		case 'E':
		case 'e':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/zelda.mp3", TRUE);
			mundo.inicializa();
			estado = JUEGO;
			break;
		case 'S':
		case 's':
			exit(0);
			break;
		}
	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
		switch (key) {
		case 27:
			ETSIDI::stopMusica();
			estado = PAUSA;
			break;
		}
	}

	else if (estado == PAUSA) {
		switch (key) {
		case 'S':
		case 's':
			exit(0);
			break;
		case 'J':
		case 'j':
			ETSIDI::playMusica("sonidos/zelda.mp3", TRUE);
			estado = JUEGO;
			break;
		case 'M':
		case 'm':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/No Place For Straw Cowboys.mp3", TRUE);
			estado = INICIO;
			break;
		}
	}

	else if (estado == INSTRUCCIONES) {
		switch (key) {
		case 'M':
		case 'm':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/No Place For Straw Cowboys.mp3", TRUE);
			estado = INICIO;
			break;
		}
	}

	if (estado == HISTORIA)
	{
		if (key == 's' || key == 'S')
		{
			// saltar toda la historia e ir a la última página
			ContadorHisoria = 5;
		}
		
		if (ContadorHisoria == 5)
		{
			switch (key) {
			case 'J': //empezar el juego
			case 'j':
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonidos/zelda.mp3", TRUE);
				mundo.inicializa();
				estado = JUEGO;
				break;
			case 'M':  // volver al menú principal
			case 'm':
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonidos/No Place For Straw Cowboys.mp3", TRUE);
				ContadorHisoria = 1;
				estado = INICIO;
				break;
			}

			key = 'Q';			//LIMPIAR BUFFER TECLADO
		}
	}

	else if (estado == GAMEOVER) {
		switch (key) {
		case 'S':
		case 's':
			exit(0);
			break;
		case 'M':
		case 'm':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/No Place For Straw Cowboys.mp3", TRUE);
			estado = INICIO;
			break;
		}
	}

	else if (estado == EXITO) {
		switch (key) {
		case 'S':
		case 's':
			exit(0);
			break;
		case 'M':
		case 'm':
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/No Place For Straw Cowboys.mp3", TRUE);
			estado = INICIO;
			break;
		}
	}
};

void Coordinador::TeclaEspecial(int key) {

	if (estado == HISTORIA)
	{

		if (key == GLUT_KEY_RIGHT && ContadorHisoria != 5)
		{
			ContadorHisoria++;
			key = 'Q';			//LIMPIAR BUFFER TECLADO
		}
		if (key == GLUT_KEY_LEFT && ContadorHisoria != 1)
		{
			ContadorHisoria--;
		}

	}
	else if (estado == JUEGO) {
		mundo.teclaEspecial(key);
	}
};

void Coordinador::TeclaEspecialUp(int key) {
	if (estado == JUEGO) {
		mundo.teclaEspecialUp(key);

	}
}