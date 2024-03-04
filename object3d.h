/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include <QImageReader>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
    vector<_vertex3ui> Triangles;
    vector<_vertex3f> Triangles_normals;
    vector<_vertex3f> Vertices_normals;
    vector<_vertex2f> Vertices_texcoord;

  void draw_line();
  void draw_fill();
  void draw_chess() ;

  void draw_lighting_flat();
  void draw_lighting_smooth();
  void draw_texture();
  void set_texture(QString file);

  /**
   * @brief compute_triangles_normals
   * Hay que incluir este método en todos los constructores
   * Todos los objetos deben llamar a esta función para que se calcule las normales de los
   * vértices
   */
  void compute_triangles_normals();
  void compute_vertices_normals();
};



#endif // OBJECT3D_H
