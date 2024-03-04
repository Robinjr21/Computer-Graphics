#include "revolutionobject.h"
#include <cmath>
#include <algorithm>
#include <iostream>

void revolutionObject::revolution(const int &n)
{
    _vertex3f aux;
    /*Para 270º
    double angulo_inicial = (3.0 * M_PI) / 2 /(n-1) ;
    double new_angulo = (3.0 * M_PI) / 2 / (n-1);
    
    Para 180º
    double angulo_inicial = (M_PI) /(n-1) ;
    double new_angulo = (M_PI) / (n-1);*/
    
    
    int tamanio = Vertices.size();
    Triangles.resize(n * tamanio * 2);


    int newN = n - 1; // Para evitar repetir los primeros vértices

    bool invertido = false;

    if (Vertices[0].y > Vertices[Vertices.size() - 1].y) {
        invertido = true;
        if (invertido) {
            std::reverse(Vertices.begin(), Vertices.end());
        }
    }

    std::vector<_vertex3f> centralZone;
    centralZone.resize(tamanio + ((tamanio - 2) * (n - 1)));
    _vertex3f up, low;
    int pos = 0;

    for (int i = 0; i < tamanio; i++) {
        if (Vertices[i].x != 0.0f || Vertices[i].z != 0.0f) {
            centralZone[pos++] = Vertices[i];
        } else if (Vertices[i].x == 0.0f && Vertices[i].z == 0.0f && Vertices[i].y > 0.0f) {
            up = Vertices[i];
        } else {
            low = Vertices[i];
        }
    }

    bool tieneCara = (pos > 1);

    tamanio = pos;

    for (int i = 0; i < newN; i++) {
        for (int j = 0; j < tamanio; j++) {
            float r = centralZone[j].x;

            aux.x = r * cos(angulo_inicial + i * new_angulo);  // Ajusta el ángulo aquí
            aux.z = -r * sin(angulo_inicial + i * new_angulo); // Ajusta el ángulo aquí
            aux.y = centralZone[j].y;

            centralZone[pos++] = aux;
        }
    }

    centralZone[pos++] = low;
    centralZone[pos++] = up;

    Vertices = centralZone;

    std::cout << "N puntos: " << Vertices.size() << endl;

    int posLow = Vertices.size() - 2;
    int posUp = Vertices.size() - 1;

    int indice = 0;

    int tamSinT = Vertices.size() - 2;

    pos = 0;
    if (tieneCara) {
        for (int row = 0; row < newN; row++) {
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
        for (int i = 0; i < newN ; i++) {
            Triangles[pos++] = _vertex3ui(i, posLow, (i + tamanio) % n);
            Triangles[pos++] = _vertex3ui(i, (i + tamanio) % n, posUp); // Cara impar
        }
    }
}


