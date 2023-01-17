#ifndef DISTRIBUTIONS_HPP
#define DISTRIBUTIONS_HPP

#include "data.hpp"
#include "logic.hpp"
#include <cmath>
#include <cassert>

namespace sl 
{

template<Ratio CalcType = double>
class pdf
{
	public :
		static inline CalcType chi_sqr(CalcType value, size_t degrees_of_freedom);
		static inline CalcType t(CalcType value, size_t degrees_of_freedom);
		
};

template<Ratio CalcType>
CalcType pdf<CalcType>::chi_sqr(CalcType value, size_t degrees_of_freedom)
{
	assert(!std::isnan(value));
	assert(!std::isinf(value));

	if (value < 0.0 || degrees_of_freedom < 1) {
		return 0.0;
	}
	CalcType k = degrees_of_freedom * (CalcType)0.5;
	return std::pow(value, k - 1) * std::exp(value * (CalcType)-0.5) /
		(std::pow((CalcType)2, k) * std::tgamma(k));
}

template<Ratio CalcType>
CalcType pdf<CalcType>::t(CalcType value, size_t degrees_of_freedom)
{
	assert(!std::isnan(value));
	assert(!std::isinf(value));

	return std::pow(
			1 + value * value / (CalcType)degrees_of_freedom,
			(CalcType)-0.5 * (CalcType)(degrees_of_freedom + 1)
		) /
		(
			std::sqrt((CalcType)degrees_of_freedom) *
			std::beta((CalcType)0.5, (CalcType)degrees_of_freedom * (CalcType)0.5)
		);
}

}

#endif
