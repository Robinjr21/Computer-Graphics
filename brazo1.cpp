#include "brazo1.h"

void brazo1::draw_chess(){
    /* Hay tres pilas y OpenGL es una máquina de estados
    La última acción se guarda y se aplica a todas las demás
    funciones
    */

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(Angulo, 0,0,1);
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 0, 0, 1); // Ángulo 90, eje z --> (0,0,1)
    glScalef(1, 0.5, 0.5);
    Cubo.draw_chess();
    glPopMatrix();
}

void brazo1::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(Angulo, 0,0,1);
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 0, 0, 1); // Ángulo 90, eje z --> (0,0,1)
    glScalef(1, 0.5, 0.5);
    Cubo.draw_fill();
    glPopMatrix();
}

void brazo1::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(Angulo, 0,0,1);
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 0, 0, 1); // Ángulo 90, eje z --> (0,0,1)
    glScalef(1, 0.5, 0.5);
    Cubo.draw_point();
    glPopMatrix();
}

void brazo1::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(Angulo, 0,0,1);
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 0, 0, 1); // Ángulo 90, eje z --> (0,0,1)
    glScalef(1, 0.5, 0.5);
    Cubo.draw_line();
    glPopMatrix();
}
