#ifndef FIRST_RUN_H
#define FIRST_RUN_H

#include <QMainWindow>
#include "functions/everything.c"
namespace Ui {
class first_run;
}

class first_run : public QMainWindow
{
    Q_OBJECT

public:
    explicit first_run(QWidget *parent = nullptr);
    ~first_run();

private slots:
    void on_start_button_clicked();

    //void on_pushButton_clicked();

    void on_user_create_clicked();

    void on_home_dir_button_clicked();

    void on_template_button_clicked();

    void on_letsGO_button_clicked();

private:
    Ui::first_run *ui;


    //CUSTOM FUNCTIONS------->
    void hide_covers();
    void prepUI();
    //----------------------->
};

#endif // FIRST_RUN_H
