#include "_ply.h"

_ply::_ply(float Size, const string &File)
{
    vector<float> Coordinates;
    vector<unsigned int> Positions;
    int pos = 0;
    _file_ply ply2;

    if( ply2.open(File) == 1){

        ply2.read(Coordinates, Positions);

        Vertices.resize(Coordinates.size()/3);

        for(unsigned int i = 0; i< Coordinates.size(); i+=3){

            Vertices[pos++] = _vertex3f(Coordinates[i], Coordinates[i+1], Coordinates[i+2]);
        }

        Triangles.resize(Positions.size()/2);

        pos = 0;
        for(unsigned int i = 0; i < Positions.size(); i+=3){

            Triangles[pos++] = _vertex3ui(Positions[i], Positions[i+1], Positions[i+2]);
        }

        ply2.close();
    }

    compute_triangles_normals();
    compute_vertices_normals();
}
