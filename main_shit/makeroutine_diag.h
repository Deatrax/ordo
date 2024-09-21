#ifndef MAKEROUTINE_DIAG_H
#define MAKEROUTINE_DIAG_H

#include <QDialog>

namespace Ui {
class makeroutine_diag;
}

class makeroutine_diag : public QDialog
{
    Q_OBJECT

public:
    explicit makeroutine_diag(QWidget *parent = nullptr);
    ~makeroutine_diag();

private:
    Ui::makeroutine_diag *ui;
};

#endif // MAKEROUTINE_DIAG_H
