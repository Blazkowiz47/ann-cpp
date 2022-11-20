#ifndef INITIALISER_H
#define INITIALISER_H

#include <cstdlib>
#include <string>
#include <vector>

namespace ANN {
    class Initialiser {
        public:
            void static random(std::vector<std::vector<double>> &result);
            void static zeros(std::vector<std::vector<double>> &result);
            auto static initialiser(std::string initialiser) {
                if (initialiser.compare("random") == 0) {
                    return random;
                }
                else if (initialiser.compare("zeros") == 0) {
                    return zeros;
                }
                return random;
            }
    };
}

#endif