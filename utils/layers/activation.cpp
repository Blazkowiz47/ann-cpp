#include <vector>
#include "activation.h"

namespace ANN
{

  void relu(std::vector<std::vector<double>> &result)
  {
    for (int i = 0; i < result.size(); i++)
    {
      for (int j = 0; j < result[0].size(); j++)
      {
        if (result[i][j] < 0)
        {
          result[i][j] = 0;
        }
      }
    }
  }

  void sigmoid(std::vector<std::vector<double>> &result)
  {
    for (int i = 0; i < result.size(); i++)
    {
      for (int j = 0; j < result[0].size(); j++)
      {
        //   result[i][j] = 1/(1+exp(result[i][j]));
      }
    }
  }
}

