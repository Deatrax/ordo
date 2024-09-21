#ifndef ADDTASK_H
#define ADDTASK_H

#include <QWidget>
#include <primary_window.h>
namespace Ui {
class addTask;
}

class addTask : public QWidget
{
    Q_OBJECT

public:
    explicit addTask(primary_window *mainwindow, QWidget *parent = nullptr);
    ~addTask();

    void changeTask();
    bool changeMode=false;
    int lineNo=0;
private slots:
    void on_pushButton_clicked();

private:
    Ui::addTask *ui;
    primary_window *m_mainWindow;
};

#endif // ADDTASK_H
