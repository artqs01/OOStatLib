#include "data.hpp"
#include "distributions.hpp"
#include "paired_data_algorhithms.hpp"
#include "single_data_algorhithms.hpp"
#include <iostream>
#include <memory>

int main()
{
	sl::single_container<double> data1 = {
		26.5,
		27.5,
		27.5,
		26.9,
		27.9,
		27.0,
		27.7,
		27.6,
		27.9,
		27.4,
		28.3,
		27.6,
		26.3,
		25.9,
		27.9
	};
	sl::paired_container<double, double> data2 = {
		{63.8, 63.1},
		{62.1, 60.9},
		{62.7, 60.5},
		{66.3, 66.4},
		{69.9, 69.3},
		{65.9, 63.5},
		{66.0, 65.2},
		{67.5, 68.9},
		{68.7, 68.5},
		{68.4, 70.2},
		{65.1, 62.7},
		{66.5, 65.1}
	};
	auto data1_ptr = std::make_shared<sl::single_container<double>>(data1);
	sl::shapiro_wilk<double> sw1(
		data1_ptr,
		sl::significance::five_hundredths);
	sl::mean_significance_test<double> mst(
		data1_ptr,
		sl::significance::five_hundredths,
		27.0);
	sl::variance_significance_test<double> vst(
		data1_ptr,
		sl::significance::five_hundredths,
		27.0);
	auto data2_ptr = std::make_shared<sl::paired_container<double, double>>(data2);
	std::cout << "sw: " << sl::shapiro_wilk<double>::evaluate(*data1_ptr, sl::significance::five_hundredths) <<
		", mst: " << mst() <<
		", vst: " << vst() <<
		", pot: " << sl::pair_observations_test<double, double>::evaluate(*data2_ptr, sl::significance::five_hundredths) << "\n\n";
	// std::cout << sw1.get_significance() << "\n";
	// std::cout << sl::sw::get_coefficient(20, 9);
	// std::cout << sl::pdf_t(1.87866958564078, 14) << "\n\n";
	// std::cout << sl::pdf_chi_sqr(3.88675680850485, 7) << "\n";
	// B<"dupa"> b;
}
