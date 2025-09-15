#include <iostream>
int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите число n: ";
	std::cin >> n;
	if (n < 1 ||std::cin.fail()) {                          //Проверка на буву или число меньшее 1
		std::cout << "Введено неправильное значение n";
		exit(0);
	}
	int a = 2;
	int S = 0;                          //Переменные суммы произведения и начального числа
	long long p = 1;
	int b = 1;
	while (a <= n) {
		S += a;
		a += 2; 
	}
	std::cout << "Сумма четных чисел = " << S << std::endl;
	while (b <= n) {
		p *= b;
		b += 2;
	}
    std::cout << "Произведение нечетных чисел = " << p << std::endl;
	return 0;
}
