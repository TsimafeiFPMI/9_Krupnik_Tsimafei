#include <iostream>
#include <iomanip>
#include <random>

void length_side(int& len) {
	std::cout << "Enter the length of the side matrix: ";
	if (!(std::cin >> len) || len < 1) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
}
void create_matrix(int**& matrix, int len) {
	matrix = new int* [len];
	for (int i = 0; i < len; i++) {
		matrix[i] = new int[len];
	}
}
void filing_random_number(int** matrix, int len) {
	int low, upp;
	std::cout << "Enter the boundaries from lower to upper: ";
	std::cin >> low;
	if (std::cin.fail()) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(666);
	}
	std::cin >> upp;
	if (std::cin.fail() ) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(666);
	}

	if (low > upp) {
		std::swap(low, upp);
	}

	std::mt19937 gen(45218965);
	std::uniform_int_distribution<int> dist(low, upp);

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			matrix[i][j] = dist(gen);
		}
	}
}
void filing_manual_number(int** matrix, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (!(std::cin >> matrix[i][j])) {
				std::cout << "You have entered an invalid value.. ";
				std::exit(666);
			}
		}
	}
}
void printMatrix(int** matrix, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << "\n";
	}
}
void choice(int** matrix, int len) {
	int choose;
	std::cout << "How do you want to fill the matrix: Random numbers (1) or manual input (2) ";
	std::cin >> choose;
	if (std::cin.fail() || choose < 1 || choose > 2) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
	if (choose == 1) {
		filing_random_number(matrix, len);
		std::cout << "\nThis is your random numbers:\n";
		printMatrix(matrix, len);
	}
	else {
		std::cout << "Enter elements: ";
		filing_manual_number(matrix, len);
	}
}
void sortRows(int** matrix, int len) {
	int* sums = new int[len];
	for (int i = 0; i < len; i++) {
		sums[i] = 0;
		for (int j = 0; j < len; j++) {
			sums[i] += matrix[i][j];
		}
	}
	std::cout << "Sums before sorting: ";
	for (int i = 0; i < len; i++) {
		std::cout << sums[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (sums[j] > sums[j + 1]) {
				std::swap(sums[j], sums[j + 1]);
				std::swap(matrix[j], matrix[j + 1]);
			}
		}
	}
	std::cout << "Sums after sorting:  ";
	for (int i = 0; i < len; i++) {
		std::cout << sums[i] << " ";
	}
	std::cout << std::endl;

	delete[] sums;
}
int findFirstPositiveColumn(int** matrix, int len) {
	for (int j = 0; j < len; ++j) {
		bool hasNegative = false;
		for (int i = 0; i < len; ++i) {
			if (matrix[i][j] < 0) {
				hasNegative = true;
				break;
			}
		}
		if (!hasNegative) {
			return j;
		}
	}

	return -1;
}
void deleting(int** matrix, int len) {
	for (int i = 0; i < len; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main() {
	int len;
	length_side(len);

	int** matrix;
	create_matrix(matrix, len);

	choice(matrix, len);

	sortRows(matrix, len);

	printMatrix(matrix, len);

	std::cout << "\n Finding first column without negative elements \n";
	int columnIndex = findFirstPositiveColumn(matrix, len);

	if (columnIndex != -1) {
		std::cout << "First column without negative elements: column " << columnIndex << std::endl;
		std::cout << "Column " << columnIndex << ": ";
		for (int i = 0; i < len; i++) {
			std::cout << matrix[i][columnIndex] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "No column without negative elements found! " << std::endl;
	}

    deleting(matrix, len);

	return 0;
}
