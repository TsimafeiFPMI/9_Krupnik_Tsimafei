#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <set>
#include <windows.h>

using namespace std;

struct Mark {
    string subject;
    int mark;
};
struct Student {
    string name;
    int number;
    vector<Mark> marks;
    double avg() const {
        if (marks.empty()) return 0.0;
        double sum = 0;
        for (const auto& m : marks) sum += m.mark;
        return sum / marks.size();
    }
    int total() const {
        int sum = 0;
        for (const auto& m : marks) sum += m.mark;
        return sum;
    }
    bool has_bad() const {
        for (const auto& m : marks)
            if (m.mark <= 3) return true;
        return false;
    }
    bool has_subject(const string& subj) const {
        for (const auto& m : marks)
            if (m.subject == subj) return true;
        return false;
    }
};
map<int, Student> read_students(const string& filename) {
    map<int, Student> students;
    ifstream f(filename);
    if (!f.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return students;
    }
    string line;
    while (getline(f, line)) {
        if (line.empty() || line.find_first_not_of(" \t") == string::npos)
            continue;
        stringstream ss(line);
        Student st;
        string token;
        // читаем ФИО до первого числа
        st.name = "";
        while (ss >> token) {
            if (!token.empty() && isdigit(static_cast<unsigned char>(token[0]))) {
                st.number = stoi(token);
                break;
            }
            if (!st.name.empty()) st.name += " ";
            st.name += token;
        }
        // оценки
        string subj;
        int mark_val;
        while (ss >> subj >> mark_val) {
            st.marks.push_back({ subj, mark_val });
        }
        if (st.number != 0) {
            students[st.number] = move(st);
        }
    }
    return students;
}

void print_list(const vector<pair<int, Student>>& vec, bool with_avg = false) {
    if (vec.empty()) {
        cout << "  (нет данных)\n";
        return;
    }

    int idx = 1;
    cout << left;
    for (const auto& p : vec) {
        const auto& st = p.second;
        cout << setw(3) << (idx++) << ")  "
            << setw(26) << st.name
            << setw(10) << st.number;
        if (with_avg) {
            cout << fixed << setprecision(2) << st.avg();
        }
        cout << '\n';
    }
}

int main() {
    // Для вывода русских букв в консоли Windows
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    auto students = read_students("students.txt");
    if (students.empty()) {
        cout << "База студентов пуста или файл не прочитан\n";
        return 1;
    }
    vector<pair<int, Student>> vec(students.begin(), students.end());
    cout << "\n=== 1–2. Студенты по номеру зачётки ===\n";
    cout << string(70, '-') << '\n';
    print_list(vec, true);

    // 4. Алфавитный + по убыванию среднего при одинаковых ФИО
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.second.name != b.second.name)
            return a.second.name < b.second.name;
        return a.second.avg() > b.second.avg();
        });

    cout << "\n=== 4. Алфавитный порядок ===\n";
    cout << string(70, '-') << '\n';
    print_list(vec, true);

    // 5. Диапазон 4.0–5.0 (можно поменять значения)
    cout << "\n=== 5. Средний балл 4.0 ... 5.0 ===\n";
    cout << string(70, '-') << '\n';
    vector<pair<int, Student>> range_list;
    for (const auto& p : students) {
        double a = p.second.avg();
        if (a >= 4.0 && a <= 5.0) range_list.push_back(p);
    }
    sort(range_list.begin(), range_list.end(),
        [](const auto& a, const auto& b) { return a.second.avg() > b.second.avg(); });
    print_list(range_list, true);

    // 6. Пример — сдавали "Математика"
    string wanted_subject = "Математика";
    cout << "\n=== 6. Сдавали \"" << wanted_subject << "\" ===\n";
    cout << string(70, '-') << '\n';
    vector<pair<int, Student>> by_subj;
    for (const auto& p : students)
        if (p.second.has_subject(wanted_subject))
            by_subj.push_back(p);
    print_list(by_subj);

    // 7. Сколько студентов по каждому предмету
    cout << "\n=== 7. Сколько студентов сдавало предмет ===\n";
    cout << string(70, '-') << '\n';
    map<string, int> subj_count;
    for (const auto& p : students) {
        set<string> uniq;
        for (const auto& m : p.second.marks) uniq.insert(m.subject);
        for (const string& s : uniq) subj_count[s]++;
    }
    for (const auto& [s, cnt] : subj_count) {
        cout << left << setw(28) << s << cnt << '\n';
    }

    // 8. Средний балл по предметам (по убыванию)
    cout << "\n=== 8. Средний балл по предметам (убывание) ===\n";
    cout << string(70, '-') << '\n';
    map<string, pair<double, int>> subj_stats;
    for (const auto& p : students) {
        for (const auto& m : p.second.marks) {
            subj_stats[m.subject].first += m.mark;
            subj_stats[m.subject].second += 1;
        }
    }
    vector<pair<string, double>> subj_avgs;
    for (const auto& [s, data] : subj_stats) {
        subj_avgs.emplace_back(s, data.first / data.second);
    }
    sort(subj_avgs.rbegin(), subj_avgs.rend(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
    for (const auto& [s, avg] : subj_avgs) {
        cout << left << setw(28) << s << fixed << setprecision(2) << avg << '\n';
    }

    // 9. Максимальная сумма баллов
    int max_sum = 0;
    for (const auto& p : students) max_sum = max(max_sum, p.second.total());

    cout << "\n=== 9. Максимальная сумма баллов = " << max_sum << " ===\n";
    cout << string(70, '-') << '\n';
    vector<pair<int, Student>> tops;
    for (const auto& p : students)
        if (p.second.total() == max_sum)
            tops.push_back(p);
    print_list(tops);

    // 10. Есть хотя бы одна оценка ≤ 3
    cout << "\n=== 10. Есть неуд. оценки (≤3) ===\n";
    cout << string(70, '-') << '\n';
    vector<pair<int, Student>> with_bad;
    for (const auto& p : students)
        if (p.second.has_bad())
            with_bad.push_back(p);
    print_list(with_bad);
    cout << '\n';
    return 0;
}