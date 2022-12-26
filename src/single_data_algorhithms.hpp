#ifndef SINGLE_DATA_ALGORHITHMS
#define SINGLE_DATA_ALGORHITHMS

#include "data.hpp"

namespace sl
{

template<Interval T>
T mean(const std::vector<T>& data);

template<Ratio T>
T standard_deviation(const std::vector<T>& data);

template<Ratio T>
T shapiro_wilk(const std::vector<T>& data);

}


#endif
