#include "ArrayFactory.h"

Array ArrayFactory::createEmptyArray() {
    int valori[] = {0};
    return Array(1, valori);
}

Array ArrayFactory::createArrayWithValues(int n, const int valori[]) {
    return Array(n, valori);
}

/*Array ArrayFactory::createArrayWithDefaultValue(int n, int valoareImplicita) {
    std::vector<int>valori(n, valoareImplicita);
    return Array(n, valori.data());
}
*/

