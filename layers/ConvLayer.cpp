#include <vector>
#include <utility>
#include <string>
#include <iostream>



#include "initialiser.h"
#include "layer.h"
#include "linalg.h"
#include "activation.h"
#include "ConvLayer.h"

namespace ANN{
    ANN::ConvLayer::ConvLayer(int input_channels, int output_channels, std::string activation)
    {
        this->input_channels=input_channels; 
        this->output_channels=output_channels;
        this->stride = 1;
        this->activation = activation;
    }

    ANN::ConvLayer::ConvLayer(int input_channels, int output_channels, int stride, int padding, std::string activation, std::string weight_initialiser, std::string bias_initialise, std::pair<double,double> grad_clip)
    {
        this->input_channels=input_channels; 
        this->output_channels=output_channels;
        this->stride = 1;
        this->padding = padding;
        this->activation = activation;
        
        this->grad_clip = grad_clip;
        this->activation = activation;
        
        //  std::string weight_initialiser = "random", std::string bias_initialiser = "zero", 
        

        // weights = std::vector(input_features, std::vector<double>(output_features, 0.0));
        // bias = std::vector(output_features, std::vector<double>(1, 0.0));

        // ANN::Initialiser::initialiser("random")(weights);
        // ANN::Initialiser::initialiser("zeros")(bias);
    }

   

    void ConvLayer::feedforward(std::vector<std::vector<std::vector<std::vector<double>>>> a_prev)
    {

    }

    void ConvLayer::backpropogation(std::vector<std::vector<std::vector<std::vector<double>>>> da_next, std::vector<std::vector<std::vector<std::vector<double>>>> a_prev, std::vector<std::vector<std::vector<std::vector<double>>>> z)
    {
        
    }

    void ConvLayer::update_weights(double lr)
    {

       
    }

   
    
    // void DenseLayer::print_weights() {

    //     std::cout<<"Weights:- \n";
    //     for (int i = 0; i < weights.size(); i++)
    //     {
    //         for (int j = 0; j < weights[0].size(); j++)
    //         {
    //             std::cout<<weights[i][j]<<" ";
    //         }
    //         std::cout<<"\n";
    //     }

    //     std::cout<<"\nBias:- \n";
    //     for (int i = 0; i < bias.size(); i++)
    //     {
    //         for (int j = 0; j < bias[0].size(); j++)
    //         {
    //             std::cout<<bias[i][j]<<" ";
    //         }
    //         std::cout<<"\n";
    //     }
        
    // }
}