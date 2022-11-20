#include <vector>
#include <utility>
#include <string>
#include <iostream>

#include "DenseLayer.h"
#include "initialiser.h"
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
        this->activation = activation;
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
        
        this->a_prev = ANN::copy(a_prev);

        int r=a_prev.size();
        int c=a_prev[0].size();

        ANN::dot(z,a_prev,weights);
        ANN::add(z,z,bias);
        
        this->z=ANN::copy(z);

        ANN::Activation::activation(this->activation)(z);
        
        this->a=ANN::copy(z);

        return a;
    }

    std::vector<std::vector<double>> DenseLayer::backpropogation(std::vector<std::vector<double>> da_next)
    {
        std::vector<std::vector<double>> a_prev_t, dg, dw, db, dz, w_t, da;
        ANN::Activation::d_activation(this->activation)(a);
        dg=a;

        ANN::transpose(w_t,weights);
        ANN::multiply(dz,da_next,dg);
        ANN::transpose(a_prev,a_prev);
        a_prev_t=a_prev;

        ANN::dot(dw,a_prev_t,dz);
        ANN::sum(db,dz,0);
        ANN::dot(da,dz,w_t);

        this->db=ANN::copy(db);
        this->dw=ANN::copy(dw);
        

        return da;
    }

    void DenseLayer::update_weights(double lr)
    {

        ANN::multiply(dw,dw,-lr);
        ANN::add(weights,weights,dw);
        ANN::multiply(db,db,-lr);
        ANN::add(bias,bias,db);
    }

   
    
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

        std::cout<<"\nBias:- \n";
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