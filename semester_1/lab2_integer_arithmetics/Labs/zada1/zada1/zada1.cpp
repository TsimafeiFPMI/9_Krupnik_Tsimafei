#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int a;
	std::cout << "Введите значение a: ";
	std::cin >> a;
	if (std::cin.fail()) {
		std::cout << "Введено неправильное значение a или b";
		exit(0);
	}
	int b;
	std::cout << "Введите значение b: ";
	std::cin >> b;
	if (a <= b && std::cin.fail()) {
		std::cout << "Введено неправильное значение a или b";
		exit(0);
	}
	  for (int i = a; i <= b; i++) {
		bool usl = false;
		int n = abs(i);
		while (n > 0 && !usl) {
			int ost = n % 10;
			int chislo = n / 10;
			while (chislo > 0) {
				if (chislo % 10 == ost) {
					usl = true;
					break;
				}
				chislo /= 10;
			}
			n /= 10;
		}
		if (!usl) {
			std::cout << i << " ";
	  }
	}
	return 0;
}
