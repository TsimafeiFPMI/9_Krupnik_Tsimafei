#include <iostream>
int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите число n: ";
	int n;
	std::cin >> n;
	if (n < 1 || std::cin.fail()) {
		std::cout << "Введено неправильное значение n";
		exit(0);
	std::cout << "Введите число m: ";
	int m;
	std::cin >> m;
	if (m < 1 || std::cin.fail()) {
		std::cout << "Введено неправильное значение m";
		exit(0);
		







	return 0;
}
