#include <iostream>
#include <vector>
#include <string>
#include "vector.hpp"

int main() {

	std::cout << "=====================================" << std::endl;
	std::cout << "==============[ VECTOR ]=============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Capacity " << std::endl;
	{
		std::cout << "  [ size test ]" << std::endl;
		std::cout << "> 빈 벡터 생성" << std::endl;
		std::vector<int> tmp1;
		ft::vector<int> ft1;

		std::cout << "std : " << tmp1.size() << std::endl;
		std::cout << "ft  : " << ft1.size() << std::endl;

		std::cout << "> 숫자 100 이 4개 들어간 벡터 생성" << std::endl;
		std::vector<int> tmp2(4, 100);
		ft::vector<int> ft2(4, 100);

		std::cout << "std : " << tmp2.size() << std::endl;
		std::cout << "ft  : " << ft2.size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ max_size test ]" << std::endl;
		std::cout << "std : " << tmp2.max_size() << std::endl;
		std::cout << "ft  : " << ft2.max_size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ resize test - (2) ]" << std::endl;
		// 나중에 추가 필요
		std::cout << "> 2칸으로 resize" << std::endl;
		tmp2.resize(2);
		ft2.resize(2);
		std::cout << "std : " << tmp2.size() << std::endl;
		std::cout << "ft  : " << ft2.size() << std::endl;
		std::cout << "> 10칸으로 resize, 42로 채우기" << std::endl;
		tmp2.resize(10, 42);
		ft2.resize(10, 42);
		std::cout << "std : " << tmp2.size() << std::endl;
		std::cout << "ft  : " << ft2.size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ capacity test ]" << std::endl;
		std::cout << "std : " << tmp2.capacity() << std::endl;
		std::cout << "ft  : " << ft2.capacity() << std::endl;
		tmp2.clear();
		ft2.clear();
		std::cout << "> clear로 비움" << std::endl;
		std::cout << "std : " << tmp2.capacity() << std::endl;
		std::cout << "ft  : " << ft2.capacity() << std::endl;
		std::cout << "> 빈 벡터" << std::endl;
		std::cout << "std : " << tmp1.capacity() << std::endl;
		std::cout << "ft  : " << ft1.capacity() << std::endl;
		std::cout << "std : " << tmp1.size() << std::endl;
		std::cout << "ft  : " << ft1.size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ empty test ]" << std::endl;
		std::string res;
		tmp2.push_back(1);
		ft2.push_back(1);
		std::cout << "> 빈배열의 경우" << std::endl;
		res = tmp1.empty() == true ? "true" : "false";
		std::cout << "std : " << res << std::endl;
		res = ft1.empty() == true ? "true" : "false";
		std::cout << "ft  : " << res << std::endl;
		std::cout << "> 빈배열이 아닌 경우" << std::endl;
		res = tmp2.empty() == true ? "true" : "false";
		std::cout << "std : " << res << std::endl;
		res = ft2.empty() == true ? "true" : "false";
		std::cout << "ft  : " << res << std::endl;
		std::cout << std::endl;

		std::cout << "  [ reserve test ]" << std::endl;
		std::vector<int> tmp3(4, 5);
		ft::vector<int> ft3(4, 5);
		std::cout << "> 5 가 4개 들어간 벡터"<< std::endl;
		std::cout << "std : " << tmp3.capacity() << std::endl;
		std::cout << "ft  : " << ft3.capacity() << std::endl;
		std::cout << "> 11으로 reserve"<< std::endl;
		tmp3.reserve(11);
		ft3.reserve(11);
		std::cout << "std : " << tmp3.capacity() << std::endl;
		std::cout << "ft  : " << ft3.capacity() << std::endl;
	}

	std::cout << "----------------------- Element access " << std::endl;
	{
		std::vector<int> tmp1(1, 100);
		ft::vector<int> ft1(1, 100);

		std::cout << "  [ operator[] test ]" << std::endl;
		std::cout << "std[0] : " << tmp1[0] << std::endl;
		std::cout << "ft[0]  : " << ft1[0] << std::endl;

		std::cout << "> push_back(12)" << std::endl;
		tmp1.push_back(12);
		ft1.push_back(12);
		std::cout << "std[1] : " << tmp1[1] << std::endl;
		std::cout << "ft[1]  : " << ft1[1] << std::endl;
		std::cout << std::endl;

		std::cout << "  [ at test ]" << std::endl;
		std::cout << "std.at(1) : " << tmp1.at(1) << std::endl;
		std::cout << "ft.at(1)  : " << ft1.at(1) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ front test ]" << std::endl;
		std::cout << "std.front() : " << tmp1.front() << std::endl;
		std::cout << "ft.front()  : " << ft1.front() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ back test ]" << std::endl;
		std::cout << "std.back() : " << tmp1.back() << std::endl;
		std::cout << "ft.back()  : " << ft1.back() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "----------------------- Modifiers " << std::endl;
	{
		std::vector<int> tmp1(3, 100);
		ft::vector<int> ft1(3, 100);
		std::vector<int>::iterator iter;
		// ft::vector<int>::iterator ft_iter;
		// assign 추가

		std::cout << "  [ push_back test ]" << std::endl;
		tmp1.push_back(42);
		ft1.push_back(42);
		std::cout << "std.back() : " << tmp1.back() << std::endl;
		std::cout << "ft.back()  : " << ft1.back() << std::endl;
		std::cout << 
		std::cout << std::endl;
	}
}