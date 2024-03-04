#ifndef CHASIS_H
#define CHASIS_H

#include "cube.h"
#include "wheels_axis.h"
#include "puerta.h"

class chasis
{
public:
    chasis(cube &Cube1, wheels_axis &Wheel_axis1, puerta &Door1);
    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void compute_triangle_normals();
    void compute_vertex_normals();
    void draw_lighting_smooth();
    void draw_lighting_flat();

protected:
    cube *Cube;
    wheels_axis *Wheel_axis;
    puerta *Door;
};

#endif // CHASIS_H
