#include "truck.h"

truck::truck(platform &platform, chasis &chasis, cube &cube){
    Platform = &platform;
    Chasis = &chasis;
    Cube = &cube;
    activo = false;
    angR = false;
}


void truck::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0.15,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    Platform->draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0, 1 ,0);
    glTranslatef(0,0,-0.5);
    glTranslatef(0,0,pos);
    Chasis->draw_chess();
    glPopMatrix();
}
/*
void truck::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_chess();
    glPopMatrix();

}*/

void truck::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0.15,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    Platform->draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0, 1 ,0);
    glTranslatef(0,0,-0.5);
    glTranslatef(0,0,pos);
    Chasis->draw_fill();
    glPopMatrix();
}

void truck::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0.15,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    Platform->draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0, 1 ,0);
    glTranslatef(0,0,-0.5);
    glTranslatef(0,0,pos);
    Chasis->draw_line();
    glPopMatrix();
}

void truck::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0.15,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    Platform->draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0, 1 ,0);
    glTranslatef(0,0,-0.5);
    glTranslatef(0,0,pos);
    Chasis->draw_point();
    glPopMatrix();
}

void truck::compute_triangle_normals(){
    Cube->compute_triangles_normals();
    Platform->compute_triangle_normals();
    Chasis->compute_triangle_normals();
}

void truck::compute_vertex_normals(){
    Cube->compute_vertices_normals();
    Platform->compute_vertex_normals();
    Chasis->compute_vertex_normals();
}

void truck::draw_lighting_flat(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0.15,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_lighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    Platform->drawlighting_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0, 1 ,0);
    glTranslatef(0,0,-0.5);
    glTranslatef(0,0,pos);
    Chasis->draw_lighting_flat();
    glPopMatrix();
}

void truck::draw_lighting_smooth(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0,1,0);
    glScalef(1,1,pos);
    glTranslatef(0,0.15,0.5);
    glScalef(0.2,0.1,1);
    Cube->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    Platform->draw_lighting_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,av);
    glTranslatef(0,0,1.5);
    glRotatef(ang, 0, 1 ,0);
    glTranslatef(0,0,-0.5);
    glTranslatef(0,0,pos);
    Chasis->draw_lighting_smooth();
    glPopMatrix();
}
