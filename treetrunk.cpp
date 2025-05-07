#include "treetrunk.h"
#include "leafblock.h"

TreeTrunk::TreeTrunk(Vetor3D posicaoBase, int alturaMinima) {
    base = posicaoBase;
    altura = alturaMinima < 2 ? 2 : alturaMinima;

    // Cria um bloco por nível de altura
    for (int i = 0; i < altura; ++i) {
        blocos.push_back(WoodBlock());
    }
}

void TreeTrunk::desenha() {
    for (int i = 0; i < altura; ++i) {
        Vetor3D pos = base + Vetor3D(0, i, 0);
        blocos[i].desenha(pos, Vetor3D(0,0,0), Vetor3D(1,1,1));
    }

    // Desenha a pirâmide de folhas
        int topo = altura - 1;

        for (int y = 0; y < 3; ++y) {
            int r = 2 - y; // raio da camada
            for (int x = -r; x <= r; ++x) {
                for (int z = -r; z <= r; ++z) {
                    // opcional: evitar colocar folha no centro do tronco
                    if (y == 0 && x == 0 && z == 0) continue;

                    Vetor3D posFolha = base + Vetor3D(x, topo + y, z);

                    LeafBlock lb;
                    lb.desenha(Vetor3D(posFolha.x, posFolha.y, posFolha.z), Vetor3D(0,0,0), Vetor3D(1,1,1));
                }
            }
        }
}
