#include "data.hpp"
#include "distributions.hpp"
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
	
	std::cout << "sw: " << sl::shapiro_wilk<double>::evaluate(*data1_ptr, sl::significance::five_hundredths) <<
		", mst: " << mst() <<
		", vst: " << vst() << "\n\n";
	// std::cout << sw1.get_significance() << "\n";
	// std::cout << sl::sw::get_coefficient(20, 9);
	// std::cout << sl::pdf_t(1.87866958564078, 14) << "\n\n";
	// std::cout << sl::pdf_chi_sqr(3.88675680850485, 7) << "\n";
	// B<"dupa"> b;
}
