#ifndef _PLY_H
#define _PLY_H

#include "object3d.h"
#include "_read_ply.h"

class _ply : public _object3D
{
public:
    _ply(float Size, const string &File);
};

#endif // _PLY_H
