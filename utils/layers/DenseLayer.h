#ifndef DENSELAYER_H
#define DENSELAYER_H
#include <vector>
#include <utility>
#include <string>
#include "layer.h"

namespace ANN
{
    class DenseLayer : public ANN::Layer
    {
        private:
            int input_features;
            int output_features;
            std::vector<std::vector<double>> weights, z, a_prev;
            std::vector<std::vector<double>> bias; 
            std::string activation;
            std::pair<double,double> grad_clip;        

        public:
            DenseLayer(int input_features, int output_features);
            DenseLayer(int input_features, int output_features, std::string activation, std::string weight_initialiser, std::string bias_initialiser, std::pair<double,double> grad_clip);
            std::vector<std::vector<double>> feedforward(std::vector<std::vector<double>> a_prev);
            std::vector<std::vector<double>> backpropogation(std::vector<std::vector<double>> da_next);
            void print_weights();
    };
}

#endif
