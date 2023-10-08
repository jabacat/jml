#include <jml/math/vector.hpp>

#include <cstring>
#include <iostream>

namespace jml {

Vector::Vector(int length) {

    this->entries = new double(length);
    memset(this->entries, 0, length * sizeof(double));

    this->length = length;

}

Vector::~Vector() {
    delete this->entries;
}

void Vector::apply(std::shared_ptr<ActivationFunction> fn) {
    for (int i = 0; i < this->length; ++i) {
        this->entries[i] = fn->f(this->entries[i]);
    }
}

void Vector::add(Vector& v) {
    if (this->length != v.length) {
        std::cout << "Tried to add a vector of length " << v.length <<
        "to a vector of length " << this->length << "." << std::endl;
    }
    for (int i = 0; i < this->length; ++i) {
        this->entries[i] += v.entries[i];
    }
}

int Vector::get_size() {
    return this->length;
}

double Vector::get_entry(int pos) {
    if (pos < 0 || pos >= this->length) {
        std::cout << "Position " << pos << " out of bounds." << std::endl;
    }
    return this->entries[pos];
}

void Vector::set_entry(int pos, double val) {
    if (pos < 0 || pos >= this->length) {
        std::cout << "Position " << pos << " out of bounds." << std::endl;
    }
    this->entries[pos] = val;
}

void Vector::add_entry(int pos, double val) {
    if (pos < 0 || pos >= this->length) {
        std::cout << "Position " << pos << " out of bounds." << std::endl;
    }
    this->entries[pos] += val;
}

}
