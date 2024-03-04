/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QWindow>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "_ply.h"
#include "cylinder.h"
#include "cone.h"
#include "sphere.h"
#include "_plyrevolution.h"
#include "brazo1.h"
#include "wheel.h"
#include "wheels_axis.h"
#include "platform.h"
#include "puerta.h"
#include "chasis.h"
#include "truck.h"
#include "doorM.h"
#include <QTimer>
#include "lights.h"
#include "chess_board.h"
#include <QImageReader>
#include "cylindertexture.h"
#include "spheretexture.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, PLY_OBJECT, OBJECT_CONE, OBJECT_SPHERE, OBJECT_CYLINDER, REVOLUTION_OBJECT,
                 PLY_OBJECT_R, OBJECT_ARM1,OBJECT_WHEEL, OBJECT_AXIS_WHEEL, OBJECT_PLATFORM, OBJECT_CHASIS, OBJECT_TRUCK, OBJECT_CHESS} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  void setMaterial();

  public slots:

  void idle_slot();
  void tick();

private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cone Cone;
  _sphere Sphere;
  _ply PLY = _ply(10.0, "./ply_models/big_porsche.ply");
  _plyRevolution PLY_R = _plyRevolution("./ply_models/revolution.ply");
  brazo1 Brazo;

  _cylinder Cylinder;
  wheel Wheel = wheel(Cylinder);
  wheels_axis Wheel_axis = wheels_axis(Cylinder, Wheel);
  cube Cube;
  puerta Door = puerta(Cube);
  doorM NewDoor = doorM(Door);
  platform Platform = platform(Cube, Wheel_axis,Door, NewDoor);
  chasis Chasis = chasis(Cube, Wheel_axis, Door);
  truck Truck = truck(Platform, Chasis, Cube);
  chess_board Dashboard = chess_board();
  lights Light;
  CylinderTexture CylinderText;
  SphereTexture SphereText;

  QTimer timer;
  QTimer *Timer;


  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_light_flat;
  bool Draw_light_smooth;
  bool First_light;
  bool Second_light;
  bool Unlit_texture;
  bool FlatTexture;
  bool SmoothTexture;
  bool Animacion = false;


  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  int contador = 0;
  int Material = 0;
  int alfa = 0;

  float Angulo = 0;
};

#endif
