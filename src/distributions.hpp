#ifndef DISTRIBUTIONS_HPP
#define DISTRIBUTIONS_HPP

#include "data.hpp"
#include <cassert>
#include <cmath>
#include <math.h>

namespace sl 
{

template<Ratio T = double>
T pdf_chi_sqr(T value, size_t degrees_of_freedom)
{
	assert(!std::isnan(value));
	assert(!std::isinf(value));

	if (value < 0.0 || degrees_of_freedom < 1) {
		return 0.0;
	}
	T k = degrees_of_freedom * 0.5;
	return std::pow(value, k - 1) * std::exp(value * (T)0.5) / (std::pow((T)2, k) * std::tgamma(k));
}

template<Ratio T = double>
T pdf_t(T value, size_t degrees_of_freedom)
{
	assert(!std::isnan(value));
	assert(!std::isinf(value));

	T base = (1 + value * value / (T)degrees_of_freedom) /
		(std::sqrt((T)degrees_of_freedom) * std::beta((T)0.5, (T)degrees_of_freedom * (T)0.5));
	return std::pow(base, (T)-0.5 * (T)(degrees_of_freedom + 1));
}

}

#endif
