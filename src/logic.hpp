#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "data.hpp"
#include <memory>
#include <type_traits>

namespace sl {

template<Ratio AlfaType = double>
class significance_logic
{
	public:
		significance_logic(significance alfa) : alfa_(alfa) {}
		static inline AlfaType to_floating_point(significance alfa) {
			return (AlfaType)alfa * (AlfaType)0.01;
		}
		void set_significance(significance alfa) {
			alfa_ = alfa;
		}
		AlfaType get_significance() {
			return to_floating_point<AlfaType>(alfa_);
		}
	protected:
		significance alfa_ = significance::five_hundredths;
};

template<class TestType, typename AlfaType>
concept Significance = Ratio<AlfaType> && requires(TestType test)
{
	std::is_base_of_v<significance_logic<AlfaType>, decltype(test)>;
};

template<typename DataType>
class data_logic
{
	public:
		data_logic(std::shared_ptr<DataType> data) : data_(data) {}
		void set_data(std::shared_ptr<DataType> data) {
			data_ = data;
		}
		std::shared_ptr<DataType> get_data() {
			return data_;
		}
	protected:
		std::shared_ptr<DataType> data_;
};

template<typename ClassType, typename DataType>
concept SingleContainerLogic = 
	std::is_function_v<decltype(ClassType::evaluate)> &&
	requires(ClassType c, single_container<DataType> data)
{
	std::is_base_of_v<data_logic<single_container<DataType>>, decltype(c)>;
};

template<typename ClassType, typename DataType1, typename DataType2>
concept PairedContainerLogic =
	std::is_function_v<decltype(ClassType::evaluate)> &&
	requires(ClassType c, paired_container<DataType1, DataType2> data)
{
	std::is_base_of_v<data_logic<paired_container<DataType1, DataType2>>, decltype(c)>;
};

template<typename ClassType, typename DataType>
concept MultiSampleContainerLogic =
	std::is_function_v<decltype(ClassType::evaluate)> &&
	requires(ClassType c, multi_sample_data<DataType> data)
{
	std::is_base_of_v<data_logic<multi_sample_data<DataType>>, decltype(c)>;
};

template<typename ResultType>
class algorhithm
{
	public:
		ResultType get_last_result() { return last_result_; }
	protected:
		ResultType last_result_;
};

template<typename AlgorhithmType, typename ResultType>
concept Algorhithm = requires(AlgorhithmType alg)
{
	std::is_base_of_v<algorhithm<ResultType>, decltype(alg)>;
};

template<typename T>
concept Funktor = requires(T c)
{
	{ c() };
};

}

#endif
