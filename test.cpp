#include <iostream>
#include <vector>
#include <string>
#include "vector.hpp"
#include "iterator.hpp"

template<class T>
void print_std_vector(std::vector<T>& v) {
	typename std::vector<T>::const_iterator iter;

	std::cout << "[ ";
	for (iter = v.begin(); iter != v.end(); ++iter) {
		std::cout << *iter;
		if (iter + 1 != v.end()) {
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

template<typename T>
void print_vector(ft::vector<T>& v) {
	typename ft::vector<T>::const_iterator iter;
	
	std::cout << "[ ";
	for (iter = v.begin(); iter != v.end(); ++iter) {
		std::cout << *iter;
		if (iter + 1 != v.end()) {
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

int main() {

	std::cout << "=====================================" << std::endl;
	std::cout << "==============[ VECTOR ]=============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	{
		std::cout << "  [ default constructor test ]" << std::endl;
		std::vector<int> tmp1;
		ft::vector<int> ft1;
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ fill constructor test ]" << std::endl;
		std::vector<int> tmp2(5, 3);
		ft::vector<int> ft2(5, 3);
		std::cout << "🟡 std ( size : " << tmp2.size() << " )" << std::endl;
		print_std_vector(tmp2);
		std::cout << "🟣 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ range constructor test ]" << std::endl;
		std::cout << "> first(begin + 1), last(end - 1)" << std::endl;
		std::vector<int> tmp3(tmp2.begin() + 1, tmp2.end() - 1);
		ft::vector<int> ft3(ft2.begin() + 1, ft2.end() - 1);
		std::cout << "🟡 std ( size : " << tmp3.size() << " )" << std::endl;
		print_std_vector(tmp3);
		std::cout << "🟣 ft  ( size : " << ft3.size() << " )" << std::endl;
		print_vector(ft3);
		std::cout << std::endl;
	}
	std::cout << "----------------------- Capacity " << std::endl;
	{
		std::cout << "  [ size test ]" << std::endl;
		std::cout << "> 빈 벡터 생성" << std::endl;
		std::vector<int> tmp1;
		ft::vector<int> ft1;

		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> 숫자 100 이 4개 들어간 벡터 생성" << std::endl;
		std::vector<int> tmp2(4, 100);
		ft::vector<int> ft2(4, 100);

		std::cout << "🟡 std ( size : " << tmp2.size() << " )" << std::endl;
		print_std_vector(tmp2);
		std::cout << "🟣 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ max_size test ]" << std::endl;
		std::cout << "🟡 std : " << tmp2.max_size() << std::endl;
		std::cout << "🟣 ft  : " << ft2.max_size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ resize test - (2) ]" << std::endl;
		// 나중에 추가 필요
		std::cout << "> 2칸으로 resize" << std::endl;
		tmp2.resize(2);
		ft2.resize(2);
		std::cout << "🟡 std ( size : " << tmp2.size() << " )" << std::endl;
		print_std_vector(tmp2);
		std::cout << "🟣 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 10칸으로 resize, 42로 채우기" << std::endl;
		tmp2.resize(10, 42);
		ft2.resize(10, 42);
		std::cout << "🟡 std ( size : " << tmp2.size() << " )" << std::endl;
		print_std_vector(tmp2);
		std::cout << "🟣 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ capacity test ]" << std::endl;
		std::cout << "🟡 std capacity : " << tmp2.capacity() << std::endl;
		std::cout << "🟣 ft capacity  : " << ft2.capacity() << std::endl;
		tmp2.clear();
		ft2.clear();
		std::cout << "> clear로 비움" << std::endl;
		std::cout << "🟡 std ( capacity : " << tmp2.capacity() << " )" << std::endl;
		print_std_vector(tmp2);
		std::cout << "🟣 ft  ( capacity : " << ft2.capacity() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ empty test ]" << std::endl;
		tmp2.push_back(1);
		ft2.push_back(1);
		std::cout << "> 빈배열의 경우" << std::endl;
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> 빈배열이 아닌 경우" << std::endl;
		std::cout << "🟡 std ( size : " << tmp2.size() << " )" << std::endl;
		print_std_vector(tmp2);
		std::cout << "🟣 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;


		std::cout << "  [ reserve test ]" << std::endl;
		std::vector<int> tmp3(4, 5);
		ft::vector<int> ft3(4, 5);
		std::cout << "> 5 가 4개 들어간 벡터"<< std::endl;
		std::cout << "🟡 std ( capacity : " << tmp3.capacity() << " )" << std::endl;
		print_std_vector(tmp3);
		std::cout << "🟣 ft  ( capacity : " << ft3.capacity() << " )" << std::endl;
		print_vector(ft3);
		std::cout << std::endl;

		std::cout << "> 11으로 reserve"<< std::endl;
		std::cout << "🟡 std ( capacity : " << tmp3.capacity() << " )" << std::endl;
		print_std_vector(tmp3);
		std::cout << "🟣 ft  ( capacity : " << ft3.capacity() << " )" << std::endl;
		print_vector(ft3);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Element access " << std::endl;
	{
		std::vector<int> tmp1(1, 100);
		ft::vector<int> ft1(1, 100);

		std::cout << "  [ operator[] test ]" << std::endl;
		std::cout << "🟡 std : ";
		print_std_vector(tmp1);
		std::cout << "std[0] : " << tmp1[0] << std::endl;
		std::cout << std::endl;
		std::cout << "🟣 ft  : ";
		print_vector(ft1);
		std::cout << "ft[0]  : " << ft1[0] << std::endl;
		std::cout << std::endl;

		std::cout << "> push_back(12)" << std::endl;
		tmp1.push_back(12);
		ft1.push_back(12);
		std::cout << "🟡 std : ";
		print_std_vector(tmp1);
		std::cout << "std[1] : " << tmp1[1] << std::endl;
		std::cout << std::endl;

		std::cout << "🟣 ft  : ";
		print_vector(ft1);
		std::cout << "ft[1]  : " << ft1[1] << std::endl;
		std::cout << std::endl;

		std::cout << "  [ at test ]" << std::endl;
		std::cout << "🟡 std.at(1) : " << tmp1.at(1) << std::endl;
		std::cout << "🟣 ft.at(1)  : " << ft1.at(1) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ front test ]" << std::endl;
		std::cout << "🟡 std.front() : " << tmp1.front() << std::endl;
		std::cout << "🟣 ft.front()  : " << ft1.front() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ back test ]" << std::endl;
		std::cout << "🟡 std.back() : " << tmp1.back() << std::endl;
		std::cout << "🟣 ft.back()  : " << ft1.back() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "----------------------- Modifiers " << std::endl;
	{
		std::vector<int> tmp1(3, 100);
		ft::vector<int> ft1(3, 100);
		std::vector<int>::iterator iter;
		ft::vector<int>::iterator ft_iter;

		std::cout << "  [ assign test ]" << std::endl;
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> 2, 77 assign" << std::endl;
		tmp1.assign(2, 77);
		ft1.assign(2, 77);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> 5, 42 assign" << std::endl;
		tmp1.assign(5, 42);
		ft1.assign(5, 42);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> (begin() + 1, end() - 1) iterator assign" << std::endl;
		iter = tmp1.begin() + 1;
		ft_iter = ft1.begin() + 1;
		tmp1.assign(iter, tmp1.end() - 1);
		ft1.assign(ft_iter, ft1.end() - 1);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ push_back test ]" << std::endl;
		std::cout << "> push_back(100)" << std::endl;
		tmp1.push_back(100);
		ft1.push_back(100);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ pop_back test ]" << std::endl;
		std::cout << "> pop_back" << std::endl;
		tmp1.pop_back();
		ft1.pop_back();
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ insert test ]" << std::endl;
		std::cout << "> insert begin(), 1" << std::endl;
		tmp1.insert(tmp1.begin(), 1);
		ft1.insert(ft1.begin(), 1);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> insert begin() + 1, 2, 2" << std::endl;
		tmp1.insert(tmp1.begin() + 1, 2, 2);
		ft1.insert(ft1.begin() + 1, 2, 2);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> insert begin() + 3, iter(begin), iter(end)" << std::endl;
		std::cout << "> iter : [3, 3, 3]" << std::endl;
		std::vector<int> add1(3, 3);
		ft::vector<int> add2(3, 3);
		iter = add1.begin();
		ft_iter = add2.begin();
		tmp1.insert(tmp1.begin() + 3, iter, add1.end());
		ft1.insert(ft1.begin() + 3, ft_iter, add2.end());
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ erase test ]" << std::endl;
		std::cout << "> erase begin" << std::endl;
		tmp1.erase(tmp1.begin() + 3);
		ft1.erase(ft1.begin() + 3);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> erase end() - 1" << std::endl;
		tmp1.erase(tmp1.end() - 1);
		ft1.erase(ft1.end() - 1);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> erase first(begin), last(begin + 3)" << std::endl;
		tmp1.erase(tmp1.begin(), tmp1.begin() + 3);
		ft1.erase(ft1.begin(), ft1.begin() + 3);
		std::cout << "🟡 std ( size : " << tmp1.size() << " )" << std::endl;
		print_std_vector(tmp1);
		std::cout << "🟣 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;


	}
}