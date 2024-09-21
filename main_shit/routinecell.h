#ifndef ROUTINECELL_H
#define ROUTINECELL_H

#include <QWidget>

namespace Ui {
class routineCell;
}

class routineCell : public QWidget
{
    Q_OBJECT

public:
    explicit routineCell(QWidget *parent = nullptr);
    ~routineCell();

    QString name;
    QString inst;
    QString Locl;

    void initialize(QString nam, QString ins, QString loca);
    void initialize(char nam[], char ins[], char loca[]);
    void setSame();
    void setFree();
    void peviousOne();
private:
    Ui::routineCell *ui;
};

#endif // ROUTINECELL_H
