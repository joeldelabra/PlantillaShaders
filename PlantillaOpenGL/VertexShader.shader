#version 330 core
// LA PRIMERA LINEA SIEMPRE ES LA VERSION

// Atributo de entrada (vienen desde c++)
in vec3 posicion;
in vec4 color;

// Atributos de salida (van hacia el fragment shader)
out vec4 FragmentColor;

// Funcion main
void main()
{
	// Posicion de salida del vertice.
    // 
	gl_Position.xyz = posicion;
	gl_Position.w = 1.0;

	// Establecer valores de atributos de salida
	FragmentColor = color;

}