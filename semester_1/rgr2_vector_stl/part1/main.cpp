#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <set>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> vec;
    int num;

    // Ввод чисел с клавиатуры до конца ввода (Ctrl+D в Linux/macOS, Ctrl+Z в Windows)
    std::cout << "Введите целые числа (для завершения ввода нажмите Ctrl+D или Ctrl+Z):\n";
    while (std::cin >> num) {
        vec.push_back(num);
    }

    // Если вектор пуст
    if (vec.empty()) {
        std::cout << "Вектор пуст.\n";
        return 0;
    }

    // 1. Сумма чисел
    long long sum = std::accumulate(vec.begin(), vec.end(), 0LL);
    std::cout << "Сумма всех чисел: " << sum << "\n";

    // 2. Общее количество чисел
    size_t total_count = vec.size();
    std::cout << "Общее количество чисел: " << total_count << "\n";

    // 3. Количество чисел, равных заданному
    int target;
    std::cout << "Введите число, количество вхождений которого нужно найти: ";
    std::cin.clear(); // Очистка состояния потока после предыдущего использования
    std::cin >> target;
    int count_target = std::count(vec.begin(), vec.end(), target);
    std::cout << "Количество чисел, равных " << target << ": " << count_target << "\n";

    // 4. Количество чисел, больше чем n
    int n;
    std::cout << "Введите число n для подсчёта элементов, больших n: ";
    std::cin >> n;
    int count_greater = std::count_if(vec.begin(), vec.end(),
                                      [n](int x) { return x > n; });
    std::cout << "Количество чисел, больших " << n << ": " << count_greater << "\n";

    // 5. Заменить все нули на целую часть среднего арифметического
    if (sum != 0 || total_count > 0) {
        int average = static_cast<int>(sum / static_cast<long long>(total_count));
        std::replace(vec.begin(), vec.end(), 0, average);
        std::cout << "Все нули заменены на целую часть среднего арифметического (" << average << ").\n";
    }

    // Вывод вектора после замены нулей (для наглядности)
    std::cout << "Вектор после замены нулей: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";

    // 6. Добавить к каждому элементу сумму всех чисел из заданного интервала этого же вектора
    size_t start_idx, end_idx;
    std::cout << "Введите начальный и конечный индексы интервала (включительно, от 0 до " 
              << total_count - 1 << "): ";
    std::cin >> start_idx >> end_idx;

    // Проверка корректности индексов
    if (start_idx >= total_count || end_idx >= total_count || start_idx > end_idx) {
        std::cout << "Некорректный интервал. Пропускаем шаг 6.\n";
    } else {
        long long interval_sum = std::accumulate(vec.begin() + start_idx, vec.begin() + end_idx + 1, 0LL);
        std::transform(vec.begin(), vec.end(), vec.begin(),
                       [interval_sum](int x) { return x + static_cast<int>(interval_sum); });
        std::cout << "К каждому элементу добавлена сумма элементов с индексами [" 
                  << start_idx << ", " << end_idx << "] = " << interval_sum << "\n";
    }

    // Вывод после шага 6
    std::cout << "Вектор после добавления суммы интервала: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";

    // 7. Заменить все числа, модуль которых — чётное число, на разность максимума и минимума
    auto [min_it, max_it] = std::minmax_element(vec.begin(), vec.end());
    int min_val = *min_it;
    int max_val = *max_it;
    int diff = max_val - min_val;

    std::transform(vec.begin(), vec.end(), vec.begin(),
        [diff](int x) {
            return (std::abs(x) % 2 == 0) ? diff : x;
        });
    std::cout << "Числа с чётным модулем заменены на разность максимума и минимума (" 
              << diff << ").\n";

    // Вывод после шага 7
    std::cout << "Вектор после замены по чётному модулю: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";

    // 8. Удалить из последовательности все равные по модулю числа, кроме первого
    std::vector<int> result;
    std::set<int> seen_abs;

    for (int x : vec) {
        int abs_x = std::abs(x);
        if (seen_abs.find(abs_x) == seen_abs.end()) {
            result.push_back(x);
            seen_abs.insert(abs_x);
        }
    }

    vec = std::move(result);
    std::cout << "После удаления дубликатов по модулю (оставлены первые): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}