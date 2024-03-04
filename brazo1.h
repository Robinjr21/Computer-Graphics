#ifndef BRAZO1_H
#define BRAZO1_H

#include "cube.h"

class brazo1
{
public:
    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void increase_angle(){Angulo++;}
    void decrease_angle(){Angulo--;}
protected:
    cube Cubo;

    float Angulo = 0;
};

#endif // BRAZO1_H
