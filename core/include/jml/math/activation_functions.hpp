/**
 * Author: Jake Roggenbuck
 * Date: 09-30-23
 */

#pragma once

namespace jml {

class ActivationFunction {
  public:
    virtual double f(double x) = 0;
    virtual double df(double x) = 0;

    virtual double f_precomp(double x) = 0;
    virtual double df_precomp(double x) = 0;

  private:
    double x;
    double precomputed;
};

class FastSigmoid : private ActivationFunction {
    // If you know you are going to call f at least once then df at least once
    // afterwards (In that order!), then you can use f_precomp and df_precomp
    // f_precomp will compute common values that are shared in df_precomp
    // Make sure to use FastSigmoid(double x); to initialize.
    //
    // Otherwise, just use f and df and initialize with FastSigmoid();

  public:
    double f(double x);
    double df(double x);

    double f_precomp(double x);
    double df_precomp(double x);

  private:
    double x;
    double precomputed;
};

} // namespace jml
