#include "./stack.hpp"
#include <stack>
#include "./vector.hpp"

template<class T>
void print_std_stack(std::stack<T> s) {
	std::cout << "std" << std::endl;
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

template<class T>
void print_stack(ft::stack<T> s) {
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
	std::stack<int> std1;
	ft::stack<int> ft1;

	std::cout << " 1, 2, 3, 4, 5 push" << std::endl;
	for (int i = 0; i < 5; i++) {
		std1.push(i + 1);
		ft1.push(i + 1);
	}

	std::cout << "π‘ std : " << std::endl;
	print_std_stack(std1);
	std::cout << "-----------" << std::endl;
	std::cout << "π£ ft  : " << std::endl;
	print_stack(ft1);


	std::cout << "----------------------- Empty " << std::endl;
	std::stack<int> std2;
	ft::stack<int> ft2;

	std::cout << "> λΉ μ€νμΈ κ²½μ°" << std::endl;
	std::cout << "π‘ std : " << std2.empty() << std::endl;
	std::cout << "π£ ft  : " << ft2.empty() << std::endl;
	
	std::cout << "> λΉ μ€νμ΄ μλ κ²½μ°" << std::endl;
	std::cout << "π‘ std : " << std1.empty() << std::endl;
	std::cout << "π£ ft  : " << ft1.empty() << std::endl;

	std::cout << "----------------------- Size " << std::endl;

	std::cout << "> μ¬μ΄μ¦ 0" << std::endl;
	std::cout << "π‘ std : " << std2.size() << std::endl;
	std::cout << "π£ ft  : " << ft2.size() << std::endl;
	
	std::cout << "> μ¬μ΄μ¦ 5" << std::endl;
	std::cout << "π‘ std : " << std1.size() << std::endl;
	std::cout << "π£ ft  : " << ft1.size() << std::endl;

	std::cout << "----------------------- Top " << std::endl;
	std::cout << "π‘ std : " << std1.top() << std::endl;
	std::cout << "π£ ft  : " << ft1.top() << std::endl;

	std::cout << "----------------------- Push " << std::endl;
	std::cout << "> push 42" << std::endl;
	std1.push(42);
	ft1.push(42);

	std::cout << "π‘ std.top() : " << std1.top() << std::endl;
	std::cout << "π£ ft.top()  : " << ft1.top() << std::endl;

	std::cout << "> push 100" << std::endl;
	std1.push(100);
	ft1.push(100);

	std::cout << "π‘ std.top() : " << std1.top() << std::endl;
	std::cout << "π£ ft.top()  : " << ft1.top() << std::endl;

	std::cout << "----------------------- Pop " << std::endl;
	std::cout << "> pop" << std::endl;
	std1.pop();
	ft1.pop();

	std::cout << "π‘ std.top() : " << std1.top() << std::endl;
	std::cout << "π£ ft.top()  : " << ft1.top() << std::endl;

	std::cout << "> pop" << std::endl;
	std1.pop();
	ft1.pop();

	std::cout << "π‘ std.top() : " << std1.top() << std::endl;
	std::cout << "π£ ft.top()  : " << ft1.top() << std::endl;

	std::cout << "----------------------- Relational operators" << std::endl;
	std::cout << "> [1, 2, 3] == [1, 2, 3]" << std::endl;

	std::stack<int> std3;
	std::stack<int> std4;
	ft::stack<int> ft3;
	ft::stack<int> ft4;

	for (int i = 0; i < 3; i++) {
		std3.push(i + 1);
		std4.push(i + 1);
		ft3.push(i + 1);
		ft4.push(i + 1);
	}

	std::cout << "========= κ°μ μ€νμ κ²½μ° ========" << std::endl;
	std::cout << "> [1, 2, 3] == [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 == std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 == ft4) << std::endl;
	std::cout << "> [1, 2, 3] != [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 != std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 != ft4) << std::endl;
	std::cout << "> [1, 2, 3] < [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 < std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 < ft4) << std::endl;
	std::cout << "> [1, 2, 3] <= [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 <= std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 <= ft4) << std::endl;
	std::cout << "> [1, 2, 3] > [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 > std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 > ft4) << std::endl;
	std::cout << "> [1, 2, 3] >= [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 >= std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 >= ft4) << std::endl;

	std3.push(4);
	ft3.push(4);

	std::cout << "========= μ¬μ΄μ¦κ° λ€λ₯Έ μ€νμ κ²½μ° ========" << std::endl;
	std::cout << "> [1, 2, 3, 4] == [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 == std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 == ft4) << std::endl;
	std::cout << "> [1, 2, 3, 4] != [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 != std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 != ft4) << std::endl;
	std::cout << "> [1, 2, 3, 4] < [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 < std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 < ft4) << std::endl;
	std::cout << "> [1, 2, 3, 4] <= [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 <= std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 <= ft4) << std::endl;
	std::cout << "> [1, 2, 3, 4] > [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 > std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 > ft4) << std::endl;
	std::cout << "> [1, 2, 3, 4] >= [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 >= std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 >= ft4) << std::endl;

	std::cout << "========= μ¬μ΄μ¦λ κ°κ³  κ°μ΄ λ€λ₯Έ μ€νμ κ²½μ° ========" << std::endl;
	std3.pop();
	std3.pop();
	ft3.pop();
	ft3.pop();
	std3.push(4);
	ft3.push(4);

	std::cout << "> [1, 2, 4] == [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 == std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 == ft4) << std::endl;
	std::cout << "> [1, 2, 4] != [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 != std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 != ft4) << std::endl;
	std::cout << "> [1, 2, 4] < [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 < std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 < ft4) << std::endl;
	std::cout << "> [1, 2, 4] <= [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 <= std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 <= ft4) << std::endl;
	std::cout << "> [1, 2, 4] > [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 > std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 > ft4) << std::endl;
	std::cout << "> [1, 2, 4] >= [1, 2, 3]" << std::endl;
	std::cout << "π‘ std : " << (std3 >= std4) << std::endl;
	std::cout << "π£ ft  : " << (ft3 >= ft4) << std::endl;

	std::cout << "========= string μ€νμ κ²½μ° ========" << std::endl;
	std::stack<std::string> std5;
	std::stack<std::string> std6;
	ft::stack<std::string> ft5;
	ft::stack<std::string> ft6;

	for (int i = 0; i < 3; i++) {
		std5.push("aaa");
		std6.push("aaa");
		ft5.push("aaa");
		ft6.push("aaa");
	}
	std::cout << "> κ°μ λ¬Έμμ΄ μ€ν" << std::endl;
	std::cout << "> [aaa, aaa, aaa] == [aaa, aaa, aaa]" << std::endl;
	std::cout << "π‘ std : " << (std5 == std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 == ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] != [aaa, aaa, aaa]" << std::endl;
	std::cout << "π‘ std : " << (std5 != std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 != ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] < [aaa, aaa, aaa]" << std::endl;
	std::cout << "π‘ std : " << (std5 < std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 < ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] <= [aaa, aaa, aaa]" << std::endl;
	std::cout << "π‘ std : " << (std5 <= std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 <= ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] > [aaa, aaa, aaa]" << std::endl;
	std::cout << "π‘ std : " << (std5 > std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 > ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] >= [aaa, aaa, aaa]" << std::endl;
	std::cout << "π‘ std : " << (std5 >= std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 >= ft6) << std::endl;
	std::cout << std::endl;
	
	std6.pop();
	ft6.pop();
	std6.push("aab");
	ft6.push("aab");

	std::cout << "> κΈΈμ΄λ κ°μ§λ§ κΈμκ° λ€λ₯Έ λ¬Έμμ΄ μ€ν" << std::endl;
	std::cout << "> [aaa, aaa, aaa] == [aaa, aaa, aab]" << std::endl;
	std::cout << "π‘ std : " << (std5 == std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 == ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] != [aaa, aaa, aab]" << std::endl;
	std::cout << "π‘ std : " << (std5 != std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 != ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] < [aaa, aaa, aab]" << std::endl;
	std::cout << "π‘ std : " << (std5 < std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 < ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] <= [aaa, aaa, aab]" << std::endl;
	std::cout << "π‘ std : " << (std5 <= std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 <= ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] > [aaa, aaa, aab]" << std::endl;
	std::cout << "π‘ std : " << (std5 > std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 > ft6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] >= [aaa, aaa, aab]" << std::endl;
	std::cout << "π‘ std : " << (std5 >= std6) << std::endl;
	std::cout << "π£ ft  : " << (ft5 >= ft6) << std::endl;

}