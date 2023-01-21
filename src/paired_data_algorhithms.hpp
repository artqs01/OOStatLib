#ifndef PAIRED_DATA_ALGORHITHMS
#define PAIRED_DATA_ALGORHITHMS

#include "data.hpp"
#include "logic.hpp"
#include "single_data_algorhithms.hpp"
#include <cassert>
#include <cmath>
#include <vector>

namespace sl 
{

template<Interval DataType1, Interval DataType2, Ratio CalcType = double>
class pair_observations_test :
	public data_logic<paired_container<DataType1, DataType2>>,
	public significance_logic<CalcType>,
	public algorhithm<bool>
{
	public:
		pair_observations_test(
			std::shared_ptr<paired_container<DataType1, DataType2>> data,
			significance alfa
		) :
			data_logic<paired_container<DataType1, DataType2>>(data),
			significance_logic<CalcType>(alfa),
			algorhithm<bool>()
		{
			static_assert(
				Funktor<pair_observations_test<DataType1, DataType2, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Significance<pair_observations_test<DataType1, DataType2, CalcType>, CalcType>,
				"No setters or no getters for significance."
			);
			
			static_assert(
				PairedContainerLogic<pair_observations_test<DataType1, DataType2, CalcType>, DataType1, DataType2>,
				"Wrong data for pair observations test."
			);
			static_assert(
				Algorhithm<pair_observations_test<DataType1, DataType2, CalcType>, bool>,
				"No implementation of algothithm."
			);
		}
		bool operator()();
		static bool evaluate(paired_container<DataType1, DataType2>& data, significance alfa);
};


// TODO: implement evaluate() for pair observations test
template<Interval DataType1, Interval DataType2, Ratio CalcType>
bool pair_observations_test<DataType1, DataType2, CalcType>::evaluate(paired_container<DataType1, DataType2> &data, significance alfa)
{
	std::vector<CalcType> difference(data.size());
	for (const auto& pair : data) {
		difference.push_back(pair.second - pair.first);
	}
	CalcType t = mean<CalcType, CalcType>::evaluate(difference) * std::sqrt(difference.size()) /
		standard_deviation<CalcType, CalcType>::evaluate(difference);
	return pdf<CalcType>::t(std::abs(t), data.size() - 1) < significance_logic<CalcType>::to_floating_point(alfa);
}

template<Interval DataType1, Interval DataType2, Ratio CalcType>
bool pair_observations_test<DataType1, DataType2, CalcType>::operator()()
{
	this->last_result_ = evaluate(*this->data_, this->alfa_);
	return this->last_result_;
}



}

#endif
