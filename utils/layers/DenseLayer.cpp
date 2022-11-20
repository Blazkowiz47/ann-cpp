#include <vector>
#include <utility>
#include <string>
#include <layer.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "linalg.h"
#include "DenseLayer.h"



int input_features;
        int output_features;
        std::vector<std::vector<double>> weights, z, a_prev;
        std::vector<double> bias; 
        std::string activation;


DenseLayer::DenseLayer(int input_features, int output_features, std::string activation = "linear",
 std::string weight_initialiser = "random", 
 std::string bias_initialiser = "zero", std::pair<double,double> grad_clip = std::make_pair<double,double>(-100.0, 100.0))
{
    input_features=25;
    output_features=10;
    // grad_clip=(-100,100);
    initialise(weight_initialiser,bias_initialiser);
 
}
void initialise(std::string weight_initialiser = "random", std::string bias_initialiser = "zero")
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
        bias[i]=0;
    }
    
    
}

std::vector<std::vector<double>> feedforward(std::vector<std::vector<double>> a_prev)
{
    std::vector<std::vector<double>> z;
    std::vector<std::vector<double>> a;
    int r=a_prev.size();
    int c=a_prev[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            ANN::multiply(z,a_prev,weights);
        }
    }

    ANN::add(z,z,bias);

    ANN::sigmoid(a,z);

    
    return a;


}

std::vector<std::vector<double>> backpropogation(std::vector<std::vector<double>> da_next)
{

}