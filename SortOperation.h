#ifndef SORTOPERATION_H
#define SORTOPERATION_H

#include "Operation.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

class SortOperation : public Operation {
private:
    std::vector<int> data;

public:
    explicit SortOperation(const std::vector<int>& data)
        : Operation("Sort by ascending order"), data(data) {}

    void execute() const override {
        std::vector<int> sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
        std::cout << "Sorted data: ";
        for (int val : sortedData) std::cout << val << " ";
        std::cout << "\n";
    }

    std::string getDescription() const override {
        return "Sort Operation";
    }

    std::unique_ptr<Operation> clone() const override {
        return std::make_unique<SortOperation>(*this);
    }
};


#endif // SORTOPERATION_H
