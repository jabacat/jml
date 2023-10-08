#include <jml/math/matrix.hpp>

#include <iostream>

namespace jml {

Matrix::Matrix(int m, int n) {
    this->entries = new double(m * n);
}

Matrix::~Matrix() {
    delete this->entries;
}

int Matrix::get_rows() {
    return m;
}

int Matrix::get_cols() {
    return n;
}

int Matrix::get_position(int i, int j) {
    return i * this->n + j;
}

void Matrix::set_entry(int i, int j, double value) {

    if (i < 0 || i >= this->m) {
        std::cout << "Row number " << i << " out of bounds." << std::endl;
    }
    if (j < 0 || j >= this->n) {
        std::cout << "Column number " << i << " out of bounds." << std::endl;
    }

    this->entries[get_position(i, j)] = value;

}

std::unique_ptr<Vector> Matrix::multiply(std::unique_ptr<Vector> in) {

    if (in->get_size() != this->n) {
        std::cout << "Tried to multiply a vector of size " << in->get_size()
        << " with a matrix containing " << this->n << " columns." << std::endl;
    }

    std::unique_ptr<Vector> ret = std::make_unique<Vector>(this->m);

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j)
            ret->add_entry(i, in->get_entry(j) * this->entries[get_position(i, j)]);
    }

    return ret;

}

}
