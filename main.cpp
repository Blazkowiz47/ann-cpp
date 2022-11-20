#include <iostream>
#include <vector>
#include "layers/DenseLayer.h"

int main() {
    ANN::DenseLayer a = ANN::DenseLayer(3,2);
    a.print_weights();
    std::vector<std::vector<double>> o, x = {{1,1,1}, {0,0,0}, {2,2,2}};
    o = a.feedforward(x);
    for(auto x : o) {
        for (auto y : x) {
            std::cout<<y<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    a.backpropogation({{1, 0}, {0, 0}, {1, 1}});
    a.update_weights(100);
    a.print_weights();

    return 0;   
}