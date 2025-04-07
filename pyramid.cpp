#include "pyramid.h"

#include <gui.h>

Pyramid::Pyramid()
{
    this->size = 1;
}

Pyramid::Pyramid(float size)
{
    this->size = size;
}

void Pyramid::draw() {
    // Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,size/2);

        glVertex3f(0,0,0);
        glVertex3f(size,0,0);
        glVertex3f(size / 2,size,-size/2);
    glEnd();

    // Lateral direita
    glBegin(GL_POLYGON);
        glNormal3f(size/2,0,0);

        glVertex3f(size,0,0);
        glVertex3f(size,0,-size);
        glVertex3f(size/2,size,-size/2);
    glEnd();

}
