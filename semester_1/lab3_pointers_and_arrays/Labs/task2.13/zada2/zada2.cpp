#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите количество элементов ";
	std::cin >> n;
	if (std::cin.fail() || n < 0) {
		std::cout << "Введено недействительное количество элементов";
		exit(1);
	}
double array[1000];
for (int i = 0; i < n; i++) {
	std::cin >> array[i];
}
double lastpositive = -1;
	for (int j = n-1; j >= 0; j--) {
		if (array[j] > 0) {
			lastpositive = j;
			break;
		}
	}
	double sum = 0;
	if(lastpositive != -1){
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
	return 0;
 }
