#include "platform.h"

platform::platform(cube &Cube1, wheels_axis &Wheel_axis1,puerta &door, doorM &doorM){
    Cube = &Cube1;
    Wheel_axis = &Wheel_axis1;
    Door = &door;
    DoorM = &doorM;
}

void platform::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    //glRotatef (90, 0, 0, 1);
    glTranslatef(0,0.15,0);
    glScalef(2, 0.25, 3);
    Cube->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    Wheel_axis->draw_point();
    glPopMatrix();

    /*glPushMatrix();
    glTranslatef(0, 0, 1.5);
    glRotatef(Angulo, 1,0,0);
    Wheel_axis.draw_point();
    glPopMatrix();
    */
    glPushMatrix();
    glTranslatef(0.88, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.87, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, +0.25, -1.4);
    glRotatef(angle, 1,0,0);
    glTranslatef(0, -0.25, +1.4);
    DoorM->draw_point();
    glPopMatrix();
}

void platform::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    //glRotatef (90, 0, 0, 1);
    glTranslatef(0,0.15,0);
    glScalef(2, 0.25, 3);
    Cube->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    Wheel_axis->draw_chess();
    glPopMatrix();
    /*
    glPushMatrix();
    glTranslatef(0, 0, 1.5);
    glRotatef(Angulo, 1,0,0);
    Wheel_axis.draw_chess();
    glPopMatrix();*/

    glPushMatrix();
    glTranslatef(0.88, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.87, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, +0.25, -1.4);
    glRotatef(angle, 1,0,0);
    glTranslatef(0, -0.25, +1.4);
    DoorM->draw_chess();
    glPopMatrix();
}

void platform::draw_line(){


    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    //glRotatef (90, 0, 0, 1);
    glTranslatef(0,0.15,0);
    glScalef(2, 0.25, 3);
    Cube->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    Wheel_axis->draw_line();
    glPopMatrix();
    /*
    glPushMatrix();
    glTranslatef(0, 0, 1.5);
    glRotatef(Angulo, 1,0,0);
    Wheel_axis.draw_line();
    glPopMatrix();*/

    glPushMatrix();
    glTranslatef(0.88, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.87, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, +0.25, -1.4);
    glRotatef(angle, 1,0,0);
    glTranslatef(0, -0.25, +1.4);
    DoorM->draw_line();

    glPopMatrix();
}

void platform::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    //glRotatef (90, 0, 0, 1);
    glTranslatef(0,0.15,0);
    glScalef(2, 0.25, 3);
    Cube->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    Wheel_axis->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.87, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, +0.25, -1.4);
    glRotatef(angle, 1,0,0);
    glTranslatef(0, -0.25, +1.4);
    DoorM->draw_fill();
    glPopMatrix();
}


void platform::compute_triangle_normals(){
    Cube->compute_triangles_normals();
    Wheel_axis->computeTriangleNormals();
    Door->computeTriangleNormals();
}

void platform::compute_vertex_normals(){
    Cube->compute_vertices_normals();
    Wheel_axis->computeVertexNormals();
    Door->computeVertexNormals();
}

void platform::drawlighting_flat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    //glRotatef (90, 0, 0, 1);
    glTranslatef(0,0.15,0);
    glScalef(2, 0.25, 3);
    Cube->draw_lighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    Wheel_axis->drawFlat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->drawlighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.87, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->drawlighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, +0.25, -1.4);
    glRotatef(angle, 1,0,0);
    glTranslatef(0, -0.25, +1.4);
    DoorM->draw_lighting_flat();
    glPopMatrix();
}

void platform::draw_lighting_smooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(Angulo, 1,0,0);
    //glRotatef (90, 0, 0, 1);
    glTranslatef(0,0.15,0);
    glScalef(2, 0.25, 3);
    Cube->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    Wheel_axis->drawSmooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.87, 1.25, -1.25);
    glRotatef(90, 0,0,1);
    glRotatef(90, 1,0,0);
    Door->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, +0.25, -1.4);
    glRotatef(angle, 1,0,0);
    glTranslatef(0, -0.25, +1.4);
    DoorM->draw_lighting_smooth();
    glPopMatrix();
}
