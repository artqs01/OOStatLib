#ifndef SINGLE_DATA_ALGORHITHMS
#define SINGLE_DATA_ALGORHITHMS

#include "data.hpp"
#include "distributions.hpp"
#include "table_values.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

namespace sl
{

template<Interval DataType, Ratio ReturnType = double>
ReturnType alg_mean(const single_container<DataType>& data)
{
	DataType sum = 0;
	for (const auto& value : data) {
		sum += value;
	}
	return (ReturnType)sum / (ReturnType)data.size();
}

template<Interval DataType, Ratio ReturnType = double>
ReturnType alg_variance(const single_container<DataType>& data)
{
	ReturnType mean = alg_mean(data);
	ReturnType sum = 0;
	for (const auto& value : data) {
		sum += (value - mean) * (value - mean);
	}
	return sum / (data.size() - 1);
}

template<Interval DataType, Ratio ReturnType = double>
ReturnType alg_standard_deviation(const single_container<DataType>& data)
{
	return std::sqrt(alg_variance(data));
}

template<Interval DataType, Ratio CalcType = double>
class mean_significance_test :
	public data_container<single_container<DataType>>,
	public significance_component<CalcType>
{
	public:
		mean_significance_test(
			std::shared_ptr<single_container<DataType>> data,
			significance alfa,
			CalcType mean) :
			data_container<single_container<DataType>>(data),
			significance_component<CalcType>(alfa),
			mean_(mean)
		{
			static_assert(Test<decltype(*this)>, "No implementation of algothithm.");
			static_assert(Significance<decltype(*this), CalcType>, "No setters or no getters for significance.");
			static_assert(SingleDataContainer<decltype(*this), DataType>, "Wrong data for Mean Significance test.");
		}
		void set_mean(CalcType mean) { mean_ = mean; }
		CalcType get_mean() { return mean_; }
		bool operator()();
	private:
		CalcType mean_;
};

template<Interval DataType, Ratio CalcType>
bool mean_significance_test<DataType, CalcType>::operator()()
{
	CalcType t = (alg_mean<DataType, CalcType>(*this->data_) - mean_) * std::sqrt(this->data_->size()) /
		alg_standard_deviation<DataType, CalcType>(*this->data_);
	return pdf_t(std::abs(t), this->data_->size() - 1) > this->get_significance();
}

template<Interval DataType, Ratio CalcType = double>
class variance_significance_test :
	public data_container<single_container<DataType>>,
	public significance_component<CalcType>
{
	public:
		variance_significance_test(
			std::shared_ptr<single_container<DataType>> data,
			significance alfa,
			CalcType variance) :
			data_container<single_container<DataType>>(data),
			significance_component<CalcType>(alfa),
			variance_(variance)
		{
			static_assert(Test<decltype(*this)>, "No implementation of algothithm.");
			static_assert(Significance<decltype(*this), CalcType>, "No setters or no getters for significance.");
			static_assert(SingleDataContainer<decltype(*this), DataType>, "Wrong data for Variance Significance test.");
		}
		void set_variance(CalcType variance) { variance_ = variance; }
		CalcType get_variance() { return variance_; }
		bool operator()();
	private:
		CalcType variance_;
};

template<Interval DataType, Ratio CalcType>
bool variance_significance_test<DataType, CalcType>::operator()()
{
	CalcType chi = alg_variance<DataType, CalcType>(*this->data_) * (this->data_->size() - 1) / variance_;
	return pdf_chi_sqr(std::abs(chi), this->data_->size() - 1) > this->get_significance();
}


template<Ratio T = double>
constexpr static inline T sw_get_coefficient(size_t data_count, size_t index)
{
	return SW_COEFFICIENTS<T>[((data_count - 1) * (data_count - 1) / 4) + index];
}

template<UnsignedIntegral T>
void sw_data_count_check(T data_count)
{
	assert(data_count >= 3);
	assert(data_count <= 50);
}

constexpr size_t p_value_offset = 47;

template<Ratio T = double>
constexpr static inline T sw_get_p_value(size_t data_count, significance alfa)
{
	sw_data_count_check(data_count);
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
		shapiro_wilk(std::shared_ptr<single_container<DataType>> data, significance alfa) :
			data_container<single_container<DataType>>(data),
			significance_component<CalcType>(alfa)
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
