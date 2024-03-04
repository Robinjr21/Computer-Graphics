/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Tiene un comportamiento por defecto
    glBegin(GL_TRIANGLES);
    glColor3fv((GLfloat *) &RED);

    for (unsigned int i=0;i<Triangles.size();i++){     
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }


    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    glColor3fv((GLfloat *) &YEllOW);

    for (unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){

        if(i%2 == 0) glColor3fv((GLfloat *) &GREEN);
        else glColor3fv( (GLfloat *) &BLUE);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/
void _object3D::compute_triangles_normals(){

    _vertex3f A,B,C;
    Triangles_normals.resize(Triangles.size());

    for(unsigned int i = 0;  i < Triangles.size(); i++){
        //Calculamos la normal
        A = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
        B = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];
        C = A.cross_product(B);
        Triangles_normals[i] = C.normalize();

    }
}

void _object3D::compute_vertices_normals() {
    // Inicializamos las normales de los vértices a cero
    Vertices_normals.resize(Vertices.size());

    vector<float> contador;
    contador.resize(Vertices.size());

    // Iteramos sobre todos los triángulos
    for (unsigned int i = 0; i < Triangles.size(); i++) {

        _vertex3f triangle_normal = Triangles_normals[i];

        Vertices_normals[Triangles[i]._0] += triangle_normal;
        contador[Triangles[i]._0] += 1;
        Vertices_normals[Triangles[i]._1] += triangle_normal;
        contador[Triangles[i]._1] += 1;
        Vertices_normals[Triangles[i]._2] += triangle_normal;
        contador[Triangles[i]._2] += 1;
    }

    // Normalizamos las normales de los vértices
    for (unsigned int i = 0; i < Vertices_normals.size(); i++) {
        if(contador[i] != 0){
            Vertices_normals[i] /= contador[i];
            Vertices_normals[i].normalize();
        }
    }
}
/*
void _object3D::compute_vertices_normals() {
    // Inicializamos las normales de los vértices a cero
    Vertices_normals.resize(Vertices.size(), _vertex4f(0,0,0,0));

    // Iteramos sobre todos los triángulos
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        Vertices_normals[Triangles[i]._0] += Triangles_normals[i];
        Vertices_normals[Triangles[i]._1] += Triangles_normals[i];
        Vertices_normals[Triangles[i]._2] += Triangles_normals[i];
        Vertices_normals[Triangles[i]._0]._3 += 1;
        Vertices_normals[Triangles[i]._1]._3 += 1;
        Vertices_normals[Triangles[i]._2]._3 += 1;
    }

    // Normalizamos las normales de los vértices
    for (unsigned int i = 0; i < Vertices_normals.size(); i++) {
        if(Vertices_normals[i]._3 != 0){
            Vertices_normals[i] /= Vertices_normals[i]._3;
            Vertices_normals[i].normalize();
        }
    }
}*/




 // Crear método draw_lighting_flat en cada objeto
 // Para eso hay que mandarle a openGL la luz, el material
 // y las normales, una por triángulo
void _object3D::draw_lighting_flat()
{

    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
        glNormal3fv((GLfloat *) &Triangles_normals[i]);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
}

void _object3D::draw_lighting_smooth() {

    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT, GL_FILL);
    //glEnable(GL_COLOR_MATERIAL);
    //glColor3f( 0,  0 ,0  );

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        //glNormal3fv((GLfloat *) &Triangles_normals[i]);

        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);


        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
}

void _object3D::draw_texture(){
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0;i<Triangles.size();i++){
        //glTexCoord2fv();
        glTexCoord2f(Vertices_texcoord[Triangles[i]._0].x, Vertices_texcoord[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

        glTexCoord2f(Vertices_texcoord[Triangles[i]._1].x, Vertices_texcoord[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glTexCoord2f(Vertices_texcoord[Triangles[i]._2].x, Vertices_texcoord[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void _object3D::set_texture(QString file){
    QString File_name(file);
    QImage Image;
    QImageReader Reader(File_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();
    if (Image.isNull()) {
        /*
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
        */
        exit(-1);
    }
    Image=Image.mirrored();
    Image=Image.convertToFormat(QImage::Format_RGB888);
    // Code to control the application of the texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Code to pass the image to OpenGL to form a texture 2D
    glTexImage2D(GL_TEXTURE_2D,0,4,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
}

/*
void _object3D::esmeraldMaterial(){

    //El cuarto valor representa la opacidad del color,
    //controla la transparencia del material en el modelo RGBA
    GLfloat ambient[]={0.0215, 0.1745, 0.0215, 1.0},
        diffuse[]={0.07568, 0.61424, 0.07568, 1.0},
        specular[]={0.633, 0.727811, 0.633, 1.0},
        shininess= 0.6;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void _object3D::rubyMaterial(){

    GLfloat ambient[]={0.1745, 0.01175, 0.01175, 1.0},
        diffuse[]={0.61424, 0.04136, 0.04136, 1.0},
        specular[]={0.727811, 0.626959, 0.626959, 1.0},
        shininess= 0.6;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void _object3D::goldMaterial(){
    GLfloat ambient[]={0.24725, 0.1995, 0.0745, 1.0},
        diffuse[]={0.75164, 0.60648, 0.22648, 1.0},
        specular[]={0.628281, 0.555802, 0.366065, 1.0},
        shininess= 0.4;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
*/

