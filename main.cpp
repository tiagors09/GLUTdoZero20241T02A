#include <iostream>

using namespace std;

#include <gui.h>
#include "pyramid.h"
#include "floor.h"
#include "woodblock.h"

Vetor3D posEsfera = Vetor3D(2,1,0);
float raioEsfera = 1;

Model3DS carro = Model3DS("../3ds/cartest.3DS");

void desenha() {
    GUI::displayInit();
        {
            GUI::setLight(0,0,3,0,true,false);

            GUI::drawOrigin(1);

            GUI::setColor(1,1,1);

            GUI::habilitaTextura(true, false, 0);
            GUI::selecionaTextura(10);
                glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
                GUI::drawFloor(10, 10);
            GUI::desabilitaTextura(true, false);

            Floor chao(3, 5);
            chao.desenha();

            WoodBlock wb;
            wb.desenha(Vetor3D(0,1,0), Vetor3D(0,0,0), Vetor3D(1,1,1));
        }
    GUI::displayEnd();
}

// tecla - tecla apertada
// x e y - posição do mouse ao ser apertado
void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);
    {
        switch (tecla) {
        case 'a':
            posEsfera.x -= 0.1;
            break;
        case 'd':
            posEsfera.x += 0.1;
            break;
        case 'w':
            posEsfera.y += 0.1;
            break;
        case 's':
            posEsfera.y -= 0.1;
        case 'l':
            glutGUI::trans_luz = !glutGUI::trans_luz;
            break;
        case 'p':
            glutGUI::trans_obj = !glutGUI::trans_obj;
            break;
        default:
            break;
        }
    }
}

int main()
{
    GUI gui = GUI(800,600,desenha,teclado);
}
