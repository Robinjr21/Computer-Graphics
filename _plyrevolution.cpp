#include "_plyrevolution.h"

_plyRevolution::_plyRevolution(const string &File)
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

        revolution(30);

        ply2.close();
    }

    compute_triangles_normals();
    compute_vertices_normals();
}
