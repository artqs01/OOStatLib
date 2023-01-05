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
concept Interval = std::is_integral_v<T> || std::is_floating_point_v<T>;

template<typename T>
concept Ratio = std::is_floating_point_v<T>;

template<typename T>
concept UnsignedIntegral = std::is_integral_v<T> && std::is_unsigned_v<T>;

template<class T>
concept Test = requires(T test)
{
	{test()} -> std::same_as<bool>;
};

enum class significance
{
	one_hundredth = 1,
	two_hundredths = 2,
	five_hundredths = 5,
	one_tenth = 10
};

template<Ratio T = double>
class significance_component
{
	public:
		significance_component(significance alfa) : alfa_(alfa) {
		}
		void set_significance(significance alfa) {
			alfa_ = alfa;
		}
		T get_significance() {
			return (T)alfa_ / (T)0.01;
		}
		
	protected:
		significance alfa_ = significance::five_hundredths;
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
		std::shared_ptr<T> get_data() {
			return data_;
		}
	protected:
		std::shared_ptr<T> data_;
};

template<typename T>
using single_container = typename std::vector<T>;

template<typename T>
using paired_data = typename std::vector<std::pair<T, T>>;

template<typename T>
using multi_sample_data = typename std::vector<std::vector<T>>;

template<typename TestType, typename DataType>
concept SingleDataContainer = requires(TestType test)
{
	std::is_base_of_v<data_container<single_container<DataType>>, decltype(test)>;
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
