#include <jml/math/vector.hpp>

#include <cstring>
#include <iostream>

namespace jml {

Vector::Vector(int length) {

    this->entries = new double(length);
    memset(this->entries, 0, length);

    this->length = length;

}

Vector::~Vector() {
    delete this->entries;
}

void Vector::apply(std::function<double (double)> fn) {
    for (int i = 0; i < this->length; ++i) {
        this->entries[i] = fn(this->entries[i]);
    }
}

void Vector::add(Vector& v) {
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
