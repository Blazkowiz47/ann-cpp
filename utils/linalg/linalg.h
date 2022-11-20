#ifndef LINALG_H
#define LINALG_H

#include <vector>

namespace ANN{
    void dot(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB);
    void transpose(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix);
    
    void sum(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, int axis);
    void sum(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrix, int axis);
    
    void square(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix);
    void square(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix);
    
    void mean(double &result, std::vector<std::vector<double>> &matrix);
    
    void std(double &result, std::vector<std::vector<double>> &matrix);
    
    void exp(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix);
    void exp(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix);

    void multiply(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, double n);
    void multiply(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrix, double n);
    void multiply(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix, double n);
    void multiply(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB);
    void multiply(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrixA, std::vector<std::vector<std::vector<double>>> &matrixB);
    
    
    void divide(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, double n);
    void divide(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB);
    void divide(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix, double n);
    void divide(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixA, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixB);
    
    void sub(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB);
    void sub(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixA, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixB);
    
    void sqrt(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix);
    void sqrt(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix);

    void add(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrix, double n);
    void add(std::vector<std::vector<double>> &result, std::vector<std::vector<double>> &matrixA, std::vector<std::vector<double>> &matrixB);
    void add(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrix, double n);
    void add(std::vector<std::vector<std::vector<double>>> &result, std::vector<std::vector<std::vector<double>>> &matrixA, std::vector<std::vector<std::vector<double>>> &matrixB);
    void add(std::vector<std::vector<std::vector<std::vector<double>>>> &result, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixA, std::vector<std::vector<std::vector<std::vector<double>>>> &matrixB);

}
#endif
