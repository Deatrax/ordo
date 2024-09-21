#include "materialelement.h"
#include "ui_materialelement.h"

materialElement::materialElement(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::materialElement)
{
    ui->setupUi(this);
}

materialElement::~materialElement()
{
    delete ui;
}
