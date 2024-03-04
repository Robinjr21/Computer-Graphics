#ifndef TRUCK_H
#define TRUCK_H

#include "platform.h"
#include "chasis.h"

class truck
{
public:
    truck(platform &platform, chasis &chasis, cube &cube);

    truck();

    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();


    void trasladaD(){
        if(pos < 5){
            pos += incPos;
            if(pos >=5){
                move = false;
            }
        }
    }

    void trasladaA(){
        if(pos > 1.6 && ang != 0){
            pos -= incPos;
        }else if( ang == 0 && pos >0){
            pos -= incPos;
        }

        if((pos <=0) || (ang != 0 && pos <= 1.6))move=true;
    }

    void rotacionD(){
        if(ang < 80){
            ang += incAng;
        }
        if(ang >= 80){
            angR = false;
        }
    }

    void rotacionI(){
        if(ang > -80){
            ang -= incAng;
        }
        if(ang <= -80)angR=true;
    }

    bool getAngR(){return angR;};
    bool getMov(){return move;};

    void speedUpR(){if(incAng < 10) incAng+=2;};
    void speedDownR(){if(incAng > 1) incAng -= 2;
        else if(incAng <= 1 && incAng > 0)incAng-=0.1;};

    void speedUpT(){if(incPos < 2)incPos += 0.1;};
    void speedDownT(){if(incPos > 0)incPos -= 0.1;};

    void compute_triangle_normals();
    void compute_vertex_normals();
    void draw_lighting_smooth();
    void draw_lighting_flat();

protected:
    platform *Platform;
    chasis *Chasis;
    cube *Cube;
    bool activo, angR = true, move = true;
    bool ad = true;

    float pos = 0, ang = 0;

    float av = 0, incAv = 0.1,incPos=0.1, incAng=1;
};

#endif // TRUCK_H
