#include "revolution2object.h"

revolution2object::revolution2object(const int &n)
{
    _vertex3f aux;
    double angulo_inicial = (2.0 * M_PI) / n;
    double new_angulo = (2.0 * M_PI) / n;
    int tamanio = Vertices.size();

    int newN = n - 1; // Para evitar repetir los primeros vértices

    std::vector<_vertex3f> centralZone;
    centralZone.resize(tamanio + ((tamanio - 2) * newN));
    _vertex3f up, low;

    int pos = 0;

    // Extraer los vértices de la zona central


    for (int i = 0; i < tamanio; i++) {
        if (Vertices[i].x != 0.0f || Vertices[i].z != 0.0f) {
            centralZone[pos++] = Vertices[i];
        } else if (Vertices[i].x == 0.0f && Vertices[i].z == 0.0f && Vertices[i].y > 0.0f) {
            up = Vertices[i];
        } else {
            low = Vertices[i];
        }
    }

    tamanio = tamanio - 2;

    // Generar los vértices de la curva generatriz de la zona central
    for (int i = 0; i < newN; i++) {
        for (int j = 0; j < tamanio; j++) {
            float r = centralZone[j].x;
            aux.x = r * cos(angulo_inicial);
            aux.z = -r * sin(angulo_inicial);
            aux.y = centralZone[j].y;
            centralZone[pos++] = aux;
        }
        angulo_inicial += new_angulo;
    }


    centralZone[pos++] = low;
    centralZone[pos++] = up;

    std::cout << "Pos: " << pos << std::endl;
    std::cout << "Size: " << centralZone.size() << std::endl;
    Vertices = centralZone;

    std::cout << "Vertices size: " << Vertices.size() << std::endl;

    // Generar los triángulos

    std::cout << "POINTS TAPAS: " << std::endl;

    int tamSinT = Vertices.size() - 2;

    for (int row = 0; row < newN + 1; row++) {
        for (int col = 0; col < tamanio; col++) {
            int point = (row * tamanio) + col;
            std::cout << point << " ";

            if (point % 2 == 0) {
                Triangles.push_back(_vertex3ui(point % tamSinT, Vertices.size() - 2, (point + tamanio) % tamSinT));
            } else {
                Triangles.push_back(_vertex3ui(point % tamSinT, (point + tamanio) % tamSinT, Vertices.size() - 1));
            }
        }
    }

    std::cout << "\nPOINTS CARAS: " << std::endl;

    for (int row = 0; row < newN + 1; row++) {
        for (int col = 0; col < tamanio; col++) {
            int indice = (row * tamanio) + col;
            std::cout << indice << " ";

            Triangles.push_back(_vertex3ui(indice % tamSinT, (indice + tamanio) % tamSinT, (indice + 1) % tamSinT)); // Cara impar
            Triangles.push_back(_vertex3ui((indice + 1) % tamSinT, (indice + tamanio) % tamSinT, (indice + 1 + tamanio) % tamSinT));
        }
    }

}

/*
    _vertex3f aux;
    double angulo_inicial = (2.0 * M_PI) / n;
    double new_angulo = (2.0 * M_PI) / n;
    int tamanio = Vertices.size();

    int newN = n - 1; // Para evitar repetir los primeros vértices

    std::vector<_vertex3f> centralZone;
    centralZone.resize(tamanio + ((tamanio - 2) * newN));
    _vertex3f up, low;

    int pos = 0;

    // Extraer los vértices de la zona central


    for (int i = 0; i < tamanio; i++) {
        if (Vertices[i].x != 0.0f || Vertices[i].z != 0.0f) {
            centralZone[pos++] = Vertices[i];
        } else if (Vertices[i].x == 0.0f && Vertices[i].z == 0.0f && Vertices[i].y > 0.0f) {
            up = Vertices[i];
        } else {
            low = Vertices[i];
        }
    }

    tamanio = tamanio - 2;

    // Generar los vértices de la curva generatriz de la zona central
    for (int i = 0; i < newN; i++) {
        for (int j = 0; j < tamanio; j++) {
            float r = centralZone[j].x;
            aux.x = r * cos(angulo_inicial);
            aux.z = -r * sin(angulo_inicial);
            aux.y = centralZone[j].y;
            centralZone[pos++] = aux;
        }
        angulo_inicial += new_angulo;
    }


    centralZone[pos++] = low;
    centralZone[pos++] = up;

    std::cout << "Pos: " << pos << std::endl;
    std::cout << "Size: " << centralZone.size() << std::endl;
    Vertices = centralZone;

    std::cout << "Vertices size: " << Vertices.size() << std::endl;

    // Generar los triángulos

    std::cout << "POINTS TAPAS: " << std::endl;

    int tamSinT = Vertices.size() - 2;

    for (int row = 0; row < newN + 1; row++) {
        for (int col = 0; col < tamanio; col++) {
            int point = (row * tamanio) + col;
            std::cout << point << " ";

            if (point % 2 == 0) {
                Triangles.push_back(_vertex3ui(point % tamSinT, Vertices.size() - 2, (point + tamanio) % tamSinT));
            } else {
                Triangles.push_back(_vertex3ui(point % tamSinT, (point + tamanio) % tamSinT, Vertices.size() - 1));
            }
        }
    }

    std::cout << "\nPOINTS CARAS: " << std::endl;

    for (int row = 0; row < newN + 1; row++) {
        for (int col = 0; col < tamanio; col++) {
            int indice = (row * tamanio) + col;
            std::cout << indice << " ";

            Triangles.push_back(_vertex3ui(indice % tamSinT, (indice + tamanio) % tamSinT, (indice + 1) % tamSinT)); // Cara impar
            Triangles.push_back(_vertex3ui((indice + 1) % tamSinT, (indice + tamanio) % tamSinT, (indice + 1 + tamanio) % tamSinT));
        }
    }
*/
