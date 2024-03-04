#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "object3d.h"

class chess_board : public _object3D
{
public:
    chess_board(){};
    void initialize(float height=1, float width=1, int hCuts=1, int wCuts=1);
    void mapTexture(float xSize, float ySize);
};

#endif // CHESS_BOARD_H
