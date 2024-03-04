#ifndef REVOLUTIONOBJECT_H
#define REVOLUTIONOBJECT_H

#include "object3d.h"
#include <GL/gl.h>

class revolutionObject :public _object3D
{
public:
    void revolution(const int &n);
};

#endif // REVOLUTIONOBJECT_H
