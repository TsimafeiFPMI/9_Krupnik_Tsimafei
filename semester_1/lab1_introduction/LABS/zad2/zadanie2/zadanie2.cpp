#include <iostream>
int main()
{
	std::cout << "Введите число k";
	int k;
	std::cin >> k;
	setlocale(LC_ALL, "RU");
	if (k < 0 || std::cin.fail()) {
		std::cout << "Введено неправильное значение k";
		exit(0);
	}
	int a = 1;
	int p1 = 1;
	int b = 2;
	int p2 = 1;
	while (a <= k) {
		p1 *= a;
		a += 2;
	}
	if (p1 % 2 == 0) {
		std::cout << "Ваш двойной факториал = " << p1 << std::endl;
	}
	else {
		while (b <= k) {
			p2 *= b;
			b += 2;
		}
	}

	return 0;
}
