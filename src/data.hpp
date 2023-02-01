#ifndef DATA_HPP
#define DATA_HPP

#include <type_traits>
#include <vector>
#include <concepts>

/**
	\file data.hpp
	\brief Plik zawierający definicje konceptów odpowiedzialnych za dane przetwarzane przez bibliotekę

	oraz enum sl::significance przechowujące dostępne wartości poziomów istotności dla wszystkich testów statystycznych.
*/

/**
	\brief Przestrzeń nazw dla wszystkich typów danych, oraz wszystkich testów zaimplementowanych w bibliotece.
*/
namespace sl 
{

//! Koncept definiujący dane będące skalą nominalną (zdefiniowany znak równości).
template<typename T>
concept Nominal = std::equality_comparable<T>;

//! Koncept definiujący dane będące skalą porządkową (zdefiniowany znak równości oraz zdefiniowana hierarchia między zmiennymi należącymi do skali).
template<typename T>
concept Ordinal = std::totally_ordered<T>;

//! Koncept definiujący dane będące skalą interwałową (ściśle zdefiniowana różnica między zmiennymi).
template<typename T>
concept Interval = std::is_integral_v<T> || std::is_floating_point_v<T>;

//! Koncept definiujący dane będące skalą różnicową (ściśle zdefiniowany stosunek między zmiennymi).
template<typename T>
concept Ratio = std::is_floating_point_v<T>;

//! Koncept pomocniczy, definiujący typ całkowity bezznakowy.
template<typename T>
concept UnsignedIntegral = std::is_integral_v<T> && std::is_unsigned_v<T>;

/**
	\brief Enum definiujące cztery typowe poziomy istotności występujące w statystyce:
	- 0,01;
	- 0,02;
	- 0,05;
	- 0,1.

	Wartości zostały dobrane w taki sposób, by łatwo dało się je rzutować na typ zmiennoprzecinkowy, mnożąc przez jedną setną.
*/
enum class significance
{
	one_hundredth = 1,
	two_hundredths = 2,
	five_hundredths = 5,
	one_tenth = 10
};

//! Using dla kontenera przechowujące pojedyncze liczby.
template<typename T>
using single_container = typename std::vector<T>;

//! Using dla kontenera przechowujące pary wartości potencjalnie różnych typów.
template<typename T1, typename T2>
using paired_container = typename std::vector<std::pair<T1, T2>>;

//! Using dla kontenera łączącego różne zestawy danych o różnych rozmiarach.
template<typename T>
using multi_sample_container = typename std::vector<std::vector<T>>;

}

#endif
