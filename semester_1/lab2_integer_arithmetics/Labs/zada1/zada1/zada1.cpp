#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int a;
	std::cout << "Введите значение a: ";
	std::cin >> a;
	if (std::cin.fail()) {
		std::cout << "Введено неправильное значение a";
		exit(0);
	}                                                        //Проверка на букву или неправильное значение
	int b;
	std::cout << "Введите значение b: ";
	std::cin >> b;
	if (a <= b && std::cin.fail()) {
		std::cout << "Введено неправильное значение b";
		exit(0);
	}
	  for (int i = a; i <= b; i++) {
		bool usl = false;
		int n = abs(i);
		while (n > 0 && !usl) {
			int ost = n % 10;                                 //перебираем последнюю цифру 
			int chislo = n / 10;
			while (chislo > 0) {
				if (chislo % 10 == ost) {                     //проверяем на одинаковые цифры
					usl = true;
					break;
				}
				chislo /= 10;                                 
			}
			n /= 10;
		}
		if (!usl) {                                           //если число подходит под условие мы его выводим
			std::cout << i << " ";
	  }
	}
	return 0;
}
