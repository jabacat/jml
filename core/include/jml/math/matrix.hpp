/**
 * This specifies the data type of a matrix -- that is, a set of weights for a
 * fully connected layer.
 * Author: Adam Hutchings
 * Date: 09-20-23
 */

#pragma once

#include <memory>

#include <jml/math/vector.hpp>

namespace jml {

class Matrix {

int m; // Number of rows
int n; // Number of columns

double * entries;

public:
     Matrix(int m, int n);
    ~Matrix();
    int set_entry(int i, int j, double value);
    std::unique_ptr<Vector> multiply(Vector& in);

};

}
