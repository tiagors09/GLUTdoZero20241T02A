#include "woodblock.h"

#include <gui.h>

WoodBlock::WoodBlock() {

}

void WoodBlock::desenha(Vetor3D t, Vetor3D a, Vetor3D s) {
    glPushMatrix();
    Objeto::desenha(t, a, s);

    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(TREE_SIDE);

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

    GUI::desabilitaTextura(true, false);

    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(TREE_SIDE);
        // Cima
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glTexCoord2f(0,1); glVertex3f(.5,1,.5);
            glTexCoord2f(1,1); glVertex3f(.5,1,-.5);
            glTexCoord2f(1,0); glVertex3f(-.5,1,-.5);
            glTexCoord2f(0,0); glVertex3f(-.5,1,.5);
        glEnd();
    GUI::desabilitaTextura(true, false);


    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(TREE_SIDE);
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
