#include "revolutionobject.h"
#include <cmath>
#include <algorithm>
#include <iostream>

void revolutionObject::revolution(const int &n)
{
    const int static ZERO = 0;
    _vertex3f aux;
    double angulo_inicial = (2 * M_PI) /n ;
    double new_angulo = (2 * M_PI) /n;
    int tamanio = Vertices.size();
    Triangles.resize(n * tamanio * 2);

    bool invertido = (Vertices[ZERO].y > Vertices[tamanio - 1].y);

    if (invertido) {
        std::reverse(Vertices.begin(), Vertices.end());
    }

    std::vector<_vertex3f> centralZone;
    centralZone.resize(tamanio + ((tamanio - 2) * (n - 1)));
    _vertex3f up, low;
    int pos = ZERO;

    up = Vertices[tamanio-1];
    low = Vertices[ZERO];

    // Añadimos solo los vértices de la zona central (no están en el eje y)
    for (int i = 0; i < tamanio; i++) {
        if (Vertices[i].x != 0.0f || Vertices[i].z != 0.0f) {
            centralZone[pos++] = Vertices[i];
        }
    }

    bool tieneCara = (pos > 1); //Si hay más de dos vértices en la zona central

    tamanio = pos;

    int newN = n - 1; // Para evitar repetir los primeros vértices

    // Obtenemos los demás vértices por revolución
    for (int i = 0; i < newN; i++) {
        for (int j = 0; j < tamanio; j++) {
            float r = centralZone[j].x;

            aux.x = r * cos(angulo_inicial + i * new_angulo);
            aux.z = -r * sin(angulo_inicial + i * new_angulo);
            aux.y = centralZone[j].y;

            centralZone[pos++] = aux;
        }
    }

    // Se añaden los vértices del eje y al final
    centralZone[pos++] = low;
    centralZone[pos++] = up;

    Vertices = centralZone;

    //std::cout << "N puntos: " << Vertices.size() << endl;

    int posLow = Vertices.size() - 2;
    int tamSinT = Vertices.size() - 2;
    int posUp = Vertices.size() - 1;
    int indice = ZERO;

    pos = ZERO;
    if (tieneCara) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < tamanio - 1; col++) {
                indice = (row * tamanio) + col;

                Triangles[pos++] = _vertex3ui((indice + 1) % tamSinT, (indice + tamanio) % tamSinT, (indice + 1 + tamanio) % tamSinT);// Cara par
                Triangles[pos++] = _vertex3ui(indice % tamSinT, (indice + tamanio) % tamSinT, (indice + 1) % tamSinT); // Cara impar

                if (indice % tamanio == 0) {
                    Triangles[pos++] = _vertex3ui(indice % tamSinT, posLow, (indice + tamanio) % tamSinT);  // Triángulo de tapa inferior
                }
            }
            int indiceUP = ((row * tamanio) + (tamanio - 1)) % tamSinT;
            Triangles[pos++] = _vertex3ui(indiceUP, (indiceUP + tamanio) % tamSinT, posUp);   // Triángulo tapa superior
        }
    }else {
        for (int i = 0; i < n ; i++) {
            Triangles[pos++] = _vertex3ui(i, posLow, (i + tamanio) % n);
            Triangles[pos++] = _vertex3ui(i, (i + tamanio) % n, posUp);
        }
    }

    //std::cout << "N triangulo: " << pos << endl;
}


/*
void revolutionObject::revolution(const int &n)
{
    // Vertice auxiliar
    _vertex3f vertice_aux;

    // Declarar angulo inicial
    double angulo = 0.0;

    // Le pasamos el numero de vertices que tiene el perfil
    int perfil = Vertices.size();

    // Permitir que lo puntos en el perfil tengan cualquier direccion
    if (Vertices[0].y > Vertices[perfil-1].y)
        reverse(Vertices.begin(), Vertices.end());
    else if (Vertices[0].y == Vertices[perfil-1].y && Vertices[0].x < Vertices[perfil-1].x)
        reverse(Vertices.begin(), Vertices.end());

    // Generar los Vertices
    for (int i = 0; i < n; i++){

        for (int j = 0; j < perfil; j++) {

            float radio = Vertices[j].x;

            vertice_aux.x = radio * cos(angulo);
            vertice_aux.z = radio * -sin(angulo);
            vertice_aux.y = Vertices[j].y;
            Vertices.push_back(vertice_aux);
        }

        angulo += (2 * M_PI) / n;
    }

    // Generar los Triangulos

    int num_puntos = Vertices.size();
    Triangles.resize(num_puntos * 2);
    int indice = 0;

    for (int i = 0; i < num_puntos - 1; i++){
        Triangles[indice] = _vertex3ui(i, (i + perfil)%num_puntos, i+1); indice++;
        Triangles[indice] = _vertex3ui(i+1, (i + perfil)%num_puntos, (i + perfil + 1)%num_puntos); indice++;
    }
}




    /*
    _vertex3f aux;


    int inicial = 45;
    int final = 120;

    //Ángulo en el que comienza
    //double angulo_inicial = (inicial*M_PI)/180;
    //número de veces a incrementar (120 es el angulo final y 45 el inicial)
    //double new_angulo = (((final-inicial)*M_PI)/180)/num_caras;

    //360 grados
    double angulo_inicial = (2 * M_PI)/n;
    double new_angulo = (2 * M_PI)/n;

    int tamanio = Vertices.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < tamanio;j++){
            aux.x =  Vertices[j].x * cos(angulo_inicial);
            aux.z =  Vertices[j].x * sin(angulo_inicial);
            aux.y  = Vertices[j].y;
            Vertices.push_back(aux);
        }
        angulo_inicial += new_angulo;
    }

    int indice=0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < tamanio - 1; j++){
            indice = (i * tamanio) + j; // Numero de caras
            Triangles.push_back(_vertex3ui(indice,indice+tamanio,indice+1)); //Caras superiores
            Triangles.push_back(_vertex3ui(indice+1,indice+tamanio,indice+1+tamanio)); //Caras inferiores
        }

    }*/

