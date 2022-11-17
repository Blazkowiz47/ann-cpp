#ifndef CONVLAYER_H
#define CONVLAYER_H

#include <vector>
#include <utility>
#include <string>
#include <layer.h>

class ConvLayer : Layer
{
     private:
        int input_channels;
        int output_channels;
        int stride;
        int padding;
        std::vector<std::vector<std::vector<std::vector<double>>>> filters;
        std::vector<double> bias;
        std::string activation;
        std::pair<double,double> grad_clip;

    public:
        ConvLayer(int input_channels, int output_channels, int stride = 1, int padding = 1, std::string activation = "linear", std::string weight_initialiser = "random", std::string bias_initialiser = "zero", std::pair<double,double> grad_clip = std::make_pair<double,double>(-100.0, 100.0));
        void initialise();
        void feedforward(std::vector<std::vector<std::vector<std::vector<double>>>> a_prev);
        void backpropogation(std::vector<std::vector<std::vector<std::vector<double>>>> da_next, std::vector<std::vector<std::vector<std::vector<double>>>> a_prev, std::vector<std::vector<std::vector<std::vector<double>>>> z);
};

#endif