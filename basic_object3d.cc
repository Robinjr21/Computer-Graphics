/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _basic_object3D::draw_point()
{
  glBegin(GL_POINTS);
  for (unsigned int i=0;i<Vertices.size();i++){
    //glVertex3fv((GLfloat *) &Vertices[i]);
    glVertex3f(Vertices[i].x, Vertices[i].y,Vertices[i].z);
  }
  glEnd();
}

/*
void _wire_object3D::draw_line()
{
  glBegin(GL_LINES);
  for (unsigned int i=0;i<Vertices.size();i++){
    //unsigned int Pos_v_ini=Edges[i]._0;
    //unsigned int Pos_v_ini=Edges[i]._1;

    glVertex3f(Vertices[Edges[i]._0].x,Vertices[Edges[i]._0].y, Vertices[Edges[i]._0].z);
    glVertex3f(Vertices[Edges[i]._1].x,Vertices[Edges[i]._1].y, Vertices[Edges[i]._1].z);
  }
  glEnd();
}
*/
