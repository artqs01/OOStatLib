#ifndef DATA_HPP
#define DATA_HPP

#include <type_traits>
#include <vector>
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

enum class significance
{
	one_hundredth = 1,
	two_hundredths = 2,
	five_hundredths = 5,
	one_tenth = 10
};

template<typename T>
using single_container = typename std::vector<T>;

template<typename T1, typename T2>
using paired_container = typename std::vector<std::pair<T1, T2>>;

template<typename T>
using multi_sample_data = typename std::vector<std::vector<T>>;

}

#endif
