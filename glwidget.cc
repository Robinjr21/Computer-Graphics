/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=PLY_OBJECT;break;
  case Qt::Key_7:Object=PLY_OBJECT_R;break;
  //case Qt::Key_8:Object=OBJECT_ARM1;break;
  case Qt::Key_8:Object=OBJECT_TRUCK;break;
  case Qt::Key_9:Object=OBJECT_CHESS;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;
  case Qt::Key_F3:Draw_light_flat=!Draw_light_flat;break;
  case Qt::Key_F4:Draw_light_smooth=!Draw_light_smooth;break;
  case Qt::Key_F5:Unlit_texture=!Unlit_texture;break;
  case Qt::Key_F6:FlatTexture=!FlatTexture;break;
  case Qt::Key_F7:SmoothTexture=!SmoothTexture;break;

  case Qt::Key_J:First_light=!First_light;break;
  case Qt::Key_K:Second_light=!Second_light;break;
  case Qt::Key_M:Material = (Material + 1)%3; break;

  case Qt::Key_A:Animacion = !Animacion;
  if(Animacion)
    Timer->start();
  else{
    Timer->stop();
  }break;


  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;

  case Qt::Key_W:Platform.increase_angle();break;
  case Qt::Key_Q:Platform.decrease_angle();break;
  case Qt::Key_D:Truck.trasladaD();break;
  case Qt::Key_S:Truck.trasladaA();break;
  case Qt::Key_Z:Truck.rotacionD();break;
  case Qt::Key_X:Truck.rotacionI();break;

  case Qt::Key_E:Platform.speedDown();break;
  case Qt::Key_R:Platform.speedUp();break;
  case Qt::Key_T:Truck.speedDownT();break;
  case Qt::Key_Y:Truck.speedUpT();break;
  case Qt::Key_U:Truck.speedDownR();break;
  case Qt::Key_I:Truck.speedUpR();break;
  }

  update();
}

void _gl_widget::idle_slot(){

  if(Truck.getMov())Truck.trasladaD();
  else Truck.trasladaA();

  if(Truck.getAngR())Truck.rotacionD();
  else Truck.rotacionI();

  if(Platform.getDisp())Platform.decrease_angle();
  else Platform.increase_angle();

  if(Light.getX() <= -100 )Light.increaseRotation();
  if(Light.getX() >= 100)Light.decreaseRotation();


  update();
}

void _gl_widget::tick(){
  if(Light.getX() <= -100 )Light.increaseRotation();
  if(Light.getX() >= 100)Light.decreaseRotation();

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{

  Axis.draw_line();

  glDisable(GL_LIGHTING);
  setMaterial();


  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point(); break;
    case OBJECT_CONE:Cone.draw_point() ;break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case PLY_OBJECT:PLY.draw_point(); break;
    case PLY_OBJECT_R:PLY_R.draw_point();break;
    case OBJECT_TRUCK:Truck.draw_point();break;
    case OBJECT_CHESS:Dashboard.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line(); break;
    case OBJECT_CONE:Cone.draw_line() ;break;
    case OBJECT_SPHERE:Sphere.draw_line(); break;
    case PLY_OBJECT:PLY.draw_line(); break;
    case PLY_OBJECT_R:PLY_R.draw_line();break;
    case OBJECT_TRUCK:Truck.draw_line();break;
    case OBJECT_CHESS:Dashboard.draw_line();break;
    default:
        break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill(); break;
    case OBJECT_CONE:Cone.draw_fill() ;break;
    case OBJECT_SPHERE:Sphere.draw_fill(); break;
    case PLY_OBJECT:PLY.draw_fill(); break;
    case PLY_OBJECT_R:PLY_R.draw_fill();break;
    case OBJECT_TRUCK:Truck.draw_fill();break;
    case OBJECT_CHESS:Dashboard.draw_fill();break;
    default:break;
    }
  }

  /*
  GLfloat Position[4] = {1,1,1,1};

  glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*)&Position);

  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);*/


  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess(); break;
    case OBJECT_CONE:Cone.draw_chess() ;break;
    case OBJECT_SPHERE:Sphere.draw_chess(); break;
    case PLY_OBJECT:PLY.draw_chess(); break;
    case PLY_OBJECT_R:PLY_R.draw_chess();break;
    case OBJECT_TRUCK:Truck.draw_chess();break;
    case OBJECT_CHESS:Dashboard.draw_chess();break;
    default:break;
    }
  }
  /*
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);


   glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*)&Position);

   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHTING);*/

  //Light.FirstLight(First_light);
  //Light.SecondLight(Second_light);

  if(Draw_light_flat){
    glEnable(GL_LIGHTING);
    Light.FirstLight();
    Light.SecondLight();
    if(First_light)glEnable(GL_LIGHT0);else glDisable(GL_LIGHT0);
    if (Second_light) glEnable(GL_LIGHT1); else glDisable(GL_LIGHT1);
    switch (Object) {
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_lighting_flat();break;
    case OBJECT_CUBE:Cube.draw_lighting_flat();break;
    case OBJECT_CYLINDER:Cylinder.draw_lighting_flat(); break;
    case OBJECT_CONE:Cone.draw_lighting_flat() ;break;
    case OBJECT_SPHERE:Sphere.draw_lighting_flat(); break;
    case PLY_OBJECT:PLY.draw_lighting_flat(); break;
    case PLY_OBJECT_R:PLY_R.draw_lighting_flat();break;
    case OBJECT_CHESS:Dashboard.draw_lighting_flat();break;
    case OBJECT_TRUCK:Truck.draw_lighting_flat();break;
    default:break;
    }
  }
  /*
   glDisable(GL_LIGHT0);
   glDisable(GL_LIGHTING);

   glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*)&Position);

   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHTING);*/
   if(Draw_light_smooth){
    glEnable(GL_LIGHTING);
    Light.FirstLight();
    Light.SecondLight();
    if(First_light)glEnable(GL_LIGHT0);else glDisable(GL_LIGHT0);
    if (Second_light) glEnable(GL_LIGHT1); else glDisable(GL_LIGHT1);
    switch (Object) {
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_lighting_smooth();break;
    case OBJECT_CUBE:Cube.draw_lighting_smooth();break;
    case OBJECT_CYLINDER:Cylinder.draw_lighting_smooth(); break;
    case OBJECT_CONE:Cone.draw_lighting_smooth() ;break;
    case OBJECT_SPHERE:Sphere.draw_lighting_smooth(); break;
    case PLY_OBJECT:PLY.draw_lighting_smooth(); break;
    case PLY_OBJECT_R:PLY_R.draw_lighting_smooth();break;
    case OBJECT_CHESS:Dashboard.draw_lighting_smooth();break;
    case OBJECT_TRUCK:Truck.draw_lighting_smooth();break;
    default:break;
    }
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);
   }


   /*
   glDisable(GL_LIGHT0);
   glDisable(GL_LIGHTING);*/

   if(Unlit_texture){
    glEnable(GL_TEXTURE_2D);
    QString tex = "/home/robinjr/ETSIIT 3º AÑO/1º Cuatri/IG/Práctica/P1_skeleton/texturas/dia_8192.jpg";

    switch (Object) {

    case OBJECT_CHESS:
        Dashboard.set_texture(tex);
        Dashboard.draw_texture();
        break;

    case OBJECT_CYLINDER:
        CylinderText.set_texture(tex);
        CylinderText.draw_texture();
        break;

    case OBJECT_SPHERE:
        SphereText.set_texture(tex);
        SphereText.draw_texture();
        break;
    }

    glDisable(GL_TEXTURE_2D);
   }

   if(FlatTexture && Draw_light_flat){
    glEnable(GL_TEXTURE_2D);
    switch (Object) {
    case OBJECT_CHESS:

        Dashboard.set_texture("/home/robinjr/ETSIIT 3º AÑO/1º Cuatri/IG/Práctica/P1_skeleton/texturas/dia_8192.jpg");
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        Dashboard.draw_texture();
        break;
    }
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glDisable(GL_TEXTURE_2D);
   }

   if(SmoothTexture && Draw_light_smooth){
    glEnable(GL_TEXTURE_2D);
    switch (Object) {
    case OBJECT_CHESS:

        Dashboard.set_texture("/home/robinjr/ETSIIT 3º AÑO/1º Cuatri/IG/Práctica/P1_skeleton/texturas/dia_8192.jpg");
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        Dashboard.draw_texture();
        break;
    }

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glDisable(GL_TEXTURE_2D);
   }

}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
  Draw_light_flat=false;
  Draw_light_smooth=false;
  Unlit_texture = false;
  FlatTexture = false;
  SmoothTexture = false;
  First_light = false;
  Second_light = false;

  timer.setInterval(0);
  connect(&timer, SIGNAL(timeout()), this, SLOT(idle_slot()));
  Animacion = false;
  Dashboard.initialize(8,8,8,8);
  CylinderText.initialize(1, 0.5, 20, 10, 30);
  SphereText.initialize(0.5, 40, 40);

  // Code to define the Qtimer for the animation
  Timer = new QTimer(this);
  Timer->setInterval(0);
  connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));

}

void _gl_widget::setMaterial(){
  GLfloat ambient[4], diffuse[4], specular[4], shininess;

  switch(Material){
  case 0: // PLatino
    ambient[0] = 0.23125; ambient[1] = 0.23125; ambient[2] = 0.23125; ambient[3] = 1.0;
    diffuse[0] = 0.2775; diffuse[1] = 0.2775; diffuse[2] = 0.2775; diffuse[3] = 1.0;
    specular[0] = 0.773911; specular[1] = 0.773911; specular[2] = 0.773911; specular[3] = 1.0;
    shininess = 89.6;
    break;
  case 1: // Copper
    ambient[0]=0.19125,ambient[1]=  0.0735,ambient[2]= 0.19225,ambient[3]= 1.0;
    diffuse[0]=0.7038,diffuse[1]= 0.27048, diffuse[2]=0.50754, diffuse[3]=1.0;
    specular[0]=0.256777, specular[1]=0.137622, specular[2]=0.508273, specular[3]=1.0;
    shininess= 53.6;
    break;
  case 2: // Gold
    ambient[0] = 0.24725; ambient[1] = 0.1995; ambient[2] = 0.0745; ambient[3] = 1.0;
    diffuse[0] = 0.75164; diffuse[1] = 0.60648; diffuse[2] = 0.22648; diffuse[3] = 1.0;
    specular[0] = 0.628281; specular[1] = 0.555802; specular[2] = 0.366065; specular[3] = 1.0;
    shininess = 51.2;
    break;
  }

  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}
