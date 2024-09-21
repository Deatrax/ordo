#include "first_run.h"
#include "ui_first_run.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <iostream>
#include <QTimer>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
//#include <windows.h>
// #include "functions/decipher.c"
// //#include "functions/login.c"
// #include "functions/test.c"
// #include "functions/uchk.c"
// #include "functions/file_test.c"

//#include "functions/umake.c"
//#include "functions/cipher.c"
//#include "functions/everything.c"




//GLOBAL RECLERATION================>
int user_flag=0;

//==================================>



first_run::first_run(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::first_run)
{
    ui->setupUi(this);


    //=====ANIMATION=======================>
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect();
    ui->start_button->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(1500);
    a->setStartValue(0);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *eff2 = new QGraphicsOpacityEffect();
    ui->stuff_box->setGraphicsEffect(eff2);
    QPropertyAnimation *a2 = new QPropertyAnimation(eff2,"opacity");
    a2->setDuration(500);
    a2->setStartValue(0);
    a2->setEndValue(0);
    a2->setEasingCurve(QEasingCurve::InBack);
    a2->start(QPropertyAnimation::DeleteWhenStopped);


    //=====CONFIG_FILE_FUNCTIONS===========>
    prepUI();

}

first_run::~first_run()
{
    delete ui;
}

//=======GLOBAL DECLERATIONS========>
QString tmpl;
int tmplFlag=0;
int umade=0;
char ctmpl_path[1024];
QString qdef_dir;
//==================================>




void first_run::on_start_button_clicked()
{
    QGraphicsOpacityEffect *effff = new QGraphicsOpacityEffect();
    ui->hide_box->setGraphicsEffect(effff);
    QPropertyAnimation *a2 = new QPropertyAnimation(effff,"opacity");
    a2->setDuration(1000);
    a2->setStartValue(1);
    a2->setEndValue(0);
    a2->setEasingCurve(QEasingCurve::InBack);
    a2->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect();
    ui->start_button->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(1000);
    a->setStartValue(1);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *eff2 = new QGraphicsOpacityEffect();
    ui->paadding->setGraphicsEffect(eff2);
    QPropertyAnimation *a22 = new QPropertyAnimation(eff2,"opacity");
    a22->setDuration(1000);
    a22->setStartValue(1);
    a22->setEndValue(0);
    a22->setEasingCurve(QEasingCurve::InBack);
    a22->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *eff3 = new QGraphicsOpacityEffect();
    ui->stuff_box->setGraphicsEffect(eff3);
    QPropertyAnimation *a3 = new QPropertyAnimation(eff3,"opacity");
    a3->setDuration(1000);
    a3->setStartValue(0);
    a3->setEndValue(1);
    a3->setEasingCurve(QEasingCurve::InBack);
    a3->start(QPropertyAnimation::DeleteWhenStopped);

    QObject::connect(a, &QAbstractAnimation::finished, this, &first_run::hide_covers);

    // QPropertyAnimation *a3=new QPropertyAnimation(ui->start_button,"geometry");
    // a3->setDuration(20000);
    // a3->setStartValue(ui->start_button->geometry());
    // a3->setEndValue(QRect(0,0,0,0));
    // a3->start();

    // QPropertyAnimation *a4=new QPropertyAnimation(ui->hide_box,"geometry");
    // a4->setDuration(3000);
    // a4->setStartValue(ui->start_button->geometry());
    // a4->setEndValue(QRect(0,0,0,0));
    // a4->start();

    //QTimer::singleShot(2000, &first_run::hide_covers);
}

void first_run::hide_covers(){

    ui->start_button->hide();
    ui->hide_box->hide();
    ui->paadding->hide();
}

void first_run::prepUI()
{

    char udir[512];
    get_usr_env(udir);
    std::string def_dir(udir);
    //def_dir=udir;
    //std::cout<<"got the directory: "<<def_dir<<std::endl;
    qdef_dir = QString::fromStdString(def_dir);
    ui->home_dir->setText(qdef_dir);
}


void first_run::on_user_create_clicked()
{

    QString pass=ui->password->text();
    QString usernam=ui->username->text();

    std::string usr=usernam.toUtf8().constData();
    std::string pas=pass.toUtf8().constData();

    if(pas=="0000" || pas=="1000"){

        QMessageBox::warning(this,"Vulnerable pin!!","The enerted pin is not acceptable");
        return;
    }
    std::cout<<"got the usrname: "<<usr<<" got the pass: "<<pas<<std::endl;
    //char *ar_str1=(char*)malloc(usr.length()*sizeof(char));
    //char *ar_str2=(char*)malloc(pas.length()*sizeof(char));

    char ar_str1[200];
    char ar_str2[200];

    strcpy(ar_str1,usr.c_str());
    strcpy(ar_str2,pas.c_str());
    int int_pass=atoi(ar_str2);

    printf("got the username %s and the password %s and the pass in int is %d\n",ar_str1,ar_str2,int_pass);
    std::cout<<"the stuff in arr is:"<<ar_str1<<" and "<<ar_str2<<std::endl;


    char notes[2000]="\0";
    int ret=umake(ar_str1,int_pass);
    if(ret==1){

        //ui->notes->setText("new user created successfully!!");
        ui->user_create->setText("Change");
        //QMessageBox::information(this, "Success!", "The user has been created successfully, but you can still change it by clicking the \"change\" button after you have entered the new credentials");


        QMessageBox msgBox;
        msgBox.setText("Success!");
        msgBox.setInformativeText("The user has been created successfully, but you can still change it by clicking the \"change\" button after you have entered the new credentials");
        // Apply stylesheet to QMessageBox
        msgBox.setStyleSheet("QMessageBox { background-color: white; color: black; }");
        msgBox.exec();
        umade=1;

    }
}



void first_run::on_home_dir_button_clicked()
{
    qdef_dir= QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::homePath(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->home_dir->setText(qdef_dir);
}


void first_run::on_template_button_clicked()
{
    tmpl=QFileDialog::getOpenFileName(this, "select a template (.tmpl file)", QDir::homePath());


    //QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/home", "Text Files (*.txt)");

    if (!tmpl.isEmpty()) {
        // Get filename and path
        QString fullPath = tmpl;
        QString filename = QFileInfo(fullPath).fileName();

        // Use filename and fullPath as needed
        qDebug() << "Selected file: " << filename;
        qDebug() << "Full path: " << fullPath;
        ui->template_slec->setText(filename);

        std::string filepathCPP=fullPath.toUtf8().constData();
        strcpy(ctmpl_path,filepathCPP.c_str());

    }

    tmplFlag=1;
}


void first_run::on_letsGO_button_clicked()
{
    if(umade!=1){

        QMessageBox::warning(this,"User not made yet","User not made, please make user first");
    }
    else{

        QString dname=ui->get_display_name->text();
        std::string dnameCpp=dname.toUtf8().constData();
        char dnameC[256];
        strcpy(dnameC,dnameCpp.c_str());

        std::string mainDIR=qdef_dir.toUtf8().constData();
        char mainDIRc[1024];
        strcpy(mainDIRc, mainDIR.c_str());

        printf("the stuff are: %s  %s",mainDIRc, dnameC);
        int ret=write_uconfig(tmplFlag,ctmpl_path,mainDIRc,dnameC);
        if(ret==1){
            QMessageBox msgBox;
            msgBox.setText("Success!");
            msgBox.setInformativeText("Setup completed successfully!! Please relaunch the app.");
            // Apply stylesheet to QMessageBox
            msgBox.setStyleSheet("QMessageBox { background-color: white; color: black; }");
            msgBox.exec();

            close();
        }
        else if(ret==0){
            QMessageBox::warning(this,"Setup failed","Program failed to make config file");
        }
        else{
             QMessageBox::warning(this,"Setup failed","Something went wrong");
        }
    }

}

