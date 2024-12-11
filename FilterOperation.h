
#ifndef FILTEROPERATION_H
#define FILTEROPERATION_H

#include "Operation.h"
#include <vector>
#include <iostream>

class FilterOperation : public Operation {
private:
    std::vector<int> data;

public:
    explicit FilterOperation(const std::vector<int>& data)
        : Operation("Filter elements greater than 10"), data(data) {}

    void execute() const override {
        std::cout << "Filtered data: ";
        for (int val : data) {
            if (val > 10) {
                std::cout << val << " ";
            }
        }
        std::cout << "\n";
    }

    std::string getDescription() const override {
        return "Filter Operation";
    }

    std::unique_ptr<Operation> clone() const override {
        return std::make_unique<FilterOperation>(*this);
    }
};


#endif //FILTEROPERATION_H
