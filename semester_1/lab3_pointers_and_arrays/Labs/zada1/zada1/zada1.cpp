#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
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
	std::cout << "макс число массива: " << max;






	return 0;
}
