#ifndef INITIALISER_H
#define INITIALISER_H

#include <cstdlib>
#include <string>
#include <vector>

namespace ANN {
    auto initialiser(std::string initialiser) {
        if (initialiser.compare("random") == 0) {
            return ANN::random;
        }
        else if (initialiser.compare("zeros") == 0) {
            return ANN::zeros;
        }
    }
    void random(std::vector<std::vector<double>> &result);
    void zeros(std::vector<std::vector<double>> &result);
}

#endif