#ifndef NEW_ROUTINE_H
#define NEW_ROUTINE_H

#include <QWidget>
#include <QString>

namespace Ui {
class new_routine;
}

class new_routine : public QWidget
{
    Q_OBJECT

public:
    explicit new_routine(QWidget *parent = nullptr);
    ~new_routine();

    QString class_name;
    QString instructor;
    QString location;

    void set_period(QString i);
    void get_info();
    void clear_info();
    void warn();
private:
    Ui::new_routine *ui;
};

#endif // NEW_ROUTINE_H
