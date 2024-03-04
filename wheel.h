#ifndef WHEEL_H
#define WHEEL_H

#include "cylinder.h"

class wheel
{
public:
    wheel(_cylinder &Cylinder1);
    wheel();

    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void computeTriangleNormals();
    void computeVertexNormals();
    void draw_lighting_smooth();
    void drawlighting_flat();


protected:
    _cylinder *Cylinder;

    float Angulo = 0;
};

#endif // WHEEL_H
