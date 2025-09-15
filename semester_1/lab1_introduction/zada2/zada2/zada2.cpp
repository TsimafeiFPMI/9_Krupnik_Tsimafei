#include <iostream>
int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите число k: ";
	int k;
	std::cin >> k;
	if (k < 0 || std::cin.fail()) {
		std::cout << "Введено неправильное значение k";
		exit(0);
	}
	int a = 1;
	int p1 = 1;
	int b = 2;
	int p2 = 1;
	if (k % 2 == 0) {
		while (b <= k) {
			p2 *= b;
			b += 2;
		}
		std::cout << "Ваш двойной факториал = " << p2 << std::endl;
	}
	else {
		while (a <= k) {
			p1 *= a;
			a += 2;
		}
		std::cout << "Ваш двойной факториал = " << p1 << std::endl;
	}

	return 0;
}
