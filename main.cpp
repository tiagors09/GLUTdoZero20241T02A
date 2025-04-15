#include <iostream>

using namespace std;

#include <gui.h>
#include "pyramid.h"

Vetor3D posEsfera = Vetor3D(2,1,0);
float raioEsfera = 1;

Model3DS carro = Model3DS("../3ds/cartest.3DS");

void desenha() {
    GUI::displayInit();
        {
            GUI::setLight(0,0,3,0,true,false);

            //GUI::drawOrigin(.5);
            GUI::drawOriginAL(5);

            GUI::setColor(0.8,0.0,0.0,1,true);
            GUI::drawFloor(5,5);

            // Bola verde
            /*
            GUI::setColor(0.0,0.8,0.0,1,true);
            GUI::drawSphere(2,1.001,0,0.2);
            */

            // Bola vermelha
            /*
            GUI::setColor(0.8,0.0,0.0,1,true);
            GUI::drawSphere(
                        posEsfera.x,
                        posEsfera.y,
                        posEsfera.z,
                        raioEsfera
                        );
            */

            GUI::setColor(1,1,1,1,true);
            /*
            GUI::drawHalfSphere(
                        posEsfera.x,
                        posEsfera.y,
                        posEsfera.z,
                        raioEsfera
                        );

            GUI::drawSphereInsideBox222(posEsfera.x - 2,
                                        posEsfera.y,
                                        posEsfera.z,
                                        raioEsfera + 1);
            */
            // Caixa verde
            // GUI::setColor(0.0,0.8,0.0,1,true);
            // GUI::drawBox(-1,-1,-1,1,1,1);

            /*
                glBegin(GL_POINTS);
                    glVertex3f(0,0,0);
                    glVertex3f(1,0,0);
                    glVertex3f(1,1,0);
                glEnd();
            */

            /*
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0,0,0);
                glVertex3f(1,0,0);
                glVertex3f(1,1,0);
            glEnd();
            */

            GUI::habilitaTextura(true, false, 0);
            GUI::selecionaTextura(7);

            Pyramid p(9);
            p.draw();

            GUI::desabilitaTextura(true, false);

            /*
            glRotatef(270,1,0,0);

            GLdouble plane[4] = {
                1.0,
                0.0,
                1.0,
                0.5
            };

            glClipPlane(GL_CLIP_PLANE0, plane);
            glEnable(GL_CLIP_PLANE0);
                GUI::drawSphere(0,0,0,1);
            glDisable(GL_CLIP_PLANE0);

            posEsfera.x += glutGUI::drx;
            posEsfera.y += glutGUI::dry;
            posEsfera.z += glutGUI::dlrx * 0.125;
            raioEsfera += glutGUI::dlx * 0.125;
            */

            // GUI::draw3ds(carro);
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
