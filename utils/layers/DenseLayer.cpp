#include <vector>
#include <utility>
#include <string>
#include <layer.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "DenseLayer.h"
#include "linalg.h"
#include "activation.h"

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
        
        initialise(weight_initialiser,bias_initialiser);
    
    }
    void DenseLayer::initialise(std::string weight_initialiser = "random", std::string bias_initialiser = "zero")
    {
        srand(time(0));
        for(int i=0;i<weights.size();i++)
        {
            for(int j=0;j<weights[0].size();j++)
            {
                weights[i][j]=rand();
            }
        }

        for(int i=0;i<bias.size();i++)
        {
            bias[i][0]=0;
        }
        
        
    }

    std::vector<std::vector<double>> DenseLayer::feedforward(std::vector<std::vector<double>> a_prev)
    {
        std::vector<std::vector<double>> z;
        std::vector<std::vector<double>> a;
        int r=a_prev.size();
        int c=a_prev[0].size();

        ANN::multiply(z,a_prev,weights);

        ANN::add(z,z,bias);
        
        ANN::sigmoid(a,z);

        
        return a;


    }

    std::vector<std::vector<double>> DenseLayer::backpropogation(std::vector<std::vector<double>> da_next)
    {

    }
}