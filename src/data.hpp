#ifndef DATA_HPP
#define DATA_HPP

#include <cstddef>
#include <cassert>
#include <type_traits>
#include <vector>
#include <memory>
#include <concepts>

namespace sl 
{

template<typename T>
concept Nominal = std::equality_comparable<T>;

template<typename T>
concept Ordinal = std::totally_ordered<T>;

template<typename T>
concept Interval = Ordinal<T> && requires(T a, T b)
{
	{a + b} -> std::same_as<T>;
	{a - b} -> std::same_as<T>;

	{a += b} -> std::same_as<T>;
	{a -= b} -> std::same_as<T>;
};

template<typename T>
concept Ratio = std::is_floating_point_v<T>;

template<class T>
concept Test = requires(T test)
{
	{test()} -> std::same_as<bool>;
};

template<Ratio T>
void significance_check(T alfa) {
	assert(alfa == 0.01 || alfa == 0.02 || alfa == 0.05 || alfa == 0.1 );
}

template<Ratio T>
class significance_component
{
	public:
		significance_component(T alfa) : alfa_(alfa) {
			significance_check<T>(alfa_);
		}
		void set_significance(T alfa) {
			significance_check<T>(alfa_);
			alfa_ = alfa;
		}
		T get_significance() {
			return alfa_;
		}
		
	protected:
		T alfa_ = 0.05;
};

template<class TestType, typename AlfaType>
concept Significance = Ratio<AlfaType> && requires(TestType test)
{
	std::is_base_of_v<significance_component<AlfaType>, decltype(test)>;
};

template<typename T>
class data_container
{
	public:
		data_container(std::shared_ptr<T> data) : data_(data) {}
		void set_data(std::shared_ptr<T> data) {
			data_ = data;
		}
		T get_data() {
			return data_;
		}
	protected:
		std::shared_ptr<T> data_;
};

template<typename T>
using single_data = typename std::vector<T>;

template<typename T>
using paired_data = typename std::vector<std::pair<T, T>>;

template<typename T>
using multi_sample_data = typename std::vector<std::vector<T>>;

template<typename TestType, typename DataType>
concept SingleDataContainer = requires(TestType test)
{
	std::is_base_of_v<data_container<single_data<DataType>>, decltype(test)>;
};

template<typename TestType, typename DataType>
concept PairedDataContainer = requires(TestType test)
{
	std::is_base_of_v<data_container<paired_data<DataType>>, decltype(test)>;
};

template<typename TestType, typename DataType>
concept MultiSampleContainer = requires(TestType test)
{
	std::is_base_of_v<data_container<multi_sample_data<DataType>>, decltype(test)>;
};

}

#endif
