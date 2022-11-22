#include <vector>
#include "activation.h"
#include "linalg.h"
#include "loss_func.h"

namespace ANN
{

    void Loss_function::mse(double &result, std::vector<std::vector<double>> &a, std::vector<std::vector<double>> &y)
    {

        std::vector<std::vector<double>> temp;
        temp = std::vector(a.size(), std::vector<double>(a[0].size(), 0.0));
        ANN::sub(temp,a,y);
        ANN::square(temp, temp);
        ANN::divide(temp,temp,2);
        ANN::mean(result,temp);

       



    }

    void Loss_function::cross_entropy(double &result, std::vector<std::vector<double>> &a, std::vector<std::vector<double>> &y)
    {

    }
            

    void Loss_function::d_mse(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &a,std::vector<std::vector<double>> &y)
    {
        ANN::sub(result,a,y);
    }
    void Loss_function::d_cross_entropy(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &a,std::vector<std::vector<double>> &y)
    {
        
    }

    
}
