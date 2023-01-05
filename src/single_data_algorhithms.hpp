#ifndef SINGLE_DATA_ALGORHITHMS
#define SINGLE_DATA_ALGORHITHMS

#include "data.hpp"
#include <cmath>
#include <vector>

namespace sl
{

template<Interval DataType, Ratio ReturnType = double>
ReturnType mean(const single_container<DataType>& data)
{
	DataType sum = 0;
	for (const auto& value : data) {
		sum += value;
	}
	return (ReturnType)sum / (ReturnType)data.size();
}

template<Interval DataType, Ratio ReturnType = double>
ReturnType variance(const single_container<DataType>& data)
{
	ReturnType average = mean(data);
	ReturnType sum = 0;
	for (const auto& value : data) {
		sum += (value - average) * (value - average);
	}
	return sum / (data.size() - 1);
}

template<Interval DataType, Ratio ReturnType = double>
ReturnType standard_deviation(const single_container<DataType>& data)
{
	return std::sqrt(variance(data));
}



}


#endif
