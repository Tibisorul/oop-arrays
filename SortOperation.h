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
    explicit SortOperation(const std::string& description, const std::vector<int>& data)
        : Operation(description), data(data) {}

    void execute() const override {
        if (data.empty()) {
            std::cout << "No data to sort.\n";
            return;
        }
        std::vector<int> sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
        std::cout << "Sorted data: ";
        for (int val : sortedData) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::string getDescription() const override {
        return "Sort Operation";
    }

    std::unique_ptr<Operation> clone() const override {
        return std::make_unique<SortOperation>(*this);
    }
};

#endif
