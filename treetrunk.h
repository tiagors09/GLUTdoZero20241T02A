#ifndef TREETRUNK_H
#define TREETRUNK_H

#include "woodblock.h"
#include <vector>
#include "leafblock.h"

class TreeTrunk {
public:
    TreeTrunk(Vetor3D posicaoBase, int alturaMinima = 5);

    void desenha();

private:
    Vetor3D base;
    int altura;
    std::vector<WoodBlock> blocos;
};

#endif
