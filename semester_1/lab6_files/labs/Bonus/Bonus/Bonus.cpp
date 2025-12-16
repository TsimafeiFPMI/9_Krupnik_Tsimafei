#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

// Подключаем Google Test (установишь через NuGet за 10 секунд)
#include <gtest/gtest.h>

// ===================================================================
// ТВОЯ ОРИГИНАЛЬНАЯ ЛОГИКА — вынесена в функцию, чтобы тестировать
// ===================================================================
std::vector<int> getNumbersWithUniqueDigits(int a, int b) {
    // Если a > b — меняем местами (твой код падал, если a > b)
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    std::vector<int> result;

    for (int i = a; i <= b; ++i) {
        int n = abs(i);
        bool hasRepeat = false;

        // Точная копия твоего алгоритма
        while (n > 0 && !hasRepeat) {
            int lastDigit = n % 10;
            int remaining = n / 10;

            while (remaining > 0) {
                if (remaining % 10 == lastDigit) {
                    hasRepeat = true;
                    break;
                }
                remaining /= 10;
            }
            n /= 10;
        }

        if (!hasRepeat) {
            result.push_back(i);
        }
    }
    return result;
}

// ===================================================================
// Оригинальная программа (с cin/cout) — теперь запускается отдельно
// ===================================================================
int original_main() {
    setlocale(LC_ALL, "RU");

    int a, b;
    std::cout << "Введите значение a: ";
    if (!(std::cin >> a)) {
        std::cout << "Введено неправильное значение a\n";
        return 1;
    }

    std::cout << "Введите значение b: ";
    if (!(std::cin >> b)) {
        std::cout << "Введено неправильное значение b\n";
        return 1;
    }

    // Используем ту же функцию — гарантируем одинаковый результат
    auto numbers = getNumbersWithUniqueDigits(a, b);

    for (int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}

// ===================================================================
// GOOGLE TEST — те самые unit-тесты
// ===================================================================
TEST(UniqueDigitsTest, PositiveRange_1_to_30) {
    auto res = getNumbersWithUniqueDigits(1, 30);
    std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,23,24,25,26,27,28,29,30 };
    EXPECT_EQ(res, expected);
}

TEST(UniqueDigitsTest, NegativeNumbers) {
    auto res = getNumbersWithUniqueDigits(-15, -10);
    std::vector<int> expected = { -15,-14,-13,-12,-10 };
    EXPECT_EQ(res, expected);
}

TEST(UniqueDigitsTest, WithZero) {
    auto res = getNumbersWithUniqueDigits(-5, 5);
    std::vector<int> expected = { -5,-4,-3,-2,-1,0,1,2,3,4,5 };
    EXPECT_EQ(res, expected);
}

TEST(UniqueDigitsTest, RepeatsExcluded) {
    EXPECT_FALSE(getNumbersWithUniqueDigits(11, 11).empty() == false); // 11 — повтор
    EXPECT_TRUE(std::find(getNumbersWithUniqueDigits(1, 100).begin(),
        getNumbersWithUniqueDigits(1, 100).end(), 98) !=
        getNumbersWithUniqueDigits(1, 100).end()); // 98 — ок
}

TEST(UniqueDigitsTest, BigNumberWithAllUnique) {
    EXPECT_TRUE(getNumbersWithUniqueDigits(1023456789, 1023456789)[0] == 1023456789);
}

TEST(UniqueDigitsTest, SwapWhenA_Greater_B) {
    EXPECT_EQ(getNumbersWithUniqueDigits(10, 1), getNumbersWithUniqueDigits(1, 10));
}

// ===================================================================
// Запуск: сначала тесты, потом твоя программа
// ===================================================================
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    int testResult = RUN_ALL_TESTS();

    std::cout << "\n\nТесты завершены. Запускаем твою программу:\n\n";
    original_main();

    system("pause");
    return testResult;
}