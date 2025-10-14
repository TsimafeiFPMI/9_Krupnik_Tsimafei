#include <iostream>
#include <time.h>
int* fooarr(int size) {
	if (size <= 0 || size > 1000) {
		std::cout << "Неверный размер массива: " << size << std::endl;
		exit(777);
	}
	return new int[size];
}
int main() {
	setlocale(LC_ALL, "RU");
	int x;
	const int n_max = 1000;
	std::cout << "Введите число x: ";
	std::cin >> x;
	if (std::cin.fail()) {
		std::cout << "Введено недействительное значение x ";
		exit(0);
	}
	int chisl;
	std::cout << "Как вы хотите сделать размер массива: Рандомно - нажмите 0, или ручной ввод - нажмите 1" << std::endl;
	std::cin >> chisl;
	if (std::cin.fail() || chisl <0 || chisl >1) {
		std::cout << "Введено недействительное значение chisl ";
		exit(0);
	}
	if (chisl == 1) {
		int n;
		std::cout << "Введите размер массива" << std::endl;
		std::cin >> n;
		if (std::cin.fail() || n < 1 || n >1000) {
			std::cout << "Введен недействительный размер массива  ";
			exit(0);
		}
		int* arr = fooarr(n);
		std::cout << "Размер массива: " << n << std::endl;
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
			std::cout << "Ваши значения массива, El " << i << ": " << arr[i] << std::endl;
		}
		int lastpositive = -1;
		for (int j = n - 1; j >= 0; j--) {
			if (arr[j] > 0) {
				lastpositive = j;
				break;
			}
		}
		int fpos = -1;
		for (int j = 0; j < n; j++) {
			if (arr[j] > 0) {
				fpos = j;
				break;
			}
		}
		int sum = 0;
		if (lastpositive != -1 && fpos != -1 && fpos <= lastpositive) {
			for (int i = fpos; i <= lastpositive; i++) {
				sum += arr[i];
			}delete[] arr;
			std::cout << "Сумма элементов от первого до последнего положительного: " << sum << std::endl;
		}
		else {
			std::cout << "Увы вам не выпало положительное число" << std::endl;
		}
		for (int i = 0; i < n; i++) {
			int modul = abs(arr[i]);
			if (x < modul) {
				std::cout << "Ваш модуль больший чем x, El " << i << ": " << modul << std::endl;
			}
		}
		for (int i = 0; i < n; i++) {
			int modul = abs(arr[i]);
			if (x > modul) {
				std::cout << "Оставшиеся числа меньше чем x, El " << i << ": " << modul << std::endl;
			}
		}
	}
	else {
		srand(time(NULL));
		int rand_n = 1 + rand() % 100;
		int* arr = fooarr(rand_n);
		std::cout << "Рандомный размер массива: " << rand_n << std::endl;
		for (int i = 0; i < rand_n; i++) {
			arr[i] = -100 + rand() % 201;
			std::cout << "Ваши случайные значения массива, El " << i << ": " << arr[i] << std::endl;
		}
		int lastpositive = -1;
		for (int j = rand_n - 1; j >= 0; j--) {
			if (arr[j] > 0) {
				lastpositive = j;
				break;
			}
		}
		int fpos = -1;
		for (int j = 0; j < rand_n; j++) {
			if (arr[j] > 0) {
				fpos = j;
				break;
			}
		}
		int sum = 0;
		if (lastpositive != -1 && fpos != -1 && fpos <= lastpositive) {
			for (int i = fpos; i <= lastpositive; i++) {
				sum += arr[i];
			}
			std::cout << "Сумма элементов от первого до последнего положительного: " << sum << std::endl;
		}
		else {
			std::cout << "Увы вам не выпало положительное число" << std::endl;
		}
		for (int i = 0; i < rand_n; i++) {
			int modul = abs(arr[i]);
			if (x < modul) {
				std::cout << "Ваш модуль больший чем x, El " << i << ": " << modul << std::endl;
			}
		}
		for (int i = 0; i < rand_n; i++) {
			int modul = abs(arr[i]);
			if (x > modul) {
				std::cout << "Оставшиеся числа меньше чем x, El " << i << ": " << modul << std::endl;
			}
		}
		delete[] arr;
	}
	return 0;
}
