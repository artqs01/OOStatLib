#ifndef SINGLE_DATA_ALGORHITHMS
#define SINGLE_DATA_ALGORHITHMS

#include "data.hpp"
#include <cmath>
#include <vector>

namespace sl
{

// template<typename TestType, typename DataType, typename AlfaType = double>
// concept SingleDataTest = Test<TestType> && Significance<TestType, AlfaType> && SingleDataContainer<TestType, DataType>;

// template<typename TestType, typename DataType, typename AlfaType>
// concept PairedDataTest = Test<TestType> && Significance<TestType, AlfaType> && PairedDataContainer<TestType, DataType>;

// template<typename TestType, typename DataType, typename AlfaType>
// concept MultiSampleTest = Test<TestType> && Significance<TestType, AlfaType> && MultiSampleContainer<TestType, DataType>;

template<Interval DataType, Ratio ReturnType = double>
ReturnType mean(const single_data<DataType>& data)
{
	DataType sum = 0;
	for (const auto& value : data) {
		sum += value;
	}
	return (ReturnType)sum / (ReturnType)data.size();
}

template<Interval DataType, Ratio ReturnType = double>
ReturnType variance(const single_data<DataType>& data)
{
	ReturnType average = mean(data);
	ReturnType sum = 0;
	for (const auto& value : data) {
		sum += (value - average) * (value - average);
	}
	return sum / data.size();
}

template<Interval DataType, Ratio ReturnType = double>
ReturnType standard_deviation(const single_data<DataType>& data)
{
	return std::sqrt(variance(data));
}

template<Ratio DataType, Ratio AlfaType = double>
class shapiro_wilk :
	public data_container<single_data<DataType>>,
	public significance_component<AlfaType>
{
	public:
		bool operator()();
	private:
};

template<Ratio DataType, Ratio AlfaType>
bool shapiro_wilk<DataType, AlfaType>::operator()()
{

}

}


#endif
