#include <cstdint>
#include <iostream>
#include <valarray>
#include <vector>

#include "SortOperation.h"
#include "StatisticsOperation.h"
#include "Array/Array.h"
#include "Statistics/Statistics.h"
#include "ArrayMenu/ArrayMenu.h"
#include "../Logger.h"

int main() {

    ArrayMenu menu;
    menu.run();


    /*try {

        ArrayMenu menu;
        menu.run();

        int valori[] = {1, 2, 3, 4, 5};
        Array array(5, valori);

        std::cout << "Suma elementelor array-ului este: " << array.getSum() << "\n";

        std::cout << "Elementul pe index-ul 2: " << array[2] << "\n";

        std::cout << "Incercare de accesare a unui index invalid: \n";
        std::cout << array[10] << "\n";

    } catch (const InvalidIndexException& e) {
        std::cerr << "InvalidIndexException prins: " << e.what() << "\n";
    } catch (const InvalidSizeException& e) {
        std::cerr << "InvalidSizeException prins: " << e.what() << "\n";
    } catch (const EmptyArrayException& e) {
        std::cerr << "EmptyArrayException prins: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Standard exception prins: " << e.what() << "\n";
    }

    std::cout << "Executia programului continua: \n";*/

    return 0;
}




