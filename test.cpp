#include <vector>
#include <iostream>

int main(void) {
	std::vector<int> a(1,1);

	a.reserve(11);
	std::cout << "size: " << a.size() << " cap : " << a.capacity()  << std::endl;

	a.insert(a.begin(), 12, 1);
	std::cout << "size: " << a.size() << " cap : " << a.capacity()  << std::endl;
}