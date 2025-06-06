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
    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(7);
    // Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,size/2);

        glTexCoord2f(0, 0); glVertex3f(0,0,0);
        glTexCoord2f(1, 0); glVertex3f(size,0,0);
        glTexCoord2f(.5, 1); glVertex3f(size / 2,size,-size/2);
    glEnd();

    // Lateral direita
    glBegin(GL_POLYGON);
        glNormal3f(size/2,0,0);

        glTexCoord2f(0, 0); glVertex3f(size,0,0);
        glTexCoord2f(1, 0); glVertex3f(size,0,-size);
        glTexCoord2f(.5, 1); glVertex3f(size/2,size,-size/2);
    glEnd();

    // Lateral esquerda
    glBegin(GL_POLYGON);
        glNormal3f(size/2,0,0);

        glTexCoord2f(0, 0); glVertex3f(0,0,0);
        glTexCoord2f(.5, 1); glVertex3f(size/2,size,-size/2);
        glTexCoord2f(1, 0); glVertex3f(0,0,-size);
    glEnd();

    // Trás
    glBegin(GL_POLYGON);
        glNormal3f(size/2,0,0);

        glTexCoord2f(0, 0); glVertex3f(size,0,-size);
        glTexCoord2f(1, 0); glVertex3f(0,0,-size);
        glTexCoord2f(.5, 1); glVertex3f(size/2,size,-size/2);
    glEnd();

    // Base
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);

        glTexCoord2f(0, 0); glVertex3f(0,0,0);
        glTexCoord2f(1, 0); glVertex3f(0,0,-size);
        glTexCoord2f(1, 1); glVertex3f(size,0,-size);
        glTexCoord2f(0, 1); glVertex3f(size,0,0);
    glEnd();
    GUI::desabilitaTextura(true, false);
}
