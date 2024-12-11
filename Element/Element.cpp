#include "Element.h"

Element::Element(int valoare) {
    this->valoare = valoare;
}

int Element::getValoare() const {
    return valoare;
}


std::ostream& operator<<(std::ostream& os, const Element& elem) {
    os << elem.valoare;
    return os;
}


/*void Element::setValoare(int valoare) {
    this->valoare = valoare;
}*/

/*bool Element::operator<(const Element& other) const {
    return valoare < other.valoare;
}

bool Element::operator>(const Element& other) const {
    return valoare > other.valoare;
}*/

/*bool Element::operator==(const Element& other) const {
    return valoare == other.valoare;
}

bool Element::operator!=(const Element& other) const {
    return valoare != other.valoare;
}*/