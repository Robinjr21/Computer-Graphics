#include "wheel.h"

wheel::wheel( _cylinder &Cylinder1){
    Cylinder = &Cylinder1;
}

void wheel::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glRotatef ( 90 , 0,0,1 );
    glScalef(1 ,0.5, 1);
    //glTranslatef(0, 0, 0);
    Cylinder->draw_point();

    glPopMatrix();
}

void wheel::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    //glRotatef(Angulo, 1,0,0);
    glRotatef ( 90 , 0,0,1 );
    glScalef(1 ,0.5, 1);
    //glTranslatef(0, 0, 0);
    Cylinder->draw_line();

    glPopMatrix();
}

void wheel::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    //glRotatef(Angulo, 1,0,0);
    glRotatef ( 90 , 0,0,1 );
    glScalef(1 ,0.5, 1);
    //glTranslatef(0, 0, 0);
    Cylinder->draw_fill();

    glPopMatrix();
}

void wheel::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glRotatef ( 90 , 0,0,1 );
    glScalef(1 ,0.5, 1);
    //glTranslatef(0, 0, 0);
    Cylinder->draw_chess();

    glPopMatrix();
}

void wheel::computeTriangleNormals(){
    Cylinder->compute_triangles_normals();
}

void wheel::computeVertexNormals(){
    Cylinder->compute_vertices_normals();
}

void wheel::drawlighting_flat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glRotatef ( 90 , 0,0,1 );
    glScalef(1 ,0.5, 1);
    //glTranslatef(0, 0, 0);
    Cylinder->draw_lighting_flat();

    glPopMatrix();
}

void wheel::draw_lighting_smooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    glRotatef ( 90 , 0,0,1 );
    glScalef(1 ,0.5, 1);
    //glTranslatef(0, 0, 0);
    Cylinder->draw_lighting_smooth();

    glPopMatrix();
}
