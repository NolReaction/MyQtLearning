QT += core gui widgets

TARGET = MyProject
CONFIG += c++11

# Исходные файлы
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    passwordchecker.cpp \
    secondwindow.cpp

# Заголовочные файлы
HEADERS += \
    mainwindow.h \
    passwordchecker.h \
    secondwindow.h

# Файлы формы (если используется Qt Designer)
FORMS += \
    mainwindow.ui \
    secondwindow.ui

# Добавляем текстовый файл с паролями
RESOURCES += \
    credentials.txt

# Добавляем файл для локализации (если используется)
TRANSLATIONS += \
    Learning_ru_RU.ts

DISTFILES += \
    .gitignore
