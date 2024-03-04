#include "puerta.h"

puerta::puerta(cube &Cubo1){
    Cube = &Cubo1;
}

void puerta::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glTranslatef(0, 1.25, 0);
    glScalef(2, 2.5, 0.25);
    Cube->draw_point();
    glPopMatrix();
}

void puerta::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glTranslatef(0, 1.25, 0);
    glScalef(2, 2.5, 0.25);
    Cube->draw_line();
    glPopMatrix();
}

void puerta::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glTranslatef(0, 1.25, 0);
    glScalef(2, 2.5, 0.25);
    Cube->draw_chess();
    glPopMatrix();
}

void puerta::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glTranslatef(0, 1.25, 0);
    glScalef(2, 2.5, 0.25);
    Cube->draw_fill();
    glPopMatrix();
}

void puerta::computeTriangleNormals(){
    Cube->compute_triangles_normals();
}

void puerta::computeVertexNormals(){
    Cube->compute_vertices_normals();
}

void puerta::drawlighting_flat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glTranslatef(0, 1.25, 0);
    glScalef(2, 2.5, 0.25);
    Cube->draw_lighting_flat();
    glPopMatrix();
}

void puerta::draw_lighting_smooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glTranslatef(0, 1.25, 0);
    glScalef(2, 2.5, 0.25);
    Cube->draw_lighting_smooth();
    glPopMatrix();
}
