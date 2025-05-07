#include "leafblock.h"
#include <gui.h>

LeafBlock::LeafBlock() {}

void LeafBlock::desenha(Vetor3D t, Vetor3D a, Vetor3D s) {
    glPushMatrix();
    Objeto::desenha(t, a, s);

    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(LEAF); // ou uma textura de folhas
        // Frente
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glTexCoord2f(0,1); glVertex3f(-.5,0,.5);
            glTexCoord2f(1,1); glVertex3f(.5,0,.5);
            glTexCoord2f(1,0); glVertex3f(.5,1,.5);
            glTexCoord2f(0,0); glVertex3f(-.5,1,.5);
        glEnd();

        // Direita
        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glTexCoord2f(0,1); glVertex3f(.5,0,.5);
            glTexCoord2f(1,1); glVertex3f(.5,0,-.5);
            glTexCoord2f(1,0); glVertex3f(.5,1,-.5);
            glTexCoord2f(0,0); glVertex3f(.5,1,.5);
        glEnd();

        // Esquerda (ajustada)
        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glTexCoord2f(0,1); glVertex3f(-.5,0,.5);   // Era (0,0)
            glTexCoord2f(0,0); glVertex3f(-.5,1,.5);   // Era (0,1)
            glTexCoord2f(1,0); glVertex3f(-.5,1,-.5);  // Era (1,1)
            glTexCoord2f(1,1); glVertex3f(-.5,0,-.5);  // Era (1,0)
        glEnd();

        // Trás
        glBegin(GL_POLYGON);
            glNormal3f(0,0,-1);
            glTexCoord2f(0,1); glVertex3f(.5,0,-.5);
            glTexCoord2f(1,1); glVertex3f(-.5,0,-.5);
            glTexCoord2f(1,0); glVertex3f(-.5,1,-.5);
            glTexCoord2f(0,0); glVertex3f(.5,1,-.5);
        glEnd();

        // Cima
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glTexCoord2f(0,1); glVertex3f(.5,1,.5);
            glTexCoord2f(1,1); glVertex3f(.5,1,-.5);
            glTexCoord2f(1,0); glVertex3f(-.5,1,-.5);
            glTexCoord2f(0,0); glVertex3f(-.5,1,.5);
        glEnd();

        // Baixo (corrigido)
        glBegin(GL_POLYGON);
            glNormal3f(0,-1,0);
            glTexCoord2f(0,0); glVertex3f(-.5,0,-.5);  // canto inferior esquerdo
            glTexCoord2f(1,0); glVertex3f(.5,0,-.5);   // canto inferior direito
            glTexCoord2f(1,1); glVertex3f(.5,0,.5);    // canto superior direito
            glTexCoord2f(0,1); glVertex3f(-.5,0,.5);   // canto superior esquerdo
        glEnd();
    GUI::desabilitaTextura(true, false);
    glPopMatrix();
}
