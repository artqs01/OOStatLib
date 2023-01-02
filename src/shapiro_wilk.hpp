#ifndef SHAPIRO_WILK_HPP
#define SHAPIRO_WILK_HPP

#include "data.hpp"
#include "single_data_algorhithms.hpp"
#include "shapiro_wilk_coefficients.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include <algorithm>

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
