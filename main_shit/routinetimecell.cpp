#include "routinetimecell.h"
#include "ui_routinetimecell.h"

routineTimeCell::routineTimeCell(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::routineTimeCell)
{
    ui->setupUi(this);
}

routineTimeCell::~routineTimeCell()
{
    delete ui;
}


void routineTimeCell::setCellTime(QString str){

    ui->class_time->setText(str);
}


void routineTimeCell::setCellTime(char arr[]){

    ui->class_time->setText(arr);
}
