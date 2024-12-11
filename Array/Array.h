//
// Created by tiber on 29.11.2024.
//

#ifndef ARRAY_H
#define ARRAY_H

#include "../Element/Element.h"
#include <vector>
#include <iostream>
#include "../CustomExceptions.h"

class Array {
private:
    std::vector<Element> v;
    static int objectCount;

public:
    Array();
    Array(int n, const int valori[]);
    // Array(const Array &a); -> nu folosesc
    //Array& operator=(const Array& a);
    //~Array();

    std::vector<int> getData() const;

    int getN() const;

    long long getSum() const;
    int getMax() const;
    int getMin() const;
    int getPozMax() const;
    int getPozMin() const;

    void sort(int order = 1);

    /*bool operator==(const Array& a) const;
    bool operator!=(const Array& a) const;*/

    Element& operator[](int i);
    const Element& operator[](int i) const;

    friend std::ostream& operator<<(std::ostream& os, const Array& a);
    friend std::istream& operator>>(std::istream& is, Array& a);
};

#endif
