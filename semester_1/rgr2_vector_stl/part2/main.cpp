#include "time_utility.h"
#include "train.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <cstdlib>


int main() {
    setlocale(LC_ALL, "RU");
    using namespace time_utility;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::time_t t1 = SetTime(12, 23);
    try {
        t1 = SetTime(12, 60);
    } catch (const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }

    std::time_t t2 = GenerateRandomTime(generator);

    std::cout << "t1: ";
    PrintTime(t1);

    std::cout << "t2: ";
    PrintTime(t2);

    std::cout << "t1 < t2: " << std::boolalpha << (t1 < t2) << '\n';
    std::cout << "t2 < t1: " << std::boolalpha << (t2 < t1) << '\n';

    auto ParseHHMM = [](const std::string& s) -> std::pair<size_t, size_t> {
        if (s.size() != 5 || s[2] != ':')
            throw std::invalid_argument("Invalid time format: expected HH:MM");
        size_t h = std::stoi(s.substr(0, 2));
        size_t m = std::stoi(s.substr(3, 2));
        if (h > 23 || m > 59)
            throw std::out_of_range("Hours must be 0-23, minutes 0-59");
        return {h, m};
    };

    std::vector<Train> trains;
    std::ifstream in("trains.txt");
    if (!in) {
        std::cerr << "Файл trains.txt не найден.\n";
        return EXIT_FAILURE;
    }

    TrainId id;
    std::string type_str, dest, disp, trav;
    while (in >> id >> type_str >> dest >> disp >> trav) {
        TrainType type;
        if (type_str == "Passenger")
            type = TrainType::Passenger;
        else if (type_str == "Express")
            type = TrainType::Express;
        else if (type_str == "Freight")
            type = TrainType::Freight;
        else if (type_str == "HighSpeed")
            type = TrainType::HighSpeed;
        else
            continue;

        try {
            trains.emplace_back(id, type, dest, disp, trav);
        } catch (const std::exception& e) {
            std::cerr << "Ошибка при создании поезда " << id << ": " << e.what() << "\n";
        }
    }
    in.close();

    if (trains.empty()) {
        std::cout << "Нет корректных данных о поездах.\n";
        return EXIT_SUCCESS;
    }

    // 1. Вывод всех поездов
    std::cout << "\n=== Все поезда ===\n";
    for (const auto& t : trains)
        t.print();

    // 2. Сортировка по времени отправления
    std::sort(trains.begin(), trains.end());
    std::cout << "=== Поезда, отсортированные по времени отправления ===\n";
    for (const auto& t : trains)
        t.print();

    // 3. Диапазон времени
    std::string start_str, end_str;
    std::cout << "Введите начальное и конечное время (HH:MM HH:MM): ";
    std::cin >> start_str >> end_str;

    auto [h1, m1] = ParseHHMM(start_str);
    auto [h2, m2] = ParseHHMM(end_str);
    std::time_t t_start = SetTime(h1, m1);
    std::time_t t_end = SetTime(h2, m2);

    std::cout << "\n=== Поезда, отправляющиеся с " << start_str << " по " << end_str << " ===\n";
    bool found = false;
    for (const auto& t : trains) {
        if (t.dispatch_time() >= t_start && t.dispatch_time() <= t_end) {
            t.print();
            found = true;
        }
    }
    if (!found)
        std::cout << "Нет поездов в этом диапазоне.\n";

    // 4. Пункт назначения
    std::string target_dest;
    std::cout << "\nВведите пункт назначения: ";
    std::cin >> target_dest;

    std::cout << "\n=== Все поезда в " << target_dest << " ===\n";
    found = false;
    for (const auto& t : trains) {
        if (t.destination() == target_dest) {
            t.print();
            found = true;
        }
    }
    if (!found)
        std::cout << "Нет поездов в " << target_dest << ".\n";

    // 5. Тип + пункт
    std::string type_target;
    std::cout << "Введите тип поезда (Passenger/Express/Freight/HighSpeed): ";
    std::cin >> type_target;

    TrainType tgt_type;
    if (type_target == "Passenger")
        tgt_type = TrainType::Passenger;
    else if (type_target == "Express")
        tgt_type = TrainType::Express;
    else if (type_target == "Freight")
        tgt_type = TrainType::Freight;
    else if (type_target == "HighSpeed")
        tgt_type = TrainType::HighSpeed;
    else {
        std::cout << "Неизвестный тип. Пропускаем шаг.\n";
        tgt_type = static_cast<TrainType>(-1);
    }

    if (tgt_type != static_cast<TrainType>(-1)) {
        std::cout << "\n=== Поезда типа " << type_target << " в " << target_dest << " ===\n";
        found = false;
        for (const auto& t : trains) {
            if (t.destination() == target_dest && t.type() == tgt_type) {
                t.print();
                found = true;
            }
        }
        if (!found)
            std::cout << "Нет таких поездов.\n";
    }

    // 6. Самый быстрый в target_dest
    std::cout << "\n=== Самый быстрый поезд в " << target_dest << " ===\n";
    const Train* fastest = nullptr;
    for (const auto& t : trains) {
        if (t.destination() == target_dest) {
            if (!fastest || t.travelling_time() < fastest->travelling_time()) {
                fastest = &t;
            }
        }
    }
    if (fastest) {
        fastest->print();
    } else {
        std::cout << "Нет поездов в " << target_dest << ".\n";
    }

    return EXIT_SUCCESS;
}