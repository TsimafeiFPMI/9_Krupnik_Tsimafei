#include <iostream>
#include <time.h>
int main() {
	setlocale(LC_ALL, "RU");
	double a;
	const int n_max = 1000;
	std::cout << "Введите значение a: ";
	std::cin >> a;
	if (std::cin.fail()) {
		std::cout << "Введено неправильное значение a";
		exit(0);
	}                                                        
	double b;
	std::cout << "Введите значение b: ";
	std::cin >> b;
	if (std::cin.fail() || a >= b) {
		std::cout << "Введено неправильное значение b";
		exit(0);
	}
	int chisl;
	std::cout << "Вы хотите рандомный размер массива - 0 или же ручной ввод - 1" << std::endl;
	std::cin >> chisl;
	if (std::cin.fail() || chisl < 0 || chisl > 1) {
		std::cout << "Введено неправильное значение ";
		exit(666);
	}
	if (chisl == 1) {
		int n;
		std::cout << "Введите количество элементов ";
		std::cin >> n;
		if (std::cin.fail() || n < 1 || n > 1000) {
			std::cout << "Введено недействительное количество элементов";
			exit(1);
		}
		double array[n_max];
		for (int j = 0; j < n; j++) {
			std::cout << "Введите элемент массива " << j << std::endl;
			std::cin >> array[j];
			if (std::cin.fail()) {
				std::cout << "Введено недействительное значение ";
				exit(1);
			}
			std::cout << "Ваш элемент " << j << ": " << array[j] << std::endl;
		}
		double max = array[0];
		for (int i = 1; i <= n; i++) {
			if (array[i] > max) {
				max = array[i];
			}
		}
		int writeIndex = 0;
		std::cout << "макс число массива: " << max << std::endl;
		for (int readIndex = 0; readIndex < n; readIndex++) {
			double modul = abs(array[readIndex]);
			if (modul < a || modul > b) {
				array[writeIndex] = array[readIndex];
				writeIndex++;
			}
		}
		for (int i = writeIndex; i < n; i++) {
			array[i] = 0;
		}
		std::cout << "Сжатый массив:" << std::endl;
		for (int i = 0; i < n; i++) {
			std::cout << array[i] << " ";
		}
	}
	else {
		srand(time(NULL));
		int rand_n = 1 + rand() % 100;
		int* arr = new int[rand_n];
		std::cout << "Ваш размер массива: " << rand_n << std::endl;
		for (int j = 0; j < rand_n; j++) {
			arr[j] = -100 + rand() % 201; 
			std::cout << "Ваш элемент " << j << ": " << arr[j] << std::endl;
		}
		int max = arr[0];
		for (int i = 1; i <= rand_n; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		int writeIndex = 0;
		std::cout << "макс число массива: " << max << std::endl;
		for (int readIndex = 0; readIndex < rand_n; readIndex++) {
			double modul = abs(arr[readIndex]);
			if (modul < a || modul > b) {
				arr[writeIndex] = arr[readIndex];
				writeIndex++;
			}
		}
		for (int i = writeIndex; i < rand_n; i++) {
			arr[i] = 0;
		}
		std::cout << "Сжатый массив:" << std::endl;
		for (int i = 0; i < rand_n; i++) {
			std::cout << arr[i] << " ";
		}
	}
     return 0;
}
