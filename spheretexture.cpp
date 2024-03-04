#include "spheretexture.h"

SphereTexture::SphereTexture()
{

}

/**
 * @brief Initialization of the Textured Sphere Class
 * @param radius    The desired radius of the Sphere. Default is 0,5.
 * @param vCuts     Total number of vertical cuts for the Sphere. Default is 20.
 * @param rCuts     Total number of horizontal cuts for the Sphere. Default is 20.
 */
void SphereTexture::initialize(float radius, int vCuts, int rCuts)
{
    // Check for correct inputs
    if( radius <= 0 )
    {
        cout<<"Sphere: Radius can't be zero or negative."<<endl;
        exit(1);
    }

    if( vCuts < 2 || rCuts < 3)
    {
        cout<<"Sphere: Erroneous number of cuts"<<endl;
        exit(1);
    }

    // Bottom of profile, left-most point.
    vector<_vertex3f> auxVer;

    // Originally, the top and bottom of the Sphere where in the auxVer so that it could reuse code of the _objRev class
    Vertices.push_back(_vertex3f(0, -radius, 0));


    // Circumference
    float alpha = (M_PI / vCuts);
    float newX, newY;

    for(int i = 1; i < vCuts; i++)
    {
        newX = Vertices[0].x * cos(alpha*i) - Vertices[0].y * sin(alpha*i);
        newY = Vertices[0].x * sin(alpha*i) + Vertices[0].y * cos(alpha*i);
        Vertices.push_back(_vertex3f(newX, newY, 0));
    }

    // Top of profile, left-most point.
    Vertices.push_back(_vertex3f(0, radius, 0));

    // Circular sweeping.
    //      [P4] New function that repeats points.
    this->rotation(rCuts);
    rCuts++;

    // Generating triangles.
    //      [P4] New function, removed the code to add the last set of triangles. It needs rCuts to be one more in order
    //      to handle the repeated vertices.
    this->genTriangles(rCuts);


    // [P4] Calculate the normals.
    this->calculateVertNormals();
    this->calculateTrigNormals();

    // [P4] Map the texture.
    this->mapTexture(rCuts);
}

/**
 * @brief Calculate the Vertex Normals of the Sphere.
 * @details It's easier to first calculate the Vertex Normals since each vertex
 *          already makes a vector from the origin to its position, it only needs to
 *          be normalized.
 */
void SphereTexture::calculateVertNormals()
{
    int vertSize = Vertices.size();

    Vertices_normals.resize(vertSize);

    for(auto i = 0; i < vertSize; i++)
    {
        Vertices_normals[i].x = Vertices[i].x;
        Vertices_normals[i].y = Vertices[i].y;
        Vertices_normals[i].z = Vertices[i].z;

        Vertices_normals[i].normalize();

    }
}

/**
 * @brief Calculate the Triangle Normals of the Sphere.
 * @details It's the average of the Vertex Normals of each Triangle.
 */
void SphereTexture::calculateTrigNormals()
{
    int trigSize = Triangles.size();
    Triangles_normals.resize(trigSize);

    for(auto i = 0; i < trigSize ; i++)
    {
        Triangles_normals[i].x = (Vertices_normals[Triangles[i]._0].x + Vertices_normals[Triangles[i]._1].x + Vertices_normals[Triangles[i]._2].x) / 3;
        Triangles_normals[i].y = (Vertices_normals[Triangles[i]._0].y + Vertices_normals[Triangles[i]._1].y + Vertices_normals[Triangles[i]._2].y) / 3;
        Triangles_normals[i].z = (Vertices_normals[Triangles[i]._0].z + Vertices_normals[Triangles[i]._1].z + Vertices_normals[Triangles[i]._2].z) / 3;

        Triangles_normals[i].normalize();
    }
}

/**
 * [P4]
 * @brief Modified _objRev::rotation() function in order to map the texture.
 * @param rCuts     Number of cuts of the radius.
 */
void SphereTexture::rotation(int rCuts)
{
    float alpha = 2*M_PI / rCuts;
    float newX, newZ;
    int plySizeVert = Vertices.size();

    // The loop makes one more pass in order to get repeated points at 360º/0º
    for(auto i = 1; i < rCuts + 1; i++)
    {
        for(auto j = 0; j < plySizeVert; j++)
        {
            newX = Vertices[j].x * cos(alpha*i);
            newZ = -Vertices[j].x * sin(alpha*i);
            Vertices.push_back(_vertex3f(newX, Vertices[j].y, newZ));
        }
    }
}

/**
 * [P4]
 * @brief Modified _objRev::genTriangles() function in order to map the texture.
 * @param rCuts     Number of cuts of the radius.
 */
void SphereTexture::genTriangles(int rCuts)
{
    int vertSize = Vertices.size();
    int plySizeVert = vertSize / rCuts;

    for(int j = 0; j < rCuts - 1; j++)
    {
        for(int i = 0; i < plySizeVert - 1; i++)
        {
            Triangles.push_back(_vertex3ui(i + j * plySizeVert, (i + (j+1) * plySizeVert), ((i+1) + (j+1) * plySizeVert)));
            Triangles.push_back(_vertex3ui(i + j * plySizeVert, ((i+1) + (j+1) * plySizeVert), (i+1) + j * plySizeVert));
        }
    }
}

/**
 * [P4]
 * @brief Mapping the texture to the Sphere.
 * @param rCuts     Number of cuts of the radius.
 */
void SphereTexture::mapTexture(int rCuts)
{
    int vertSize = Vertices.size();
    int plySizeVert = vertSize / rCuts;
    Vertices_texcoord.resize(vertSize);

    /*
     * To map the texture between [0,1] the texture coordinates of each point are calculated based on the number of radius cuts,
     * that can be thought of as the Longitude line that goes from North to South and the number of vertices in each line of Longitude.
     */
    for(int j = 0; j < rCuts; j++)
    {
        for(int i = 0; i < plySizeVert; i++)
        {
            Vertices_texcoord[i + ((plySizeVert) * j)] = _vertex2f( (1.0 / (rCuts - 1.0)) * (j), (1.0 / (plySizeVert - 1.0)) * (i) );
        }
    }
}
