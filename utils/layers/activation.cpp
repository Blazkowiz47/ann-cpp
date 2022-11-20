#include <vector>
#include "activation.h"
#include "linalg.h"


namespace ANN
{

  void relu(std::vector<std::vector<double>> &z)
  {
    for (int i = 0; i < z.size(); i++)
    {
      for (int j = 0; j < z[0].size(); j++)
      {
        if (z[i][j] < 0)
        {
          z[i][j] = 0;
        }
      }
    }
  }

  void sigmoid(std::vector<std::vector<double>> &z)
  {
    ANN::multiply(z,z,-1);
    ANN::exp(z,z);
    ANN::add(z,z,1);
    ANN::inv(z,z);

  }
 void linear(std::vector<std::vector<double>> &z)
 {

 }

 void d_relu(std::vector<std::vector<double>> &a)
 {
    for (int i = 0; i < a.size(); i++)
    {
      for (int j = 0; j < a[0].size(); j++)
      {
        if (a[i][j] > 0)
        {
          a[i][j] = 1;
        }
        else a[i][j] = 0;
      }
    }
 }


 void d_sigmoid(std::vector<std::vector<double>> &a)
 {
    std::vector<std::vector<double>> temp;

    ANN::multiply(temp,a,-1);
    ANN::add(temp,temp,1);
    ANN::multiply(a,a,temp);
 }

 void d_linear(std::vector<std::vector<double>> &a)
 {
    a = std::vector(a.size(), std::vector<double>(a[0].size(), 1.0));

 }
}

