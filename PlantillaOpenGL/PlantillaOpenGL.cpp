// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

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

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> Piramide;
GLuint vertexArrayPiramideID;
GLuint bufferPiramideID;

vector<Vertice> EscaleraPiramide;
GLuint vertexArrayEscaleraPiramideID;
GLuint bufferEscaleraPiramideID;

void inicializarPiramide() {
	
	Vertice v1 = {
		vec3(-0.9, -0.5, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v2 = {
		vec3(-0.9, -0.4, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v3 = {
		vec3(-0.8, -0.4, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v4 = {
		vec3(-0.8, -0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v5 = {
		vec3(-0.7, -0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v6 = {
		vec3(-0.7, -0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v7 = {
		vec3(-0.6, -0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v8 = {
		vec3(-0.6, -0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v9 = {
		vec3(-0.5, -0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v10 = {
		vec3(-0.5, 0.0, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v11 = {
		vec3(-0.4, 0.0, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v12 = {
		vec3(-0.4, 0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v13 = {
		vec3(-0.3, 0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v14 = {
		vec3(-0.3, 0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v15 = {
		vec3(-0.2, 0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v16 = {
		vec3(-0.2, 0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v17 = {
		vec3(-0.1, 0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v18 = {
		vec3(-0.1, 0.45, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v19 = {
		vec3(0.1, 0.45, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v20 = {
		vec3(0.1, 0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v21 = {
		vec3(0.2, 0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v22 = {
		vec3(0.2, 0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v23 = {
		vec3(0.3, 0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v24 = {
		vec3(0.3, 0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v25 = {
		vec3(0.4, 0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v26 = {
		vec3(0.4, 0.0, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v27 = {
		vec3(0.5, 0.0, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v28 = {
		vec3(0.5, -0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v29 = {
		vec3(0.6, -0.1, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v30 = {
		vec3(0.6, -0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v31 = {
		vec3(0.7, -0.2, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v32 = {
		vec3(0.7, -0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v33 = {
		vec3(0.8, -0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v34 = {
		vec3(0.8, -0.4, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v35 = {
		vec3(0.9, -0.4, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v36 = {
		vec3(0.9, -0.5, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
   
	


	Piramide.push_back(v1);
	Piramide.push_back(v2);
	Piramide.push_back(v3);
	Piramide.push_back(v4);
	Piramide.push_back(v5);
	Piramide.push_back(v6);
	Piramide.push_back(v7);
	Piramide.push_back(v8);
	Piramide.push_back(v9);
	Piramide.push_back(v10);
	Piramide.push_back(v11);
	Piramide.push_back(v12);
	Piramide.push_back(v13);
	Piramide.push_back(v14);
	Piramide.push_back(v15);
	Piramide.push_back(v16);
	Piramide.push_back(v17);
	Piramide.push_back(v18);
	Piramide.push_back(v19);
	Piramide.push_back(v20);
	Piramide.push_back(v21);
	Piramide.push_back(v22);
	Piramide.push_back(v23);
	Piramide.push_back(v24);
	Piramide.push_back(v25);
	Piramide.push_back(v26);
	Piramide.push_back(v27);
	Piramide.push_back(v28);
	Piramide.push_back(v29);
	Piramide.push_back(v30);
	Piramide.push_back(v31);
	Piramide.push_back(v32);
	Piramide.push_back(v33);
	Piramide.push_back(v34);
	Piramide.push_back(v35);
	Piramide.push_back(v36);

}
void inicializarEscaleraPiramide()
{
	Vertice v1 = {
		vec3(0.1, -0.5, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v2 = {
		vec3(0.1, 0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v3 = {
		vec3(-0.1, 0.3, 0.0),
		vec4(0.59, 0.48, 0.35)
	};
	Vertice v4 = {
		vec3(-0.1, -0.5, 0.0),
		vec4(0.59, 0.48, 0.35)
	};



	EscaleraPiramide.push_back(v1);
	EscaleraPiramide.push_back(v2);
	EscaleraPiramide.push_back(v3);
	EscaleraPiramide.push_back(v4);
	

}

void inicializarTriangulo() {
	Vertice v1 =
	{
		vec3(0.0f,0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void dibujar() {
	//Elegir el shader
	shader->enlazar();
	//Elegir un vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

	//Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_LINE_LOOP, 0, cuadrado.size());

	// PIRAMIDE
	glBindVertexArray(vertexArrayPiramideID);
	glDrawArrays(GL_LINE_LOOP, 0, Piramide.size());

	// Escalera PIRAMIDE
	glBindVertexArray(vertexArrayEscaleraPiramideID);
	glDrawArrays(GL_LINE_LOOP, 0, EscaleraPiramide.size());

	//Soltar el vertex array
	glBindVertexArray(0);
	//Soltar el shader
	shader->desenlazar();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//Si no se pudo iniciar glfw
	//terminamos ejcución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window =
		glfwCreateWindow(1024, 768, "Ventana",
			NULL, NULL);
	//Si no podemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido  el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout <<
			glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: "
		<< versionGL;

	// inicializarTriangulo();
	inicializarPiramide();
	inicializarEscaleraPiramide();

	const char *rutaVertex =
		"VertexShader.shader";
	const char *rutaFragment =
		"FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader->desenlazar();

	//Crear un vertex array
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	//Crear vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);
	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * triangulo.size(),
		triangulo.data(), GL_STATIC_DRAW);

	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Vertex array y buffer para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * cuadrado.size(), cuadrado.data(),
		GL_STATIC_DRAW);

	//Vertex array y buffer para Piramide
	glGenVertexArrays(1, &vertexArrayPiramideID);
	glBindVertexArray(vertexArrayPiramideID);
	glGenBuffers(1, &bufferPiramideID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPiramideID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * Piramide.size(), Piramide.data(),
		GL_STATIC_DRAW);

	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));


	//Vertex array y buffer para Escalera Piramide
	glGenVertexArrays(1, &vertexArrayEscaleraPiramideID);
	glBindVertexArray(vertexArrayEscaleraPiramideID);
	glGenBuffers(1, &bufferEscaleraPiramideID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferEscaleraPiramideID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * EscaleraPiramide.size(), EscaleraPiramide.data(),
		GL_STATIC_DRAW);



	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//Especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Esablecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(0, 0.8, 1.0, 1);
		//Borramos
		glClear(
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
