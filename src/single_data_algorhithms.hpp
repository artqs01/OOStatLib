#ifndef SINGLE_DATA_ALGORHITHMS
#define SINGLE_DATA_ALGORHITHMS

#include "data.hpp"
#include "logic.hpp"
#include "distributions.hpp"
#include "table_values.hpp"
#include <algorithm>
#include <cassert>
#include <cstddef>

namespace sl
{

template<Interval DataType, Ratio CalcType = double>
class mean :
	public data_logic<single_container<DataType>>,
	public algorhithm<CalcType>
{
	public:
		mean(std::shared_ptr<single_container<DataType>> data) : data_logic<DataType>(data) {
			static_assert(
				Funktor<mean<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Algorhithm<mean<DataType, CalcType>, CalcType>,
				"No implementation of algothithm."
			);
			static_assert(
				SingleContainerLogic<mean<DataType, CalcType>, DataType>,
				"Wrong data for mean algorhithm."
			);
		}
		static CalcType evaluate(const single_container<DataType>& data);
		CalcType operator()();
};

template<Interval DataType, Ratio CalcType>
CalcType mean<DataType, CalcType>::evaluate(const single_container<DataType>& data)
{
	DataType sum = 0;
	for (const auto& value : data) {
		sum += value;
	}
	return (CalcType)sum / (CalcType)data.size();
}

template<Interval DataType, Ratio CalcType = double>
class variance :
	public data_logic<single_container<DataType>>,
	public algorhithm<CalcType>
{
	public:
		variance(std::shared_ptr<single_container<DataType>> data) : data_logic<DataType>(data) {
			static_assert(
				Funktor<variance<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Algorhithm<variance<DataType, CalcType>, CalcType>,
				"No implementation of algothithm."
			);
			static_assert(
				SingleContainerLogic<variance<DataType, CalcType>, DataType>,
				"Wrong data for mean algorhithm."
			);
		}
		static CalcType evaluate(const single_container<DataType>& data);
		CalcType operator()();
};

template<Interval DataType, Ratio CalcType>
CalcType variance<DataType, CalcType>::evaluate(const single_container<DataType>& data)
{
	CalcType avreage = mean<DataType, CalcType>::evaluate(data);
	CalcType sum = 0;
	for (const auto& value : data) {
		sum += (value - avreage) * (value - avreage);
	}
	return sum / (data.size() - 1);
}

template<Interval DataType, Ratio CalcType = double>
class standard_deviation :
	public data_logic<single_container<DataType>>,
	public algorhithm<CalcType>
{
	public:
		standard_deviation(std::shared_ptr<single_container<DataType>> data) : data_logic<DataType>(data) {
			static_assert(
				Funktor<standard_deviation<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Algorhithm<standard_deviation<DataType, CalcType>, CalcType>,
				"No implementation of algothithm."
			);
			static_assert(
				SingleContainerLogic<standard_deviation<DataType, CalcType>, DataType>,
				"Wrong data for mean algorhithm."
			);
		}
		static CalcType evaluate(const single_container<DataType>& data);
		CalcType operator()();
};

template<Interval DataType, Ratio CalcType>
CalcType standard_deviation<DataType, CalcType>::evaluate(const single_container<DataType>& data)
{
	return std::sqrt(variance<DataType, CalcType>::evaluate(data));
}

template<Interval DataType, Ratio CalcType = double>
class shapiro_wilk :
	public data_logic<single_container<DataType>>,
	public significance_logic<CalcType>,
	public algorhithm<bool>
{
	public:
		shapiro_wilk(std::shared_ptr<single_container<DataType>> data, significance alfa) :
			data_logic<single_container<DataType>>(data),
			significance_logic<CalcType>(alfa)
		{
			static_assert(
				Funktor<shapiro_wilk<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Significance<shapiro_wilk<DataType, CalcType>, DataType>,
				"No setters or no getters for significance."
			);
			static_assert(
				Algorhithm<shapiro_wilk<DataType, CalcType>, bool>,
				"No implementation of algothithm."
			);
			static_assert(
				SingleContainerLogic<shapiro_wilk<DataType, CalcType>, DataType>,
				"Wrong data for Shapiro-Wilk test."
			);
		}
		void sw_data_count_check(size_t data_count)
		{
			assert(data_count >= 3);
			assert(data_count <= 50);
		}
		constexpr static inline CalcType sw_get_p_value(size_t data_count, significance alfa);
		constexpr static inline CalcType sw_get_coefficient(size_t data_count, size_t index);
		static bool evaluate(single_container<DataType>& data, significance alfa);
		bool operator()();
	private:
		constexpr static size_t p_value_offset = 47;
		
};

template<Interval DataType, Ratio CalcType>
constexpr inline CalcType shapiro_wilk<DataType, CalcType>::sw_get_coefficient(size_t data_count, size_t index)
{
	return SW_COEFFICIENTS<CalcType>[((data_count - 1) * (data_count - 1) / 4) + index];
}

template<Interval DataType, Ratio CalcType>
constexpr inline CalcType shapiro_wilk<DataType, CalcType>::sw_get_p_value(size_t data_count, significance alfa)
{
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
	return SW_P_VALUES<CalcType>[offset + data_count];
}

template<Interval DataType, Ratio CalcType>
bool shapiro_wilk<DataType, CalcType>::evaluate(single_container<DataType>& data, significance alfa)
{
	CalcType w = 0.0;
	std::sort(data.begin(), data.end());
	for (size_t i = 0; i < data.size() / 2; i++) {
		w += (data[data.size() - 1 - i] - data[i]) *
			sw_get_coefficient(data.size(), i);
	}
	w *= w;
	w /= (variance<DataType, CalcType>::evaluate(data) * (data.size() - 1));
	return w > sw_get_p_value(data.size(), alfa);
}

template<Interval DataType, Ratio CalcType>
bool shapiro_wilk<DataType, CalcType>::operator()()
{
	this->last_result_ = evaluate(*this->data_, this->alfa_);
	return this->last_result_;
}

template<Interval DataType, Ratio CalcType = double>
class mean_significance_test :
	public data_logic<single_container<DataType>>,
	public significance_logic<CalcType>,
	public algorhithm<bool>
{
	public:
		mean_significance_test(
			std::shared_ptr<single_container<DataType>> data,
			significance alfa,
			CalcType mean) :
			data_logic<single_container<DataType>>(data),
			significance_logic<CalcType>(alfa),
			mean_(mean)
		{
			static_assert(
				Funktor<mean_significance_test<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Significance<mean_significance_test<DataType, CalcType>, CalcType>,
				"No significance logic in mean significance test."
			);
			static_assert(
				SingleContainerLogic<mean_significance_test<DataType, CalcType>, DataType>,
				"Wrong data for mean significance test."
			);
			static_assert(
				Algorhithm<shapiro_wilk<DataType, CalcType>, bool>,
				"No implementation of algothithm."
			);
		}
		void set_mean(CalcType mean) { mean_ = mean; }
		CalcType get_mean() { return mean_; }
		bool operator()();
		static bool evaluate(single_container<DataType>& data, CalcType _mean, significance alfa);
	private:
		CalcType mean_;
};

template<Interval DataType, Ratio CalcType>
bool mean_significance_test<DataType, CalcType>::evaluate(
	single_container<DataType>& data,
	CalcType _mean,
	significance alfa)
{
	bool if_normal = shapiro_wilk<DataType, CalcType>::evaluate(data, alfa);
	assert(if_normal);
	CalcType t = (mean<DataType, CalcType>::evaluate(data) - _mean) * std::sqrt(data.size()) /
		standard_deviation<DataType, CalcType>::evaluate(data);
	return pdf<CalcType>::t(std::abs(t), data.size() - 1) >
		significance_logic<CalcType>::to_floating_point(alfa);
}

template<Interval DataType, Ratio CalcType>
bool mean_significance_test<DataType, CalcType>::operator()()
{
	this->last_result_ = evaluate(*this->data_, mean_, this->alfa_);
	return this->last_result_;
}

template<Interval DataType, Ratio CalcType = double>
class variance_significance_test :
	public data_logic<single_container<DataType>>,
	public significance_logic<CalcType>,
	public algorhithm<bool>
{
	public:
		variance_significance_test(
			std::shared_ptr<single_container<DataType>> data,
			significance alfa,
			CalcType variance) :
			data_logic<single_container<DataType>>(data),
			significance_logic<CalcType>(alfa),
			variance_(variance)
		{
			static_assert(
				Funktor<variance_significance_test<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Significance<variance_significance_test<DataType, CalcType>, CalcType>,
				"No setters or no getters for significance."
			);
			static_assert(
				SingleContainerLogic<variance_significance_test<DataType, CalcType>, DataType>,
				"Wrong data for Variance Significance test."
			);
			static_assert(
				Algorhithm<shapiro_wilk<DataType, CalcType>, bool>,
				"No implementation of algothithm."
			);
		}
		void set_variance(CalcType variance) { variance_ = variance; }
		CalcType get_variance() { return variance_; }
		bool operator()();
		static bool evaluate(single_container<DataType>& data, CalcType _variance, significance alfa);
	private:
		CalcType variance_;
};

template<Interval DataType, Ratio CalcType>
bool variance_significance_test<DataType, CalcType>::evaluate(
	single_container<DataType>& data,
	CalcType _variance,
	significance alfa)
{
	bool if_normal = shapiro_wilk<DataType, CalcType>::evaluate(data, alfa);
	assert(if_normal);
	CalcType chi = variance<DataType, CalcType>::evaluate(data) * (data.size() - 1) / _variance;
	return pdf<CalcType>::chi_sqr(std::abs(chi), data.size() - 1) >
		significance_logic<CalcType>::to_floating_point(alfa);
}

template<Interval DataType, Ratio CalcType>
bool variance_significance_test<DataType, CalcType>::operator()()
{
	this->last_result_ = evaluate(*this->data_, variance_, this->alfa_);
	return this->last_result_;
}

}


#endif
