#ifndef TALLGRASS_H
#define TALLGRASS_H

#include "Objeto.h"    // Se você tiver uma classe base Objeto
#include "gui.h"   // Para usar Vetor3D

class TallGrass : public Objeto {
public:
    TallGrass();

    void desenha(Vetor3D t, Vetor3D a = Vetor3D(0,0,0), Vetor3D s = Vetor3D(1,1,1)); // t = posição, a = ângulo, s = escala
};

#endif // TALLGRASS_H
