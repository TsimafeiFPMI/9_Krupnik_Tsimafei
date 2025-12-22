#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;


enum class TrainType { 
    Passenger, Express, Freight, HighSpeed };

// Вспомогательная функция: преобразует строку "HH:MM" в пару (часы, минуты)
inline std::pair<size_t, size_t> ParseTimeStr(const std::string& s) {
    if (s.length() != 5 || s[2] != ':') {
        throw std::invalid_argument("Неверный формат времени: ожидается HH:MM");
    }
    size_t h = std::stoul(s.substr(0, 2));
    size_t m = std::stoul(s.substr(3, 2));
    if (h > 23 || m > 59) {
        throw std::out_of_range("Часы должны быть 0–23, минуты — 0–59");
    }
    return {h, m};
}

// Преобразует количество секунд в строку "HH:MM" (для времени в пути)
inline std::string FormatDuration(std::time_t seconds) {
    size_t total = static_cast<size_t>(seconds);
    size_t h = total / 3600;
    size_t m = (total % 3600) / 60;
    std::ostringstream oss;
    oss.fill('0');
    oss.width(2);
    oss << h;
    oss << ':';
    oss.width(2);
    oss << m;
    return oss.str();
}

class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    // Конструктор из данных (включая строки времени "HH:MM")
    Train(TrainId id, TrainType type, const std::string& destination,
          const std::string& dispatch_str, const std::string& travel_str)
        : id_(id), type_(type), destination_(destination) {
        auto [h1, m1] = ParseTimeStr(dispatch_str);
        dispatch_time_ = time_utility::SetTime(h1, m1);

        auto [h2, m2] = ParseTimeStr(travel_str);
        travelling_time_ = static_cast<std::time_t>(h2 * 3600 + m2 * 60);
    }

    // Геттеры
    TrainId id() const {
        return id_;
    }
    TrainType type() const {
        return type_;
    }
    const std::string& destination() const {
        return destination_;
    }
    std::time_t dispatch_time() const {
        return dispatch_time_;
    }
    std::time_t travelling_time() const {
        return travelling_time_;
    }  // в секундах

    // Для сортировки по времени отправления
    bool operator<(const Train& other) const {
        return dispatch_time_ < other.dispatch_time_;
    }

    // Вывод информации о поезде
    void print() const {
        std::cout << "Поезд #" << id_ << " ";
        switch (type_) {
            case TrainType::Passenger:
                std::cout << "(Passenger)";
                break;
            case TrainType::Express:
                std::cout << "(Express)";
                break;
            case TrainType::Freight:
                std::cout << "(Freight)";
                break;
            case TrainType::HighSpeed:
                std::cout << "(HighSpeed)";
                break;
        }
        std::cout << " в " << destination_ << "\n  Отправление: ";
        time_utility::PrintTime(dispatch_time_);  // выводит в формате asctime
        std::cout << "  Время в пути: " << FormatDuration(travelling_time_) << "\n\n";
    }
};
