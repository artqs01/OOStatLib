#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class A
{
	protected:
		/*std::shared_ptr<std::vector<T>>*/ int dupa = 1;
};

template<typename T>
class B : public A<T>
{
	public:
		B() {
			std::cout << this->dupa;
		}
};

#endif
