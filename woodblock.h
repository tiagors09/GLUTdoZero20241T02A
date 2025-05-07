#ifndef WOODBLOCK_H
#define WOODBLOCK_H

#include <Objeto.h>

class WoodBlock : public Objeto
{
public:
    WoodBlock();
    void desenha(Vetor3D t = Vetor3D(0,0,0), Vetor3D a = Vetor3D(0,0,0), Vetor3D s = Vetor3D(1,1,1));
};

#endif // WOODBLOCK_H
