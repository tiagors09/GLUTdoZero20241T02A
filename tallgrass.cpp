#include "tallgrass.h"
#include <gui.h>
#include <GL/glut.h>

TallGrass::TallGrass() {}

void TallGrass::desenha(Vetor3D t, Vetor3D a, Vetor3D s) {
    glPushMatrix();
    Objeto::desenha(t, a, s);  // posiciona

    glDisable(GL_CULL_FACE); // desativa "back-face culling" para renderizar os dois lados

    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(TALL_GRASS); // ou TALLGRASS se tiver separado

    float halfSize = 0.5;

    // Primeira face
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glTexCoord2f(0, 1); glVertex3f(-halfSize, 0, -halfSize);
        glTexCoord2f(1, 1); glVertex3f( halfSize, 0,  halfSize);
        glTexCoord2f(1, 0); glVertex3f( halfSize, 1,  halfSize);
        glTexCoord2f(0, 0); glVertex3f(-halfSize, 1, -halfSize);
    glEnd();

    // Segunda face
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glTexCoord2f(0, 1); glVertex3f( halfSize, 0, -halfSize);
        glTexCoord2f(1, 1); glVertex3f(-halfSize, 0,  halfSize);
        glTexCoord2f(1, 0); glVertex3f(-halfSize, 1,  halfSize);
        glTexCoord2f(0, 0); glVertex3f( halfSize, 1, -halfSize);
    glEnd();

    GUI::desabilitaTextura(true, false);
    glEnable(GL_CULL_FACE); // reativa se quiser

    glPopMatrix();
}
