#include <iostream>
#include <string>

size_t CountWords(const std::string& text) {
    size_t words_amount = 0;
    size_t pos = 0;
    while (pos < text.length()) {
        // 1. Пропускаем все пробельные символы
        pos = text.find_first_not_of(" \t\n\r\f\v", pos);
        if (pos == std::string::npos) break;  // больше нет слов
        // 2. Ищем конец слова
        size_t end = text.find_first_of(" \t\n\r\f\v", pos);
        if (end == std::string::npos) {
            end = text.length();  // до конца строки
        }
        // 3. Проверяем длину слова
        if (end > pos) {
            ++words_amount;
        }
        pos = end;
    }

    return words_amount;
}

int main() {
    std::string text;
    std::getline(std::cin, text);

    size_t words_amount = CountWords(text);
    std::cout << words_amount << std::endl;

    return 0;
}