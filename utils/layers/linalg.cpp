#include <numeric>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>

#include "linalg.h"

namespace ANN
{
    void normalise(std::vector<std::vector<double>> &result,std::vector<std::vector<double>> &matrix)
    {
        std::vector<std::vector<double>> result = std::vector(matrix.size(), std::vector<double>(matrix[0].size(), 0.0));
        double max1=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                max1=std::max(max1,matrix[i][j]);
            }
        }

        ANN::divide(result,matrix,max1);

    }

    std::vector<std::vector<double>> copy(std::vector<std::vector<double>> &matrix)
    {
        std::vector<std::vector<double>> result = std::vector(matrix.size(), std::vector<double>(matrix[0].size(), 0.0));

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                result[i][j]=matrix[i][j];
            }
        }

        return result;
    }

    std::vector<std::vector<std::vector<std::vector<double>>>> copy(std::vector<std::vector<std::vector<std::vector<double>>>> &matrix)
    {
        auto result = std::vector(matrix.size(), std::vector(matrix[0].size(), std::vector(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0.0))));

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                for(int k=0;k<matrix.size();k++)
                    
                    for(int l=0;l<matrix.size();l++)

                        result[i][j][k][l] = matrix[i][j][k][l];
            }
        }

        return result;
    }

    void dot(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB)
    {
        int rowA = matrixA.size();
        int colA = matrixA[0].size();
        int rowB = matrixB.size();
        int colB = matrixB[0].size();
        if (colA != rowB)
        {
            std::cout << "Dot Function error: Dimension Mismatch" << std::endl;
        }
        result = std::vector<std::vector<double>>(rowA, std::vector<double>(colB, 0));
        // std::vector<std::vector<double>> res(rowA, std::vector<double>(colB, 0));
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colB; j++)
            {
                double sum = 0;
                for (int k = 0; k < colA; k++)
                {
                    sum += matrixA[i][k] * matrixB[k][j];
                }
                result[i][j] = sum;
            }
        }
        // result = res;
    }

    void transpose(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(col, std::vector<double>(row, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[j][i] = matrix[i][j];
            }
        }
        result = res;
    }

    void sum(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, int axis)
    {
        // Axis meaning whether to sum x or y (row or col) (2 for y, 1 for x, 0 for everything)
        std::vector<std::vector<double>> res;
        int row = matrix.size();
        int col = matrix[0].size();
        if (axis == 1)
        {
            res = std::vector<std::vector<double>>(row, std::vector<double>(1, 0));
            for (int i = 0; i < row; i++)
            {
                double sum = 0;
                for (int j = 0; j < col; j++)
                {
                    sum += matrix[i][j];
                }
                res[i][0] = sum;
            }
        }
        else if (axis == 2)
        {
            res = std::vector<std::vector<double>>(1, std::vector<double>(col, 0));
            for (int i = 0; i < col; i++)
            {
                double sum = 0;
                for (int j = 0; j < row; j++)
                {
                    sum += matrix[j][i];
                }
                res[0][i] = sum;
            }
        }
        else
        {
            res = std::vector<std::vector<double>>(1, std::vector<double>(1, 0));
            double sum = 0;
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    sum += matrix[j][i];
                }
            }
            res[0][0] = sum;
        }
        result = res;
    }

    void sum(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrix, int axis)
    {
        int row = matrix[0].size();
        int col = matrix[0][0].size();
        result = std::vector<std::vector<std::vector<double>>>(1, std::vector<std::vector<double>>(1, std::vector<double>(1, 0)));
        // std::vector<std::vector<std::vector<double>>> res(1, std::vector<std::vector<double>>(1, std::vector<double>(1, 0)));
        double sum = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                    sum += matrix[i][j][k];
            }
        }
        result[0][0][0] = sum;
        // result = res;
    }

    void square(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = matrix[i][j] * matrix[i][j];
            }
        }
        result = res;
    }

    void square(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrix[i][j][k][l] * matrix[i][j][k][l];
                    }
                }
            }
        }
        result = res;
    }

    void mean(double &result, std::vector<std::vector<double>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        double sum = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += matrix[i][j];
            }
        }
        result = sum / (row * col);
    }

    void std(double &result, std::vector<std::vector<double>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        double firstMean;
        mean(firstMean, matrix);
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = matrix[i][j] - firstMean;
            }
        }
        ANN::square(res, res);
        double secondMean;
        ANN::mean(secondMean, res);
        result = std::sqrt(secondMean);
    }

    void exp(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = std::exp(matrix[i][j]);
            }
        }
        result = res;
    }

    void exp(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = std::exp(matrix[i][j][k][l]); 
                    }
                }
            }
        }
        result = res;
    }
    
    void inv(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = 1.0/matrix[i][j];
            }
        }
        result = res;
    }

    void inv(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] =1.0 / matrix[i][j][k][l]; 
                    }
                }
            }
        }
        result = res;
    }

    void multiply(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = matrix[i][j] * n;
            }
        }
        result = res;
    }

    void multiply(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB)
    {
        int rowA = matrixA.size();
        int colA = matrixA[0].size();
        int rowB = matrixB.size();
        int colB = matrixB[0].size();
        if (rowA * colA != rowB * colB)
        {
            std::cout << "MultMatrices Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<double>> res(rowA, std::vector<double>(colA, 0));
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)
            {
                res[i][j] = matrixA[i][j] * matrixB[i][j];
            }
        }
        result = res;
    }

    void multiply(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrixA, std::vector<std::vector<std::vector<double>>> &matrixB)
    {
        int rowA = matrixA.size();
        int colA = matrixA[0].size();
        int rowB = matrixB.size();
        int colB = matrixB[0].size();
        if (rowA * colA * matrixA[0][0].size() != rowB * colB * matrixB[0][0].size())
        {
            std::cout << "MultMatrices3D Function error: Dimensions are not the same" << std::endl;
        }
        result = std::vector<std::vector<std::vector<double>>>(rowA, std::vector<std::vector<double>>(colA, std::vector<double>(matrixA[0][0].size(), 0)));
        // std::vector<std::vector<std::vector<double>>> res(rowA, std::vector<std::vector<double>>(colA, std::vector<double>(matrixA[0][0].size(), 0)));
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)
            {
                for (int k = 0; k < matrixA[0][0].size(); k++)
                    result[i][j][k] = matrixA[i][j][k] * matrixB[i][j][k];
            }
        }
        // result = res;
    }

    void multiply(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<double>>> res(row, std::vector<std::vector<double>>(col, std::vector<double>(matrix[0][0].size(), 0)));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    res[i][j][k] = matrix[i][j][k] * n;
                }
            }
        }
        result = res;
    }

    void multiply(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrix[i][j][k][l] * n;
                    }
                }
            }
        }
        result = res;
    }

    void divide(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = matrix[i][j] / n;
            }
        }
        result = res;
    }

    void divide(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrix[i][j][k][l] / n;
                    }
                }
            }
        }
        result = res;
    }

    void divide(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> matrixA, std::vector<std::vector<double>> matrixB)
    {
        int row = matrixA.size();
        int col = matrixA[0].size();
        if (row * col != matrixB.size() * matrixB[0].size())
        {
            std::cout << "Divi2DMat Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = matrixA[i][j] / matrixB[i][j];
            }
        }
        result = res;
    }

    void divide(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixA, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixB)
    {
        int row = matrixA.size();
        int col = matrixA[0].size();
        if (row * col * matrixA[0][0].size() * matrixA[0][0][0].size() != matrixB.size() * matrixB[0].size() * matrixB[0][0].size() * matrixB[0][0][0].size())
        {
            std::cout << "Divi4DMat Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrixA[0][0].size(), std::vector<double>(matrixA[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrixA[0][0].size(); k++)
                {
                    for (int l = 0; l < matrixA[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrixA[i][j][k][l] / matrixB[i][j][k][l];
                    }
                }
            }
        }
        result = res;
    }

    void sub(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB)
    {
        int rowA = matrixA.size();
        int colA = matrixA[0].size();
        int rowB = matrixB.size();
        int colB = matrixB[0].size();
        if (rowA * colA != rowB * colB)
        {
            std::cout << "Sub Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<double>> res(rowA, std::vector<double>(colA, 0));
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)
            {
                res[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        result = res;
    }

    void sub(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixA, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixB)
    {
        int row = matrixA.size();
        int col = matrixA[0].size();
        if (row * col * matrixA[0][0].size() * matrixA[0][0][0].size() != matrixB.size() * matrixB[0].size() * matrixB[0][0].size() * matrixB[0][0][0].size())
        {
            std::cout << "Sub4DMat Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrixA[0][0].size(), std::vector<double>(matrixA[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrixA[0][0].size(); k++)
                {
                    for (int l = 0; l < matrixA[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrixA[i][j][k][l] - matrixB[i][j][k][l];
                    }
                }
            }
        }
        result = res;
    }

    void sqrt(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = std::sqrt(matrix[i][j]);
            }
        }
        result = res;
    }

    void sqrt(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = std::sqrt(matrix[i][j][k][l]);
                    }
                }
            }
        }
        result = res;
    }

    void add(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<double>> res(row, std::vector<double>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[i][j] = matrix[i][j] + n;
            }
        }
        result = res;
    }

    void add(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix, double n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrix[0][0].size(), std::vector<double>(matrix[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrix[0][0].size(); k++)
                {
                    for (int l = 0; l < matrix[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrix[i][j][k][l] + n;
                    }
                }
            }
        }
        result = res;
    }

    void add(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB)
    {
        int rowA = matrixA.size();
        int colA = matrixA[0].size();
        int rowB = matrixB.size();
        int colB = matrixB[0].size();
        int matrixALength = rowA + colA;
        int matrixBLength = rowB + colB;
        // Check if dimensions need broadcasting
        int tempColB = colB;
        if (colB == 1)
        {
            colB = colA;
        }
        int tempColA = colA;
        if (colA == 1)
        {
            colA = colB;
        }
        if (colA != colB)
        {
            std::cout << "Add Function error: Dimension Mismatch" << std::endl;
        }
        colA = tempColA;
        colB = tempColB;
        // Broadcasting
        std::vector<std::vector<double>> mA = matrixA;
        std::vector<std::vector<double>> mB = matrixB;
        int resultRow;
        int resultCol;
        if (rowB < rowA)
        {
            for (int i = 0; i < rowA - rowB; i++)
            {
                mB.push_back(mB[0]);
            }
        }
        else if (rowA < rowB)
        {
            for (int i = 0; i < rowB - rowA; i++)
            {
                mA.push_back(mA[0]);
            }
        }
        if (colB < colA)
        {
            for (int i = 0; i < colA - colB; i++)
            {
                for (int j = 0; j < rowB; j++)
                {
                    mB[j].push_back(mB[j][0]);
                }
            }
        }
        else if (colA < colB)
        {
            for (int i = 0; i < colB - colA; i++)
            {
                for (int j = 0; j < rowA; j++)
                {
                    mA[j].push_back(mA[j][0]);
                }
            }
        }
        resultRow = std::max(rowA, rowB);
        resultCol = std::max(colA, colB);
        std::vector<std::vector<double>> res(resultRow, std::vector<double>(resultCol, 0));
        for (int i = 0; i < resultRow; i++)
        {
            for (int j = 0; j < resultCol; j++)
            {
                res[i][j] = mA[i][j] + mB[i][j];
            }
        }
        result = res;
    }

    void add(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrixA, std::vector<std::vector<std::vector<double>>> &matrixB)
    {
        int row = matrixA.size();
        int col = matrixA[0].size();
        if (row * col * matrixA[0][0].size() != matrixB.size() * matrixB[0].size() * matrixB[0][0].size())
        {
            std::cout << "Add3D Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<std::vector<double>>> res(row, std::vector<std::vector<double>>(col, std::vector<double>(matrixA[0][0].size(), 0)));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrixA[0][0].size(); k++)
                {
                    res[i][j][k] = matrixA[i][j][k] + matrixB[i][j][k];
                }
            }
        }
        result = res;
    }

    void add(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixA, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixB)
    {
        int row = matrixA.size();
        int col = matrixA[0].size();
        if (row * col * matrixA[0][0].size() * matrixA[0][0][0].size() != matrixB.size() * matrixB[0].size() * matrixB[0][0].size() * matrixB[0][0][0].size())
        {
            std::cout << "Add4D Function error: Dimensions are not the same" << std::endl;
        }
        std::vector<std::vector<std::vector<std::vector<double>>>> res(row, std::vector<std::vector<std::vector<double>>>(col, std::vector<std::vector<double>>(matrixA[0][0].size(), std::vector<double>(matrixA[0][0][0].size(), 0))));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < matrixA[0][0].size(); k++)
                {
                    for (int l = 0; l < matrixA[0][0][0].size(); l++)
                    {
                        res[i][j][k][l] = matrixA[i][j][k][l] + matrixB[i][j][k][l];
                    }
                }
            }
        }
        result = res;
    }

}