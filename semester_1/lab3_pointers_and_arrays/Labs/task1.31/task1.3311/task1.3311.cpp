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
	int chisl;
	std::cout << "Как вы будете заполнять массив: Рандомно - нажмите клавишу 0, или сами будете вводить число - нажмите 1" << std::endl;
	std::cin >> chisl;
	if (std::cin.fail() || chisl < 0 || chisl > 1) {
		std::cout << "Введено недействительное значение chisl";
		exit(777);
	}
	if (chisl == 1) {
		int n;
		std::cout << "Введите размер массива ";
		std::cin >> n;
		if (std::cin.fail() || n < 1 || n > 1000) {
			std::cout << "Введено недействительное значение размера ( от 1 до 1000)";
			exit(777);
		}
		int* arr = new int[n];
		int min = 100000;
			std::cout << "Размер массива: " << n << std::endl;
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
			std::cout << "Ваше число " << i << ": " << arr[i] << std::endl;
			if (arr[i] < min) {
				min = arr[i];
				std::cout << "Ваш минимальный элемент теперь, El: " << i << ": " << min << std::endl;
			}
		}
		for (int i = 0; i < n; i++) {
			int modul = abs(arr[i]);
			if (x < modul) {
				std::cout << "Ваш модуль больший чем x, El " << i << ": " << modul << std::endl;
			}
		}
		for (int i = 0; i < n; i++) {
			int modul = abs(arr[i]);
			if (x >= modul) {
				std::cout << "Оставшиеся числа меньше чем x, El " << i << ": " << modul << std::endl;
			}
			
		}
		std::cout << "Ваш минимальный элемент " << min << std::endl;
		delete[] arr;
	}
	else {
		srand(time(NULL));
		int rand_n = 1 + rand() % 100;
		int* arr = new int[rand_n];
		int min = 100000;
		std::cout << "Рандомный размер массива: " << rand_n << std::endl;
		for (int i = 0; i < rand_n; i++) {
			arr[i] = -100 + rand() % 201;
			std::cout << "Ваше число " << i << ": " << arr[i] << std::endl;
			if (arr[i] < min) {
				min = arr[i];
				std::cout << "Ваш минимальный элемент теперь, El: " << i << ": " << min << std::endl;
			}
		}
		for (int i = 0; i < rand_n; i++) {
			int modul = abs(arr[i]);
			if (x < modul) {
				std::cout << "Ваш модуль больший чем x, El " << i << ": " << modul << std::endl;
			}
		}
		for (int i = 0; i < rand_n; i++) {
			int modul = abs(arr[i]);
			if (x >= modul) {
				std::cout << "Оставшиеся числа меньше чем x, El " << i << ": " << modul << std::endl;
			}
		}
		delete[] arr;
		std::cout << "Ваш минимальный элемент " << min << std::endl;

	}
	return 0;
}
