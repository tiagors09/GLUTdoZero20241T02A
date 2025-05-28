#include <iostream>

using namespace std;

#include <gui.h>
#include "pyramid.h"
#include "floor.h"
#include "woodblock.h"
#include "treetrunk.h"
#include "tallgrass.h"
#include "pivot.h"

Vetor3D t = Vetor3D(0,0,0);
Pivot p;
BlocoTerra bt;
std::vector<Objeto*> objetos;

void desenha() {
    GUI::displayInit();
        GUI::setLight(0,0,3,0,true,false);

        GUI::drawOrigin(1);

        GUI::setColor(1,1,1);

        glClearColor(0.529f, 0.808f, 0.922f, 1.0f);

        p.t = t;
        p.desenha();

        for (Objeto* o : objetos)
            o->desenha();
    GUI::displayEnd();
}

// tecla - tecla apertada
// x e y - posição do mouse ao ser apertado
void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);
    {
        switch (tecla) {
        case 'w':
            t.y += 1;
            break;
        case 'a':
            t.x += 1;
            break;
        case 's':
            t.y -= 1;
            break;
        case 'd':
            t.x -= 1;
            break;
        case 'e':
            t.z += 1;
            break;
        case 'r':
            t.z -= 1;
            break;
        case ' ':
            objetos.push_back(new BlocoTerra());
            objetos.back()->t = t;
            break;
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

    for (Objeto* o : objetos)
            delete o;

    return 0;
}
