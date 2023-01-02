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

namespace sw
{

template<Ratio T = double>
constexpr static inline T get_coefficient(size_t data_count, size_t index)
{
	assert(data_count >= 2);
	assert(data_count <= 50);
	assert(index < data_count / 2);
	return SHAPIRO_WILK_COEFFICIENTS<T>[((data_count - 1) * (data_count - 1) / 4) + index];
}

constexpr size_t p_value_offset = 47;

template<Ratio T = double>
constexpr static inline T get_p_value(size_t data_count, T significance)
{
	assert(data_count >= 3);
	assert(data_count <= 50);
	significance_check<T>(significance);
	size_t offset = 0;
	if (significance == 0.01) {
		offset = 0;
	}
	else if (significance == 0.02) {
		offset = p_value_offset;
	}
	else if (significance == 0.05) {
		offset = p_value_offset * 2;
	}
	else if (significance == 0.1) {
		offset = p_value_offset * 3;
	}
	return SHAPIRO_WILK_P_VALUES<T>[offset + data_count];
}

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
	DataType w = 0.0;
	std::sort(this->data_->begin(), this->data_->end());
	for (const auto& n : *this->data_) {
		std::cerr << n << "\n";
	}
	for (size_t i = 0; i < this->data_->size() / 2; i++) {
		w += ((*this->data_)[this->data_->size() - 1 - i] - (*this->data_)[i]) *
			get_coefficient(this->data_->size(), i);
		std::cerr << "w: " << w << " greater: " << (*this->data_)[this->data_->size() - 1 - i] << " lesser: " << (*this->data_)[i] << " coefisient: " << get_coefficient(this->data_->size(), i) << "\n";
	}
	std::cerr << w << ", " ;
	w *= w;
	w /= (variance(*this->data_) * (this->data_->size() - 1));
	std::cerr << w << ", " << this->data_->size() << ", ";
	return w > get_p_value(this->data_->size(), this->alfa_);
}

}

}

#endif
