#ifndef SETTINGS_PAGE_H
#define SETTINGS_PAGE_H

#include <QWidget>
#include "primary_window.h"

namespace Ui {
class settings_page;
}

class settings_page : public QWidget
{
    Q_OBJECT

public:
    explicit settings_page(primary_window *mainwindow, QWidget *parent = nullptr);
    ~settings_page();

    void setAutoStartWindows(bool flag);
private slots:
    void on_loginCheckBox_clicked(bool checked);

    void on_trayCheckBox_clicked(bool checked);

private:
    Ui::settings_page *ui;
    primary_window *m_mainWindow;
};

#endif // SETTINGS_PAGE_H
