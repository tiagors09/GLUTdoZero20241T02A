#ifndef BLOCOTERRA_H
#define BLOCOTERRA_H

#include <Objeto.h>

class BlocoTerra : public Objeto
{
public:
    BlocoTerra();
    void desenha(Vetor3D t = Vetor3D(0,0,0), Vetor3D a = Vetor3D(0,0,0), Vetor3D s = Vetor3D(1,1,1));
};

#endif // BLOCOTERRA_H
