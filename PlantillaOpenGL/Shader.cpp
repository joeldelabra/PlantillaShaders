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

	// 3.- Compilar Shaders.
	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	// 4.- Verificar errores de compilacion.
	VerificarCompilacion(vertexShaderID);
	VerificarCompilacion(fragmentShaderID);

	// 5.- Adjuntar shaders al programa.
	glAttachShader(shaderID, vertexShaderID);
	glAttachShader(shaderID, fragmentShaderID);

	// 6.- Vincular el programa.
	glLinkProgram(shaderID);

	// 7.- Verificar la vinculación.
	VerificarVinculacion(shaderID);

	// 8.- Usar el programa.
	glUseProgram(shaderID);

}

void Shader::VerificarCompilacion(GLuint id)
{
	GLint resultado = GL_FALSE;
	GLint longitudLog = 0;

	glGetShaderiv(id,GL_COMPILE_STATUS,&resultado);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &longitudLog);

	if (longitudLog > 0)
	{
		vector<char> mensajeError(longitudLog);
		glGetShaderInfoLog(id, longitudLog, NULL, &mensajeError[0]);
		for (vector<char>::const_iterator i = mensajeError.begin();
			i != mensajeError.end(); i++)
		{
			cout << *i;
		}

	}
}

void Shader::VerificarVinculacion(GLuint id)
{
	GLint estadoVinculacion, estadoValidacion;
	glGetProgramiv(id, GL_LINK_STATUS, &estadoVinculacion);
	if (estadoVinculacion == GL_FALSE)
	{
		cout << "No se pudo vincular el programa" << endl;
	}
	glGetProgramiv(id, GL_VALIDATE_STATUS, &estadoValidacion);
	if(estadoValidacion == GL_FALSE)
	{
		cout << "No se pudo vincular la validación" << endl;
	}

}