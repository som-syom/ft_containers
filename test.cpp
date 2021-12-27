#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<int> tmp1;
	std::cout << tmp1.size() << std::endl;

	std::cout << tmp1.capacity() << std::endl;
	tmp1.push_back(1);
	std::cout << tmp1.capacity() << std::endl;
	tmp1.push_back(2);
	std::cout << tmp1.capacity() << std::endl;
	tmp1.push_back(3);
	std::cout << tmp1.capacity() << std::endl;

	// std::vector<int> tmp2(2147483648, 1);
	// std::cout << tmp2.size() << std::endl;

	const int& test = int();
	const char& tt = char();
	const std::string& t = std::string();
	std::cout << t << std::endl;
}