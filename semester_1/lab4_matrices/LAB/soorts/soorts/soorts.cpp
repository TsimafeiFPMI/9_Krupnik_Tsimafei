#include <iostream>
#include <fstream>
#include <ctime>

void writeLog(const std::string& message,
    const std::string& filename = "app.log") {
    // ios::app - добавляем в конец, не перезаписываем
    std::ofstream logFile(filename, std::ios::out | std::ios::app);

    if (logFile.is_open()) {
        // Получаем текущее время
        std::time_t now = std::time(nullptr);
        char timeStr[100];
        std::strftime(timeStr, sizeof(timeStr),
            "[%Y-%m-%d %H:%M:%S]", std::localtime(&now));

        logFile << timeStr << " " << message << std::endl;
        logFile.close();
    }
}

int main() {
    writeLog("Приложение запущено");
    writeLog("Выполнена операция 1");
    writeLog("Приложение завершено");

    return 0;
}