#ifndef PLANE_H
#define PLANE_H

#include "object3d.h"

class plane : public _object3D
{
public:
    plane(float Size=1.0){
        Vertices[0] = _vertex3f(-Size/2,-Size/2, 0);
        Vertices[1] = _vertex3f(Size/2,-Size/2, 0);
        Vertices[2] = _vertex3f(-Size/2,Size/2, 0);
        Vertices[3] = _vertex3f(Size/2,Size/2, 0);

        Triangles.resize(2);

        Triangles[0] = _vertex3ui(0,1,2);
        Triangles[1] = _vertex3ui(1,3,2);

        Vertices_texcoord.resize(4);
        Vertices_texcoord[0] = _vertex2f(0,0);
        Vertices_texcoord[1] =_vertex2f(1,0);
        Vertices_texcoord[2] =_vertex2f(0,1);
        Vertices_texcoord[3] =  _vertex2f(1,1);

        //compute_triangles_normals();
    };

};

#endif // PLANE_H
