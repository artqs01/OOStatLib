#include "shapiro_wilk.hpp"
#include <iostream>

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
	sl::sw::shapiro_wilk<double> sw1(std::make_shared<sl::single_container<double>>(data1), 0.05);
	std::cout << sw1() << "\n\n";
	// std::cout << sw1.get_significance() << "\n";
	// std::cout << sl::sw::get_coefficient(20, 9);

	// B<"dupa"> b;
}
