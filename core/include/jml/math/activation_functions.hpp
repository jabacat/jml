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

class FastSigmoid {
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
