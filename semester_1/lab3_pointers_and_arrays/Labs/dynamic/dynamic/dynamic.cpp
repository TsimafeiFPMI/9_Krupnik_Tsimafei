#include <iostream>
#include <ctime>
#include <cmath>

double* fooarr(int size) {
    if (size <= 0 || size > 1000) {
        std::cout << "Неверный размер массива: " << size << std::endl;
        exit(777);
    }
    return new double[size];
}

int main() {
    setlocale(LC_ALL, "RU");
    double x;
    std::cout << "Введите значение x: ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cout << "Введено недействительное значение x";
        exit(777);
    }

    int chisl;
    std::cout << "Как вы будете заполнять массив: Рандомно - нажмите клавишу 0, или сами будете вводить число - нажмите 1" << std::endl;
    std::cin >> chisl;
    if (std::cin.fail() || chisl < 0 || chisl > 1) {
        std::cout << "Введено недействительное значение chisl";
        exit(777);
    }

    if (chisl == 1) {
        int n;
        std::cout << "Введите размер массива ";
        std::cin >> n;
        if (std::cin.fail() || n < 1 || n > 1000) {
            std::cout << "Введено недействительное значение размера ( от 1 до 1000 )";
            exit(777);
        }

        double* arr = fooarr(n);
        int min_index = 0;
        std::cout << "Размер массива: " << n << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            std::cout << "Ваше число " << i << ": " << arr[i] << std::endl;
            if (arr[i] < arr[min_index]) {
                min_index = i;
                std::cout << "Ваш минимальный элемент теперь, El: " << i << ": " << arr[i] << std::endl;
            }
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
            }
            std::cout << "Сумма элементов от первого до последнего положительного: " << sum << std::endl;
        }
        else {
            std::cout << "Увы вам не выпало положительное число" << std::endl;
        }
        int write_index = 0;
        for (int i = 0; i < n; i++) {
            if (std::abs(arr[i]) > x) {
                arr[write_index++] = arr[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (std::abs(arr[i]) <= x) {
                arr[write_index++] = arr[i];
            }
        }
        std::cout << "Преобразованный массив: ";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Ваш минимальный элемент " << arr[min_index] << std::endl;

        delete[] arr;
    }
    else {
        srand(time(NULL));
        double lower_bound, upper_bound;
        std::cout << "Введите нижнюю границу для рандомных чисел: ";
        std::cin >> lower_bound;
        std::cout << "Введите верхнюю границу для рандомных чисел: ";
        std::cin >> upper_bound;

        if (std::cin.fail() || lower_bound >= upper_bound) {
            std::cout << "Неверные границы для рандомных чисел";
            exit(777);
        }

        std::cout << "Введите размер массива " << std::endl;
        int rand_n;
        std::cin >> rand_n;
        if (std::cin.fail() || rand_n < 1 || rand_n > 1000) {
            std::cout << "Неверный размер массива";
            exit(777);
        }

        double* arr = fooarr(rand_n);
        int min_index = 0;
        for (int i = 0; i < rand_n; i++) {
            arr[i] = lower_bound + (rand() * 1.0 / RAND_MAX) * (upper_bound - lower_bound);
            std::cout << "Ваше число " << i << ": " << arr[i] << std::endl;
            if (arr[i] < arr[min_index]) {
                min_index = i;
                std::cout << "Ваш минимальный элемент теперь, El: " << i + 1 << ": " << arr[i] << std::endl;
            }
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

        // преобразование массива
        int write_index = 0;
        for (int i = 0; i < rand_n; i++) {
            if (std::abs(arr[i]) > x) {
                arr[write_index++] = arr[i];
            }
        }
        for (int i = 0; i < rand_n; i++) {
            if (std::abs(arr[i]) <= x) {
                arr[write_index++] = arr[i];
            }
        }

        std::cout << "Преобразованный массив: ";
        for (int i = 0; i < rand_n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Ваш минимальный элемент " << min_index + 1 << std::endl;

        delete[] arr;
    }

    return 0;
}
