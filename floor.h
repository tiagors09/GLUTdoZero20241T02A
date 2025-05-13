#ifndef FLOOR_H
#define FLOOR_H

#include "BlocoTerra.h"
#include <vector>

class Floor {
public:
    Floor(int m, int n);  // largura (x), profundidade (z)
    void desenha(float y = 0);

private:
    int m, n;
    std::vector<BlocoTerra> blocos;
};

#endif // FLOOR_H
