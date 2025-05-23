#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void engage();

private slots:
    void on_password_returnPressed();

    void on_pushButton_clicked();

    void login();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
