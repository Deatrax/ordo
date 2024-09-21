#include "course_item.h"
#include "ui_course_item.h"

Course_Item::Course_Item(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Course_Item)
{
    ui->setupUi(this);
}

Course_Item::~Course_Item()
{
    delete ui;
}
