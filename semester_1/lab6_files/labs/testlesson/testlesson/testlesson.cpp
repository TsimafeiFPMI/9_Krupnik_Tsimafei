#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		int val;
		std::cin >> val;
		vec.push_back(val);
		std::cout << val;
	}
	return 0;
}
