#include <iostream>
#include "utils/layers/DenseLayer.h"

int main() {
    ANN::DenseLayer a = ANN::DenseLayer(3,2);
    a.print_weights();
    return 0;   
}