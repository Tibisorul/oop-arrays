#ifndef ARRAYMENU_H
#define ARRAYMENU_H

#include "../Array/Array.h"
#include "../Statistics/Statistics.h"
#include <vector>
#include "../Operation.h"



class ArrayMenu {
private:
    std::vector<Array> arrays;
    std::vector<std::unique_ptr<Operation>> operations;

public:
    ArrayMenu();

    void run();
    static void handleOperation(const Operation& operation);


private:
    void addArray();
    void removeArray();
    void viewArray();
    void handleArrayOption(Array& array, int option);
    static void displayStatistics(const Array& array);
    void identifyOperation();

};

#endif
