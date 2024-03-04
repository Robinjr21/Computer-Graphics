#include "cone.h"

_cone::_cone()
{
    Vertices.resize(3);

    Vertices[0] = _vertex3f(0,-0.5,0);
    Vertices[1] = _vertex3f(0.5,-0.5,0);
    Vertices[2] = _vertex3f(0,0.5,0);

    revolution(90);
    compute_triangles_normals();
    compute_vertices_normals();
}
