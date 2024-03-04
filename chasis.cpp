#include "chasis.h"

chasis::chasis(cube &Cube, wheels_axis &Wheel_axis, puerta &Door)
{
    this->Cube = &Cube;
    this->Wheel_axis = &Wheel_axis;
    this->Door = &Door;
}

void chasis::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0, 1.3,1.3);
    glScalef(2,2.5,2);
    Cube->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.2);
    Wheel_axis->draw_point();
    glPopMatrix();
}

void chasis::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0, 1.3,1.3);
    glScalef(2,2.5,2);
    Cube->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.2);
    Wheel_axis->draw_line();
    glPopMatrix();
}

void chasis::draw_fill(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0, 1.3,1.3);
    glScalef(2,2.5,2);
    Cube->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.2);
    Wheel_axis->draw_fill();
    glPopMatrix();
}

void chasis::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0, 1.3,1.3);
    glScalef(2,2.5,2);
    Cube->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.2);
    Wheel_axis->draw_chess();
    glPopMatrix();
}

void chasis::compute_triangle_normals(){
    Cube->compute_triangles_normals();
    Wheel_axis->computeTriangleNormals();
}

void chasis::compute_vertex_normals(){
    Cube->compute_vertices_normals();
    Wheel_axis->computeVertexNormals();
}

void chasis::draw_lighting_flat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0, 1.3,1.3);
    glScalef(2,2.5,2);
    Cube->draw_lighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.2);
    Wheel_axis->drawFlat();
    glPopMatrix();
}

void chasis::draw_lighting_smooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0, 1.3,1.3);
    glScalef(2,2.5,2);
    Cube->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.2);
    Wheel_axis->drawSmooth();
    glPopMatrix();
}
