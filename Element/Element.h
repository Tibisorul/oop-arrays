
#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

class Element {
    int valoare;

public:
    explicit Element(int valoare = 0);
    int getValoare() const;
    friend std::ostream& operator<<(std::ostream& os, const Element& elem);

    //void setValoare(int valoare);

    /*bool operator<(const Element& other) const;
    bool operator>(const Element& other) const;*/

    /*bool operator==(const Element& other) const;
    bool operator!=(const Element& other) const;*/
};

#endif
