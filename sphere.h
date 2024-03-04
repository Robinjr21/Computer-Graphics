#ifndef SPHERE_H
#define SPHERE_H

#include "revolutionobject.h"

class _sphere : public revolutionObject
{
public:
    _sphere();
    ~_sphere();

    //
    void compute_vertices_normals();
};

#endif // SPHERE_H
