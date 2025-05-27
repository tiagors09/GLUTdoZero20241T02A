#ifndef PIVOT_H
#define PIVOT_H

#include "Objeto.h"    // Se você tiver uma classe base Objeto
#include "gui.h"   // Para usar Vetor3D

class Pivot: public Objeto
{
public:
    int texture;
    Pivot();

    void desenha(); // t = posição, a = ângulo, s = escala
};

#endif // PIVOT_H
