#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <vector>
#include <string>


namespace ANN {
    class Activation {
        public:
           void static relu(std::vector<std::vector<double>> &z);
            void static sigmoid(std::vector<std::vector<double>> &z);
            void static linear(std::vector<std::vector<double>> &z);

            void static d_linear(std::vector<std::vector<double>> &a);
            void static d_sigmoid(std::vector<std::vector<double>> &a);
            void static d_relu(std::vector<std::vector<double>> &a);
            
            auto static activation(std::string activation) {
                if (activation.compare("relu") == 0) {
                    return relu;
                }
                else if (activation.compare("sigmoid") == 0) {
                    return sigmoid;
                }
                return linear;
            }

            auto static d_activation(std::string activation) {
                if (activation.compare("relu") == 0) {
                    return d_relu;
                }
                else if (activation.compare("sigmoid") == 0) {
                    return d_sigmoid;
                }
                return d_linear;
            }
    };
}


#endif

