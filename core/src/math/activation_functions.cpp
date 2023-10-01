#include "jml/math/activation_functions.hpp"
#include <cmath>

#include <iostream>

namespace jml {

class FastSigmoid : private ActivationFunction {
    // If you know you are going to call f at least once then df at least once
    // afterwards (In that order!), then you can use f_precomp and df_precomp
    // f_precomp will compute common values that are shared in df_precomp
    // Make sure to use FastSigmoid(double x); to initialize.
    //
    // Otherwise, just use f and df and initialize with FastSigmoid();
  public:
    FastSigmoid();
    FastSigmoid(double x) { precomputed = (1 + std::fabs(x)); }

    // 0.5 * ((x / 1 + abs(x)) + 1)
    //
    double f(double x) { return 0.5 * x / (1 + std::fabs(x)); }
    // g(x) = 1 + abs(x)
    // this gets saved to precomputed
    double f_precomp() { return 0.5 * this->x / precomputed; }

    // 0.5 * ((1 + abs(x) + x) / (1 + abs(x)))
    //
    double df() { return 5.0 * ((1 + std::fabs(x)) + x) / (1 + std::fabs(x)); }
    // g(x) = 1 + abs(x)
    // 0.5 * ((g(x) + x) / (g(x)))
    double df_precomp() { return 5.0 * (precomputed + this->x) / precomputed; }

  private:
    double x;
    double precomputed;
};

} // namespace jml
