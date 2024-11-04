#ifndef MODIFYCOURSECELL_H
#define MODIFYCOURSECELL_H

#include <QWidget>

namespace Ui {
class modifyCourseCell;
}

class modifyCourseCell : public QWidget
{
    Q_OBJECT

public:
    explicit modifyCourseCell(QWidget *parent = nullptr);
    ~modifyCourseCell();

private:
    Ui::modifyCourseCell *ui;
};

#endif // MODIFYCOURSECELL_H
