#ifndef SINGLE_DATA_ALGORHITHMS
#define SINGLE_DATA_ALGORHITHMS

#include "data.hpp"
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
		mean_significance_test(std::shared_ptr<single_container<DataType>> data, CalcType significance) :
			data_container<single_container<DataType>>(data),
			significance_component<CalcType>(significance)
		{
			static_assert(Test<decltype(*this)>, "No implementation of algothithm.");
			static_assert(Significance<decltype(*this), CalcType>, "No setters or no getters for significance.");
			static_assert(SingleDataContainer<decltype(*this), DataType>, "Wrong data for Shapiro-Wilk test.");
		}
		bool operator()();
	private:
		CalcType mean;
};

template<Interval DataType, Ratio CalcType>
bool mean_significance_test<DataType, CalcType>::operator()()
{

}

}


#endif
