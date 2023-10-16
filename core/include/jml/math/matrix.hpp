/**
 * This specifies the data type of a matrix -- that is, a set of weights for a
 * fully connected layer.
 * Author: Adam Hutchings
 * Date: 09-20-23
 */

#pragma once

#include <memory>

#include <jml/internal/logger.hpp>
#include <jml/jmldefs.h>
#include <jml/math/vector.hpp>

namespace jml {

extern Logger *LOGGER;

class JML_API Matrix {

    int m; // Number of rows
    int n; // Number of columns

    double *entries;

    // This gets the array position for a particular row and column combination.
    int JML_LOCAL get_position(int i, int j) const;

  public:
    Matrix(int m, int n);
    ~Matrix();
    int get_n_rows() const;
    int get_n_cols() const;
    void set_entry(int i, int j, double value);
    double get_entry(const int i, const int j) const;
    std::unique_ptr<Vector> multiply(const Vector &in) const;
};

} // namespace jml
