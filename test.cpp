#include <iostream>
#include <vector>
#include <string>
// #include "vector.hpp"

int main() {
	std::vector<int> tmp1(3, 100);
	std::cout << tmp1.size() << std::endl;
	std::cout << tmp1.max_size() << std::endl;
	std::cout << tmp1.capacity() << std::endl;

	tmp1.push_back(1);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(1);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(1);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(1);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;

	tmp1.reserve(13);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	// ft::vector<int> tmp2(7, 100);
	// std::cout << tmp2.size() << std::endl;
	// std::cout << tmp2.max_size() << std::endl;
	// std::cout << tmp2.capacity() << std::endl;
}