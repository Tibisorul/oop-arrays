#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

template <typename T>
class Calculator {
private:
    std::vector<T> data;

public:
    explicit Calculator(const std::vector<T>& inputData) : data(inputData) {
        if (data.empty()) {
            throw std::invalid_argument("Vectorul de date este gol.");
        }
    }

    T getSuma() const {
        return std::accumulate(data.begin(), data.end(), static_cast<T>(0));
    }

    T getMax() const {
        return *std::max_element(data.begin(), data.end());
    }

    T getMin() const {
        return *std::min_element(data.begin(), data.end());
    }
};

template <typename T>
void afiseazaVector(const std::vector<T>& vec) {
    std::cout << "Vectorul contine elementele: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

#endif //CALCULATOR_H
