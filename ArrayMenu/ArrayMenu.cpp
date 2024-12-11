#include "ArrayMenu.h"
#include <iostream>
#include "../FilterOperation.h"
#include "../StatisticsOperation.h"
#include "../SortOperation.h"


void ArrayMenu::handleOperation(const Operation& operation) {
    std::cout << "Executing operation: " << operation.getDescription() << "\n";
    operation.execute();

    // Exemplu cu dynamic_cast
    if (const auto* sortOp = dynamic_cast<const SortOperation*>(&operation)) {
        std::cout << "This is a sorting operation!\n";
    } else if (const auto* statsOp = dynamic_cast<const StatisticsOperation*>(&operation)) {
        std::cout << "This is a statistics operation!\n";
    } else if (const auto* filterOp = dynamic_cast<const FilterOperation*>(&operation)) {
        std::cout << "This is a filter operation!\n";
    }
}

ArrayMenu::ArrayMenu() {
    // Constructor implicit
}

void ArrayMenu::run() {
    int input;
    std::cout << "Aveti " << arrays.size() << " array-uri. Alegeti o optiune:\n"
              << "1. Adaugati un array.\n"
              << "2. Stergeti un array.\n"
              << "3. Vizualizati un array.\n"
              << "0. Iesire.\n";
    std::cin >> input;

    while (input != 0) {
        switch (input) {
            case 1:
                addArray();
                break;
            case 2:
                removeArray();
                break;
            case 3:
                viewArray();
                break;
            default:
                std::cout << "Optiune invalida! Va rugam sa reintroduceti.\n";
                break;
        }
        std::cout << "Aveti " << arrays.size() << " array-uri. Alegeti o optiune:\n"
                  << "1. Adaugati un array.\n"
                  << "2. Stergeti un array.\n"
                  << "3. Vizualizati un array.\n"
                  << "0. Iesire.\n";
        std::cin >> input;
    }
}

void ArrayMenu::addArray() {
    Array a;
    std::cout << "Introduceti valorile pentru noul array:\n";
    std::cin >> a;
    arrays.push_back(a);
    std::cout << "Array adaugat cu succes!\n";
}

void ArrayMenu::removeArray() {
    int x;
    std::cout << "Introduceti numarul array-ului pe care doriti sa il stergeti (1 - " << arrays.size() << "):\n";
    std::cin >> x;

    if (x < 1 || x > static_cast<int>(arrays.size())) {
        std::cout << "Acest array nu exista, va rugam sa reintroduceti.\n";
        return;
    }
    arrays.erase(arrays.begin() + x - 1);
    std::cout << "Array-ul a fost sters cu succes!\n";
}

void ArrayMenu::viewArray() {
    int arr;
    std::cout << "Introduceti numarul array-ului pe care doriti sa il vizualizati (1 - " << arrays.size() << "): ";
    std::cin >> arr;

    if (arr < 1 || arr > static_cast<int>(arrays.size())) {
        std::cout << "Acest array nu exista, va rugam sa reintroduceti.\n";
        return;
    }

    Array& selectedArray = arrays[arr - 1];
    std::cout << selectedArray;

    int option;
    std::cout << " Alegeti o optiune:\n"
              << "1. Calculati minimul.\n"
              << "2. Calculati maximul.\n"
              << "3. Calculati pozitia minimului.\n"
              << "4. Calculati pozitia maximului.\n"
              << "5. Calculati suma elementelor.\n"
              << "6. Reintroduceti elementele.\n"
              << "7. Sortati elementele.\n"
              << "8. Afisati statistici (media, varianța, mediana).\n"
              << "0. Inapoi.\n";
    std::cin >> option;

    while (option != 0) {
        if (option == 8) {
            displayStatistics(selectedArray);
        } else {
            handleArrayOption(selectedArray, option);
        }
        std::cout << selectedArray;
        std::cout << " Alegeti o optiune:\n"
                  << "1. Calculati minimul.\n"
                  << "2. Calculati maximul.\n"
                  << "3. Calculati pozitia minimului.\n"
                  << "4. Calculati pozitia maximului.\n"
                  << "5. Calculati suma elementelor.\n"
                  << "6. Reintroduceti elementele.\n"
                  << "7. Sortati elementele.\n"
                  << "8. Afisati statistici (media, varianța, mediana).\n"
                  << "0. Inapoi.\n";
        std::cin >> option;
    }
}

void ArrayMenu::handleArrayOption(Array& array, int option) {
    switch (option) {
        case 1:
            std::cout << "Valoarea minima din array este: " << array.getMin() << ".\n";
            break;
        case 2:
            std::cout << "Valoarea maxima din array este: " << array.getMax() << ".\n";
            break;
        case 3:
            std::cout << "Pozitia valorii minime din array este: " << array.getPozMin() << ".\n";
            break;
        case 4:
            std::cout << "Pozitia valorii maxime din array este: " << array.getPozMax() << ".\n";
            break;
        case 5:
            std::cout << "Suma elementelor din array este: " << array.getSum() << ".\n";
            break;
        case 6:
            std::cout << "Reintroduceti valorile pentru array:\n";
            std::cin >> array;
            break;
        case 7: {
            int order;
            std::cout << "Crescator / Descrescator? (1 / 0): ";
            std::cin >> order;
            array.sort(order == 1 ? 1 : -1);
            std::cout << "Array-ul a fost sortat!\n";
            break;
        }
        default:
            std::cout << "Optiune invalida!\n";
            break;
    }
}

void ArrayMenu::displayStatistics(const Array& array) {
    std::cout << "Statistici pentru array-ul selectat:\n";
    std::cout << "Media: " << Statistics::getMediaElementelor(array) << "\n";
    std::cout << "Varianța: " << Statistics::getVarianta(array) << "\n";
    std::cout << "Mediana: " << Statistics::getMediana(array) << "\n";
}
