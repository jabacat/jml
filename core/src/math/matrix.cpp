#include <internal/logger.hpp>
#include <jml/math/matrix.hpp>

#include <iostream>

namespace jml {

Logger *LOGGER = Logger::Instance();

Matrix::Matrix(int m, int n) { this->entries = new double(m * n); }

<<<<<<< HEAD
Matrix::~Matrix() { delete this->entries; }

int Matrix::get_position(int i, int j) { return i * this->n + j; }
=======
int Matrix::get_n_rows() {
    return m;
}

int Matrix::get_n_cols() {
    return n;
}

int Matrix::get_position(int i, int j) {
    return i * this->n + j;
}
>>>>>>> bcbd26dc9e3b18d25cb361a2aab71f7f00feab85

void Matrix::set_entry(int i, int j, double value) {

    if (i < 0 || i >= this->m) {
        LOGGER->log(Log() << WARN << "Row number " << i << " out of bounds.\n");
    }
    if (j < 0 || j >= this->n) {
        LOGGER->log(Log() << WARN << "Column number " << i
                          << " out of bounds.\n");
    }

    this->entries[get_position(i, j)] = value;
}

<<<<<<< HEAD
std::unique_ptr<Vector> Matrix::multiply(Vector &in) {

    if (in.get_size() != this->n) {
        std::cout << "Tried to multiply a vector of size " << in.get_size()
                  << " with a matrix containing " << this->n << " columns."
                  << std::endl;
=======
std::unique_ptr<Vector> Matrix::multiply(std::unique_ptr<Vector> in) {

    if (in->get_size() != this->n) {
        std::cout << "Tried to multiply a vector of size " << in->get_size()
        << " with a matrix containing " << this->n << " columns." << std::endl;
>>>>>>> bcbd26dc9e3b18d25cb361a2aab71f7f00feab85
    }

    std::unique_ptr<Vector> ret = std::make_unique<Vector>(this->m);

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j)
<<<<<<< HEAD
            ret->add_entry(i,
                           in.get_entry(j) * this->entries[get_position(i, j)]);
=======
            ret->add_entry(i, in->get_entry(j) * this->entries[get_position(i, j)]);
>>>>>>> bcbd26dc9e3b18d25cb361a2aab71f7f00feab85
    }

    return ret;
}

} // namespace jml
