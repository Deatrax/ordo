#ifndef NEWBOX_H
#define NEWBOX_H

#include <QGroupBox>
#include "mainwindow.h"
#include"primary_window.h"

namespace Ui {
class newbox;
}

class newbox : public QGroupBox
{
    Q_OBJECT

public:
    Ui::newbox *ui;
    explicit newbox(primary_window *mainWindow,QWidget *parent = nullptr);
    void innit(char *str, char* str2);
    ~newbox();

    char arr[50];
    char courseFolderPath[650];
    int activeTab=0;
    QWidget* targTab;
private slots:
    void on_pushButton_clicked();

private:
    primary_window *m_mainWindow;
};

#endif // NEWBOX_H
