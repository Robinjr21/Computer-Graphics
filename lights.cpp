#include "lights.h"

using namespace _colors_ne;

void lights::initialize()
{
    //      Setting up the color.
    //_vertex3f color = _vertex3f(1,1,1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, (GLfloat *) &MAGENTA);
    glLightfv(GL_LIGHT1, GL_SPECULAR, (GLfloat *) &MAGENTA);
}

/**
 * @brief Toggle the 1st light.
 * @param toggle    Boolean, switch ON or OFF the 1st light.
 */
void lights::FirstLight()
{
    /*
    if(_switch)
    {
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat *) &lightPos);
    }
    else
        glDisable(GL_LIGHT0);*/
    // añado una luz blanca en el infinito
    GLfloat position[] = { 1.0,1.0,1.0,1.0};
    GLfloat color[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, color);

}

/**
 * @brief Toggle ON/OFF the 2nd light.
 * @param toggle    Boolean, switch On/OFF the 2nd light.
 */
void lights::SecondLight()
{
    /*
    if(_switch)
    {
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat *) &actPos2);
    }
    else
        glDisable(GL_LIGHT1);*/
    // añado una luz magenta
    GLfloat position[] = { 0.0, Y, Z, 0.0};
    GLfloat color[] = {1.0, 0.0, 1.0, 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_SPECULAR, color);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, color);

}

float lights::getX(){
    return X;
}

void lights::increaseRotation(){
    X += 0.5;
}

void lights::decreaseRotation(){
    X -= 0.5;
}
