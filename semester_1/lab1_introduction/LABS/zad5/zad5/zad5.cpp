#include <iostream>
int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите число n: ";
	int n;
	std::cin >> n;
	if (n < 1000 || n > 9999 || std::cin.fail()) {
	std::cout << "Введено неправильное значение n";
		exit(0);
	}
	int a4 = n % 10;
	int a3 = (n / 10) % 10;
	int a2 = (n / 100) % 10;
	int a = (n / 1000);
	if (n == (a4 * 1000 + a3 * 100 + a2 * 10 + a)) {
		std::cout << "Число " << n << " является палиндромом";
	}
	else {
		std::cout << "Число " << n << " не является палиндромом";
	}
	return 0;
}
