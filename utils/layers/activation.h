#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <vector>

namespace ANN
{
    void relu(std::vector<std::vector<double>> &result);
    void sigmoid(std::vector<std::vector<double>> &result);
}

#endif

