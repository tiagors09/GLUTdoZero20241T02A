#ifndef TALLGRASS_H
#define TALLGRASS_H

#include "Objeto.h"    // Se você tiver uma classe base Objeto
#include "gui.h"   // Para usar Vetor3D

class TallGrass : public Objeto {
public:
    TallGrass();

    void desenha(); // t = posição, a = ângulo, s = escala
};

#endif // TALLGRASS_H
