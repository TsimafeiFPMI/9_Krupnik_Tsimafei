#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
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
	if (a >= b || std::cin.fail()) {
		std::cout << "Введено неправильное значение b";
		exit(0);
	}
	int n;
	std::cout << "Введите количество элементов ";
	std::cin >> n;
	if (std::cin.fail()) {
		std::cout << "Введено недействительное количество элементов";
		exit(1);
	}
	int array[1000] ;
	for (int j = 0; j < n; j++) {
		std::cin >> array[j];
	}
	int max = array[0];
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






	return 0;
}
