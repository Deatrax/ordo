#ifndef ROUTINEUNIT_H
#define ROUTINEUNIT_H

#include <QGroupBox>

namespace Ui {
class routineUnit;
}

class routineUnit : public QGroupBox
{
    Q_OBJECT

public:
    explicit routineUnit(QWidget *parent = nullptr);
    ~routineUnit();

private:
    Ui::routineUnit *ui;
};

#endif // ROUTINEUNIT_H
