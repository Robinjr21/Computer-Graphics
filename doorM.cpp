#include "doorM.h"

void doorM::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.40,-1.27);
    glScalef(1,1,pos);
    glRotatef(90, 1,0,0);
    DoorM->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.25, -1.4);
    glScalef(1,0.9,1);
    DoorM->draw_point();
    glPopMatrix();
}

void doorM::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.40,-1.27);
    glScalef(1,1,pos);
    glRotatef(90, 1,0,0);
    DoorM->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.25, -1.4);
    glScalef(1,0.9,1);
    DoorM->draw_line();
    glPopMatrix();
}

void doorM::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.40,-1.27);
    glScalef(1,1,pos);
    glRotatef(90, 1,0,0);
    DoorM->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.25, -1.4);
    glScalef(1,0.9,1);
    DoorM->draw_fill();
    glPopMatrix();
}

void doorM::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.40,-1.27);
    glScalef(1,1,pos);
    glRotatef(90, 1,0,0);
    DoorM->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.25, -1.4);
    glScalef(1,0.9,1);
    DoorM->draw_chess();
    glPopMatrix();
}

void doorM::computeTriangleNormals(){
    DoorM->computeTriangleNormals();
}

void doorM::computeVertexNormals(){
    DoorM->computeVertexNormals();
}

void doorM::draw_lighting_flat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.40,-1.27);
    glScalef(1,1,pos);
    glRotatef(90, 1,0,0);
    DoorM->drawlighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.25, -1.4);
    glScalef(1,0.9,1);
    DoorM->drawlighting_flat();
    glPopMatrix();
}

void doorM::draw_lighting_smooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.40,-1.27);
    glScalef(1,1,pos);
    glRotatef(90, 1,0,0);
    DoorM->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.25, -1.4);
    glScalef(1,0.9,1);
    DoorM->draw_lighting_smooth();
    glPopMatrix();
}


