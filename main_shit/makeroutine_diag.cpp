#include "makeroutine_diag.h"
#include "ui_makeroutine_diag.h"

makeroutine_diag::makeroutine_diag(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::makeroutine_diag)
{
    ui->setupUi(this);
}

makeroutine_diag::~makeroutine_diag()
{
    delete ui;
}
