#include <iostream>
#include <vector>
#include <set>

int main() {
    setlocale(LC_ALL, "RU");
    int N;
    std::cout << "Введите N: ";
    std::cin >> N;

    if (N < 2) {
        std::cout << "Нет простых чисел, не превосходящих " << N << ".\n";
        return 0;
    }

    // Шаг 1: Создаём вектор-решето
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    // Шаг 2: Решето Эратосфена
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Шаг 3: Собираем простые числа в std::set
    std::set<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.insert(i);
        }
    }

    // Шаг 4: Вывод
    std::cout << "Простые числа, не превосходящие " << N << ":\n";
    for (int p : primes) {
        std::cout << p << " ";
    }
    std::cout << "\n";

    return 0;
}