#include "./stack.hpp"
#include <stack>
#include "./vector.hpp"

template<class T>
void print_std_stack(std::stack<T, ft::vector<T> > s) {
	std::cout << "std" << std::endl;
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

template<class T>
void print_stack(ft::stack<T> s) {
	std::cout << "ft print : " << &s << std::endl;

	std::cout << "ft" << std::endl;
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

int main() {
	std::cout << "=====================================" << std::endl;
	std::cout << "==============[ STACK ]==============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	std::stack<int, ft::vector<int> > std1;
	ft::stack<int> ft1;

		std::cout << "ft1 main : " << &ft1 << std::endl;


	for (int i = 0; i < 5; i++) {
		std1.push(i + 1);
		ft1.push(i + 1);
	}

	std::cout << "🟡 std : " << std::endl;
	print_std_stack(std1);
	// std::cout << "-----------" << std::endl;
	// std::cout << "🟣 ft  : " << std::endl;
	// print_stack(ft1);

	// std::cout << ft1.size() << std::endl;
	// std::cout << std1.size() << std::endl;

}