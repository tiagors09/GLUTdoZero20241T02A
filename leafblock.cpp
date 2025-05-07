#include "leafblock.h"
#include <gui.h>

LeafBlock::LeafBlock() {}

void LeafBlock::desenha(Vetor3D t, Vetor3D a, Vetor3D s) {
    glPushMatrix();
    Objeto::desenha(t, a, s);

    GUI::habilitaTextura(true, false, 0);
    GUI::selecionaTextura(LEAF); // ou uma textura de folhas

    GUI::drawBox(1, 1, 1, 1, 1, 1);

    GUI::desabilitaTextura(true, false);
    glPopMatrix();
}
