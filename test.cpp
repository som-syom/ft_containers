#include <iostream>
#include <vector>
#include <string>
#include "vector.hpp"

int main() {
	std::vector<int> tmp1;
	std::cout << tmp1.size() << std::endl;
	std::cout << tmp1.max_size() << std::endl;
	std::cout << tmp1.capacity() << std::endl;

	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(11);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(12);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(13);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(14);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	tmp1.push_back(15);

	// tmp1.reserve(13);
	// std::cout << "size     : " << tmp1.size() << std::endl;
	// std::cout << "capacity : " << tmp1.capacity() << std::endl;
	// tmp1.reserve(13);
	std::cout << "size     : " << tmp1.size() << std::endl;
	std::cout << "capacity : " << tmp1.capacity() << std::endl;
	std::cout << "test : " << tmp1[15] << std::endl;
	// std::cout << "test : " << tmp1.at(7) << std::endl;


	std::cout << "--------------------------" << std::endl;
	ft::vector<int> tmp2(7, 100);
	std::cout << tmp2.size() << std::endl;
	std::cout << tmp2.max_size() << std::endl;
	std::cout << tmp2.capacity() << std::endl;
	std::cout << tmp2[-1] << std::endl;
	std::cout << tmp2.at(0) << std::endl;
	std::cout << tmp2.front() << std::endl;
	tmp2.clear();
	std::cout << tmp2.size() << std::endl;
}