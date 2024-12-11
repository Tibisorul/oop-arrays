#ifndef STATISTICS_H
#define STATISTICS_H

#include "../Array/Array.h" // Include necesar pentru clasa Array
#include <cmath> // Pentru operații matematice precum pow

class Statistics {
public:
    static double getMediaElementelor(const Array& arr);
    static double getVarianta(const Array& arr);
    static double getMediana(Array arr); // Array-ul este copiat pentru sortare
};

#endif //STATISTICS_H
