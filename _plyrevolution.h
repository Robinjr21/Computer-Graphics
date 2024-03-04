#ifndef _PLYREVOLUTION_H
#define _PLYREVOLUTION_H

#include "object3d.h"
#include "_read_ply.h"
#include "revolutionobject.h"

class _plyRevolution : public revolutionObject
{
public:
    _plyRevolution(const string &File);
};

#endif // _PLYREVOLUTION_H
