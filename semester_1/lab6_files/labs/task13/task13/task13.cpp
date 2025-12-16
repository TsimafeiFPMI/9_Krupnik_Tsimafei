#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> searchwords(const std::string& line) {
    std::vector<std::string> words;
    std::string currentWord;
    for (char c : line) {
        if (c == ' ' || c == ',' || c == '.' || c == '\t' || c == '\n' || c == '!' || c == '?') {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else {
            currentWord += c;
        }
    }
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }
    return words;
}

bool containsWord(const std::string& line, const std::string& word) {
    std::vector<std::string> words = searchwords(line);
    for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
        if (*it == word) {
            return true;
        }
    }
    return false;
}

void createFile() {
    std::fstream file("input.txt", std::ios::out);
    if (file.is_open()) {
        file << "Hello world\n";
        file << "my,sad,\n";
        file << "world.my,sad,world\n";
        file << "Hello,my,sad\n";
        file.close();
        std::cout << "File was created!\n";
    }
    else {
        std::cout << "File was not created\n";
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    std::ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        std::cout << "Файл не найден. Создаём тестовый...\n";
        createFile();
        inFile.open("input.txt");
        if (!inFile.is_open()) {
            std::cout << "Error: не удалось открыть файл\n";
            return 1;
        }
    }

    std::vector<std::string> allLines;
    std::string line;
    while (std::getline(inFile, line)) {
        allLines.push_back(line);
    }
    inFile.close();

    if (allLines.empty()) {
        std::cout << "Файл пустой\n";
        return 0;
    }

    std::vector<std::string> target = searchwords(allLines[0]);
    if (target.size() < 2) {
        std::cout << "В первой строке меньше двух слов!\n";
        return 0;
    }

    std::string word1 = target[0];
    std::string word2 = target[1];

    std::cout << "Первое слово: " << word1 << "\n";
    std::cout << "Второе слово: " << word2 << "\n";

    std::vector<std::string> textLines;
    for (size_t i = 1; i < allLines.size(); ++i) {
        textLines.push_back(allLines[i]);
    }

    int idx1 = -1;
    int idx2 = -1;
    for (size_t i = 0; i < textLines.size(); ++i) {
        if (idx1 == -1 && containsWord(textLines[i], word1)) {
            idx1 = static_cast<int>(i);
        }
        if (idx2 == -1 && containsWord(textLines[i], word2)) {
            idx2 = static_cast<int>(i);
        }
        if (idx1 != -1 && idx2 != -1) break;
    }

    std::cout << "\nИсходный текст:\n";
    for (size_t i = 0; i < allLines.size(); ++i) {
        std::cout << allLines[i] << "\n";
    }

    if (idx1 == -1) {
        std::cout << "\nСлово '" << word1 << "' не найдено в тексте\n";
    }
    else if (idx2 == -1) {
        std::cout << "\nСлово '" << word2 << "' не найдено в тексте\n";
    }
    else if (idx1 == idx2) {
        std::cout << "\nОба слова в одной строке - ничего не меняем\n";
    }
    else {
        std::swap(textLines[idx1], textLines[idx2]);
        std::cout << "\nСтроки поменяны местами!\n";
        std::cout << "\nИзменённый текст:\n";
        std::cout << allLines[0] << "\n";
        for (size_t i = 0; i < textLines.size(); ++i) {
            std::cout << textLines[i] << "\n";
        }
    }

    return 0;
}