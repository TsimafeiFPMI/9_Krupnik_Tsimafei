#include <iostream>
#include <random>
#include <iomanip>
void fill_matrix(int& rows, int& cols) {
	std::cout << "Enter the data of the matrix" << std::endl;
	if (!(std::cin >> rows) || rows < 1) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
	if (!(std::cin >> cols) || cols < 1) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
}
void create_matrix(int**& matrix, int rows, int cols) {
	matrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
			matrix[i] = new int[cols];
		}
}
void filing_random_number(int** matrix, int rows, int cols) {
	int low, upp;
	std::cout << "Enter the boundaries from lower to upper: ";
	std::cin >> low;
	if (std::cin.fail()) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(666);
	}
	std::cin >> upp;
	if (std::cin.fail()) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(666);
	}

	if (low > upp) {
		std::swap(low, upp);
	}

	std::mt19937 gen(45218965);
	std::uniform_int_distribution<int> dist(low, upp);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = dist(gen);
		}
	}
}
void filing_manual_number(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!(std::cin >> matrix[i][j])) {
				std::cout << "You have entered an invalid value.. ";
				std::exit(666);
			}
		}
	}
}
void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << "\n";
	}
}
void choice(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to fill the matrix: Random numbers (1) or manual input (2) ";
	std::cin >> choose;
	if (std::cin.fail() || choose < 1 || choose > 2) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
	if (choose == 1) {
		filing_random_number(matrix, rows, cols);
		std::cout << "\nThis is your random numbers:\n";
		printMatrix(matrix, rows, cols);
	}
	else {
		std::cout << "Enter elements: ";
		filing_manual_number(matrix, rows, cols);
	}
}
void sortRows(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to go : ascending(1) or descending(2)" << std::endl;
	std::cin >> choose;

	for (int row = 0; row < rows; ++row) {
		if (choose == 1) {
			for (int i = 0; i < cols - 1; ++i) {
				for (int j = 0; j < cols - i - 1; ++j) {
					if (matrix[row][j] > matrix[row][j + 1]) {
						std::swap(matrix[row][j], matrix[row][j + 1]);
					}
				}
			}
		}
		else {
			for (int i = 0; i < cols - 1; ++i) {
				for (int j = 0; j < cols - i - 1; ++j) {
					if (matrix[row][j] < matrix[row][j + 1]) {
						std::swap(matrix[row][j], matrix[row][j + 1]);
					}
				}
			}
		}
	}
}
void choice_of_sorts(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to go : Bubble (1) --- Merge (2) --- Counter (3)";
	std::cin >> choose;
	if (std::cin.fail() || choose < 1 || choose > 3) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
	if (choose == 1) {
		sortRows(matrix, rows, cols);
	}
	else if (choose == 2) {
		std::cout << "good";
	}
}
void deleting(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
int main() {
	int rows;
	int cols;
	fill_matrix(rows, cols);
	int** matrix;
	create_matrix(matrix, rows, cols);
	choice(matrix, rows, cols);
	choice_of_sorts(matrix, rows, cols);
	printMatrix(matrix, rows, cols);
	return 0;
}
