#ifndef LEAFBLOCK_H
#define LEAFBLOCK_H

#include "Objeto.h"

class LeafBlock : public Objeto {
public:
    LeafBlock();
    void desenha(Vetor3D t, Vetor3D a, Vetor3D s);
};

#endif
