#include <map>
#include <iostream>
#include "map.hpp"

template<typename T1, typename T2>
void print_map(ft::map<T1, T2> map) {
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
	{
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
	}

	std::cout << "----------------------- Iterators " << std::endl;
	{
		std::map<int, std::string> std1;
		ft::map<int, std::string> ft1;

		std1[1] = "one";
		ft1[1] = "one";
		std1[2] = "two";
		ft1[2] = "two";
		std1[3] = "three";
		ft1[3] = "three";


		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;
		std::cout << "> begin " << std::endl;
		std::cout << "🟡 std.begin() => " << std1.begin()->first << " : " << std1.begin()->second << std::endl;
		std::cout << "🟣 ft.begin()  => " << ft1.begin()->first << " : " << ft1.begin()->second << std::endl;
		std::cout << std::endl;
		std::cout << "> end " << std::endl;
		std::cout << "🟡 std.end() - 1 => " << (--std1.end())->first << " : " << (--std1.end())->second << std::endl;
		std::cout << "🟣 ft.end() - 1  => " << (--ft1.end())->first << " : " << (--ft1.end())->second << std::endl;
		std::cout << std::endl;
		std::cout << "> rbegin " << std::endl;
		std::cout << "🟡 std.rbegin() => " << std1.rbegin()->first << " : " << std1.rbegin()->second << std::endl;
		std::cout << "🟣 ft.rbegin()  => " << ft1.rbegin()->first << " : " << ft1.rbegin()->second << std::endl;
		std::cout << std::endl;
		std::cout << "> rend " << std::endl;
		std::cout << "🟡 std.rend() - 1 => " << (--std1.rend())->first << " : " << (--std1.rend())->second << std::endl;
		std::cout << "🟣 ft.rend() - 1  => " << (--ft1.rend())->first << " : " << (--ft1.rend())->second << std::endl;
		std::cout << std::endl;

		std::cout << "> itertor 로 출력" << std::endl;
		std::cout << "🟡 std " << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft " << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> reverse itertor 로 출력" << std::endl;
		std::map<int, std::string>::reverse_iterator std_rit = std1.rbegin();
		ft::map<int, std::string>::reverse_iterator ft_rit = ft1.rbegin();

		std::cout << "🟡 std " << std::endl;
		while (std_rit != std1.rend()) {
			std::cout << std_rit->first << " : " << std_rit->second << std::endl;
			std_rit++;
		}
		std::cout << "🟣 ft " << std::endl;
		while (ft_rit != ft1.rend()) {
			std::cout << ft_rit->first << " : " << ft_rit->second << std::endl;
			ft_rit++;
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------- Capacity " << std::endl;
	{
		std::map<int, std::string> std1;
		ft::map<int, std::string> ft1;
		std::cout << "> empty - 비어있는 경우" << std::endl;
		std::cout << "🟡 std " << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft " << std::endl;
		print_map(ft1);
		std::cout << std::endl;
		std::cout << "🟡 std1.empty() => " << std1.empty() << std::endl;
		std::cout << "🟣 ft1.empty() => " << ft1.empty() << std::endl;
		std::cout << std::endl;

		std::cout << "> empty - 비어있지 않은 경우 " << std::endl;
		std1[1] = "hi";
		ft1[1] = "hi";
		std::cout << "🟡 std " << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft " << std::endl;
		print_map(ft1);
		std::cout << std::endl;
		std::cout << "🟡 std1.empty() => " << std1.empty() << std::endl;
		std::cout << "🟣 ft1.empty() => " << ft1.empty() << std::endl;
		std::cout << std::endl;

		std::cout << "> size " << std::endl;
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> size - 요소 3개 추가" << std::endl;
		std1[2] = "dhyeon2";
		std1[3] = "dhyeon3";
		std1[4] = "dhyeon4";
		ft1[2] = "dhyeon2";
		ft1[3] = "dhyeon3";
		ft1[4] = "dhyeon4";
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> max_size " << std::endl;
		std::cout << "🟡 std.max_size() => " << std1.max_size() << std::endl;
		std::cout << "🟣 ft.max_size()  => " << ft1.max_size() << std::endl;
		std::cout << std::endl;

		std::cout << "----------------------- Element access " << std::endl;
		std::cout << "> operator[] " << std::endl;
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << "🟡 std[1] : " << std1[1] << std::endl;
		std::cout << "🟡 std[2] : " << std1[2] << std::endl;
		std::cout << "🟡 std[3] : " << std1[3] << std::endl;
		std::cout << "🟡 std[4] : " << std1[4] << std::endl;
		std::cout << "🟣 ft[1] : " << ft1[1] << std::endl;
		std::cout << "🟣 ft[2] : " << ft1[2] << std::endl;
		std::cout << "🟣 ft[3] : " << ft1[3] << std::endl;
		std::cout << "🟣 ft[4] : " << ft1[4] << std::endl;

	}

	std::cout << "----------------------- Modifiers " << std::endl;
	{
		std::map<std::string, int> std1;
		ft::map<std::string, int> ft1;

		std::cout << "> insert1 " << std::endl;
		std::cout << "> [dhyeon, 42] 추가 " << std::endl;
		std::pair<std::map<std::string, int>::iterator, bool> std_pair;
		ft::pair<ft::map<std::string, int>::iterator, bool> ft_pair;
		std_pair = std1.insert(std::make_pair<std::string, int>("dhyeon", 42));
		ft_pair = ft1.insert(ft::make_pair<std::string, int>("dhyeon", 42));

		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "insert return : " << std_pair.second << std::endl;
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << "insert return : " << ft_pair.second << std::endl;
		std::cout << std::endl;

		std::cout << "> 같은 key 한번 더 insert" << std::endl;
		std_pair = std1.insert(std::make_pair<std::string, int>("dhyeon", 42));
		ft_pair = ft1.insert(ft::make_pair<std::string, int>("dhyeon", 42));

		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "insert return : " << std_pair.second << std::endl;
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << "insert return : " << ft_pair.second << std::endl;
		std::cout << std::endl;

		std::cout << "> insert2 [som: 100]" << std::endl;
		std1.insert(std1.begin(), std::pair<std::string, int>("som", 100));
		ft1.insert(ft1.begin(), ft::pair<std::string, int>("som", 100));

		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> insert3 [one: 1, two: 2, three:3] " << std::endl;
		std::map<std::string, int> std2;
		ft::map<std::string, int> ft2;

		std2["one"] = 1;
		std2["two"] = 2;
		std2["three"] = 3;
		ft2["one"] = 1;
		ft2["two"] = 2;
		ft2["three"] = 3;
		
		std1.insert(std2.begin(), std2.end());
		ft1.insert(ft2.begin(), ft2.end());
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> erase1 - begin()" << std::endl;
		std1.erase(std1.begin());
		ft1.erase(ft1.begin());
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> erase2 key - som" << std::endl;
		std1.erase("som");
		ft1.erase("som");
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> erase3 begin(), ++begin()" << std::endl;
		std1.erase(std1.begin(), ++std1.begin());
		ft1.erase(ft1.begin(), ++ft1.begin());
		std::cout << "🟡 std ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;

		std::cout << "> swap " << std::endl;
		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << "🟡 std2 ( size : " << std2.size() << " )" << std::endl;
		print_std_map(std2);
		std::cout << "🟣 ft2  ( size : " << ft2.size() << " )" << std::endl;
		print_map(ft2);
		std::cout << std::endl;
		std::cout << "> 1.swap(2)" << std::endl;
		std1.swap(std2);
		ft1.swap(ft2);
		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << "🟡 std2 ( size : " << std2.size() << " )" << std::endl;
		print_std_map(std2);
		std::cout << "🟣 ft2  ( size : " << ft2.size() << " )" << std::endl;
		print_map(ft2);
		std::cout << std::endl;

		std::cout << "> clear 1" << std::endl;
		std1.clear();
		ft1.clear();
		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Observers " << std::endl;
	{
		std::map<std::string, int> std1;
		ft::map<std::string, int> ft1;
		std::map<std::string, int>::key_compare std_comp = std1.key_comp();
		ft::map<std::string, int>::key_compare ft_comp = ft1.key_comp();

		std1["abc"] = 100;
		std1["aaa"] = 200;
		std1["abd"] = 300;
		ft1["abc"] = 100;
		ft1["aaa"] = 200;
		ft1["abd"] = 300;

		std::string highest = std1.rbegin()->first;
		std::string highest2 = ft1.rbegin()->first;

		std::cout << "> key_comp " << std::endl;
		std::map<std::string,int>::iterator std_it = std1.begin();
		ft::map<std::string,int>::iterator ft_it = ft1.begin();
		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		do {
			std::cout << std_comp((*std_it).first, highest) << std::endl;
			std::cout << std_it->first << " => " << std_it->second << '\n';
		} while ( std_comp((*std_it++).first, highest) );
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		do {
			std::cout << ft_comp((*ft_it).first, highest2) << std::endl;
			std::cout << ft_it->first << " => " << ft_it->second << '\n';
		} while ( ft_comp((*ft_it++).first, highest2) );
		std::cout << std::endl;

		std::cout << "> value_comp " << std::endl;

		std_it = std1.begin();
		ft_it = ft1.begin();

		std::pair<std::string, int> v_highest = *std1.rbegin();
		ft::pair<std::string, int> v_highest2 = *ft1.rbegin();

		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		do {
			std::cout << std1.value_comp()(*std_it, v_highest) << std::endl;
			std::cout << std_it->first << " => " << std_it->second << '\n';
		} while ( std1.value_comp()(*std_it++, v_highest) );
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		do {
			std::cout << ft1.value_comp()(*ft_it, v_highest2) << std::endl;
			std::cout << ft_it->first << " => " << ft_it->second << '\n';
		} while ( ft1.value_comp()(*ft_it++, v_highest2) );
		std::cout << std::endl;
	}

	std::cout << "----------------------- Operations " << std::endl;
	{
		std::map<int, std::string> std1;
		ft::map<int, std::string> ft1;

		std1[0] = "zero";
		std1[1] = "one";
		std1[2] = "two";
		ft1[0] = "zero";
		ft1[1] = "one";
		ft1[2] = "two";



		std::cout << "> find " << std::endl;
		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);
		std::cout << "🟡 std1.find(0) => " << std1.find(0)->second << std::endl;
		std::cout << "🟡 std1.find(1) => " << std1.find(1)->second << std::endl;
		std::cout << "🟡 std1.find(2) => " << std1.find(2)->second << std::endl;
		std::cout << "🟣 ft1.find(0) => " << ft1.find(0)->second << std::endl;
		std::cout << "🟣 ft1.find(1) => " << ft1.find(1)->second << std::endl;
		std::cout << "🟣 ft1.find(2) => " << ft1.find(2)->second << std::endl;
		std::cout << std::endl;

		std::cout << "> count " << std::endl;
		for (int i = -1; i < 4; i++) {
			std::cout << "🟡 std1.find(" << i << ") => ";
			if (std1.count(i) > 0)
				std::cout << "is an element" << std::endl;
			else
				std::cout << "is not an element" << std::endl;
			std::cout << "🟣 ft1.find(" << i << ") => ";
			if (ft1.count(i) > 0)
				std::cout << "is an element" << std::endl;
			else
				std::cout << "is not an element" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "> lower_bound " << std::endl;
		std1[4] = "four";
		std1[6] = "six";
		std1[8] = "eight";
		ft1[4] = "four";
		ft1[6] = "six";
		ft1[8] = "eight";
		std::cout << "🟡 std1 ( size : " << std1.size() << " )" << std::endl;
		print_std_map(std1);
		std::cout << "🟣 ft1  ( size : " << ft1.size() << " )" << std::endl;
		print_map(ft1);

		std::cout << "🟡 std1.lower_bound(3) => " << std1.lower_bound(3)->first << " : " << std1.lower_bound(3)->second << std::endl;
		std::cout << "🟣 ft1.lower_bound(3)  => " << ft1.lower_bound(3)->first << " : " << ft1.lower_bound(3)->second << std::endl;
		std::cout << std::endl;

		std::cout << "> upper_bound " << std::endl;
		std::cout << "🟡 std1.upper_bound(3) => " << std1.upper_bound(3)->first << " : " << std1.upper_bound(3)->second << std::endl;
		std::cout << "🟣 ft1.upper_bound(3)  => " << ft1.upper_bound(3)->first << " : " << ft1.upper_bound(3)->second << std::endl;
		std::cout << std::endl;
		std::cout << "> equal_range " << std::endl;
		std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> std_it_pair;
		ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_it_pair;
		std_it_pair = std1.equal_range(1);
		ft_it_pair = ft1.equal_range(1);
		std::cout << "🟡 std : " << std_it_pair.first->first << " => " << std_it_pair.first->second << std::endl;
		std::cout << "🟡 std : " << std_it_pair.second->first << " => " << std_it_pair.second->second << std::endl;
		std::cout << "🟣 ft  : " << ft_it_pair.first->first << " => " << ft_it_pair.first->second << std::endl;
		std::cout << "🟣 ft  : " << ft_it_pair.second->first << " => " << ft_it_pair.second->second << std::endl;
		std::cout << std::endl;
	}

	std::cout << "----------------------- Allocator " << std::endl;
	{
		std::cout << "> get_allocator " << std::endl;
		int std_size;
		int ft_size;
		std::map<char, int> std1;
		ft::map<char, int> ft1;
		std::pair<const char, int>* std_p;
		ft::pair<const char, int>* ft_p;

		std_p = std1.get_allocator().allocate(5);
		ft_p = ft1.get_allocator().allocate(5);

		std_size = sizeof(std::map<char,int>::value_type) * 5;
		ft_size = sizeof(ft::map<char,int>::value_type) * 5;

		std::cout << "🟡 std : The allocated array has a size of " << std_size << " bytes.\n";
		std::cout << "🟣 ft  : The allocated array has a size of " << ft_size << " bytes.\n";

		std1.get_allocator().deallocate(std_p, 5);
		ft1.get_allocator().deallocate(ft_p, 5);

	}

}