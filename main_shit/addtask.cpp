#include "addtask.h"
#include "qmessagebox.h"
#include "ui_addtask.h"
#include "functions/everything.c"
#include <iostream>
#include <iostream>
#include <QString>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

addTask::addTask(primary_window *mainwindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addTask)
    , m_mainWindow(mainwindow)
{
    ui->setupUi(this);
}

addTask::~addTask()
{
    delete ui;
}

//==========GLOBAL VARIABLE SPACE========

//=======================================

void addTask::on_pushButton_clicked()
{
    if(changeMode){
        changeTask();
        return;
    }
    char file[260]="upcoming.md";
    make_appData_filePath(file);
    FILE *fp=fopen(file,"a");
    if(fp==NULL){
        QMessageBox msgBox;
        msgBox.setText("Failed!");
        msgBox.setInformativeText("Failed to open upcoming.md");
        // Apply stylesheet to QMessageBox
        msgBox.setStyleSheet("color:rgb(0, 0, 0);font: 15pt \"Cascadia Code\";background:rgb(105, 255, 160);border-radius:15px;");
        msgBox.exec();
    }
    else{

        QString name=ui->name->text();
        QString type=ui->type->text();
        QString dat=ui->day->text();
        QString mont=ui->month->text();
        QString yr=ui->year->text();


        std::string nam=name.toUtf8().constData();
        std::string typ=type.toUtf8().constData();
        std::string datee=dat.toUtf8().constData();
        std::string mon=mont.toUtf8().constData();
        std::string yer=yr.toUtf8().constData();

        std::cout<<nam<<" "<<typ<<" "<<datee<<" "<<mon<<" "<<yer<<std::endl;




        fprintf(fp,"\n|%s|%s|%s|%s|%s|",nam.c_str(),typ.c_str(),datee.c_str(),mon.c_str(),yer.c_str());
        if(fp!=NULL)
            fclose(fp);
        close();
        m_mainWindow->resetFlag(4);
        m_mainWindow->resetFlag(5);
        m_mainWindow->resetFlag(6);
        m_mainWindow->refreshCurrentPage();
    }

}

void addTask::changeTask(){
    QString name=ui->name->text();
    QString type=ui->type->text();
    QString dat=ui->day->text();
    QString mont=ui->month->text();
    QString yr=ui->year->text();


    std::string nam=name.toUtf8().constData();
    std::string typ=type.toUtf8().constData();
    std::string datee=dat.toUtf8().constData();
    std::string mon=mont.toUtf8().constData();
    std::string yer=yr.toUtf8().constData();

    std::cout<<nam<<" "<<typ<<" "<<datee<<" "<<mon<<" "<<yer<<std::endl;


    char buff[200]="\0";

    sprintf(buff,"|%s|%s|%s|%s|%s|\0",nam.c_str(),typ.c_str(),datee.c_str(),mon.c_str(),yer.c_str());
    char file[260]="upcoming.md";
    make_appData_filePath(file);
    replaceLINE(file,lineNo,buff);
    close();
}

