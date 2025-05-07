#include "floor.h"

Floor::Floor(int m, int n) : m(m), n(n) {
    blocos.resize(m * n); // aloca m*n blocos
}

void Floor::desenha() {
    int index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            float x = i - m / 2.0f + 0.5f; // centraliza no (0,0)
            float z = j - n / 2.0f + 0.5f;
            blocos[index++].desenha(Vetor3D(x, 0, z), Vetor3D(0,0,0), Vetor3D(1,1,1));
        }
    }
}
