#include "stdafx.h"
#include "Shader.h"

GLuint Shader::getID()
{
	return shaderID;
}

Shader ::Shader(const char * rutavertex, const char * rutaFragment)
{
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



}