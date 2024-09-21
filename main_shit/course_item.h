#ifndef COURSE_ITEM_H
#define COURSE_ITEM_H

#include <QWidget>

namespace Ui {
class Course_Item;
}

class Course_Item : public QWidget
{
    Q_OBJECT

public:
    explicit Course_Item(QWidget *parent = nullptr);
    ~Course_Item();

private:
    Ui::Course_Item *ui;
};

#endif // COURSE_ITEM_H
