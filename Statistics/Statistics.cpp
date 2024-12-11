#include "Statistics.h"
#include <algorithm>
#include <numeric>


double Statistics::getMediaElementelor(const std::vector<int>& data) {
    if (data.empty()) return 0.0;
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double Statistics::getVarianta(const std::vector<int>& data) {
    if (data.size() < 2) return 0.0;
    double mean = getMediaElementelor(data);
    double variance = 0.0;
    for (int value : data) {
        variance += (value - mean) * (value - mean);
    }
    return variance / data.size();
}

double Statistics::getMediana(std::vector<int> data) {
    if (data.empty()) return 0.0;
    std::sort(data.begin(), data.end());
    size_t n = data.size();
    if (n % 2 == 0) {
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    } else {
        return data[n / 2];
    }
}