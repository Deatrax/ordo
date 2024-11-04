#include "modifycoursecell.h"
#include "StylesSheets.h"
#include "primary_window.h"
#include "ui_modifycoursecell.h"
#include "first_run.h"
#include <QMessageBox>
#include <iostream>
#include <ostream>

modifyCourseCell::modifyCourseCell(primary_window *mainwindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modifyCourseCell)
    , m_mainWindow(mainwindow)
{
    ui->setupUi(this);

    setStyleSheet(elementsStyle);
    ui->SaveNameButton->hide();
    ui->courseRenameBox->hide();
    ui->SaveNameButton->setStyleSheet(buttonStyle);
    ui->courseRenameBox->setStyleSheet(LabelStyleBordered);
}

modifyCourseCell::~modifyCourseCell()
{
    delete ui;
}


void modifyCourseCell::init(char *courseName, char* str2,int lineNo){
    ui->CourseName->setText(courseName);
    if(courseName[strlen(courseName)-1]=='\n') courseName[strlen(courseName)-1]='\0';
    strcpy(arr, courseName);
    strcpy(courseFolderPath,str2);
    lineNum=lineNo;
    if(!directoryExists(courseFolderPath)){
        dirrExists=false;
        ui->CourseName->setText("dir failed");
    }
    else{
        dirrExists=true;
    }
}


void modifyCourseCell::renameCourse(){

    ui->CourseName->hide();
    ui->SaveNameButton->show();
    ui->courseRenameBox->show();


}

void modifyCourseCell::on_SaveNameButton_clicked()
{
    std::string output;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confirmation", "Do you want to change the course name?",
                                  QMessageBox::Yes | QMessageBox::No);

    // Check the user's response and execute code accordingly
    if (reply == QMessageBox::Yes) {
        // Code to execute if "Yes" is clicked
        std::cout << "User clicked Yes!" << std::endl;
        output=ui->courseRenameBox->text().toStdString();
    } else {
        // Code to execute if "No" is clicked
        std::cout << "User clicked No!" << std::endl;
        ui->SaveNameButton->hide();
        ui->courseRenameBox->hide();
        return;
    }

    output+=","+std::string(courseFolderPath)+"/";
    qDebug("got the new course data=%s || and the line number is=%d",output.c_str(),lineNum);
    m_mainWindow->updateCourse(output,lineNum);
    ui->SaveNameButton->hide();
    ui->courseRenameBox->hide();
    ui->CourseName->show();
    ui->CourseName->setText(ui->courseRenameBox->text());
    return;
}

