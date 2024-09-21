#ifndef UPNEXTELEMENT_H
#define UPNEXTELEMENT_H

#include <QWidget>

namespace Ui {
class upnextElement;
}

class upnextElement : public QWidget
{
    Q_OBJECT

public:
    explicit upnextElement(QWidget *parent = nullptr);
    int sourceLine;
    void settextName(const char ar[]);
    void settextType(char ar[]);
    void settextDeadL(int date, int month, int year);
    void settextRem(int tme);

    ~upnextElement();

    void allowChange();
private slots:
    void on_editTaskButton_clicked();

    void on_delete_taskButton_clicked();

private:
    Ui::upnextElement *ui;
};

#endif // UPNEXTELEMENT_H
