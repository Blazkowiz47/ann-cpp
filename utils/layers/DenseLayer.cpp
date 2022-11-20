#include <vector>
#include <utility>
#include <string>
#include <iostream>

#include "DenseLayer.h"
#include "init.h"
#include "layer.h"
#include "linalg.h"
#include "activation.h"

namespace ANN{

    ANN::DenseLayer::DenseLayer(int input_features, int output_features) {
        activation = "linear";
        grad_clip = std::make_pair<double,double>(-100.0, 100.0);
        this->input_features=input_features;
        this->output_features=output_features;

        weights = std::vector(input_features, std::vector<double>(output_features, 0.0));
        bias = std::vector(output_features, std::vector<double>(1, 0.0));

        ANN::Initialiser::initialiser("random")(weights);
        ANN::Initialiser::initialiser("zeros")(bias);
    }

    ANN::DenseLayer::DenseLayer(int input_features, int output_features, std::string activation, std::string weight_initialiser, std::string bias_initialiser, std::pair<double,double> grad_clip)
    {
        this->grad_clip = grad_clip;
        this->input_features=input_features;
        this->output_features=output_features;
        // grad_clip=(-100,100);
        weights = std::vector(input_features, std::vector<double>(output_features, 0.0));
        bias = std::vector(output_features, std::vector<double>(1, 0.0));

        ANN::Initialiser::initialiser(weight_initialiser)(weights);
        ANN::Initialiser::initialiser(bias_initialiser)(bias);
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

    // std::vector<std::vector<double>> DenseLayer::backpropogation(std::vector<std::vector<double>> da_next)
    // {
    //     return {};
    // }
    
    void DenseLayer::print_weights() {

        std::cout<<"Weights:- \n";
        for (int i = 0; i < weights.size(); i++)
        {
            for (int j = 0; j < weights[0].size(); j++)
            {
                std::cout<<weights[i][j]<<" ";
            }
            std::cout<<"\n";
        }

        std::cout<<"Bias:- \n";
        for (int i = 0; i < bias.size(); i++)
        {
            for (int j = 0; j < bias[0].size(); j++)
            {
                std::cout<<bias[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        
    }
}