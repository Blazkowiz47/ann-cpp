#ifndef DENSELAYER_H
#define DENSELAYER_H

#include <vector>
#include <utility>
#include <string>
#include <layer.h>


class DenseLayer : public Layer
{
    private:
        int input_features;
        int output_features;
        std::vector<std::vector<double>> weights;
        std::vector<double> bias; 
        std::string activation;
        std::pair<double,double> grad_clip;        

    public:
        DenseLayer(int input_features, int output_features, std::string activation = "linear", std::string weight_initialiser = "random", std::string bias_initialiser = "zero", std::pair<double,double> grad_clip = std::make_pair<double,double>(-100.0, 100.0));
        void initialise();
        void feedforward(std::vector<std::vector<double>> a_prev);
        void backpropogation(std::vector<std::vector<double>> da_next, std::vector<std::vector<double>> a_prev, std::vector<std::vector<double>> z);

};

#endif