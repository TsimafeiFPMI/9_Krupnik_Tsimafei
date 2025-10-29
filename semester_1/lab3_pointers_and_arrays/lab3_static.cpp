#include <iostream>
#include<time.h>
int main() {
    const int MAX_SIZE = 1000;
    std::setlocale(LC_ALL, "RU");
    std::srand(std::time(NULL));

    double a, b;
    int choice;

    // ���� �������� a
    std::cout << "������� �������� a: ";
    std::cin >> a;
    if (std::cin.fail()) {
        std::cout << "������� ������������ �������� a" << std::endl;
        return 1;
    }

    // ���� �������� b
    std::cout << "������� �������� b: ";
    std::cin >> b;
    if (std::cin.fail() || a >= b) {
        std::cout << "������� ������������ �������� b" << std::endl;
        return 1;
    }

    // ����� ������� �����
    std::cout << "�� ������ ��������� ������ ������� - 0 ��� �� ������ ���� - 1: ";
    std::cin >> choice;
    if (std::cin.fail() || choice < 0 || choice > 1) {
        std::cout << "������� ������������ ��������" << std::endl;
        return 1;
    }

    if (choice == 1) {
        // ������ ����
        int n;
        std::cout << "������� ���������� ��������� (1-" << MAX_SIZE << "): ";
        std::cin >> n;
        if (std::cin.fail() || n < 1 || n > MAX_SIZE) {
            std::cout << "������� ���������������� ���������� ���������" << std::endl;
            return 1;
        }

        double array[MAX_SIZE];

        // ���� ��������� �������
        for (int i = 0; i < n; i++) {
            std::cout << "������� ������� ������� " << i << ": ";
            std::cin >> array[i];
            if (std::cin.fail()) {
                std::cout << "������� ���������������� ��������" << std::endl;
                return 1;
            }
            std::cout << "��� ������� " << i << ": " << array[i] << std::endl;
        }

        // �������: ������� ���� ������
        std::cout << "=== ������� ===" << std::endl;
        std::cout << "���� ������: ";
        for (int i = 0; i < n; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        // ����� ������������� ��������
        double max = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        std::cout << "������������ ����� �������: " << max << std::endl;

        // ����� ���������� �������������� � ���������� �����
        int lastPositiveIndex = -1;
        for (int i = n - 1; i >= 0; i--) {
            std::cout << "��������� ������� [" << i << "] = " << array[i];
            if (array[i] > 0) {
                lastPositiveIndex = i;
                std::cout << " - ������ �������������!" << std::endl;
                break;
            }
            std::cout << " - ������������� ��� ����" << std::endl;
        }

        std::cout << "������ ���������� ��������������: " << lastPositiveIndex << std::endl;

        double sum = 0;
        if (lastPositiveIndex != -1) {
            for (int i = 0; i <= lastPositiveIndex; i++) {
                sum += array[i];
                std::cout << "��������� ������� [" << i << "] = " << array[i] << ", ������� �����: " << sum << std::endl;
            }
            std::cout << "����� ��������� �� ���������� ��������������: " << sum << std::endl;
        }
        else {
            std::cout << "� ������� ��� ������������� ���������" << std::endl;
        }

        // ������ ������� (�������� ��������� � ������� � ��������� [a, b])
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < n; readIndex++) {
            double modulus = std::abs(array[readIndex]);
            if (modulus < a || modulus > b) {
                array[writeIndex] = array[readIndex];
                writeIndex++;
            }
        }

        // ���������� ���������� ��������� ������
        for (int i = writeIndex; i < n; i++) {
            array[i] = 0;
        }

        // ����� ������� �������
        std::cout << "������ ������:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

    }
    else {
        // ��������� ������
        int randomSize = 1 + std::rand() % MAX_SIZE;
        std::cout << "��� ������ �������: " << randomSize << std::endl;

        double* array = new double[randomSize];

        // ���������� ������� ���������� �������
        for (int i = 0; i < randomSize; i++) {
            array[i] = -100 + std::rand() % 201; // ����� �� -100 �� 100
            std::cout << "��� ������� " << i << ": " << array[i] << std::endl;
        }

        // �������: ������� ���� ������
        std::cout << "=== ������� ===" << std::endl;
        std::cout << "���� ������: ";
        for (int i = 0; i < randomSize; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        // ����� ������������� ��������
        double max = array[0];
        for (int i = 1; i < randomSize; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        std::cout << "������������ ����� �������: " << max << std::endl;

        // ����� ���������� �������������� � ���������� �����
        int lastPositiveIndex = -1;
        for (int i = randomSize - 1; i >= 0; i--) {
            std::cout << "��������� ������� [" << i << "] = " << array[i];
            if (array[i] > 0) {
                lastPositiveIndex = i;
                std::cout << " - ������ �������������!" << std::endl;
                break;
            }
            std::cout << " - ������������� ��� ����" << std::endl;
        }

        std::cout << "������ ���������� ��������������: " << lastPositiveIndex << std::endl;

        double sum = 0;
        if (lastPositiveIndex != -1) {
            for (int i = 0; i <= lastPositiveIndex; i++) {
                sum += array[i];
                std::cout << "��������� ������� [" << i << "] = " << array[i] << ", ������� �����: " << sum << std::endl;
            }
            std::cout << "����� ��������� �� ���������� ��������������: " << sum << std::endl;
        }
        else {
            std::cout << "� ������� ��� ������������� ���������" << std::endl;
        }

        // ������ �������
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < randomSize; readIndex++) {
            double modulus = std::abs(array[readIndex]);
            if (modulus < a || modulus > b) {
                array[writeIndex] = array[readIndex];
                writeIndex++;
            }
        }

        // ���������� ���������� ��������� ������
        for (int i = writeIndex; i < randomSize; i++) {
            array[i] = 0;
        }

        // ����� ������� �������
        std::cout << "������ ������:" << std::endl;
        for (int i = 0; i < randomSize; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        delete[] array; // ������������ ������
    }

    return 0;
}