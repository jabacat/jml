/**
 * This specifies the data type of a matrix -- that is, a set of weights for a
 * fully connected layer.
 * Author: Adam Hutchings
 * Date: 09-20-23
 */

#pragma once

#include <memory>

#include <jml/math/vector.hpp>
#include <jml/jmldefs.h>

namespace jml {

class JML_API Matrix {

int m; // Number of rows
int n; // Number of columns

double * entries;

// This gets the array position for a particular row and column combination.
int JML_LOCAL get_position(int i, int j);

public:
     Matrix(int m, int n);
    ~Matrix();
    void set_entry(int i, int j, double value);
    std::unique_ptr<Vector> multiply(std::unique_ptr<Vector>);

};

}
