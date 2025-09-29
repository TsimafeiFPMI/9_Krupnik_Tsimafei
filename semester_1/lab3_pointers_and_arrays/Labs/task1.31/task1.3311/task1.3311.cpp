#include <iostream>
#include <time.h>
int main() {
	setlocale(LC_ALL, "RU");
	int x;
	std::cout << "Введите значение x: ";
	std::cin >> x;
	if (std::cin.fail()) {
		std::cout << "Введено недействительное значение x";
		exit(777);
	}
	srand(time(NULL));
	int min = 0;
	int rand_n = 1 + rand() % 100;
	int* arr = new int[rand_n];
	std::cout << "Рандомный размер массива: " << rand_n << std::endl;
	for (int i = 0; i < rand_n; i++) {
		arr[i] = -100 + rand() % 201;
		std::cout << "Ваше число " << i << ": " << arr[i] << std::endl;
		if (arr[i] <= min) {
			min = arr[i];
			std::cout << "Ваш минимальный элемент теперь, El: " << i << ": " << min << std::endl;
		}
	}
	for (int i = 0; i < rand_n; i++) {
		int modul = abs(arr[i]);
		if (x < modul) {
			std::cout << "Ваш модуль больший чем x, El "<< i << ": " << modul << std::endl;
		}
	}
	for (int i = 0; i < rand_n; i++) {
		int modul = abs(arr[i]);
		if (x > modul) {
			std::cout << "Оставшиеся числа меньше чем x, El " << i << ": " << modul << std::endl;
		}
	}
	delete[] arr;
	std::cout << "Ваш минимальный элемент " << min << std::endl;
	
	return 0;
}
