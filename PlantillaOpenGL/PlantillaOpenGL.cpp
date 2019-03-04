// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"

using namespace std;

Shader *shader;
GLuint posicionID;
GLuint colorID;

vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

void inicializarTriangulo()
{
	Vertice v1 =
	{
		vec3(0.0f, 0.3f,0.0f),
		vec4(0.0f,0.8f,1.0f,1.0f)
	};

	Vertice v2 =
	{
		vec3(-0.3f, -0.3f,0.0f),
		vec4(0.0f,0.8f,1.0f,1.0f)
	};

	Vertice v3 =
	{
		vec3(0.3f, -0.3f,0.0f),
		vec4(0.0f,0.8f,1.0f,1.0f)
	};

	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);

}



void dibujar() {

}

void actualizar() {

}


int main()
{
	GLFWwindow * window;

	//Si no se pudo iniciar glfw
	//entonces inicializamos en la ventana
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana
	//Entonces terminamos la ejecucion

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);
	// Una vez establecido el contexto activamos funciones modernas.
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	
	if (errorGlew != GLEW_OK) 
	{
     	cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	inicializarTriangulo();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	// Mapeo de atributos
	posicionID = glGetAttribLocation(shader ->getID(), "Posicion");
	colorID = glGetAttribLocation(shader->getID(), "Color");

	// Desenlazar el shader
	shader->desenlazar();

	// Crear un vertex array
	glGenVertexArrays(1,&vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	// Crear un vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);

	// Llenar buffer
	glBufferData(GL_ARRAY_BUFFER,sizeof(Vertice) 
		* triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	// Habilitar atributos del Shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especififar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3,GL_FLOAT,GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	// Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	


	//Ciclo de dibujo (Draw Loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region del dibujo
		glViewport(0, 0, 1024, 768);
		//Establecer el color del borrado
		glClearColor(1, 0, 0, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		// Cambiar los buffer
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}