#include "sphere.h"

_sphere::_sphere()
{
    int tamanio = 52;
    Vertices.resize(tamanio);

    double incr_angulo = 180.0 / (tamanio - 1); // Ajustar el incremento del ángulo

    // Punto inicial
    Vertices[0] = _vertex3f(0, -0.5, 0);

    for (int i = 1; i < tamanio - 1; i++) {
        double angulo = -90.0 + i * incr_angulo; // Calcular el ángulo en función de i
        Vertices[i] = _vertex3f(cos(angulo * M_PI / 180.0) * 0.5, sin(angulo * M_PI / 180.0) * 0.5, 0);
    }

    // Punto final
    Vertices[tamanio - 1] = _vertex3f(0, 0.5, 0);

    revolution(60);
    compute_triangles_normals();
    compute_vertices_normals();
}

_sphere::~_sphere(){
    Vertices.clear();
}

void _sphere::compute_vertices_normals()
{
    int vertSize = Vertices.size();

    Vertices_normals.resize(vertSize);

    for(auto i = 0; i < vertSize; i++)
    {
        Vertices_normals[i].x = Vertices[i].x;
        Vertices_normals[i].y = Vertices[i].y;
        Vertices_normals[i].z = Vertices[i].z;

        Vertices_normals[i].normalize();

    }
}

