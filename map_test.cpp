#include <map>
#include <iostream>
#include "map.hpp"

int main(void) {
	std::map<int, std::string> std1;
	ft::map<int, std::string> ft1;

	std1.insert(std::pair<int, std::string>(1, "one"));
	ft1.insert(ft::pair<int, std::string>(1, "one"));
	std1.insert(std::pair<int, std::string>(2, "two"));
	ft1.insert(ft::pair<int, std::string>(2, "two"));

	std::cout << std1[2] << std::endl;
	std::cout << ft1[2] << std::endl;

}