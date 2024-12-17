#ifndef ARRAYFACTORY_H
#define ARRAYFACTORY_H
#include "../Array/Array.h"

class ArrayFactory {
    public:
    static Array createEmptyArray();
    static Array createArrayWithValues(int n, const int valori[]);
    static Array createArrayWithDefaultValue(int n, int valoareImplicita);
};

#endif //ARRAYFACTORY_H
