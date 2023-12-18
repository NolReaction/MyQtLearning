#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include "passwordchecker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_SignIn_clicked();

    void on_pushButton_QuestionLogin_clicked();

    void on_pushButton_QuestionPassword_clicked();

    void on_pushButton_SignUp_clicked();

private:
    Ui::MainWindow *ui;
    SecondWindow *window;
    PasswordChecker passwordChecker;
};
#endif // MAINWINDOW_H
