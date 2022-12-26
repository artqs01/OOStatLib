#ifndef DATA_HPP
#define DATA_HPP

#include <cstddef>
#include <initializer_list>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <memory>
#include <concepts>

namespace sl 
{

template<typename T>
concept Nominal = requires(T a, T b) {
	{a == b} -> std::convertible_to<bool>;
	{a != b} -> std::convertible_to<bool>;
};

template<typename T>
concept Ordinal = requires(T a, T b) {
    {a <=> b} -> std::convertible_to<bool>;
};

template<typename T>
concept Interval = requires(T a, T b) {
	{a <=> b} -> std::convertible_to<bool>;

	{a + b} -> std::same_as<T>;
	{a - b} -> std::same_as<T>;

	{a += b} -> std::same_as<T>;
	{a -= b} -> std::same_as<T>;
};

template<typename T>
concept Ratio = requires(T a, T b) {
	{a <=> b} -> std::convertible_to<bool>;

	{a + b} -> std::same_as<T>;
	{a - b} -> std::same_as<T>;
	{a * b} -> std::same_as<T>;
	{a / b} -> std::same_as<T>;

	{a += b} -> std::same_as<T>;
	{a -= b} -> std::same_as<T>;
	{a *= b} -> std::same_as<T>;
	{a /= b} -> std::same_as<T>;
};

template<typename T>
concept Test = requires(T test) {
	{test()} -> std::same_as<bool>;
	{test.set_data()} -> std::same_as<void>;
	{test.get_significance()} -> std::convertible_to<double>;
	{test.set_significance()} -> std::same_as<void>;
};

template<typename T>
concept SingleData = requires(T test) {
	{test.get_data()} -> std::same_as<std::shared_ptr<std::vector<T>>>;
};

template<typename T>
concept PairedData = requires(T test) {
	{test.get_data()} -> std::same_as<std::shared_ptr<std::vector<std::pair<T, T>>>>;
};

template<typename T>
concept MultiSample = requires(T test) {
	{test.get_data()} -> std::same_as<std::shared_ptr<std::vector<std::vector<T>>>>;
};

}

#endif
