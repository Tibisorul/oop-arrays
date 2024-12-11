
#include "Array.h"
#include <climits>
#include <cstdint>
#include <iostream>
#include <limits>

Array::Array() {
    n = 1;
    v = new Element[1];
    v[0].setValoare(0);
}

Array::Array(int n, const int valori[]) {
    if (n <= 0) {
        throw std::invalid_argument("Dimensiunea array-ului trebuie să fie mai mare decât 0.");
    }
    this->n = n;
    v = new Element[n];
    for (int i = 0; i < n; i++) {
        v[i].setValoare(valori[i]);
    }
}

Array::Array(const Array &a) {
    n = a.n;
    v = new Element[n];
    for (int i = 0; i < n; i++) {
        v[i] = a.v[i];
    }
}

Array& Array::operator=(const Array& a) {
    if (this != &a) {
        delete[] v;

        n = a.n;
        v = new Element[n];
        for (int i = 0; i < n; i++) {
            v[i] = a.v[i];
        }
    }
    return *this;
}

Array::~Array() {
    delete[] v;
}

int Array::getN() const {
    return n;
}

long long Array::getSum() const {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += v[i].getValoare();
    return sum;
}

int Array::getMax() const {
    if (n == 0) {
        throw std::logic_error("Array-ul este gol. Nu se poate calcula maximul.");
    }
    int maxim = std::numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        maxim = std::max(maxim, v[i].getValoare());
    }
    return maxim;
}

int Array::getMin() const {
    if (n == 0) {
        throw std::logic_error("Array-ul este gol. Nu se poate calcula minimul.");
    }
    int minim = std::numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        minim = std::min(minim, v[i].getValoare());
    }
    return minim;
}

int Array::getPozMax() const {
    if (n == 0) {
        throw std::logic_error("Array-ul este gol. Nu se poate calcula pozitia maximului.");
    }
    int maxim = std::numeric_limits<int>::min(), poz = 0;
    for (int i = 0; i < n; i++) {
        if (maxim < v[i].getValoare()) {
            maxim = v[i].getValoare();
            poz = i;
        }
    }
    return poz;
}

int Array::getPozMin() const {
    if (n == 0) {
        throw std::logic_error("Array-ul este gol. Nu se poate calcula pozitia minimului.");
    }
    int minim = std::numeric_limits<int>::max(), poz = 0;
    for (int i = 0; i < n; i++) {
        if (minim > v[i].getValoare()) {
            minim = v[i].getValoare();
            poz = i;
        }
    }
    return poz;
}

void Array::sort(int order) {
    if (n < 2) {
        throw std::logic_error("Array-ul trebuie să aibă cel puțin două elemente pentru a fi sortat.");
    }
    if (order >= 0) order = 1;
    else order = -1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (order * v[j].getValoare() > order * v[j + 1].getValoare()) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

bool Array::operator==(const Array& a) const {
    if (n != a.n) return false;
    for (int i = 0; i < n; i++) {
        if (v[i] != a.v[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& a) const {
    return !(*this == a);
}

Element& Array::operator[](int i) {
    if (i < 0 || i >= n) {
        throw std::out_of_range("Indexul este în afara limitelor.");
    }
    return v[i];
}

const Element& Array::operator[](int i) const {
    if (i < 0 || i >= n) {
        throw std::out_of_range("Indexul este în afara limitelor.");
    }
    return v[i];
}

std::ostream& operator<<(std::ostream& os, Array a) {
    os << "Vectorul are " << a.n << " elemente:\n";
    for (int i = 0; i < a.n; i++) {
        os << a.v[i] << " ";
    }
    os << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Array& a) {
    std::cout << "Introduceti dimensiunea array-ului: ";
    is >> a.n;
    if (a.n <= 0) {
        throw std::invalid_argument("Dimensiunea array-ului trebuie să fie mai mare decât 0.");
    }
    delete[] a.v;
    a.v = new Element[a.n];
    std::cout << "Introduceti elementele array-ului: ";
    for (int i = 0; i < a.n; i++) {
        int temp;
        is >> temp;
        a.v[i].setValoare(temp);
    }
    return is;
}


