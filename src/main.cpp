#include "data.hpp"
#include "shapiro_wilk.hpp"
#include <iostream>

int main()
{
	sl::single_data<double> data1 = {0.0, 1.0, 2.0, 3.0, 4.0};
	sl::sw::shapiro_wilk<double> sw1(std::make_shared<sl::single_data<double>>(data1), 0.05);
	sw1();
	std::cout << sw1.get_significance() << "\n";
	std::cout << sl::sw::get_coefficient(20, 9);
}
