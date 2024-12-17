#include "Array.h"
#include "../CalculatorTemplate/Calculator.h"
#include <iostream>
#include <algorithm>
#include <numeric>

int Array::objectCount = 0;

Array::Array() {
    v.emplace_back(0);
    objectCount++;
}

Array::Array(int n, const int valori[]) {
    if (n <= 0) {
        throw InvalidSizeException("Numarul elementelor din array trebuie sa fie mai mare decat zero.");
    }
    for (int i = 0; i < n; i++) {
        v.emplace_back(valori[i]);
    }
    objectCount++;
}

/*Array::Array(const Array& a) : v(a.v) {
    objectCount++;
}

Array& Array::operator=(const Array& a) {
    if (this != &a) {
        v = a.v;
    }
    return *this;
}

Array::~Array() {
    objectCount--;
}

int Array::getObjectCount() {
    return objectCount;
}*/

int Array::getN() const {
    return static_cast<int>(v.size());
}

/*
long long Array::getSum() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate calcula suma.");
    }
    long long sum = 0;
    for (const auto& elem : v) {
        sum += elem.getValoare();
    }
    return sum;
}
*/

long long Array::getSum() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate calcula suma.");
    }
    std::vector<int> valori = getData();
    Calculator<int> calc(valori);
    return calc.getSuma();
}

int Array::getMax() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate calcula maximul.");
    }
    std::vector<int> valori = getData();
    Calculator<int> calc(valori);
    return calc.getMax();
}

int Array::getMin() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate calcula minimul.");
    }
    std::vector<int> valori = getData();
    Calculator<int> calc(valori);
    return calc.getMin();
}


/*int Array::getMax() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate calcula maximul.");
    }
    return std::max_element(v.begin(), v.end(), [](const Element& a, const Element& b) {
        return a.getValoare() < b.getValoare();
    })->getValoare();
}

int Array::getMin() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate calcula minimul.");
    }
    return std::min_element(v.begin(), v.end(), [](const Element& a, const Element& b) {
        return a.getValoare() < b.getValoare();
    })->getValoare();
}*/

int Array::getPozMax() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate determina pozitia maximului.");
    }

    int poz = 0;
    int maxim = v[0].getValoare();

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i].getValoare() > maxim) {
            maxim = v[i].getValoare();
            poz = static_cast<int>(i);
        }
    }

    return poz;
}

int Array::getPozMin() const {
    if (v.empty()) {
        throw EmptyArrayException("Array-ul este gol. Nu se poate determina pozitia minimului.");
    }

    int poz = 0;
    int minim = v[0].getValoare();

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i].getValoare() < minim) {
            minim = v[i].getValoare();
            poz = static_cast<int>(i);
        }
    }

    return poz;
}

void Array::sort(int order) {
    if (v.size() < 2) {
        throw EmptyArrayException("Array-ul trebuie sa aiba cel putin doua elemente pentru a fi sortat.");
    }
    if (order >= 0) {
        std::sort(v.begin(), v.end(), [](const Element& a, const Element& b) {
            return a.getValoare() < b.getValoare();
        });
    } else {
        std::sort(v.begin(), v.end(), [](const Element& a, const Element& b) {
            return a.getValoare() > b.getValoare();
        });
    }
}

/*
bool Array::operator==(const Array& a) const {
    return v == a.v;
}

bool Array::operator!=(const Array& a) const {
    return !(*this == a);
}*/

Element& Array::operator[](int i) {
    if (i < 0 || i >= static_cast<int>(v.size())) {
        throw InvalidIndexException("Indexul este in afara limitelor.");
    }
    return v[i];
}

const Element& Array::operator[](int i) const {
    if (i < 0 || i >= static_cast<int>(v.size())) {
        throw InvalidIndexException("Indexul este in afara limitelor.");
    }
    return v[i];
}

/*std::ostream& operator<<(std::ostream& os, const Array& a) {
    os << "Array-ul are " << a.getN() << " elemente:\n";
    for (const auto& elem : a.v) {
        os << elem << " ";
    }
    os << "\n";
    return os;
}*/

std::ostream& operator<<(std::ostream& os, const Array& a) {
    os << "Array-ul are " << a.getN() << " elemente:\n";
    afiseazaVector(a.getData());
    return os;
}


std::istream& operator>>(std::istream& is, Array& a) {
    std::cout << "Introduceti dimensiunea array-ului:";
    int n;
    is >> n;
    if (n <= 0) {
        throw InvalidSizeException("Dimensiunea array-ului trebuie sa fie mai mare decat 0.");
    }
    a.v.clear();
    std::cout << "Introduceti elementele array-ului:";
    for (int i = 0; i < n; i++) {
        int temp;
        is >> temp;
        a.v.emplace_back(temp);
    }
    return is;
}

std::vector<int> Array::getData() const {
    std::vector<int> data;
    for (const auto& elem : v) {
        data.push_back(elem.getValoare());
    }
    return data;
}
