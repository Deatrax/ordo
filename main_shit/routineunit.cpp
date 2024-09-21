#include "routineunit.h"
#include "ui_routineunit.h"

routineUnit::routineUnit(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::routineUnit)
{
    ui->setupUi(this);
}

routineUnit::~routineUnit()
{
    delete ui;
}
