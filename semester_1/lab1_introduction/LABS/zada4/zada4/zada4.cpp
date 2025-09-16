#include <iostream>
int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите число n: ";
	int n;
	int s = 0;
	std::cin >> n;
	if (n < 1 || std::cin.fail()) {
		std::cout << "Введено неправильное значение n";
		exit(0);
	}
	for (int i = 0; i <= n*2; i++) {
		if (i % 2 != 0) {
			s += i;
		}
	}
	std::cout << "сумма ваших нечетных: " << s;

	return 0;
}
