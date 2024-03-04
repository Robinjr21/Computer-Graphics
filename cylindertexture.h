#ifndef CYLINDERTEXTURE_H
#define CYLINDERTEXTURE_H

#include "revolutionobject.h"


class CylinderTexture : public revolutionObject
{
public:
    CylinderTexture();
    void initialize(float height = 1, float radius = 0.5, int hCuts = 1, int vCuts = 1, int rCuts = 3);
    void rotation(int rCuts);
    void genTriangles(int rCuts);
    void mapTexture(int rCuts, int hCuts, int vCuts);
};

#endif // CYLINDERTEXTURE_H
