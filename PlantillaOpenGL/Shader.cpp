#include "stdafx.h"
#include "Shader.h"

GLuint Shader::getID()
{
	return shaderID;
}

Shader ::Shader(const char * rutavertex, const char * rutaFragment)
{
	// Guardar en variables el texto de los codigos de los shaders.
	string codigoVertexShader;
	ifstream vertexShaderStream(rutavertex, ios::in);
	if (vertexShaderStream.is_open())
	{
		string linea;
		while (getline(vertexShaderStream, linea))
		{
			codigoVertexShader += linea + "\n";
		}
		vertexShaderStream.close();

	}else 
	{ 
		cout << "No se pudo abrir el archivo" << rutavertex << std::endl;
	}

	string CodigoFragmentShader;
	ifstream FragmentShaderStream(rutaFragment, ios::in);

	if (FragmentShaderStream.is_open())
	{
		string linea;
		while (getline(FragmentShaderStream, linea))
		{
			CodigoFragmentShader += linea + "\n";
		}
		FragmentShaderStream.close();
	}
	else
	{
		cout << "no se pudo abrir el archivo" << rutaFragment << std::endl;
	}

	// Convertir string a cadena de char.
	const char * CadenaCodigoVertex = codigoVertexShader.c_str();
	const char * CadenaCodigoFragment = CodigoFragmentShader.c_str();

	// 1.- Crear el proghrama de shaders
	shaderID = glCreateProgram();
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// 2.- Cargar el codigo del Shader.
	glShaderSource(vertexShaderID, 1, &CadenaCodigoVertex, NULL);
	glShaderSource(fragmentShaderID, 1, &CadenaCodigoFragment, NULL);

	// 3.- Compilar Shaders
	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);


}

void Shader::VerificarCompilacion(GLuint id)
{
	GLint resultado = GL_FALSE;
	int longitudLog = 0;

}