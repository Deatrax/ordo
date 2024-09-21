#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "primary_window.h"
#include "first_run.h"
#include <QString>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
//#include<ctype.h>
//#include "functions/cipher.c"
// #include "functions/decipher.c"
//#include "functions/login.c"
// #include "functions/test.c"
// #include "functions/umake.c"
// #include "functions/uchk.c"
// #include "functions/file_test.c"
//#include "functions/everything.c"


int flag=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    
    char file[260]="uconfig.spenc";
    make_appData_filePath(file);
    char file0[260]="ulist.spenc";
    make_appData_filePath(file0);
    //=====CHECK IF THIS IS THE FIRST TIME RUNNING BY CHECKING THE EXISTANCE OF "uconfig.spenc" FILE============>
    FILE *FRUN=fopen(file,"rb");
    if(FRUN==NULL   /*====DISABLE SETUP WINDOW=====>>>>>*/ /*false*/){
        if(FRUN!=NULL)
            fclose(FRUN);
        engage();
    }
    else{
        FILE *fp=fopen(file0,"rb");
        if(fp==NULL){
            show();
            ui->notes->setText("No user found,\nmaking new user");
            if(fp!=NULL)
                fclose(fp);
            flag++;
        }
        else{

            show();
            ui->notes->setText("Please login");
            if(fp!=NULL)
                fclose(fp);
        }
    }
    //engage();
    //show();

    //=====previous workin segment before "frist_run" window addition========>
    //
    // FILE *fp=fopen("ulist.spenc","rb");
    // if(fp==NULL){
    //     ui->notes->setText("No user found,\nmaking new user");
    //     fclose(fp);
    //     flag++;
    // }
    // else{
    //     show();
    //     ui->notes->setText("Please login");
    //     fclose(fp);
    // }
    //=======================================================================>


    //===========DISABLE LOGIN FOR "primary_window" UI DEV=========>   at line 80, 158/155, 143-148
    //on_password_returnPressed();
    //=============================================================>


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::engage(){

    hide();
    first_run *frun=new first_run();
    frun->show();

}

void MainWindow::on_password_returnPressed()
{

    login();
}


void MainWindow::on_pushButton_clicked()
{
    login();

}


void MainWindow::login(){

    QString pass=ui->password->text();
    QString usernam=ui->username->text();

    qDebug()<<"got the initial data: "<<usernam<<" and "<<pass<<"\n";
    std::string usr=usernam.toUtf8().constData();
    std::string pas=pass.toUtf8().constData();

    //DEBUG std::cout<<"got the usrname: "<<usr<<" got the pass: "<<pas<<std::endl;
    //char *ar_str1=(char*)malloc(usr.length()*sizeof(char));
    //char *ar_str2=(char*)malloc(pas.length()*sizeof(char));

    int n0=usr.length();
    int n=pas.length();
    char* psword=allocate1DCharArray(n+1);
    char* slt=allocate1DCharArray(n0+1);

    std::cout<<"the length of pass is: "<<(int)pas.length()<<"\n";
    strcpy(slt,usr.c_str());
    strcpy(psword,pas.c_str());
    //int int_pass=atoi(ar_str2);

    printf("got the username %s and the password %s ",slt,psword);
    //DEBUG std::cout<<"the stuff in arr is:"<<ar_str1<<" and "<<ar_str2<<std::endl;


    //UNUSED VARIABLE char notes[2000]="\0";

    int ret=5;
    if(flag!=0){
        ret= umake(slt,psword);
    }
    else{
        ret=chk(slt,psword);
    }

    //DEBUG std::cout<<"ret is: "<<ret<<std::endl;
    if(ret==1){

        ui->notes->setText("new user created successfully!!");
    }
    else if(ret==2  /*true*/  /*<<<<<====DISABLE LOGIN FOR UI DEV*========*/){

        ui->notes->setText("login successful");
        primary_window* w2=new primary_window();
        w2->show();
        hide();
        //--this didn't work-> close();

    }
    else if(ret==0 && flag!=0){
        ui->notes->setText("user creation failed");
    }
    else if(ret==0 && flag==0){
        ui->notes->setText("login failed");
    }


    // int ret =test(ar_str1,int_pass);
    // //int ret=login2(ar_str1,int_pass,notes);
    // std::string out_notes=notes;
    // QString output=QString::fromStdString(out_notes);

    // if(ret==-2){
    //     ui->notes->setText(output);
    // }
    // else if(ret==-1){
    //     ui->notes->setText(output);
    // }
    // else if(ret==0){
    //     ui->notes->setText("yoooo mofo");
    // }

    //ui->notes->setText("this is working fine");
}
