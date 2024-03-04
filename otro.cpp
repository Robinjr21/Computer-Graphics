#include "otro.h"

otro::otro(float Size){
    Vertices.resize(16);

    Vertices[0]=_vertex3f(-Size/2, Size/2, -Size/2);
    Vertices[1]=_vertex3f(Size/2, Size/2, -Size/2);
    Vertices[2]=_vertex3f(-Size/2, Size/2, Size/2);
    Vertices[3]=_vertex3f(Size/2, Size/2, Size/2);

    Vertices[4]=_vertex3f(-Size/2, -Size/2, -Size/2);
    Vertices[5]=_vertex3f(Size/2, -Size/2, -Size/2);
    Vertices[6]=_vertex3f(-Size/2, -Size/2, Size/2);
    Vertices[7]=_vertex3f(Size/2, -Size/2, Size/2);

    Vertices[8]=_vertex3f(-Size, Size, -Size);
    Vertices[9]=_vertex3f(Size, Size, -Size);
    Vertices[10]=_vertex3f(-Size, Size, Size);
    Vertices[11]=_vertex3f(Size, Size, Size);

    Vertices[12]=_vertex3f(-Size, -Size, -Size);
    Vertices[13]=_vertex3f(Size, -Size, -Size);
    Vertices[14]=_vertex3f(-Size, -Size, Size);
    Vertices[15]=_vertex3f(Size, -Size, Size);

    Triangles.resize(12);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(2,1,3);
    Triangles[2]=_vertex3ui(0,1,4);
    Triangles[3]=_vertex3ui(4,1,5);
    Triangles[4]=_vertex3ui(4,2,0);
    Triangles[5]=_vertex3ui(6,4,2);
    Triangles[6]=_vertex3ui(2,6,7);
    Triangles[7]=_vertex3ui(2,3,7);
    Triangles[8]=_vertex3ui(5,7,1);
    Triangles[9]=_vertex3ui(7,1,3);
    Triangles[10]=_vertex3ui(7,5,6);
    Triangles[11]=_vertex3ui(5,6,4);

}
