#include "upnextelement.h"
#include "addtask.h"
#include "ui_upnextelement.h"
#include "functions/everything.c"
#include <QMessageBox>
#include <StylesSheets.h>

upnextElement::upnextElement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::upnextElement)
{
    loadThemeFromFile();
    ui->setupUi(this);
    ui->modButtons->hide();
}

upnextElement::~upnextElement()
{
    delete ui;
}

void upnextElement::settextName(const char* ar)
{
    ui->taskName->setText(ar);
}

void upnextElement::settextType(char ar[])
{
    ui->taskType->setText(ar);
}

void upnextElement::settextDeadL(int date, int month, int year)
{
    char ar[20];
    sprintf(ar,"%d-%d-%d",date,month,year);
    ui->deadline->setText(ar);
}

void upnextElement::settextRem(int tme)
{
    if(tme==0) ui->deadline->setText("Today");
    char ar[20];
    sprintf(ar,"%d",tme);
    ui->rmDays->setText(ar);
}


void upnextElement::on_editTaskButton_clicked()
{
    addTask *nun=new addTask(nullptr);
    nun->changeMode=true;
    nun->lineNo=sourceLine;
    qDebug("the source line is %d",sourceLine);
    nun->show();
}


void upnextElement::on_delete_taskButton_clicked()
{
    QMessageBox warningBox(this);
    warningBox.setStyleSheet(elementsStyle);

    // Set the icon, title, and message text
    warningBox.setIcon(QMessageBox::Warning);
    warningBox.setWindowTitle("Warning");
    warningBox.setText("Are you sure you want to perform this action?");

    // Add buttons with standard roles
    QPushButton *yesButton = warningBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QPushButton *noButton = warningBox.addButton(tr("No"), QMessageBox::NoRole);
    QPushButton *cancelButton = warningBox.addButton(tr("Cancel"), QMessageBox::RejectRole);

    yesButton->setStyleSheet(buttonStyle);
    noButton->setStyleSheet(buttonStyle);
    cancelButton->setStyleSheet(buttonStyle);

    // Execute the message box
    warningBox.exec();

    // Handle the user's choice
    if (warningBox.clickedButton() == yesButton) {
        char file[260] = "upcoming.md";
        make_appData_filePath(file);
        removeLine(file, sourceLine);

        // Schedule the deletion of the parent widget using deleteLater()
        this->deleteLater();
    } else if (warningBox.clickedButton() == noButton) {
        // Handle 'No' option
    } else if (warningBox.clickedButton() == cancelButton) {
        // Handle 'Cancel' option
    }


}

void upnextElement::allowChange()
{
    ui->modButtons->show();
}


