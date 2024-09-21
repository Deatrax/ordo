#include "materialnavcell.h"
#include "ui_materialnavcell.h"
#include "StylesSheets.h"
#include <QDesktopServices>

materialNavCell::materialNavCell(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::materialNavCell)
{
    loadThemeFromFile();
    ui->setupUi(this);
    ui->container->setStyleSheet(elementsStyle);
    ui->renameBox->hide();
    ui->saveButton->hide();
    ui->saveButton->setStyleSheet(buttonStyle);
}

materialNavCell::~materialNavCell()
{
    delete ui;
}

void materialNavCell::innit(char* filename, char* filepath){
    ui->itemName->setText(filename);
    targetFile=filepath;
}

void materialNavCell::on_renameButton_clicked()
{
    ui->renameBox->setStyleSheet(LabelStyleBordered);
    ui->renameBox->show();
    ui->saveButton->show();
    ui->renameButton->hide();
}


void materialNavCell::on_ItemDeleteButton_clicked()
{

}


void materialNavCell::on_ItemOpenButton_clicked()
{
    //QString filePath=filepath;
    QDesktopServices::openUrl(QUrl::fromLocalFile(targetFile));

}


void materialNavCell::on_saveButton_clicked()
{
    QString newFileName=ui->renameBox->text();
    ui->renameBox->hide();
    ui->saveButton->hide();
    ui->renameButton->show();
    //rename(targetFile.toStdString().c_str(),newFileName.toStdString().c_str());
}

