#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "passwordchecker.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    passwordChecker()  // Создаем объект PasswordChecker при создании MainWindow
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    QString login = ui->lineEdit_Login->text();
    QString pass = ui->lineEdit_Password->text();

    qDebug() << "Entered login:" << login << "Password:" << pass;

    // Передаем логин и пароль для проверки в passwordChecker
    if (passwordChecker.checkPassword(login.toStdString(), pass.toStdString())) {
        hide();
        window = new SecondWindow(this);
        window->show();
    } else {
        // Обработка случая неверного логина или пароля
        QMessageBox::critical(this, "Ошибка", "Введён неверный логин или пароль");
    }
}

void MainWindow::on_pushButton_QuestionLogin_clicked()
{
    QMessageBox::information(this, "", "Введите логин, котрый вы указывали при регистрации !");
}


void MainWindow::on_pushButton_QuestionPassword_clicked()
{
    QMessageBox::information(this, "", "Введите пароль, котрый вы указывали при регистрации !");
}


void MainWindow::on_pushButton_SignUp_clicked()
{
    // Используем диалоговое окно для ввода логина
    QString login = QInputDialog::getText(this, "Регистрация", "Введите логин:");

    // Проверяем, была ли нажата кнопка "Отмена" или введенный логин пуст
    if (login.isEmpty()) {
        return;
    }

    // Используем диалоговое окно для ввода пароля
    QString password = QInputDialog::getText(this, "Регистрация", "Введите пароль:", QLineEdit::Password);

    // Проверяем, была ли нажата кнопка "Отмена" или введенный пароль пуст
    if (password.isEmpty()) {
        return;
    }

    // Добавляем логин и пароль в контейнер
    passwordChecker.addUserCredentials(login.toStdString(), password.toStdString());

    // Сохраняем обновленные учетные данные в файл
    passwordChecker.saveUserCredentialsToFile("D:/QTProjects/Learning/credentials.txt");

    // Выводим сообщение об успешной регистрации
    QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно!");
}

