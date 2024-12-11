#ifndef STATISTICSOPERATION_H
#define STATISTICSOPERATION_H

#include "Operation.h"
#include <vector>
#include <numeric>
#include <cmath>

class StatisticsOperation : public Operation {
private:
    std::vector<int> data;

public:
    explicit StatisticsOperation(const std::string& description, const std::vector<int>& data)
        : Operation(description), data(data) {}

    void execute() const override {
        if (data.empty()) {
            std::cout << "Data este goala.\n";
            return;
        }

        double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        double variance = 0.0;

        for (int val : data) {
            variance += (val - mean) * (val - mean);
        }
        variance /= data.size();
        double stddev = std::sqrt(variance);

        std::cout << "Media: " << mean << ", Varianta: " << variance << ", StdDev: " << stddev << "\n";
    }

    std::string getDescription() const override {
        return "Statistics Operation";
    }

    std::unique_ptr<Operation> clone() const override {
        return std::make_unique<StatisticsOperation>(*this);
    }
};

#endif
