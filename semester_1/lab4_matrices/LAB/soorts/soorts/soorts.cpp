#include <iostream>
#include <random>
#include <iomanip>
void fill_matrix(int& rows, int& cols) {
	std::cout << "Enter the data of the matrix (numbers) " << std::endl;
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
void merge(int* arr, int left, int mid, int right, bool ascending) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* leftArr = new int[n1];
	int* rightArr = new int[n2];

	for (int i = 0; i < n1; i++)
		leftArr[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		rightArr[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (ascending ? (leftArr[i] <= rightArr[j]) : (leftArr[i] >= rightArr[j])) {
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
	delete[] leftArr;
	delete[] rightArr;
}

void mergeSortHelper(int* arr, int left, int right, bool ascending) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSortHelper(arr, left, mid, ascending);
	mergeSortHelper(arr, mid + 1, right, ascending);
	merge(arr, left, mid, right, ascending);
}
void mergeSort(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to sort: ascending(1) or descending(2): ";
	std::cin >> choose;
	bool ascending = (choose == 1);

	for (int row = 0; row < rows; ++row) {
		mergeSortHelper(matrix[row], 0, cols - 1, ascending);
	}
}
void countingSort(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to sort: ascending(1) or descending(2): ";
	std::cin >> choose;
	bool ascending = (choose == 1);

	for (int row = 0; row < rows; ++row) {
		int minVal = matrix[row][0];
		int maxVal = matrix[row][0];
		for (int j = 1; j < cols; ++j) {
			if (matrix[row][j] < minVal) minVal = matrix[row][j];
			if (matrix[row][j] > maxVal) maxVal = matrix[row][j];
		}
		int range = maxVal - minVal + 1;
		int* count = new int[range]();
		for (int j = 0; j < cols; ++j) {
			count[matrix[row][j] - minVal]++;
		}
		int index = 0;
		if (ascending) {
			for (int i = 0; i < range; ++i) {
				while (count[i] > 0) {
					matrix[row][index++] = i + minVal;
					count[i]--;
				}
			}
		}
		else {
			for (int i = range - 1; i >= 0; --i) {
				while (count[i] > 0) {
					matrix[row][index++] = i + minVal;
					count[i]--;
				}
			}
		}
		delete[] count;
	}
}
int partition(int* arr, int low, int high, bool ascending) {
	int pivot = arr[high];
	int i = low - 1;

	if (ascending) {
		for (int j = low; j < high; j++) {
			if (arr[j] <= pivot) {
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
	}
	else {
		for (int j = low; j < high; j++) {
			if (arr[j] >= pivot) {
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
	}

	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSortHelper(int* arr, int low, int high, bool ascending) {
	if (low < high) {
		int pi = partition(arr, low, high, ascending);
		quickSortHelper(arr, low, pi - 1, ascending);
		quickSortHelper(arr, pi + 1, high, ascending);
	}
}
void quickSort(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to sort: ascending(1) or descending(2): ";
	std::cin >> choose;
	bool ascending = (choose == 1);

	for (int row = 0; row < rows; ++row) {
		quickSortHelper(matrix[row], 0, cols - 1, ascending);
	}
}
void selectionSort(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to sort: ascending(1) or descending(2): ";
	std::cin >> choose;
	for (int p = 0; p < rows; p++) {
		if (choose == 1) {
			for (int i = 0; i < cols - 1; i++) {
				int minIndex = i;
				for (int j = i + 1; j < cols; j++) {
					if (matrix[p][j] < matrix[p][minIndex]) {
						minIndex = j;
					}
				}
				std::swap(matrix[p][i], matrix[p][minIndex]);
			}
		}
		if (choose == 2) {
			for (int i = 0; i < cols - 1; i++) {
				int minIndex = i;
				for (int j = i + 1; j < cols; j++) {
					if (matrix[p][j] > matrix[p][minIndex]) {
						minIndex = j;
					}
				}
				std::swap(matrix[p][i], matrix[p][minIndex]);
			}
		}
	}
}
void choice_of_sorts(int** matrix, int rows, int cols) {
	int choose;
	std::cout << "How do you want to go : Bubble (1) --- Merge (2) --- Counter (3) --- Quick(4) --- Selection(5)" << std::endl;
	std::cin >> choose;
	if (std::cin.fail() || choose < 1 || choose > 5) {
		std::cout << "You have entered an invalid or negative value.. ";
		std::exit(777);
	}
	if (choose == 1) {
		sortRows(matrix, rows, cols);
	}
	else if (choose == 2) {
		mergeSort(matrix, rows, cols);
	}
	else if (choose == 3) {
		countingSort (matrix, rows, cols);
	}
	else if (choose == 4) {
		quickSort (matrix, rows, cols);
	}
	else if (choose == 5) {
		selectionSort(matrix, rows, cols);
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
	deleting(matrix, rows);
	return 0;
}
