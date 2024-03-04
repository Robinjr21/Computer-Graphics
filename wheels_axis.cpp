#include "wheels_axis.h"

wheels_axis::wheels_axis(_cylinder &Cylinder1, wheel &Wheel1){
    Cylinder = &Cylinder1;
    Wheel = &Wheel1;
}

void wheels_axis::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glRotatef (90, 0, 0, 1);
    glScalef(0.15, 3, 0.15);
    Cylinder->draw_point();
    glPopMatrix();


    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(-1.5, 0, 0);
    Wheel->draw_point();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(1.5, 0, 0);
    Wheel->draw_point();
    glPopMatrix();
}

void wheels_axis::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glRotatef (90, 0, 0, 1);
    glScalef(0.15, 3, 0.15);
    Cylinder->draw_line();
    glPopMatrix();


    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(-1.5, 0, 0);
    Wheel->draw_line();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(1.5, 0, 0);
    Wheel->draw_line();
    glPopMatrix();
}

void wheels_axis::draw_fill(){
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glRotatef (90, 0, 0, 1);
    glScalef(0.15, 3, 0.15);
    Cylinder->draw_fill();
    glPopMatrix();


    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(-1.5, 0, 0);
    Wheel->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(1.5, 0, 0);
    Wheel->draw_fill();
    glPopMatrix();
}

void wheels_axis::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glRotatef (90, 0, 0, 1);
    glScalef(0.15, 3, 0.15);
    Cylinder->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(-1.5, 0, 0);
    Wheel->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(1.5, 0, 0);
    Wheel->draw_chess();
    glPopMatrix();
}

void wheels_axis::computeTriangleNormals(){
    Cylinder->compute_triangles_normals();
    Wheel->computeTriangleNormals();
}

void wheels_axis::computeVertexNormals(){
    Cylinder->compute_vertices_normals();
    Wheel->computeVertexNormals();
}

void wheels_axis::drawFlat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glRotatef (90, 0, 0, 1);
    glScalef(0.15, 3, 0.15);
    Cylinder->draw_lighting_flat();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(-1.5, 0, 0);
    Wheel->drawlighting_flat();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(1.5, 0, 0);
    Wheel->drawlighting_flat();
    glPopMatrix();
}

void wheels_axis::drawSmooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glRotatef (90, 0, 0, 1);
    glScalef(0.15, 3, 0.15);
    Cylinder->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(-1.5, 0, 0);
    Wheel->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Angulo, 1,0,0);
    glTranslatef(1.5, 0, 0);
    Wheel->draw_lighting_smooth();
    glPopMatrix();
}
