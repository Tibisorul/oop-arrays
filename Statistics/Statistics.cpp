//
// Created by tiber on 29.11.2024.
//

#include "Statistics.h"

// Calculul mediei elementelor dintr-un array
double Statistics::getMediaElementelor(const Array& arr) {
    if (arr.getN() == 0) return 0;
    return static_cast<double>(arr.getSum()) / arr.getN();
}

// Calculul varianței elementelor dintr-un array
double Statistics::getVarianta(const Array& arr) {
    if (arr.getN() == 0) return 0;
    double mean = getMediaElementelor(arr);
    double variance = 0;

    for (int i = 0; i < arr.getN(); i++) {
        variance += pow(arr[i].getValoare() - mean, 2);
    }
    return variance / arr.getN();
}

// Calculul medianei unui array
double Statistics::getMediana(Array arr) {
    arr.sort(); // Sortăm array-ul pentru calculul medianei
    int n = arr.getN();
    if (n % 2 == 0) {
        return (arr[n / 2 - 1].getValoare() + arr[n / 2].getValoare()) / 2.0;
    } else {
        return arr[n / 2].getValoare();
    }
}