#ifndef STATISTICS_H
#define STATISTICS_H

#include "../Array/Array.h"
#include <cmath>

class Statistics {
public:
    static double getMediaElementelor(const std::vector<int>& data);
    static double getVarianta(const std::vector<int>& data);
    static double getMediana(std::vector<int> data);
};

#endif
