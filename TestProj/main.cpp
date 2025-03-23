#if 0
#include <list>
#include <vector>
#include <iostream>
#include <ranges>

int main()
{
	std::vector c{ 1,2,3,4,5 };

	std::vector<int>::iterator p = c.begin();

	std::cout << *p << std::endl;
	
	int x[]{ 1,2,3,4 };

	auto a = std::begin(x);

	return 0;
}
#endif