/**
 * Author: Jake Roggenbuck
 * Date: 09-30-23
 */

#pragma once

#include <jml/jmldefs.h>

namespace jml {

class JML_API ActivationFunction {
  public:
    virtual double f(double x) = 0;
    virtual double df(double x) = 0;

    virtual double f_precomp();
    virtual double df_precomp();
};

class JML_API FastSigmoid : public ActivationFunction {
    // If you know you are going to call f at least once then df at least once
    // afterwards (In that order!), then you can use f_precomp and df_precomp
    // f_precomp will compute common values that are shared in df_precomp
    // Make sure to use FastSigmoid(double x); to initialize.
    //
    // Otherwise, just use f and df and initialize with FastSigmoid();

  public:
    FastSigmoid();
    FastSigmoid(double x);

    double f(double x);
    double df(double x);

    double f_precomp();
    double df_precomp();

  private:
    double x;
    double precomputed;
};

class JML_API Sigmoid : public ActivationFunction {
  public:
    Sigmoid();

    double f(double x);
    double df(double x);
};

class JML_API ReLU : public ActivationFunction {
  public:
    ReLU();

    double f(double x);
    double df(double x);
};

class JML_API LeakyReLU : public ActivationFunction {
  public:
    LeakyReLU();
    LeakyReLU(double x);

    double f(double x);
    double df(double x);

  private:
    double leak;
};

} // namespace jml
