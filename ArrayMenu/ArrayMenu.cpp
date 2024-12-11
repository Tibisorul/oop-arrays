#include "ArrayMenu.h"
#include <iostream>
#include "../StatisticsOperation.h"
#include "../SortOperation.h"

/*
void ArrayMenu::handleOperation(const Operation& operation) {
    std::cout << "Executam operatia: " << operation.getDescription() << "\n";
    operation.execute();

    if (dynamic_cast<const SortOperation*>(&operation)) {
        std::cout << "Aceasta este o operatie de sortare!\n";
    } else if (dynamic_cast<const StatisticsOperation*>(&operation)) {
        std::cout << "Aceasta este o operatie de statistici!\n";
    }
}
*/

ArrayMenu::ArrayMenu() {
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

    if (std::cin.fail() || arr < 1 || arr > static_cast<int>(arrays.size())) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Acest array nu exista, va rugam sa reintroduceti.\n";
        return;
    }

    Array& selectedArray = arrays[arr - 1];
    std::cout << selectedArray;

    int option;

    auto displayOptions = []() {
        std::cout << " Alegeti o optiune:\n"
                  << "1. Calculati minimul.\n"
                  << "2. Calculati maximul.\n"
                  << "3. Calculati pozitia minimului.\n"
                  << "4. Calculati pozitia maximului.\n"
                  << "5. Calculati suma elementelor.\n"
                  << "6. Reintroduceti elementele.\n"
                  << "7. Sortati elementele.\n"
                  << "8. Afisati statistici (media, varianta, mediana).\n"
                  << "9. Identificati operatia.\n"
                  << "0. Inapoi.\n";
    };

    displayOptions();
    std::cin >> option;

    while (option != 0) {
        try {
            if (option == 8) {
                displayStatistics(selectedArray);
            } else if (option == 9) {
                identifyOperation();
            } else {
                handleArrayOption(selectedArray, option);
            }
        } catch (const CustomException& ex) {
            std::cout << "A aparut o eroare: " << ex.what() << "\n";
        }

        std::cout << selectedArray;
        displayOptions();
        std::cin >> option;
    }
}

void ArrayMenu::handleArrayOption(Array& array, int option) {
    switch (option) {
        case 1:
            std::cout << "Valoarea minima din array este: " << array.getMin() << ".\n";
            operations.push_back(std::make_unique<StatisticsOperation>(
                "Calculati minimul", array.getData()));
            break;
        case 2:
            std::cout << "Valoarea maxima din array este: " << array.getMax() << ".\n";
            operations.push_back(std::make_unique<StatisticsOperation>(
                "Calculati maximul", array.getData()));
            break;
        case 3:
            std::cout << "Pozitia valorii minime din array este: " << array.getPozMin() << ".\n";
            operations.push_back(std::make_unique<StatisticsOperation>(
                "Calculati pozitia minimului", array.getData()));
            break;
        case 4:
            std::cout << "Pozitia valorii maxime din array este: " << array.getPozMax() << ".\n";
            operations.push_back(std::make_unique<StatisticsOperation>(
                "Calculati pozitia maximului", array.getData()));
            break;
        case 5:
            std::cout << "Suma elementelor din array este: " << array.getSum() << ".\n";
            operations.push_back(std::make_unique<StatisticsOperation>(
                "Calculati suma", array.getData()));
            break;
        case 6:
            std::cout << "Reintroduceti valorile pentru array:\n";
            std::cin >> array;
            break;
        case 7: {
            int order;
            std::cout << "Crescator / Descrescator? (1 / 0): ";
            std::cin >> order;

            try {
                array.sort(order == 1 ? 1 : -1);
                std::cout << "Array-ul a fost sortat!\n";
                operations.push_back(std::make_unique<SortOperation>(
                    (order == 1 ? "Sortati in ordine crescatoare" : "Sortati in ordine descrescatoare"),
                    array.getData()));
            } catch (const std::exception& e) {
                std::cerr << "Eroare la sortare: " << e.what() << "\n";
            }
            break;
        }
        case 8:
            displayStatistics(array);
            break;
        case 9:
            identifyOperation();
            break;
        default:
            std::cout << "Optiune invalida!\n";
            break;
    }
}

void ArrayMenu::identifyOperation() {
    if (operations.empty()) {
        std::cout << "Nu exista operatii disponibile.\n";
        return;
    }

    std::cout << "Lista operatiilor curente:\n";
    for (size_t i = 0; i < operations.size(); ++i) {
        std::cout << i + 1 << ". " << operations[i]->getDescription() << "\n";
    }

    std::cout << "Selectati indexul operatiei (1 la " << operations.size() << "): ";
    int index;
    std::cin >> index;

    if (index < 1 || index > static_cast<int>(operations.size())) {
        std::cout << "Index invalid.\n";
        return;
    }

    const auto& op = operations[index - 1];

    std::cout << "Descrierea operatiei: " << op->getDescription() << "\n";

    if (dynamic_cast<SortOperation*>(op.get())) {
        std::cout << "Aceasta este o operatie de sortare.\n";
    } else if (dynamic_cast<StatisticsOperation*>(op.get())) {
        std::cout << "Aceasta este o operatie de statistici.\n";
    } else {
        std::cout << "Tip de operatie necunoscut.\n";
    }
}

void ArrayMenu::displayStatistics(const Array& array) {
    std::vector<int> data = array.getData();

    if (data.empty()) {
        std::cout << "Nu se pot calcula statistici pentru un array gol.\n";
        return;
    }

    double media = Statistics::getMediaElementelor(data);
    double varianta = Statistics::getVarianta(data);
    double mediana = Statistics::getMediana(data);

    std::cout << "Statistici pentru array-ul selectat:\n";
    std::cout << "Media: " << media << "\n";
    std::cout << "Varianta: " << varianta << "\n";
    std::cout << "Mediana: " << mediana << "\n";
}
