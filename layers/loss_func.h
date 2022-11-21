#ifndef LOSSF_H
#define LOSSF_H

#include <vector>
#include <string>


namespace ANN {
    class Loss_function {
        public:
            void static mse(double &result, std::vector<std::vector<double>> &a, std::vector<std::vector<double>> &y);
            void static cross_entropy(double &result, std::vector<std::vector<double>> &a, std::vector<std::vector<double>> &y);
            

            void static d_mse(std::vector<std::vector<double>> &result,std::vector<std::vector<double>> &a,std::vector<std::vector<double>> &y);
            void static d_cross_entropy(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &a,std::vector<std::vector<double>> &y);
            
            
            auto static loss_function(std::string loss_fun) {
                if (loss_fun.compare("mse") == 0) {
                    return mse;
                }
                else if (loss_fun.compare("cross-entropy") == 0) {
                    return cross_entropy;
                }
                return mse;
            }

            auto static d_loss_function(std::string loss_fun) {
                if (loss_fun.compare("mse") == 0) {
                    return d_mse;
                }
                else if (loss_fun.compare("cross-entropy") == 0) {
                    return d_cross_entropy;
                }
                return d_mse;
            }
    };
}


#endif

