#pragma once

#include <vector>
#include <list>

class Factrize {
public:
    /** 与えられた数の素因数の集合を昇順で返す (実装の都合上、1と4を含む)*/
    static std::vector<int> factrize(int num);
};
