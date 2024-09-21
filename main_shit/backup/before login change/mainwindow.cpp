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



    //=====CHECK IF THIS IS THE FIRST TIME RUNNING BY CHECKING THE EXISTANCE OF "uconfig.spenc" FILE============>
    FILE *FRUN=fopen("uconfig.spenc","rb");
    if(FRUN==NULL   /*====DISABLE SETUP WINDOW=====>>>>>*/ /*false*/){

        if(FRUN!=NULL)
            fclose(FRUN);
        engage();
    }
    else{
        FILE *fp=fopen("ulist.spenc","rb");
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


    //===========DISABLE LOGIN FOR "primary_window" UI DEV=========>
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
    QString pass=ui->password->text();
    QString usernam=ui->username->text();

    std::string usr=usernam.toUtf8().constData();
    std::string pas=pass.toUtf8().constData();

    //DEBUG std::cout<<"got the usrname: "<<usr<<" got the pass: "<<pas<<std::endl;
    //char *ar_str1=(char*)malloc(usr.length()*sizeof(char));
    //char *ar_str2=(char*)malloc(pas.length()*sizeof(char));

    char ar_str1[200];
    char ar_str2[200];

    strcpy(ar_str1,usr.c_str());
    strcpy(ar_str2,pas.c_str());
    int int_pass=atoi(ar_str2);

    printf("got the username %s and the password %s and the pass in int is %d\n",ar_str1,ar_str2,int_pass);
    //DEBUG std::cout<<"the stuff in arr is:"<<ar_str1<<" and "<<ar_str2<<std::endl;


    //UNUSED VARIABLE char notes[2000]="\0";

    int ret=5;
    if(flag!=0){

        ret=umake(ar_str1,int_pass);

    }
    else{
        ret=chk(ar_str1,int_pass);
    }

    //DEBUG std::cout<<"ret is: "<<ret<<std::endl;
    if(ret==1){

        ui->notes->setText("new user created successfully!!");
    }
    else if(ret==2   /*=========DISABLE LOGIN FOR UI DEV*========>>>>>*/   /*true*/){

        ui->notes->setText("login successful");
        primary_window* w2=new primary_window();
        w2->show();
        //--this didn't work-> close();
        hide();

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


void MainWindow::on_pushButton_clicked()
{
    QString pass=ui->password->text();
    QString usernam=ui->username->text();

    std::string usr=usernam.toUtf8().constData();
    std::string pas=pass.toUtf8().constData();

    //DEBUG std::cout<<"got the usrname: "<<usr<<" got the pass: "<<pas<<std::endl;
    //char *ar_str1=(char*)malloc(usr.length()*sizeof(char));
    //char *ar_str2=(char*)malloc(pas.length()*sizeof(char));

    char ar_str1[200];
    char ar_str2[200];

    strcpy(ar_str1,usr.c_str());
    strcpy(ar_str2,pas.c_str());
    int int_pass=atoi(ar_str2);

    printf("got the username %s and the password %s and the pass in int is %d\n",ar_str1,ar_str2,int_pass);
    //DEBUG std::cout<<"the stuff in arr is:"<<ar_str1<<" and "<<ar_str2<<std::endl;


    //UNUSED VARIABLE char notes[2000]="\0";

    int ret=5;
    if(flag!=0){

        ret=umake(ar_str1,int_pass);

    }
    else{
        ret=chk(ar_str1,int_pass);
    }

    //DEBUG std::cout<<"ret is: "<<ret<<std::endl;
    if(ret==1){

        ui->notes->setText("new user created successfully!!");
    }
    else if(ret==2){

        ui->notes->setText("login successful");
        primary_window* w2=new primary_window();
        w2->show();
        //--this didn't work-> close();
        hide();


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

