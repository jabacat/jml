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

// This gets the array position for a particular row and column combination.
int get_position(int i, int j);

public:
     Matrix(int m, int n);
    ~Matrix();
    void set_entry(int i, int j, double value);
    std::unique_ptr<Vector> multiply(Vector& in);

};

}
