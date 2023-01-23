#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "data.hpp"
#include <memory>
#include <type_traits>

/**
	\file logic.hpp
	\brief Plik definiujący klasy definiujące logikę wspólną dla klas testów statystycznych:
	- sl::significance_logic odpowiedzialne za logikę związaną z poziomem istotności,
	- sl::data_logic odpowiedzialne za logikę do manipulacji danymi do testów i algorytmów,
	- sl::algorhithm odpowiedzialne za logikę pomocniczą dla algorytmów.
	Zdefiniowane są tutaj również koncepty związane z bezpiecznym używaniem ww. klas, które są egzakwowane przy implementacji finalnych testów statystycznych.
	\author Artur Kuś
*/

namespace sl {

//! Klasa implementująca logikę związaną z poziomem istotności testu statystycznego.
template<Ratio AlfaType = double>
class significance_logic
{
	public:
		//! Konstruktor z argumentem typu sl::significance.
		explicit significance_logic(significance alfa) : alfa_(alfa) {}

		//! Funkcja statyczna konwertująca typ sl::significance na typ zmiennoprzecinkowy.
		static inline AlfaType to_floating_point(significance alfa) {
			return (AlfaType)alfa * (AlfaType)0.01;
		}

		//! Setter poziomu istotności
		void set_significance(significance alfa) {
			alfa_ = alfa;
		}

		//! Getter zwracający wartość zmienno-przecinkową odpowiadającą poziomowi istotności.
		AlfaType get_significance() const {
			return to_floating_point<AlfaType>(alfa_);
		}

	protected:

		//! Wartość poziomu istotności typ sl::significznce.
		significance alfa_ = significance::five_hundredths;
};

//! Koncept sprawdzający, czy test statystyczny dziedziczy z sl:significance_logic
template<class TestType, typename AlfaType>
concept Significance = Ratio<AlfaType> && requires(TestType test)
{
	std::is_base_of_v<significance_logic<AlfaType>, decltype(test)>;
};

//! Klasa implementująca logikę związaną z manipulacją wskaźnikiem do kolekcji danych.
template<typename CollectionType>
class data_logic
{
	public:

		//! Konstruktor z argumentem wskaźnikowym na dane.
		explicit data_logic(std::shared_ptr<CollectionType> data) : data_(data) {}

		//! Setter wskaźnika na dane.
		void set_data(std::shared_ptr<CollectionType> data) {
			data_ = data;
		}

		//! Getter zwracający wskaźnik na dane.
		std::shared_ptr<CollectionType> get_data() const {
			return data_;
		}

	protected:

		//! Wskaźnik na kolekcję danych typu ```std::shared_ptr```.
		std::shared_ptr<CollectionType> data_;
};

//! Koncept definiujący testy korzystające z zestawów danych typu sl::single_container.
template<typename ClassType, typename DataType>
concept SingleContainerLogic = 
	std::is_function_v<decltype(ClassType::evaluate)> &&
	requires(ClassType c, single_container<DataType> data)
{
	std::is_base_of_v<data_logic<single_container<DataType>>, decltype(c)>;
};

//! Koncept definiujący testy korzystające z zestawów danych typu sl::paired_container.
template<typename ClassType, typename DataType1, typename DataType2>
concept PairedContainerLogic =
	std::is_function_v<decltype(ClassType::evaluate)> &&
	requires(ClassType c, paired_container<DataType1, DataType2> data)
{
	std::is_base_of_v<data_logic<paired_container<DataType1, DataType2>>, decltype(c)>;
};

//! Koncept definiujący testy korzystające z zestawów danych typu sl::multi_sample_container.
template<typename ClassType, typename DataType>
concept MultiSampleContainerLogic =
	std::is_function_v<decltype(ClassType::evaluate)> &&
	requires(ClassType c, multi_sample_container<DataType> data)
{
	std::is_base_of_v<data_logic<multi_sample_container<DataType>>, decltype(c)>;
};

//! Klasa implementująca logikę pomocniczą dla algorytmów.
template<typename ResultType>
class algorhithm
{
	public:

		//! Getter ostatnio obliczonej wartości przez algorytm.
		ResultType get_last_result() const { return last_result_; }

	protected:

		//! Getter ostatnio obliczonej wartości przez algorytm.
		ResultType last_result_;
};

//! Koncept definiujący sprawdzający, czy test jest algorytmem.
template<typename AlgorhithmType, typename ResultType>
concept Algorhithm = requires(AlgorhithmType alg)
{
	std::is_base_of_v<algorhithm<ResultType>, decltype(alg)>;
};

//! Koncept definiujący sprawdzający, czy test jest funktorem.
template<typename T>
concept Funktor = requires(T c)
{
	{ c() };
};

}

#endif
