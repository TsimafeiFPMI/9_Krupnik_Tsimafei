#include <iostream>
#include <time.h>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	srand(time(NULL));
	}
	int *array[1000] = new array[1000;
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
