#ifndef ARRAYMENU_H
#define ARRAYMENU_H

#include "../Array/Array.h"
#include "../Statistics/Statistics.h"
#include <vector>
#include "../Operation.h"



class ArrayMenu {
private:
    std::vector<Array> arrays; // Listă de array-uri

public:
    ArrayMenu(); // Constructor

    void run(); // Funcția care rulează meniul principal
    void handleOperation(const Operation& operation);


private:
    void addArray(); // Adaugă un array
    void removeArray(); // Șterge un array
    void viewArray(); // Vizualizează un array
    void handleArrayOption(Array& array, int option); // Gestionează opțiunile pentru un array
    void displayStatistics(const Array& array); // Afișează statistici despre un array

};

#endif //ARRAYMENU_H
