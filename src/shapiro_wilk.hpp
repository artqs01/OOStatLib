#ifndef SHAPIRO_WILK_HPP
#define SHAPIRO_WILK_HPP

#include "data.hpp"
#include "single_data_algorhithms.hpp"
#include "shapiro_wilk_coefficients.hpp"
#include <cstddef>
#include <memory>

namespace sl
{

namespace sw
{

template<Ratio DataType, Ratio AlfaType = double>
class shapiro_wilk :
	public data_container<single_data<DataType>>,
	public significance_component<AlfaType>
{
	public:
		shapiro_wilk(std::shared_ptr<single_data<DataType>> data, AlfaType significance) :
			data_container<single_data<DataType>>(data),
			significance_component<AlfaType>(significance)
		{
			static_assert(Test<decltype(*this)>, "No implementation of algothithm.");
			static_assert(Significance<decltype(*this), AlfaType>, "No setters or no getters for significance.");
			static_assert(SingleDataContainer<decltype(*this), DataType>, "Wrong data for Shapiro-Wilk test.");
		}
		bool operator()();
};

template<Ratio DataType, Ratio AlfaType>
bool shapiro_wilk<DataType, AlfaType>::operator()()
{
	return false;
}

}

}

#endif
