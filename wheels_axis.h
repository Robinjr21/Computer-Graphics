#ifndef WHEELS_AXIS_H
#define WHEELS_AXIS_H

#include "wheel.h"


class wheels_axis
{
public:

    wheels_axis(_cylinder &Cylinder1, wheel &Wheel1);
    wheels_axis();

    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void increase_angle(){Angulo++;}
    void decrease_angle(){Angulo--;}

    void computeTriangleNormals();
    void computeVertexNormals();
    void drawSmooth();
    void drawFlat();
protected:
    _cylinder *Cylinder;
    wheel *Wheel;

    float Angulo = 0;
};

#endif // WHEELS_AXIS_H
