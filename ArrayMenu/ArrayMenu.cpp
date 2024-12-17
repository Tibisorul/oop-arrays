#include "ArrayMenu.h"
#include "../Logger.h"
#include "../ArrayFactory/ArrayFactory.h"
#include <iostream>
#include "../StatisticsOperation.h"
#include "../SortOperation.h"
#include "../Statistics/Statistics.h"
#include "../CalculatorTemplate/Calculator.h"

void ArrayMenu::handleOperation(const Operation& operation) {
    std::cout << "Executam operatia: " << operation.getDescription() << "\n";
    operation.execute();

    if (dynamic_cast<const SortOperation*>(&operation)) {
        std::cout << "Aceasta este o operatie de sortare!\n";
    } else if (dynamic_cast<const StatisticsOperation*>(&operation)) {
        std::cout << "Aceasta este o operatie de statistici!\n";
    }
}

ArrayMenu::ArrayMenu() = default;

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
    std::cout << "Iesire din aplicatie...";
    Logger::getInstance()->log("[INFO] Aplicatia a fost inchisa.");
}


void ArrayMenu::addArray() {
    int n;
    std::cout << "Introduceti dimensiunea array-ului: ";
    std::cin >> n;

    if (n <= 0 || std::cin.fail()) {
        Logger::getInstance()->log("[ERROR] Dimensiune invalida pentru array.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Dimensiunea trebuie sa fie mai mare decat 0. Operatia a fost anulata.\n";
        return;
    }

    std::cout << "Introduceti valorile array-ului:\n";
    int* valori = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> valori[i];
        if (std::cin.fail()) {
            Logger::getInstance()->log("[ERROR] Valoare invalida introdusa pentru array.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Valoare invalida detectata. Operatia a fost anulata.\n";
            delete[] valori;
            return;
        }
    }


    Array a = ArrayFactory::createArrayWithValues(n, valori);
    arrays.push_back(a);


    Logger::getInstance()->log("[INFO] Un array nou a fost adaugat. Dimensiune: " + std::to_string(a.getN()));

    std::cout << "Array adaugat cu succes!\n";

    delete[] valori;
}


void ArrayMenu::removeArray() {
    int x;
    std::cout << "Introduceti numarul array-ului pe care doriti sa il stergeti (1 - " << arrays.size() << "):\n";
    std::cin >> x;

    if (x < 1 || x > static_cast<int>(arrays.size())) {
        Logger::getInstance()->log("[ERROR] Index invalid la stergerea array-ului.");
        std::cout << "Acest array nu exista, va rugam sa reintroduceti.\n";
        return;
    }
    arrays.erase(arrays.begin() + x - 1);
    Logger::getInstance()->log("[INFO] Array-ul a fost sters cu succes.");
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
    //std::cout << selectedArray;

    afiseazaVector(selectedArray.getData());

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
                  << "10. Resetare array.\n"
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
        case 6: {
            std::cout << "Reintroduceti dimensiunea array-ului: ";
            int n;
            std::cin >> n;

            if (n <= 0 || std::cin.fail()) {
                Logger::getInstance()->log("[ERROR] Dimensiune invalida pentru reintroducerea array-ului.");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Dimensiunea trebuie sa fie mai mare decat 0. Operatia a fost anulata.\n";
                return;
            }

            std::cout << "Introduceti valorile array-ului:\n";
            int* valori = new int[n];
            for (int i = 0; i < n; ++i) {
                std::cin >> valori[i];
            }

            array = ArrayFactory::createArrayWithValues(n, valori);
            Logger::getInstance()->log("[INFO] Array-ul a fost reintrodus cu succes. Dimensiune: " + std::to_string(n));

            delete[] valori;
            break;
        }
        case 7: {
            int order;
            std::cout << "Crescator / Descrescator? (1 / 0): ";
            std::cin >> order;

            try {
                array.sort(order == 1 ? 1 : -1);
                Logger::getInstance()->log("[INFO] Operatia de sortare a fost executata.");
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
        case 10: {
            array = ArrayFactory::createEmptyArray();
            Logger::getInstance()->log("[INFO] Array-ul a fost resetat la valori implicite.");
            std::cout << "Array-ul a fost resetat!\n";
            break;
        }
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

    std::cout << "Lista de operatii curente:\n";
    for (size_t i = 0; i < operations.size(); ++i) {
        std::cout << i + 1 << ". " << operations[i]->getDescription() << "\n";
    }

    std::cout << "Selectati indexul operatiei (1 - " << operations.size() << "): ";
    int index;
    std::cin >> index;

    if (index < 1 || index > static_cast<int>(operations.size())) {
        std::cout << "Index invalid.\n";
        return;
    }

    const auto& selectedOperation = operations[index - 1];

    handleOperation(*selectedOperation);

    auto clonedOperation = selectedOperation->clone();

    std::cout << "Operatia clonata: " << clonedOperation->getDescription() << "\n";

    if (dynamic_cast<SortOperation*>(clonedOperation.get())) {
        std::cout << "Aceasta este o operatie de sortare.\n";
    } else if (dynamic_cast<StatisticsOperation*>(clonedOperation.get())) {
        std::cout << "Aceasta este o operatie de statistici.\n";
    } else {
        std::cout << "Tip necunoscut de operatie.\n";
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
