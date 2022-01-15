#include <map>
#include <iostream>
#include "map.hpp"

template<typename T1, typename T2>
void print_map(ft::map<T1, T2> map) {
	int len = map.size();
	typename ft::map<T1, T2>::const_iterator start = map.begin();
	typename ft::map<T1, T2>::const_iterator end = map.end();


	std::cout << "[ " ;
	while (start != end) {
		std::cout << start->first << " : " << start->second << ", ";
		start++;
	}
	std::cout << " ]" << std::endl;
}

template<typename T1, typename T2>
void print_std_map(std::map<T1, T2> map) {
	int len = map.size();
	typename std::map<T1, T2>::const_iterator start = map.begin();
	typename std::map<T1, T2>::const_iterator end = map.end();


	std::cout << "[ " ;
	while (start != end) {
		std::cout << start->first << " : " << start->second << ", ";
		start++;
	}
	std::cout << " ]" << std::endl;
}

int main(void) {
	std::cout << "=====================================" << std::endl;
	std::cout << "===============[ MAP ]===============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	std::cout << "> default constructor" << std::endl;

	std::map<int, std::string> std1;
	ft::map<int, std::string> ft1;

	std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
	print_std_map(std1);
	std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
	print_map(ft1);
	std::cout << std::endl;

	std::cout << "> range constructor" << std::endl;
	std::cout << "> 1: one, 2: two, 3: three 추가" << std::endl;

	std1[1] = "one";
	ft1[1] = "one";
	std1[2] = "two";
	ft1[2] = "two";
	std1[3] = "three";
	ft1[3] = "three";

	std::map<int, std::string> std2(std1.begin(), std1.end());
	ft::map<int, std::string> ft2(ft1.begin(), ft1.end());

	std::cout << "🟡 std ( size : " << std2.size() << " )" << std::endl;
	print_std_map(std2);
	std::cout << "🟣 ft  ( size : " << ft2.size() << " )" << std::endl;
	print_map(ft2);
	std::cout << std::endl;
	
	std::cout << "> copy constructor" << std::endl;

	std::map<int, std::string> std3(std2);
	ft::map<int, std::string> ft3(ft2);

	std::cout << "🟡 std ( size : " << std3.size() << " )" << std::endl;
	print_std_map(std3);
	std::cout << "🟣 ft  ( size : " << ft3.size() << " )" << std::endl;
	print_map(ft3);
	std::cout << std::endl;

	std::cout << "> operator = " << std::endl;
	std::map<int, std::string> std4 = std3;
	ft::map<int, std::string> ft4 = ft3;

	std::cout << "🟡 std ( size : " << std4.size() << " )" << std::endl;
	print_std_map(std4);
	std::cout << "🟣 ft  ( size : " << ft4.size() << " )" << std::endl;
	print_map(ft4);
	std::cout << std::endl;

	std::cout << "----------------------- Iterators " << std::endl;
	std::cout << "> begin " << std::endl;
	std::cout << "> end " << std::endl;
	std::cout << "> rbegin " << std::endl;
	std::cout << "> rend " << std::endl;

	std::cout << "----------------------- Capacity " << std::endl;
	std::cout << "> empty " << std::endl;
	std::cout << "> size " << std::endl;
	std::cout << "> max_size " << std::endl;

	std::cout << "----------------------- Element access " << std::endl;
	std::cout << "> operator[] " << std::endl;

	std::cout << "----------------------- Modifiers " << std::endl;
	std::cout << "> insert1 " << std::endl;
	std::cout << "> insert2 " << std::endl;
	std::cout << "> insert3 " << std::endl;
	std::cout << "> erase1 " << std::endl;
	std::cout << "> erase2 " << std::endl;
	std::cout << "> erase3 " << std::endl;
	std::cout << "> swap " << std::endl;
	std::cout << "> clear " << std::endl;

	std::cout << "----------------------- Observers " << std::endl;
	std::cout << "> key_comp " << std::endl;
	std::cout << "> value_comp " << std::endl;

	std::cout << "----------------------- Operations " << std::endl;
	std::cout << "> find " << std::endl;
	std::cout << "> cound " << std::endl;
	std::cout << "> lower_bound " << std::endl;
	std::cout << "> upper_bound " << std::endl;
	std::cout << "> equal_range " << std::endl;

	std::cout << "----------------------- Allocator " << std::endl;
	std::cout << "> get_allocator " << std::endl;




}