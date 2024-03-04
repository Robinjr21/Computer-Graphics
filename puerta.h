#ifndef PUERTA_H
#define PUERTA_H

#include "cube.h"

class puerta
{
public:
    puerta(cube &Cube1);

    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void computeTriangleNormals();
    void computeVertexNormals();
    void draw_lighting_smooth();
    void drawlighting_flat();

protected:
    cube *Cube;

    float Angulo = 0;
};

#endif // PUERTA_H
