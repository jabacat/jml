/**
 * This offers loss functions for a model. Only one such loss function exists
 * right now, but we may need more in the future.
 *
 * Each loss function needs an actual calculation (put in a jml::Vector, get out
 * a double), and a derivative with respect to a particular entry. That is, if
 * we change the i-th entry of the input vector, how much the loss will change
 * by. This will be very important later for gradient descent.
 *
 * Author: Adam Hutchings
 * Date: 10-17-23
*/

#pragma once

#include <functional>

#include <jml/jmldefs.h>
#include <jml/math/vector.hpp>

namespace jml {

typedef JML_API std::function<double(const jml::Vector&, const jml::Vector&)> LF;
typedef JML_API std::function<double(const jml::Vector&, const jml::Vector&, int i)> DL;

class JML_API LossFunction {

private:
	LF loss;
	DL dl;

public:
	// Create a loss function with a given loss and derivative.
	LossFunction(const LF& lf, const DL& dl);
	double get_loss(const jml::Vector& actual, const jml::Vector& expected);
	double get_loss_derivative(
		const jml::Vector& actual, const jml::Vector& expected, int index
	);

};

// Also, we provide an example set of loss functions (L^2 norm)
extern JML_API LF l2lf;
extern JML_API DL l2dl;

}
