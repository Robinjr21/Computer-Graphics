#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/gl.h>
#include "vertex.h"
#include "colors.h"
#define PI 3.14159265

class lights
{
private:
    //  Position of the 1st light at infinity.
    _vertex4f lightPos = _vertex4f{0, 50, 100, 0};

    //  Position of the 2nd light locally.
    _vertex4f lightPos2 = _vertex4f{0, 0, 5, 1};

    /*  Actual position of the 2nd light, so that it can be
         *  rotated relative to the original position.
         */
    _vertex4f actPos2 = _vertex4f{0, 0, 5, 1};
    float X = 0.0, Y = -1.0, Z = 1.0;
public:
    lights(){};
    void initialize();
    void FirstLight();
    void SecondLight();
    float getX();
    void increaseRotation();
    void decreaseRotation();
};

#endif // LIGHTS_H
