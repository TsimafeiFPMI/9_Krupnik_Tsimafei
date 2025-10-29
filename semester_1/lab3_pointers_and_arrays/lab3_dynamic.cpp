#include <iostream>
#include <time.h>

int* fooarr(int size) {
    if (size <= 0 || size > 1000) {
        std::cout << "�������� ������ �������: " << size << std::endl;
        exit(777);
    }
    return new int[size];
}

int main() {
    setlocale(LC_ALL, "RU");
    int x;
    std::cout << "������� �������� x: ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cout << "������� ���������������� �������� x";
        exit(777);
    }
    int chisl;
    std::cout << "��� �� ������ ��������� ������: �������� - ������� ������� 0, ��� ���� ������ ������� ����� - ������� 1" << std::endl;
    std::cin >> chisl;
    if (std::cin.fail() || chisl < 0 || chisl > 1) {
        std::cout << "������� ���������������� �������� chisl";
        exit(777);
    }
    if (chisl == 1) {
        int n;
        std::cout << "������� ������ ������� ";
        std::cin >> n;
        if (std::cin.fail() || n < 1 || n > 1000) {
            std::cout << "������� ���������������� �������� ������� ( �� 1 �� 1000 )";
            exit(777);
        }
        int* arr = fooarr(n);
        int min = 100000;
        std::cout << "������ �������: " << n << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            std::cout << "���� ����� " << i << ": " << arr[i] << std::endl;
            if (arr[i] < min) {
                min = arr[i];
                std::cout << "��� ����������� ������� ������, El: " << i << ": " << min << std::endl;
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
            std::cout << "����� ��������� �� ������� �� ���������� ��������������: " << sum << std::endl;
        }
        else {
            std::cout << "��� ��� �� ������ ������������� �����" << std::endl;
        }
        for (int i = 0; i < n; i++) {
            int modul = abs(arr[i]);
            if (x < modul) {
                std::cout << "��� ������ ������� ��� x, El " << i << ": " << modul << std::endl;
            }
        }
        for (int i = 0; i < n; i++) {
            int modul = abs(arr[i]);
            if (x >= modul) {
                std::cout << "���������� ����� ������ ��� x, El " << i << ": " << modul << std::endl;
            }
        }
        std::cout << "��� ����������� ������� " << min << std::endl;
        delete[] arr;
    }
    else {
        srand(time(NULL));
        int rand_n = 1 + rand() % 100;
        int* arr = fooarr(rand_n);
        int min = 100000;
        std::cout << "��������� ������ �������: " << rand_n << std::endl;
        for (int i = 0; i < rand_n; i++) {
            arr[i] = -100 + rand() % 201;
            std::cout << "���� ����� " << i << ": " << arr[i] << std::endl;
            if (arr[i] < min) {
                min = arr[i];
                std::cout << "��� ����������� ������� ������, El: " << i << ": " << min << std::endl;
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
            std::cout << "����� ��������� �� ������� �� ���������� ��������������: " << sum << std::endl;
        }
        else {
            std::cout << "��� ��� �� ������ ������������� �����" << std::endl;
        }
        for (int i = 0; i < rand_n; i++) {
            int modul = abs(arr[i]);
            if (x < modul) {
                std::cout << "��� ������ ������� ��� x, El " << i << ": " << modul << std::endl;
            }
        }
        for (int i = 0; i < rand_n; i++) {
            int modul = abs(arr[i]);
            if (x >= modul) {
                std::cout << "���������� ����� ������ ��� x, El " << i << ": " << modul << std::endl;
            }
        }
        delete[] arr;
        std::cout << "��� ����������� ������� " << min << std::endl;
    }
    return 0;
}