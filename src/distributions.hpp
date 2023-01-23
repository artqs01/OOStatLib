#ifndef DISTRIBUTIONS_HPP
#define DISTRIBUTIONS_HPP

#include "data.hpp"
#include "logic.hpp"
#include <cmath>
#include <cassert>

/**
	\file distributions.hpp
	\brief Plik definiujący klasę sl::pdf zawierającej w sobie wszystkie potrzebne dystrybuanty
	i funkcje gęstości prawdopodobieństwa oraz implementacje funkcji:
	- \f$χ^2\f$,
	- T studenta. 
	\author Artur Kuś
*/
namespace sl 
{

/**
	\brief Klasa zawierająca w sobie wszystkie potrzebne dystrybuanty
	i funkcje gęstości prawdopodobieństwa oraz implementacje tychże funkcji:
*/
template<Ratio CalcType = double>
class pdf
{
	public :
		/**
			\brief Funkcja zwracająca rozkład \f$χ^2\f$.
			
			Argumenty:
			- wartość zmiennej losowej _value_,
			- liczba stopni swobody _degrees_of_freedom_.
			\note Dla wartości _nan_ oraz _inf_ program jest przerywany przez asercję
		*/
		static CalcType chi_sqr(CalcType value, size_t degrees_of_freedom);

		/**
			\brief Funkcja zwracająca rozkład \f$T\f$ studenta.
			
			Argumenty:
			- wartość zmiennej losowej _value_,
			- liczba stopni swobody _degrees_of_freedom_.
			\note Dla wartości _nan_ oraz _inf_ program jest przerywany przez asercję
		*/
		static CalcType t(CalcType value, size_t degrees_of_freedom);
		
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
