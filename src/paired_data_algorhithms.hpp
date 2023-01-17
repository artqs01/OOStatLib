#ifndef PAIRED_DATA_ALGORHITHMS
#define PAIRED_DATA_ALGORHITHMS

#include "data.hpp"
#include "logic.hpp"
#include "single_data_algorhithms.hpp"
#include <cassert>

namespace sl 
{

template<Interval DataType, Ratio CalcType = double>
class pair_observations_test :
	public data_logic<paired_container<DataType>>,
	public significance_logic<CalcType>,
	public algorhithm<bool>
{
	public:
		pair_observations_test(
			std::shared_ptr<single_container<DataType>> data,
			significance alfa,
			CalcType mean
		) :
			data_logic<single_container<DataType>>(data),
			significance_logic<CalcType>(alfa),
			mean_(mean)
		{
			static_assert(
				Funktor<pair_observations_test<DataType, CalcType>>,
				"No implementation of algothithm."
			);
			static_assert(
				Significance<pair_observations_test<DataType, CalcType>, CalcType>,
				"No setters or no getters for significance."
			);
			
			static_assert(
				PairedContainerLogic<pair_observations_test<DataType, CalcType>, DataType>,
				"Wrong data for pair observations test."
			);
			static_assert(
				Algorhithm<pair_observations_test<DataType, CalcType>, bool>,
				"No implementation of algothithm."
			);
		}
		void set_mean(CalcType mean) { mean_ = mean; }
		CalcType get_mean() { return mean_; }
		bool operator()();
		static bool evaluate(paired_container<DataType>& data, CalcType _variance, significance alfa);
	private:
		CalcType mean_;
};


// TODO: implement evaluate() for pair observations test
template<Interval DataType, Ratio CalcType>
bool pair_observations_test<DataType, CalcType>::evaluate(paired_container<DataType> &data, CalcType _variance, significance alfa)
{

	CalcType t = 0.0;
	return pdf_t(std::abs(t), data.size() - 1) > significance_logic<CalcType>::to_floating_point(alfa);
}

template<Interval DataType, Ratio CalcType>
bool pair_observations_test<DataType, CalcType>::operator()()
{
	this->last_result_ = evaluate(*this->data_, mean_, this->alfa_);
	return this->last_result_;
}



}

#endif
