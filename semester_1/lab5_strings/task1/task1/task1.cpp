#include <iostream>
#include <string>
#include <vector>
bool is_letter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}
bool is_alnum(char ch) {
    return is_letter(ch) || is_digit(ch);
}
char to_upper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}
char to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}
std::string reverse_str(const std::string& s) {
    std::string rev;
    int len = s.length();
    for (int i = len - 1; i >= 0; --i) {
        rev += s[i];
    }
    return rev;
}
std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    for (std::string::size_type i = 0; i < text.length(); ++i) {
        char ch = text[i];
        if (is_alnum(ch)) {
            word += ch;
        }
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}
std::string process_word(const std::string& word) {
    std::string::size_type len = word.length();
    if (len == 0) return word;
    bool only_digits = true;
    for (std::string::size_type i = 0; i < len; ++i) {
        if (!is_digit(word[i])) {
            only_digits = false;
            break;
        }
    }
    if (only_digits && len < 7) {
        return reverse_str(word);
    }
    bool has_letter = false, has_digit = false;
    for (std::string::size_type i = 0; i < len; ++i) {
        char c = word[i];
        if (is_letter(c)) has_letter = true;
        if (is_digit(c)) has_digit = true;
    }
    if (has_letter && has_digit) {
        std::string result = word;
        for (std::string::size_type i = 0; i < len; ++i) {
            result[i] = to_upper(result[i]);
        }
        return result;
    }
    std::string result = word;
    for (std::string::size_type i = 0; i < len; ++i) {
        result[i] = to_lower(result[i]);
    }
    return result;
}
std::string join_words(const std::vector<std::string>& words) {
    if (words.empty()) return "";
    std::string result = words[0];
    for (std::vector<std::string>::size_type i = 1; i < words.size(); ++i) {
        result += " ";
        result += words[i];
    }
    return result;
}
int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> words = split_words(input);
    std::vector<std::string> processed_words;
    for (std::vector<std::string>::size_type i = 0; i < words.size(); ++i) {
        std::string processed = process_word(words[i]);
        processed_words.push_back(processed);
    }
    std::string output = join_words(processed_words);
    std::cout << output << std::endl;
    return 0;
}