/*#include "OpenGL.h"

unsigned int OpenGL::CargaTextura(char* nombre)
{
	for (int i = 0;i < id_texturas.size();i++)
		if (0 == nombre_texturas[i].compare(nombre))
			return id_texturas[i];

	unsigned int textura = -1;
	glGenTextures(1, &textura);
	//codigo de texturas
		AUX_RGBImageRec* mitex = auxDIBImageLoadA(nombre);
	if (mitex != NULL)
	{
		int ret = gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
			mitex->sizeX, mitex->sizeY, GL_RGB,
			GL_UNSIGNED_BYTE,
			mitex->data);
		delete mitex->data;
		delete mitex;
		id_texturas.push_back(textura);
		std::string cad(nombre);
		nombre_texturas.push_back(cad);
	}
	return textura;
}

void OpenGL::BorraTexturas()
{
	for (int i = 0;i < id_texturas.size();i++)
	{
		glDeleteTextures(1, &id_texturas[i]);
	}
	id_texturas.clear();
	nombre_texturas.clear();
	glBindTexture(GL_TEXTURE_2D, NULL);
}*/