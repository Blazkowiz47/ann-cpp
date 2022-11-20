#include<vector>
#include <cstdlib>
#include <time.h>

#include "init.h"


namespace ANN {

    void Initialiser::random(std::vector<std::vector<double>> &result) {
        srand(time(0));
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[0].size();j++)
            {
                result[i][j]=rand();
            }
        }
    }

    void Initialiser::zeros(std::vector<std::vector<double>> &result) {
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[0].size();j++)
            {
                result[i][j]=0.0;
            }
        }
    }
    
}