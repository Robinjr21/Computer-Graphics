#ifndef PLATFORM_H
#define PLATFORM_H

#include "cube.h"
#include "wheels_axis.h"
#include "doorM.h"
#include "puerta.h"

class platform
{
public:
    platform(cube &Cube, wheels_axis &Wheel_axis,puerta &door, doorM &doorM);

    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void increase_angle(){
        if(DoorM->getDisp() && disp){
            DoorM->crece();
        }
        if(!disp){
            if(angle < 1)
                angle+= v;
            if(angle >= 1){
                disp = true;

            }
        }

    };


    void decrease_angle(){
        if(!DoorM->getDisp()){
            DoorM->decrece();
        }
        if(disp && DoorM->getDisp()){
            if(angle > -100)
                angle-= v;
            if(angle <= -100){
                disp = false;
            }
        }

    };

    wheels_axis &getWheelAxis(){return *Wheel_axis;};

    void setDisp(bool valor){disp = valor;};

    bool getDisp(){return (disp);};

    void speedUp(){if(v < 5) v+=0.1;};
    void speedDown(){if(v > 0) v-=0.1;};

    bool puedeAcelerar(){return v <= 0;};
    bool puedeDesacelerar(){return v >= 5;};

    void compute_triangle_normals();
    void compute_vertex_normals();
    void draw_lighting_smooth();
    void drawlighting_flat();

protected:
    cube *Cube;
    wheels_axis *Wheel_axis;
    doorM *DoorM;
    puerta *Door;

    float angle = 0, v = 1;
    bool disp = false;
};

#endif // PLATFORM_H
