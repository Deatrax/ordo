#ifndef CHANGESEMESTER_H
#define CHANGESEMESTER_H

#include <QMainWindow>
#include "first_run.h"

namespace Ui {
class ChangeSemester;
}


class ChangeSemester : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeSemester(QWidget *parent = nullptr);
    ~ChangeSemester();

    char coursePath[550];
    char semesterPath[512];
    char coursedatPath[550];
    void setToAdd();
private slots:
    void on_saveCourseButton_clicked();

private:
    Ui::ChangeSemester *ui;
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void windowClosed();

};

#endif // CHANGESEMESTER_H
