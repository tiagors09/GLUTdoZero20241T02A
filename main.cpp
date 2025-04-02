#include <iostream>

using namespace std;

#include <gui.h>

Vetor3D posEsfera = Vetor3D(0.5,1,0);
float raioEsfera = 0.2;

void casa()
{
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glTexCoord2f(0,0); glVertex3f(0,0,1);
        glTexCoord2f(0.25,0); glVertex3f(1,0,1);
        glTexCoord2f(0.25,1); glVertex3f(1,1,1);
        glTexCoord2f(0,1); glVertex3f(0,1,1);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glTexCoord2f(0.25,0); glVertex3f(1,0,1);
        glTexCoord2f(0.5,0); glVertex3f(1,0,0);
        glTexCoord2f(0.5,1); glVertex3f(1,1,0);
        glTexCoord2f(0.25,1); glVertex3f(1,1,1);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glTexCoord2f(0.5,0); glVertex3f(1,0,0);
        glTexCoord2f(0.75,0); glVertex3f(0,0,0);
        glTexCoord2f(0.75,1); glVertex3f(0,1,0);
        glTexCoord2f(0.5,1); glVertex3f(1,1,0);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glTexCoord2f(0.75,0); glVertex3f(0,0,0);
        glTexCoord2f(1,0); glVertex3f(0,0,1);
        glTexCoord2f(1,1); glVertex3f(0,1,1);
        glTexCoord2f(0.75,1); glVertex3f(0,1,0);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(1,1,1);
        glVertex3f(1,1,0);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,1);
        glVertex3f(0,0,1);
    glEnd();
    //teto esquerdo
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(0.5,1.5,0.5);
    glEnd();
}

void desenha() {
    GUI::displayInit();

        GUI::drawOrigin(0.5);
        //GUI::drawOriginAL(5,0.5);
        GUI::setColor(0.8,0.0,0.0, 1,true);
        GUI::drawFloor(5,5);

        GUI::setColor(0.0,0.8,0.0, 1,true);

        casa();

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'p':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'a':
        posEsfera.x -= 0.1;
        break;
    case 'd':
        posEsfera.x += 0.1;
        break;
    case 's':
        posEsfera.y -= 0.1;
        break;
    case 'w':
        posEsfera.y += 0.1;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//    //if () {
//    //    break;
//    //}
//}



