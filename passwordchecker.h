#ifndef PASSWORDCHECKER_H
#define PASSWORDCHECKER_H

#include <string>
#include <unordered_map>
#include <QDebug>

class PasswordChecker {
public:
    PasswordChecker();

    bool checkPassword(const std::string& login, const std::string& pass);
    void addUserCredentials(const std::string& login, const std::string& pass);
    void saveUserCredentialsToFile(const std::string& filename);

private:
    std::unordered_map<std::string, std::string> userCredentials;
};

#endif // PASSWORDCHECKER_H
