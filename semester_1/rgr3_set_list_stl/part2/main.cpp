#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

struct Author {
    std::string surname;
    std::string name;
    std::string patronymic;

    bool operator<(const Author& other) const {
        return surname < other.surname; // сортировка по фамилии
    }
};

struct Book {
    int udc;
    std::set<Author> authors;      // авторы упорядочены по фамилии
    std::string title;
    int year;

    bool operator<(const Book& other) const {
        return title < other.title; // книги упорядочены по названию
    }
};


// Разделение строки по символу
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ss(s);
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Удаление начальных/конечных пробелов
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// Парсинг автора из строки "Фамилия Имя Отчество"
Author parse_author(const std::string& full_name) {
    std::string name_str = trim(full_name);
    auto parts = split(name_str, ' ');
    if (parts.size() < 2) {
        throw std::runtime_error("Неверный формат автора: " + full_name);
    }
    Author a;
    a.surname = trim(parts[0]);
    a.name = trim(parts[1]);
    a.patronymic = (parts.size() >= 3) ? trim(parts[2]) : "";
    return a;
}

// Загрузка библиотеки из файла
std::set<Book> load_library(const std::string& filename) {
    std::set<Book> library;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Предупреждение: файл " << filename << " не найден. Будет создан пустой список.\n";
        return library;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        auto parts = split(line, '|');
        if (parts.size() < 4) continue;

        try {
            Book b;
            b.udc = std::stoi(trim(parts[0]));
            b.title = trim(parts[1]);
            b.year = std::stoi(trim(parts[2]));

            auto author_list = split(parts[3], ',');
            for (auto& auth_str : author_list) {
                std::string auth_clean = trim(auth_str);
                if (!auth_clean.empty()) {
                    b.authors.insert(parse_author(auth_clean));
                }
            }
            library.insert(b);
        }
        catch (const std::exception& e) {
            std::cerr << "Пропущена некорректная строка: " << line << "\n";
        }
    }
    file.close();
    return library;
}

// Сохранение библиотеки в файл (опционально, но полезно)
void save_library(const std::set<Book>& library, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось сохранить файл " << filename << "\n";
        return;
    }
    for (const auto& book : library) {
        file << book.udc << "|"
            << book.title << "|"
            << book.year << "|";
        bool first = true;
        for (const auto& a : book.authors) {
            if (!first) file << ", ";
            file << a.surname << " " << a.name << " " << a.patronymic;
            first = false;
        }
        file << "\n";
    }
    file.close();
}

// Печать библиотеки
void print_library(const std::set<Book>& library) {
    if (library.empty()) {
        std::cout << "Библиотека пуста.\n";
        return;
    }
    std::cout << "\n--- Библиотека (упорядочена по названию) ---\n";
    for (const auto& book : library) {
        std::cout << "\nНазвание: " << book.title << "\n"
            << "УДК: " << book.udc << "\n"
            << "Год: " << book.year << "\n"
            << "Авторы:\n";
        for (const auto& a : book.authors) {
            std::cout << "  " << a.surname << " " << a.name << " " << a.patronymic << "\n";
        }
    }
    std::cout << "\n";
}

// Добавление книги
void add_book(std::set<Book>& library) {
    Book b;
    std::cout << "Введите УДК (целое число): ";
    std::cin >> b.udc;
    std::cin.ignore();

    std::cout << "Введите название книги: ";
    std::getline(std::cin, b.title);

    std::cout << "Введите год издания: ";
    std::cin >> b.year;
    std::cin.ignore();

    std::cout << "Введите авторов (через запятую, ФИО, например: Иванов Иван Иванович, Петров Петр):\n";
    std::string author_line;
    std::getline(std::cin, author_line);

    auto authors = split(author_line, ',');
    for (auto& auth : authors) {
        std::string clean = trim(auth);
        if (!clean.empty()) {
            b.authors.insert(parse_author(clean));
        }
    }

    library.insert(b);
    std::cout << "Книга добавлена.\n";
}

// Удаление книги по названию
void remove_book(std::set<Book>& library) {
    std::cout << "Введите название книги для удаления: ";
    std::string title;
    std::getline(std::cin, title);

    Book dummy{ 0, {}, title, 0 };
    auto it = library.find(dummy);
    if (it != library.end()) {
        library.erase(it);
        std::cout << "Книга удалена.\n";
    }
    else {
        std::cout << "Книга с таким названием не найдена.\n";
    }
}

// Поиск по названию
void find_by_title(const std::set<Book>& library) {
    std::cout << "Введите название книги: ";
    std::string title;
    std::getline(std::cin, title);

    Book dummy{ 0, {}, title, 0 };
    auto it = library.find(dummy);
    if (it != library.end()) {
        std::cout << "\n--- Найдена книга ---\n"
            << "Название: " << it->title << "\n"
            << "УДК: " << it->udc << "\n"
            << "Год: " << it->year << "\n"
            << "Авторы:\n";
        for (const auto& a : it->authors) {
            std::cout << "  " << a.surname << " " << a.name << " " << a.patronymic << "\n";
        }
    }
    else {
        std::cout << "Книга не найдена.\n";
    }
}

// Поиск по автору
void find_by_author(const std::set<Book>& library) {
    std::cout << "Введите ФИО автора (например: Иванов Иван Иванович): ";
    std::string full_name;
    std::getline(std::cin, full_name);

    Author target = parse_author(full_name);
    std::cout << "\n--- Книги автора " << target.surname << " " << target.name << " ---\n";

    bool found = false;
    for (const auto& book : library) {
        if (book.authors.find(target) != book.authors.end()) {
            std::cout << "- " << book.title << " (" << book.year << ")\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Книг этого автора не найдено.\n";
    }
}

// Добавить автора к книге
void add_author_to_book(std::set<Book>& library) {
    std::cout << "Введите название книги: ";
    std::string title;
    std::getline(std::cin, title);

    Book dummy{ 0, {}, title, 0 };
    auto it = library.find(dummy);
    if (it == library.end()) {
        std::cout << "Книга не найдена.\n";
        return;
    }

    // Так как set не позволяет изменять элементы, делаем копию
    Book updated = *it;
    library.erase(it);

    std::cout << "Введите ФИО автора для добавления: ";
    std::string full_name;
    std::getline(std::cin, full_name);
    updated.authors.insert(parse_author(full_name));

    library.insert(updated);
    std::cout << "Автор добавлен.\n";
}

// Удалить автора из книги
void remove_author_from_book(std::set<Book>& library) {
    std::cout << "Введите название книги: ";
    std::string title;
    std::getline(std::cin, title);

    Book dummy{ 0, {}, title, 0 };
    auto it = library.find(dummy);
    if (it == library.end()) {
        std::cout << "Книга не найдена.\n";
        return;
    }

    Book updated = *it;
    library.erase(it);

    std::cout << "Введите ФИО автора для удаления: ";
    std::string full_name;
    std::getline(std::cin, full_name);
    Author to_remove = parse_author(full_name);

    if (updated.authors.erase(to_remove)) {
        std::cout << "Автор удалён.\n";
    }
    else {
        std::cout << "Такой автор в книге не указан.\n";
    }

    library.insert(updated);
}

int main() {
    setlocale(LC_ALL, "ru");
    std::set<Book> library = load_library("library.txt");

    char choice;
    do {
        std::cout << "\n=== Управление библиотекой ===\n";
        std::cout << "1. Показать все книги\n";
        std::cout << "2. Добавить книгу\n";
        std::cout << "3. Удалить книгу\n";
        std::cout << "4. Найти книгу по названию\n";
        std::cout << "5. Найти книги по автору\n";
        std::cout << "6. Добавить автора к книге\n";
        std::cout << "7. Удалить автора из книги\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        std::cin >> choice;
        std::cin.ignore(); // игнорируем символ новой строки

        switch (choice) {
        case '1': print_library(library); break;
        case '2': add_book(library); break;
        case '3': remove_book(library); break;
        case '4': find_by_title(library); break;
        case '5': find_by_author(library); break;
        case '6': add_author_to_book(library); break;
        case '7': remove_author_from_book(library); break;
        case '0':
            save_library(library, "library.txt");
            std::cout << "Данные сохранены. До свидания!\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != '0');

    return 0;
}