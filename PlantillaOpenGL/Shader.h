#pragma once
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

using namespace std;

class Shader
{
public: 
	GLuint getID(); // Obtine el ID del shader.
	Shader(const char * rutavertex, const char * rutaFragment);
	void enlazar();
	void desenlazar();
private:
	GLuint shaderID;
	void VerificarCompilacion(GLuint id);
	void VerificarVinculacion(GLuint id);
};

void main()
{

}