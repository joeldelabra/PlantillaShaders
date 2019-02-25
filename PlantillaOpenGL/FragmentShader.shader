#version 330 core
// Primera linea siempre es la version.

// Atributos de entrada (vienen desde el vertex shader).
in vec4 FragmentColor;

// Atributos de salida
out vec4 SalidaColor;

void main()
{
	SalidaColor = FragmentColor;
}