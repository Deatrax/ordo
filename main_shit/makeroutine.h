#ifndef MAKEROUTINE_H
#define MAKEROUTINE_H

#include "new_routine.h"
#include "qboxlayout.h"
#include "qdatetimeedit.h"
#include "qlabel.h"
#include <QMainWindow>
//#include "functions/everything.c"
typedef QString qstr;

namespace Ui {
class makeroutine;
}

class makeroutine : public QMainWindow
{
    Q_OBJECT

public:
    explicit makeroutine(QWidget *parent = nullptr);
    ~makeroutine();

    int periods;
    bool chk_sun;
    bool chk_mon;
    bool chk_tues;
    bool chk_wedn;
    bool chk_thu;
    bool chk_fri;
    bool chk_sat;
    std::vector<QTimeEdit*> td;
    std::vector<QString*> class_times;
    std::vector<new_routine*> classDatFetch;
    int set_progress=0;//to track page no in classes
    typedef struct mainClassdat{
        QString className="0";
        QString Instr="0";
        QString locale="0";
    }mainClassdat;
    QVBoxLayout* classStackLayout[7];
    QGridLayout* tds=new QGridLayout;
    bool last_page_backed=false;
    QString lunchTime_qsting;
    QString daybreak_qstring;
    char* QstrTOarry(QString qstr);
    void qTimeEdit_toC(QString time, int *hour, int *min, char *quad);
    void normal_label();
    void setupDay();
    void clearLayout(QLayout *layout);
    bool isEmptyString(QString str);
    void clearClassDats();
    int saveRoutine();

private slots:
    void on_pushButton_clicked();

    void on_procceedButton_clicked();

    void on_Go_backButton_clicked();

    void on_Next_dayButton_clicked();

    void on_change_periods_button_clicked();

    void on_pushButton_3_clicked();

    void on_previous_page_button_clicked();

private:
    Ui::makeroutine *ui;
};

#endif // MAKEROUTINE_H
