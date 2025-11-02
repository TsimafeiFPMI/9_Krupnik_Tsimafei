#include <iostream>
#include<time.h>
int main() {
    const int MAX_SIZE = 1000;
    std::setlocale(LC_ALL, "RU");
    std::srand(std::time(NULL));

    double a, b;
    int choice;

    // Ввод значения a
    std::cout << "Введите значение a: ";
    std::cin >> a;
    if (std::cin.fail()) {
        std::cout << "Введено неправильное значение a" << std::endl;
        return 1;
    }

    // Ввод значения b
    std::cout << "Введите значение b: ";
    std::cin >> b;
    if (std::cin.fail() || a >= b) {
        std::cout << "Введено неправильное значение b" << std::endl;
        return 1;
    }

    // Выбор способа ввода
    std::cout << "Вы хотите рандомный размер массива - 0 или же ручной ввод - 1: ";
    std::cin >> choice;
    if (std::cin.fail() || choice < 0 || choice > 1) {
        std::cout << "Введено неправильное значение" << std::endl;
        return 1;
    }

    if (choice == 1) {
        int n;
        std::cout << "Введите количество элементов (1-" << MAX_SIZE << "): ";
        std::cin >> n;
        if (std::cin.fail() || n < 1 || n > MAX_SIZE) {
            std::cout << "Введено недействительное количество элементов" << std::endl;
            return 1;
        }

        double array[MAX_SIZE];
        for (int i = 0; i < n; i++) {
            std::cout << "Введите элемент массива " << i << ": ";
            std::cin >> array[i];
            if (std::cin.fail()) {
                std::cout << "Введено недействительное значение" << std::endl;
                return 1;
            }
            std::cout << "Ваш элемент " << i << ": " << array[i] << std::endl;
        }
        std::cout << "=== ОТЛАДКА ===" << std::endl;
        std::cout << "Весь массив: ";
        for (int i = 0; i < n; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
        double max = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        std::cout << "Максимальное число массива: " << max << std::endl;
        int lastPositiveIndex = -1;
        for (int i = n - 1; i >= 0; i--) {
            std::cout << "Проверяем элемент [" << i << "] = " << array[i];
            if (array[i] > 0) {
                lastPositiveIndex = i;
                std::cout << " - НАЙДЕН ПОЛОЖИТЕЛЬНЫЙ!" << std::endl;
                break;
            }
            std::cout << " - отрицательный или ноль" << std::endl;
        }

        std::cout << "Индекс последнего положительного: " << lastPositiveIndex << std::endl;

        double sum = 0;
        if (lastPositiveIndex != -1) {
            for (int i = 0; i < lastPositiveIndex; i++) {
                sum += array[i];
                std::cout << "Добавляем элемент [" << i << "] = " << array[i] << ", текущая сумма: " << sum << std::endl;
            }
            std::cout << "Сумма элементов до последнего положительного: " << sum << std::endl;
        }
        else {
            std::cout << "В массиве нет положительных элементов" << std::endl;
        }

        // Сжатие массива (удаление элементов с модулем в диапазоне [a, b])
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < n; readIndex++) {
            double modulus = std::abs(array[readIndex]);
            if (modulus < a || modulus > b) {
                array[writeIndex] = array[readIndex];
                writeIndex++;
            }
        }

        // Заполнение оставшихся элементов нулями
        for (int i = writeIndex; i < n; i++) {
            array[i] = 0;
        }

        // Вывод сжатого массива
        std::cout << "Сжатый массив:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

    }
    else {
        double lower_bound, upper_bound;
        std::cout << "Введите нижнюю границу для рандомных чисел: ";
        std::cin >> lower_bound;
        std::cout << "Введите верхнюю границу для рандомных чисел: ";
        std::cin >> upper_bound;

        if (std::cin.fail() || lower_bound >= upper_bound) {
            std::cout << "Неверные границы для рандомных чисел" << std::endl;
            return 1;
        }

        int n;
        std::cout << "Введите размер массива (1-" << MAX_SIZE << "): ";
        std::cin >> n;
        if (std::cin.fail() || n < 1 || n > MAX_SIZE) {
            std::cout << "Введено недействительное количество элементов" << std::endl;
            return 1;
        }

        std::cout << "Ваш размер массива: " << n << std::endl;

        double* array = new double[n];
        double range = upper_bound - lower_bound;
        for (int i = 0; i < n; i++) {
            array[i] = lower_bound + (std::rand() % 10001) / 10000.0 * range;
            std::cout << "Ваш элемент " << i << ": " << array[i] << std::endl;
        }
        std::cout << "=== ОТЛАДКА ===" << std::endl;
        std::cout << "Весь массив: ";
        for (int i = 0; i < n; i++) {
            std::cout << array[i] << " ";
        }
        double max = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        std::cout << "Максимальное число массива: " << max << std::endl;
        int lastPositiveIndex = -1;
        for (int i = n - 1; i >= 0; i--) {
            std::cout << "Проверяем элемент [" << i << "] = " << array[i];
            if (array[i] > 0) {
                lastPositiveIndex = i;
                std::cout << " - НАЙДЕН ПОЛОЖИТЕЛЬНЫЙ!" << std::endl;
                break;
            }
            std::cout << " - отрицательный или ноль" << std::endl;
        }

        std::cout << "Индекс последнего положительного: " << lastPositiveIndex << std::endl;

        double sum = 0;
        if (lastPositiveIndex != -1) {
            for (int i = 0; i <= lastPositiveIndex; i++) {
                sum += array[i];
                std::cout << "Добавляем элемент [" << i << "] = " << array[i] << ", текущая сумма: " << sum << std::endl;
            }
            std::cout << "Сумма элементов до последнего положительного: " << sum << std::endl;
        }
        else {
            std::cout << "В массиве нет положительных элементов" << std::endl;
        }

        // Сжатие массива
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < n; readIndex++) {
            double modulus = std::abs(array[readIndex]);
            if (modulus < a || modulus > b) {
                array[writeIndex] = array[readIndex];
                writeIndex++;
            }
        }

        // Заполнение оставшихся элементов нулями
        for (int i = writeIndex; i < n; i++) {
            array[i] = 0;
        }

        // Вывод сжатого массива
        std::cout << "Сжатый массив:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        delete[] array; // Освобождение памяти
    }

    return 0;
}