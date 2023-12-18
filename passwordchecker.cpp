#include "passwordchecker.h"
#include <fstream>
#include <sstream>
#include <QDebug>

// В passwordchecker.cpp
void PasswordChecker::addUserCredentials(const std::string& login, const std::string& pass) {
    // Добавляем новый логин и пароль в контейнер
    userCredentials[login] = pass;
}

void PasswordChecker::saveUserCredentialsToFile(const std::string& filename) {
    // Открываем файл для записи
    std::ofstream file(filename);

    // Записываем учетные данные в файл
    for (const auto& entry : userCredentials) {
        file << entry.first << " " << entry.second << std::endl;
    }

    // Закрываем файл после записи
    file.close();
}

PasswordChecker::PasswordChecker() {
    // Читаем логины и пароли из текстового файла
    std::ifstream file("D:/QTProjects/Learning/credentials.txt");
    // Проверка, удалось ли открыть файл
    if (!file.is_open()) {
        qDebug() << "Failed to open the file 'credentials.txt'";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string login, password;
        iss >> login >> password;
        userCredentials[login] = password;
    }

    // Закрываем файл после использования
    file.close();

    // Выводим данные для отладки
    // qDebug() << "User credentials loaded from file:";
    // for (const auto& entry : userCredentials) {
    //     qDebug() << entry.first.c_str() << ":" << entry.second.c_str();
    // }
}


bool PasswordChecker::checkPassword(const std::string& login, const std::string& pass) {
    //qDebug() << "Checking login:" << login.c_str() << "Password:" << pass.c_str();

    auto it = userCredentials.find(login);
    if (it != userCredentials.end()) {
        qDebug() << "Stored Password:" << it->second.c_str();
        if (it->second == pass) {
            qDebug() << "Login successful!";
            return true; // Пароль верный
        }
    }

    qDebug() << "Login failed. Incorrect username or password.";
    return false; // Пароль неверный
}


