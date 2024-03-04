#ifndef DOORM_H
#define DOORM_H

#include "puerta.h"

class doorM
{
public:
    doorM(puerta &puerta){DoorM = &puerta;};
    doorM();

    void draw_chess();
    void draw_fill();
    void draw_line();
    void draw_point();

    void crece(){
        if(disp){
            if(pos < 1)pos+=0.1;
            if(pos >= 1)disp = false;
            if(pos <= 0.1)disp = true;
        }
    };

    void decrece(){
        if(!disp){
            if(pos >0.1)pos-=0.1;
            if(pos >= 1)disp = false;
            if(pos <= 0.1)disp = true;
        }

    };

    bool getDisp(){return disp;};

    void setDisp(bool val){disp = val;};

    void computeTriangleNormals();
    void computeVertexNormals();
    void draw_lighting_smooth();
    void draw_lighting_flat();

protected:
    puerta *DoorM;
    float pos = 0.0f;
    bool disp = true;
};

#endif // DOORM_H
