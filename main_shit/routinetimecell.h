#ifndef ROUTINETIMECELL_H
#define ROUTINETIMECELL_H

#include <QWidget>

namespace Ui {
class routineTimeCell;
}

class routineTimeCell : public QWidget
{
    Q_OBJECT

public:
    explicit routineTimeCell(QWidget *parent = nullptr);
    ~routineTimeCell();

    void setCellTime(QString str);
    void setCellTime(char arr[]);
private:
    Ui::routineTimeCell *ui;
};

#endif // ROUTINETIMECELL_H
