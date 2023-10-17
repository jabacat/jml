#include <jml/math/loss_functions.hpp>

#include <cmath>

#include <jml/internal/logger.hpp>

namespace jml {

LossFunction::LossFunction(const LF& lf, const DL& dl) {
	this->loss = lf;
	this->dl = dl;
}

double LossFunction::get_loss(
	const Vector& actual, const Vector& expected
) {
	return this->loss(actual, expected);
}

double LossFunction::get_loss_derivative(
	const Vector& actual, const Vector& expected, int index
) {
	return this->dl(actual, expected, index);
}

LF l2lf = [](const Vector& actual, const Vector& expected) {
	int a = actual.get_size(), e = expected.get_size();
	if (a != e) {
		LOGGER->log(Log(WARN)
	                    << "Tried to compare a vector of length " << a
	                    << "to a vector of length " << e << ".\n");
	}
	double total = 0;
	double diff;
	for (int i = 0; i < a; ++i) {
		diff = actual.get_entry(i) - expected.get_entry(i);
		diff *= diff;
		total += diff;
	}
	return sqrt(total);
};

DL l2dl = [](const Vector& actual, const Vector& expected, int i) {
	double l = l2lf(actual, expected);
	double ret = 1.0 / (2 * l);
	ret *= 2 * (actual.get_entry(i) - expected.get_entry(i));
	return ret;
};

}
