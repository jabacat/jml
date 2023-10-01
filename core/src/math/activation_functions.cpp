#include "jml/math/activation_functions.hpp"
#include <cmath>

#include <iostream>

namespace jml {

FastSigmoid::FastSigmoid() {}
FastSigmoid::FastSigmoid(double x) { this->precomputed = (1 + std::fabs(x)); }

// 0.5 * ((x / 1 + abs(x)) + 1)
//
double FastSigmoid::f(double x) { return 0.5 * x / (1 + std::fabs(x)); }
// g(x) = 1 + abs(x)
// this gets saved to precomputed
double FastSigmoid::f_precomp() { return 0.5 * this->x / this->precomputed; }

// 0.5 * ((1 + abs(x) + x) / (1 + abs(x)))
//
double FastSigmoid::df(double x) {
    return 5.0 * ((1 + std::fabs(x)) + x) / (1 + std::fabs(x));
}
// g(x) = 1 + abs(x)
// 0.5 * ((g(x) + x) / (g(x)))
double FastSigmoid::df_precomp() {
    return 5.0 * (this->precomputed + this->x) / this->precomputed;
}

} // namespace jml
