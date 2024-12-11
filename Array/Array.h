//
// Created by tiber on 29.11.2024.
//

#ifndef ARRAY_H
#define ARRAY_H

#include "../Element/Element.h"


class Array {
private:
    int n;
    Element *v;

public:
    Array();
    Array(int n, const int valori[]);
    Array(const Array &a);
    Array& operator=(const Array& a);
    ~Array();

    int getN() const;

    long long getSum() const;
    int getMax() const;
    int getMin() const;
    int getPozMax() const;
    int getPozMin() const;

    void sort(int order = 1);

    bool operator==(const Array& a) const;
    bool operator!=(const Array& a) const;

    Element& operator[](int i);
    const Element& operator[](int i) const;

    friend std::ostream& operator<<(std::ostream& os, Array a);
    friend std::istream& operator>>(std::istream& is, Array& a);
};


#endif //ARRAY_H
