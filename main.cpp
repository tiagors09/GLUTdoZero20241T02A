#include <iostream>

using namespace std;

#include <gui.h>

void desenha() {
    GUI::displayInit();

        GUI::setLight(0,0,3,0,true,false);

        //GUI::drawOrigin(.5);
        GUI::drawOriginAL(5);

        GUI::setColor(0.8,0.0,0.0,1,true);
        GUI::drawFloor(5,5,2.5,2.5);

        GUI::drawSphere(2,1,0,0.2);

    GUI::displayEnd();
}

int main()
{
    GUI gui = GUI(800,600,desenha);
}
