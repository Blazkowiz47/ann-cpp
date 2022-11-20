#include <vector>
#include <utility>
#include <string>
#include <iostream>

#include "DenseLayer.h"
#include "initialiser.h"
#include "layer.h"
#include "linalg.h"

namespace ANN{

    DenseLayer::DenseLayer(int input_features, int output_features, std::string activation = "linear",
    std::string weight_initialiser = "random", 
    std::string bias_initialiser = "zero", std::pair<double,double> grad_clip = std::make_pair<double,double>(-100.0, 100.0))
    {
        input_features=25;
        output_features=10;
        // grad_clip=(-100,100);
        weights = std::vector(input_features, std::vector<double>(output_features, 0.0));
        bias = std::vector(output_features, std::vector<double>(1, 0.0));

        ANN::initialiser(weight_initialiser)(weights);
        ANN::initialiser(bias_initialiser)(bias);
    }

    std::vector<std::vector<double>> DenseLayer::feedforward(std::vector<std::vector<double>> a_prev)
    {
        std::vector<std::vector<double>> z;
        std::vector<std::vector<double>> a;
        int r=a_prev.size();
        int c=a_prev[0].size();

        ANN::multiply(z,a_prev,weights);

        ANN::add(z,z,bias);
        
        ANN::exp(a,z);

        
        return a;


    }

    std::vector<std::vector<double>> DenseLayer::backpropogation(std::vector<std::vector<double>> da_next)
    {

    }

}