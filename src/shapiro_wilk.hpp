#ifndef SHAPIRO_WILK_HPP
#define SHAPIRO_WILK_HPP

#include "data.hpp"
#include "single_data_algorhithms.hpp"
#include "table_values.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include <algorithm>

namespace sl
{

template<Ratio T = double>
constexpr static inline T sw_get_coefficient(size_t data_count, size_t index)
{
	return SW_COEFFICIENTS<T>[((data_count - 1) * (data_count - 1) / 4) + index];
}

template<UnsignedIntegral T>
void data_count_check(T data_count)
{
	assert(data_count >= 3);
	assert(data_count <= 50);
}

constexpr size_t p_value_offset = 47;

template<Ratio T = double>
constexpr static inline T get_p_value(size_t data_count, significance alfa)
{
	data_count_check(data_count);
	size_t offset = 0;
	switch (alfa) {
		case significance::one_hundredth :
		break;
		case significance::two_hundredths :
			offset = p_value_offset;
		break;
		case significance::five_hundredths :
			offset = p_value_offset * 2;
		break;
		case significance::one_tenth :
			offset = p_value_offset * 3;
		break;
	}
	return SW_P_VALUES<T>[offset + data_count];
}

template<Ratio DataType, Ratio CalcType = double>
class shapiro_wilk :
	public data_container<single_container<DataType>>,
	public significance_component<CalcType>
{
	public:
		shapiro_wilk(std::shared_ptr<single_container<DataType>> data, CalcType significance) :
			data_container<single_container<DataType>>(data),
			significance_component<CalcType>(significance)
		{
			static_assert(Test<decltype(*this)>, "No implementation of algothithm.");
			static_assert(Significance<decltype(*this), CalcType>, "No setters or no getters for significance.");
			static_assert(SingleDataContainer<decltype(*this), DataType>, "Wrong data for Shapiro-Wilk test.");
		}
		bool operator()();
};

template<Ratio DataType, Ratio CalcType>
bool shapiro_wilk<DataType, CalcType>::operator()()
{
	CalcType w = 0.0;
	std::sort(this->data_->begin(), this->data_->end());
	for (size_t i = 0; i < this->data_->size() / 2; i++) {
		w += ((*this->data_)[this->data_->size() - 1 - i] - (*this->data_)[i]) *
			sw_get_coefficient(this->data_->size(), i);
	}
	w *= w;
	w /= (alg_variance(*this->data_) * (this->data_->size() - 1));
	return w > get_p_value(this->data_->size(), this->alfa_);
}

}

#endif
