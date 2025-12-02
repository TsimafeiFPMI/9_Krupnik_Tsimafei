#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool containsWord(const string& line, const string& word) {
	stringstream ss(line);
	string token;
	while (ss >> token) {
		while (!token.empty() && !isalnum(token.back())) token.pop_back();
		while (!token.empty() && !isalnum(token.front())) token.erase(0, 1);
		if (token == word) return true;
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "RU");
	// Если файла нет — создаём тестовый
	ifstream test("input.txt");
	if (!test.good()) {
		cout << "input.txt не найден — создаю тестовый файл...\n";
		ofstream create("input.txt");
		create << "cat dog\n"
			<< "У меня есть cat, он серый.\n"
			<< "А ещё я видел dog на улице!\n"
			<< "Кошки и собаки — друзья.\n";
		create.close();
		cout << "Тестовый файл создан.\n\n";
	}
	test.close();

	ifstream fin("input.txt");
	if (!fin.is_open()) {
		cerr << "Всё равно не удалось открыть input.txt\n";
		return 1;
	}

	vector<string> lines;
	string line;
	while (getline(fin, line)) lines.push_back(line);
	fin.close();

	stringstream first(lines[0]);
	string w1, w2;
	first >> w1 >> w2;

	int i1 = -1, i2 = -1;
	for (int i = 1; i < lines.size(); ++i) {
		if (i1 == -1 && containsWord(lines[i], w1)) i1 = i;
		if (i2 == -1 && containsWord(lines[i], w2)) i2 = i;
		if (i1 != -1 && i2 != -1) break;
	}

	if (i1 != -1 && i2 != -1 && i1 != i2) {
		swap(lines[i1], lines[i2]);
		cout << "Поменял строки " << i1 + 1 << " и " << i2 + 1 << endl;
	}
	else {
		cout << "Не нашёл одно или оба слова\n";
	}

	ofstream fout("output.txt");
	for (const auto& l : lines) fout << l << '\n';

	cout << "Готово → output.txt\n";
	return 0;
}
