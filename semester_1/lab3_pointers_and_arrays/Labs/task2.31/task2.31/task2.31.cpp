#include <iostream>
#include <time.h>
int main() {
	setlocale(LC_ALL, "RU");
	int x;
	std::cout << "Введите число x: ";
	std::cin >> x;
	if (std::cin.fail()) {
		std::cout << "Введено недействительное значение x ";
		exit(0);
	}
	srand(time(NULL));
	int rand_n = 1 + rand() % 100;
	int* arr = new int[rand_n];
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
	return 0;
}
