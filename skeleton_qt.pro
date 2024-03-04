DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x050F00

HEADERS += \
    _ply.h \
    _plyrevolution.h \
    _read_ply.h \
    brazo1.h \
    chasis.h \
    chess_board.h \
  colors.h \
  basic_object3d.h \
    cone.h \
    cube.h \
    cylinder.h \
    cylindertexture.h \
    doorM.h \
    lights.h \
  object3d.h \
  axis.h \
    otro.h \
    plane.h \
    platform.h \
    puerta.h \
    revolutionobject.h \
    sphere.h \
    spheretexture.h \
  tetrahedron.h \
#  cube.h \
  glwidget.h \
    truck.h \
    wheel.h \
    wheels_axis.h \
  window.h

SOURCES += \
    _ply.cpp \
    _plyrevolution.cpp \
    _read_ply.cpp \
  basic_object3d.cc \
    brazo1.cpp \
    chasis.cpp \
    chess_board.cpp \
    cone.cpp \
    cube.cc \
    cylinder.cpp \
    cylindertexture.cpp \
    doorM.cpp \
    lights.cpp \
  object3d.cc \
  axis.cc \
    otro.cpp \
    plane.cpp \
    platform.cpp \
    puerta.cpp \
    revolutionobject.cpp \
    sphere.cpp \
    spheretexture.cpp \
  tetrahedron.cc \
#  cube.cc \
  main.cc \
  glwidget.cc \
    truck.cpp \
    wheel.cpp \
    wheels_axis.cpp \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++14
QT += widgets opengl openglwidgets

DISTFILES += \
    ply_models/beethoven.ply
