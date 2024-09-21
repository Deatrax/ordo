#ifndef MATERIALELEMENT_H
#define MATERIALELEMENT_H

#include <QGroupBox>

namespace Ui {
class materialElement;
}

class materialElement : public QGroupBox
{
    Q_OBJECT

public:
    explicit materialElement(QWidget *parent = nullptr);
    ~materialElement();

private:
    Ui::materialElement *ui;
};

#endif // MATERIALELEMENT_H
