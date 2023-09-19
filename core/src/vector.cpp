#include <jml/math/vector.hpp>

#include <cstring>

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

}
