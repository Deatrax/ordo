#include "modifycoursecell.h"
#include "StylesSheets.h"
#include "ui_modifycoursecell.h"

modifyCourseCell::modifyCourseCell(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modifyCourseCell)
{
    ui->setupUi(this);

    setStyleSheet(elementsStyle);
}

modifyCourseCell::~modifyCourseCell()
{
    delete ui;
}
