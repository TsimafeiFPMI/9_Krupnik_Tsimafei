#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	const int n_max = 1000;
	std::cout << "Вы хотите рандомный размер массива - нажмите 0 или хотите ручной ввод - нажмите 1" << std::endl;
	int chisl;
	std::cin >> chisl;
	if (std::cin.fail() || chisl < 0 || chisl > 1) {
		std::cout << "Введено недействительное значение";
		exit(1);
	}
	if (chisl == 1) {
		int n;
		std::cout << "Введите количество элементов ";
		std::cin >> n;
		if (std::cin.fail() || n < 0) {
			std::cout << "Введено недействительное количество элементов";
			exit(1);
		}
		double array[n_max];
		for (int i = 0; i < n; i++) {
			std::cout << "Введите элемент массива " << i << ": ";
			std::cin >> array[i];
			std::cout << "Ваш элемент " << i << ": " << array[i] << std::endl;
		}
		double lastpositive = -1;
		for (int j = n - 1; j >= 0; j--) {
			if (array[j] > 0) {
				lastpositive = j;
				break;
			}
		}
		double sum = 0;
		if (lastpositive != -1) {
			for (int i = 0; i <= lastpositive; i++) {
				sum += array[i];
			}
		}
		std::cout << "Сумма элементов до последнего положительного " << sum << std::endl;
		int a;
		std::cout << "Введите значение a: ";
		std::cin >> a;
		if (std::cin.fail()) {
			std::cout << "Введено неправильное значение a";
			exit(0);
		}
		int b;
		std::cout << "Введите значение b: ";
		std::cin >> b;
		if (std::cin.fail() || a >= b) {
			std::cout << "Введено неправильное значение b";
			exit(0);
		}
		int writeIndex = 0;

		for (int readIndex = 0; readIndex < n; readIndex++) {
			double modulus = abs(array[readIndex]);
			if (modulus < a || modulus > b) {
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
		double rand_n = 1 + rand() % 100;
		double* arr = new double[rand_n];
		for (int i = 0; i < rand_n; i++) {
			arr[i] = -100 + rand() % 201;
		}
		double lastpositive = -1;
		for (int j = rand_n - 1; j >= 0; j--) {
			if (arr[j] > 0) {
				lastpositive = j;
				break;
			}
		}
		double sum = 0;
		if (lastpositive != -1) {
			for (int i = 0; i <= lastpositive; i++) {
				sum += arr[i];
			}
		}
		std::cout << "Сумма элементов до последнего положительного " << sum << std::endl;
		int a = 1 + rand() % 50;
		int b = 51 + rand() % 50;
		int writeIndex = 0;

		for (int readIndex = 0; readIndex < rand_n; readIndex++) {
			double modulus = abs(arr[readIndex]);
			if (modulus < a || modulus > b) {
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
		}delete[] arr;
	}
	
	return 0;
 }
