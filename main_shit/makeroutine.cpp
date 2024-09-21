#include "makeroutine.h"
#include "new_routine.h"
#include "ui_makeroutine.h"
#include <QString>
#include <vector>
#include <QPropertyAnimation>
#include <QGraphicsColorizeEffect>
#include <QTimer>
#include "first_run.h"
#include "StylesSheets.h"

makeroutine::makeroutine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::makeroutine)
{
    loadThemeFromFile();
    ui->setupUi(this);
    ui->pushButton->hide();
    ui->change_periods_button->hide();
    ui->page1_sideStack->setCurrentIndex(1);
    ui->routuneSetupStack->setCurrentIndex(0);
    ui->lunch_start->setDisplayFormat("hh:mm AP");
    ui->daybreak->setDisplayFormat("hh:mm AP");
    setStyleSheet(mainBG);
}

makeroutine::~makeroutine()
{
    delete ui;
}


//===================GLOBAL VARIABLE SCOPE==================>
makeroutine::mainClassdat sun[16];
makeroutine::mainClassdat mon[16];
makeroutine::mainClassdat tue[16];
makeroutine::mainClassdat wed[16];
makeroutine::mainClassdat thu[16];
makeroutine::mainClassdat fri[16];
makeroutine::mainClassdat sat[16];

//=========================================================>




//main page 1 next button to go to page 2
void makeroutine::on_pushButton_clicked()
{
    //int days=ui->weekNums->value();
    chk_sun=ui->checkSunday->checkState();
    chk_mon=ui->checkMonday->checkState();
    chk_tues=ui->checkTuesday->checkState();
    chk_wedn=ui->checkWednesday->checkState();
    chk_thu=ui->checkThursday->checkState();
    chk_fri=ui->checkFriday->checkState();
    chk_sat=ui->checkSaturday->checkState();
    qDebug("Got the states: \nsunday:%d\nmonday:%d\ntuesday:%d\nwednesday:%d\nthrusday:%d\nfriday:%d\nsatruday:%d",chk_sun,chk_mon,chk_tues,chk_wedn,chk_thu,chk_fri,chk_sat);

    /*
    //================old method of getting the time form the user using line edit and str tok
    QString times=ui->times_periods_2->toPlainText();
    std::string timesCpp=times.toStdString();
    qDebug("got the std sting:%s0",timesCpp.c_str());
    char* arr=new char[timesCpp.length()+1];
    strncpy_s(arr,sizeof(arr),timesCpp.c_str(),timesCpp.length());
    char buff[20];
    char* tok=strtok(arr,"\n");
    for (int var = 0; var < periods-1; ++var) {
        char buff2[20];
        strcpy(buff2,tok);
        qDebug("the current period:%s\n",buff2);
        tok=strtok(NULL,"\n");
    }
    //=============================================================================>
    */

    //==============testing QTimeEdit conversion to char array====================>
    lunchTime_qsting=ui->lunch_start->text();
    daybreak_qstring=ui->daybreak->text();
    qDebug("the current lunch time is:%s\n",lunchTime_qsting.toUtf8().constData());
    qDebug("the current daybreak time is:%s\n",daybreak_qstring.toUtf8().constData());
    char* arr2=QstrTOarry(daybreak_qstring);
    int hour=0;
    int min=0;
    char quad[3];
    //sscanf(arr2,"%d:%d %2s",&hour,&min,quad);
    qTimeEdit_toC(daybreak_qstring,&hour,&min,quad);
    qDebug("got the data from arr2(daybreak time): %d, %d, %s\n",hour,min,quad);
    //delete[] arr2;==============================================================>


    //Getting the period timings from the time edits
    class_times.resize(periods);
    for(int i=0;i<periods;i++){
        // class_times[i]=new QString;
        class_times[i] = new QString(td[i]->text());
        qDebug("got the class time:%s",class_times[i]->toStdString().c_str());
    }

    /*
    classDat.resize(periods);
    //TESTING IF THE NEW_ROUTINR CLASS AND THE DATA INJECT INTO IT WORKS OR NOT===>
    ui->routuneSetupStack->setCurrentIndex(2); //go to next page on setup window
    ui->classesStack->setCurrentIndex(1); //go to monday page on classes window
    classDat[0]=new new_routine;
    QVBoxLayout* layout=new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    classDat[0]->set_period("1. 9:30AM");
    layout->addWidget(classDat[0]);
    ui->monday_stack->setLayout(layout);
    //=======================================>*/

    //Resize classDat, fill them with class timings,
    classDatFetch.resize(periods);
    for(int i=0;i<periods;i++){

        classDatFetch[i]=new new_routine;
        classDatFetch[i]->set_period(*class_times[i]);
    }
    ui->routuneSetupStack->setCurrentIndex(2); //go to next page on setup window
    setupDay();
}



void makeroutine::on_change_periods_button_clicked()
{
    for(int i=0;i<periods;i++){
        delete td[i];
    }
    periods=ui->preriods->value();
    clearLayout(ui->times_scroll->layout());
    on_procceedButton_clicked();
}



void makeroutine::on_procceedButton_clicked()
{
    ui->label_no5->setStyleSheet(
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"
        "padding: 2px 2px;"
        "background-color: #FFF2D8;"  // Initial background color
        "color: black;"
        "border-radius:10px;"
        );
    /*font-size: 15px;
    font-weight: 600;
    line-height: 1;
    padding: 2px 2px;
    color:black;*/
    periods=ui->preriods->value();

    //0 entered warning animation
    if(periods==0){
        /*
        ui->label_no5->setText("Yeah you cannot have 0 classes\nin no 1. box");
        // Create a QTimer to handle the flashing effect
        QTimer* timer = new QTimer(this);
        int flashCount = 0;
        // Define the lambda for handling color changes
        connect(timer, &QTimer::timeout, this, [=]() mutable {
            if (flashCount % 2 == 0) {
                // Set to red background color
                ui->label_no5->setStyleSheet(
                    "font-size: 15px;"
                    "font-weight: 600;"
                    "line-height: 1;"
                    "padding: 2px 2px;"
                    "background-color: red;"  // Flash red
                    "color: black;"
                    );
            } else {
                // Reset to original background color
                ui->label_no5->setStyleSheet(
                    "font-size: 15px;"
                    "font-weight: 600;"
                    "line-height: 1;"
                    "padding: 2px 2px;"
                    "background-color: #FFF2D8;"  // Original color
                    "color: black;"
                    );
            }
            flashCount++;
            // Stop the timer after flashing twice
            if (flashCount >= 4) {
                timer->stop();
                timer->deleteLater(); // Clean up the timer
            }
        });
        timer->start(500); // Set the timer interval to 500 milliseconds for the flashing effect
        return;
        */

        ui->label_no5->setText("Yeah you cannot have 0 classes\nin no 1. box");

        // Set up the animation
        QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(ui->label_no5);
        ui->label_no5->setGraphicsEffect(effect);

        QPropertyAnimation* animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(1000); // Duration in milliseconds
        animation->setLoopCount(2);   // Number of flashes (2 flashes = 4 opacity changes)
        animation->setKeyValueAt(0, 1.0);   // Fully visible
        animation->setKeyValueAt(0.5, 0.0); // Fully invisible
        animation->setKeyValueAt(1, 1.0);   // Fully visible again

        // Change the background color to red during the animation
        QTimer::singleShot(100, [this]() {
            ui->label_no5->setStyleSheet(
                "font-size: 15px;"
                "font-weight: 600;"
                "line-height: 1;"
                "padding: 2px 2px;"
                "background-color: red;"  // Change to red
                "color: black;"
                "border-radius:10px;"
                );
        });

        // Reset the background color back to normal after the animation finishes
        connect(animation, &QPropertyAnimation::finished, this, [this]() {
            ui->label_no5->setStyleSheet(
                "font-size: 15px;"
                "font-weight: 600;"
                "line-height: 1;"
                "padding: 2px 2px;"
                "background-color: #FFF2D8;"  // Change back to the original color
                "color: black;"
                "border-radius:10px;"
                );
        });

        animation->start(QAbstractAnimation::DeleteWhenStopped);
        return;
    }

    ui->change_periods_button->show();
    ui->label_no5->setText("5.Enter the starting time of every\nclass or period");
    // QGridLayout* tds=new QGridLayout;
    tds->setAlignment(Qt::AlignTop);

    std::vector<QLabel*> plabels(periods);
    td.resize(periods);

    for (int i = 0; i < periods; i++) {
        td[i] = new QTimeEdit(this);
        td[i]->setDisplayFormat("hh:mm AP");
        td[i]->setStyleSheet(
            "border: 2px solid black;"
            "border-radius: 5px;"
            "font-size: 15px;"
            "font-weight: 600;"
            "line-height: 1;"
            "padding: 2px 2px;"
            "background: white;"
            "color: black;"
            );
        tds->addWidget(td[i],i,2);
        char buffer[10];
        //sprintf_s(buffer,sizeof(buffer),"Period %d",i+1);
        sprintf(buffer,"Period %d",i+1);
        plabels[i]=new QLabel(this);
        plabels[i]->setText(buffer);
        tds->addWidget(plabels[i],i,1);
    }

    ui->times_scroll->setLayout(tds);
    ui->pushButton->show();
    ui->page1_sideStack->setCurrentIndex(0);
}

void makeroutine::on_Go_backButton_clicked(){
    bool deleted=true;
    if(!last_page_backed) deleted=false;
    bool flag=true;
    while(flag){
        switch(set_progress){
            case 0:
                ui->routuneSetupStack->setCurrentIndex(0);
                for(int i=0;i<periods;i++){
                    delete classDatFetch[i];
                }
                //clearLayout(ui->sunday_stack->layout());
                if(!deleted){
                    delete classStackLayout[0];
                    deleted=!deleted;
                }
                if(last_page_backed) last_page_backed=false;
                flag=!flag;
                break;
            case 1:
                if(chk_sun){//if previous page not allowed
                    set_progress--;
                    if(!deleted){
                        delete classStackLayout[1];
                        deleted=!deleted;
                    }
                    break;
                }
                else{//if previous page is allowed
                    flag=!flag;
                    set_progress--;
                    setupDay();
                    ui->classesStack->setCurrentIndex(0);
                    //clearLayout(ui->monday_stack->layout());
                    if(!deleted){
                        delete classStackLayout[1];
                        deleted=!deleted;
                    }
                    if(last_page_backed) last_page_backed=false;
                    break;
            case 2:
                if(chk_mon){//if previous page not allowed
                    set_progress--;
                    if(!deleted){
                        delete classStackLayout[2];
                        deleted=!deleted;
                    }
                    break;
                }
                else{//if previous page is allowed
                    flag=!flag;
                    set_progress--;
                    ui->classesStack->setCurrentIndex(1);
                    setupDay();
                    //clearLayout(ui->tuesday_stack->layout());
                    if(!deleted){
                        delete classStackLayout[2];
                        deleted=!deleted;
                    }
                    if(last_page_backed) last_page_backed=false;
                    break;
                }
            case 3:
                if(chk_tues){//if previous page not allowed
                    set_progress--;
                    if(!deleted){
                        delete classStackLayout[3];
                        deleted=!deleted;
                    }
                    break;
                }
                else{//if previous page is allowed
                    flag=!flag;
                    set_progress--;
                    ui->classesStack->setCurrentIndex(2);
                    setupDay();
                    //clearLayout(ui->wednesday_stack->layout());
                    if(!deleted){
                        delete classStackLayout[3];
                        deleted=!deleted;
                    }
                    if(last_page_backed) last_page_backed=false;
                    break;
                }
            case 4:
                if(chk_wedn){//if previous page not allowed
                    set_progress--;
                    if(!deleted){
                        delete classStackLayout[4];
                        deleted=!deleted;
                    }
                    break;
                }
                else{//if previous page is allowed
                    flag=!flag;
                    set_progress--;
                    ui->classesStack->setCurrentIndex(3);
                    setupDay();
                    //clearLayout(ui->thrusday_stack->layout());
                    if(!deleted){
                        delete classStackLayout[4];
                        deleted=!deleted;
                    }
                    if(last_page_backed) last_page_backed=false;
                    break;
                }
            case 5:
                if(chk_thu){//if previous page not allowed
                    set_progress--;
                    if(!deleted){
                        delete classStackLayout[5];
                        deleted=!deleted;
                    }
                    break;
                }
                else{//if previous page is allowed
                    flag=!flag;
                    set_progress--;
                    ui->classesStack->setCurrentIndex(4);
                    setupDay();
                    //clearLayout(ui->friday_stack->layout());
                    if(!deleted){
                        delete classStackLayout[5];
                        deleted=!deleted;
                    }
                    if(last_page_backed) last_page_backed=false;
                    break;
                }
            case 6:
                if(chk_fri){//if previous page not allowed
                    set_progress--;
                    if(!deleted){
                        delete classStackLayout[6];
                        deleted=!deleted;
                    }
                    break;
                }
                else{//if previous page is allowed
                    flag=!flag;
                    set_progress--;
                    ui->classesStack->setCurrentIndex(5);
                    setupDay();
                    //clearLayout(ui->saturday_stack->layout());
                    if(!deleted){
                        delete classStackLayout[6];
                        deleted=!deleted;
                    }
                    if(last_page_backed) last_page_backed=false;
                    break;
                }
            }
        }
    }
}


void makeroutine::on_Next_dayButton_clicked(){

    //testing if i can get the data for the dynamically added widgets
    /*
    classDatFetch[0]->get_info();
    qstr str=classDatFetch[0]->class_name;
    qstr str2=classDatFetch[0]->instructor;
    qstr str3=classDatFetch[0]->location;
    qDebug("Got the data from the cell: %s, %s, %s",str.toStdString().c_str(),str2.toStdString().c_str(),str3.toStdString().c_str());
    */


    //Getting the data  on every run of Next_dayButton
    switch(set_progress){
    case 0:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            sun[i].className=classDatFetch[i]->class_name;
            sun[i].Instr=classDatFetch[i]->instructor;
            sun[i].locale=classDatFetch[i]->location;
            if(isEmptyString(sun[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
            qDebug("got the data in next day button: %s, %s, %s",sun[i].className.toStdString().c_str(),sun[i].Instr.toStdString().c_str(),sun[i].locale.toStdString().c_str());
            qDebug("the length of the data got from the cels are: %lld, %lld, %lld\n",sun[i].className.length(),sun[i].Instr.length(),sun[i].locale.length());
        }
        clearClassDats();
        delete classStackLayout[0];
        break;
    case 1:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            mon[i].className=classDatFetch[i]->class_name;
            mon[i].Instr=classDatFetch[i]->instructor;
            mon[i].locale=classDatFetch[i]->location;
            if(isEmptyString(mon[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
            qDebug("got the data in next day button: %s, %s, %s",mon[i].className.toStdString().c_str(),mon[i].Instr.toStdString().c_str(),mon[i].locale.toStdString().c_str());
        }
        clearClassDats();
        delete classStackLayout[1];
        break;
    case 2:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            tue[i].className=classDatFetch[i]->class_name;
            tue[i].Instr=classDatFetch[i]->instructor;
            tue[i].locale=classDatFetch[i]->location;
            if(isEmptyString(tue[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
            qDebug("got the data in next day button: %s, %s, %s",tue[i].className.toStdString().c_str(),tue[i].Instr.toStdString().c_str(),tue[i].locale.toStdString().c_str());
        }
        clearClassDats();
        delete classStackLayout[2];
        break;
    case 3:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            wed[i].className=classDatFetch[i]->class_name;
            wed[i].Instr=classDatFetch[i]->instructor;
            wed[i].locale=classDatFetch[i]->location;
            if(isEmptyString(wed[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
        }
        clearClassDats();
        delete classStackLayout[3];
        break;
    case 4:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            thu[i].className=classDatFetch[i]->class_name;
            thu[i].Instr=classDatFetch[i]->instructor;
            thu[i].locale=classDatFetch[i]->location;
            if(isEmptyString(thu[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
        }
        clearClassDats();
        delete classStackLayout[4];
        break;
    case 5:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            fri[i].className=classDatFetch[i]->class_name;
            fri[i].Instr=classDatFetch[i]->instructor;
            fri[i].locale=classDatFetch[i]->location;
            if(isEmptyString(fri[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
        }
        clearClassDats();
        delete classStackLayout[5];
        break;
    case 6:
        for(int i=0;i<periods;i++){
            classDatFetch[i]->get_info();
            sat[i].className=classDatFetch[i]->class_name;
            sat[i].Instr=classDatFetch[i]->instructor;
            sat[i].locale=classDatFetch[i]->location;
            if(isEmptyString(sat[i].className)){
                classDatFetch[i]->warn();
                qDebug("returning from function");
                return;
            }
        }
        clearClassDats();
        delete classStackLayout[6];
        break;
    }
    set_progress++;
    if(set_progress>=7){

        qDebug("got the datas:\nSunday\n");
        ui->routuneSetupStack->setCurrentIndex(3);
        return;
    }
    qDebug("after pressing next button, setup progress is now:%d",set_progress);
    setupDay();
}

void makeroutine::setupDay(){
    qDebug("in setupDay function, setup progress is now:%d",set_progress);
    bool n=true;
    while(n && set_progress<7){
        //recheck:
        switch(set_progress){

            case 0: if(!chk_sun){
                    ui->classesStack->setCurrentIndex(0);
                    classStackLayout[0]=new QVBoxLayout(this);
                    classStackLayout[0]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[0]->addWidget(classDatFetch[i]);
                    }
                    ui->sunday_stack->setLayout(classStackLayout[0]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    //goto recheck;
                    break;
                }
            case 1: if(!chk_mon){
                    ui->classesStack->setCurrentIndex(1);
                    classStackLayout[1]=new QVBoxLayout(this);
                    classStackLayout[1]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[1]->addWidget(classDatFetch[i]);
                    }
                    ui->monday_stack->setLayout(classStackLayout[1]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    //goto recheck;
                    break;
                }
            case 2: if(!chk_tues){
                    ui->classesStack->setCurrentIndex(2);
                    classStackLayout[2]=new QVBoxLayout(this);
                    classStackLayout[2]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[2]->addWidget(classDatFetch[i]);
                    }
                    ui->tuesday_stack->setLayout(classStackLayout[2]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    //goto recheck;
                    break;
                }
            case 3: if(!chk_wedn){
                    ui->classesStack->setCurrentIndex(3);
                    classStackLayout[3]=new QVBoxLayout(this);
                    classStackLayout[3]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[3]->addWidget(classDatFetch[i]);
                    }
                    ui->wednesday_stack->setLayout(classStackLayout[3]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    //goto recheck;
                    break;
                }
            case 4: if(!chk_thu){
                    ui->classesStack->setCurrentIndex(4);
                    classStackLayout[4]=new QVBoxLayout(this);
                    classStackLayout[4]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[4]->addWidget(classDatFetch[i]);
                    }
                    ui->thrusday_stack->setLayout(classStackLayout[4]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    // recheck;
                    break;
                }
            case 5: if(!chk_fri){
                    ui->classesStack->setCurrentIndex(5);
                    classStackLayout[5]=new QVBoxLayout(this);
                    classStackLayout[5]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[5]->addWidget(classDatFetch[i]);
                    }
                    ui->friday_stack->setLayout(classStackLayout[5]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    //goto recheck;
                    break;
                }
            case 6: if(!chk_sat){
                    ui->classesStack->setCurrentIndex(6);
                    classStackLayout[6]=new QVBoxLayout(this);
                    classStackLayout[6]->setAlignment(Qt::AlignTop);
                    for(int i=0;i<periods;i++){
                        classStackLayout[6]->addWidget(classDatFetch[i]);
                    }
                    ui->saturday_stack->setLayout(classStackLayout[6]);
                    n=!n;
                    break;
                }
                else{
                    set_progress++;
                    ui->routuneSetupStack->setCurrentIndex(3);
                }
        }
    }
}


void makeroutine::on_previous_page_button_clicked()
{
    set_progress=6;
    if(chk_sat){//if previous page not allowed
        last_page_backed=true;
        makeroutine::on_Go_backButton_clicked();
        ui->routuneSetupStack->setCurrentIndex(2);
    }
    else{//if previous page is allowed
        ui->routuneSetupStack->setCurrentIndex(2);
        ui->classesStack->setCurrentIndex(6);
        setupDay();
        //clearLayout(ui->saturday_stack->layout());
    }

}


//Final decision- yes button
void makeroutine::on_pushButton_3_clicked()
{
    qDebug("initial data:\nNo of periods:%d class times:",periods);
    for(int i=0;i<periods;i++){
        qDebug("%s",class_times[i]->toStdString().c_str());
    }
    qDebug("====printing all the obtained data=========\n");
    if(!chk_sun){
        qDebug("printing for sunday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",sun[i].className.toStdString().c_str(),sun[i].Instr.toStdString().c_str(),sun[i].locale.toStdString().c_str());
        }
    }
    if(!chk_mon){
        qDebug("\nPrinting for monday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",mon[i].className.toStdString().c_str(),mon[i].Instr.toStdString().c_str(),mon[i].locale.toStdString().c_str());
        }
    }
    if(!chk_tues){
        qDebug("\nPrinting for tuesday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",tue[i].className.toStdString().c_str(),tue[i].Instr.toStdString().c_str(),tue[i].locale.toStdString().c_str());
        }
    }
    if(!chk_wedn){
        qDebug("\nPrinting for wednesday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",wed[i].className.toStdString().c_str(),wed[i].Instr.toStdString().c_str(),wed[i].locale.toStdString().c_str());
        }
    }
    if(!chk_thu){
        qDebug("\nPrinting for thursday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",thu[i].className.toStdString().c_str(),thu[i].Instr.toStdString().c_str(),thu[i].locale.toStdString().c_str());
        }
    }
    if(!chk_fri){
        qDebug("\nPrinting for friday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",fri[i].className.toStdString().c_str(),fri[i].Instr.toStdString().c_str(),fri[i].locale.toStdString().c_str());
        }
    }
    if(!chk_sat){
        qDebug("\nPrinting for staurday:");
        for(int i=0;i<periods;i++){
            qDebug("got the data in next day button: %s, %s, %s",sat[i].className.toStdString().c_str(),sat[i].Instr.toStdString().c_str(),sat[i].locale.toStdString().c_str());
        }
    }

    saveRoutine();
}


int makeroutine::saveRoutine(){

    char dir[260];
    getAppData_folder(dir);
    char file[260]="routineDat.spenc";
    make_appData_filePath(file);

    if (ensure_directory_and_open_file(dir, file, "w") == 0) {
        printf("File opened successfully.\n");
    } else {
        printf("Failed to open file.\n");
    }

    FILE* fp=fopen(file,"w");
    fprintf(fp,"%d,",periods);
    for(int i=0;i<periods;i++){
        fprintf(fp,"%s,",class_times[i]->toStdString().c_str());
    }
    fprintf(fp,"%s,%s,\n",lunchTime_qsting.toStdString().c_str(),daybreak_qstring.toStdString().c_str());
    fprintf(fp,"%d\n",(chk_fri+chk_mon+chk_sat+chk_sun+chk_thu+chk_tues+chk_wedn));
    fprintf(fp,"%d\n",chk_sun);
    for(int i=0;i<periods;i++){
        if(!chk_sun)
        fprintf(fp,"%s, %s, %s,\n",sun[i].className.toStdString().c_str(),sun[i].Instr.toStdString().c_str(),sun[i].locale.toStdString().c_str());
        else break;
    }
    fprintf(fp,"%d\n",chk_mon);
    for(int i=0;i<periods;i++){
        if(!chk_mon)
            fprintf(fp,"%s, %s, %s,\n",mon[i].className.toStdString().c_str(),mon[i].Instr.toStdString().c_str(),mon[i].locale.toStdString().c_str());
        else break;
    }
    fprintf(fp,"%d\n",chk_tues);
    for(int i=0;i<periods;i++){
        if(!chk_tues)
            fprintf(fp,"%s, %s, %s,\n",tue[i].className.toStdString().c_str(),tue[i].Instr.toStdString().c_str(),tue[i].locale.toStdString().c_str());
        else break;
    }
    fprintf(fp,"%d\n",chk_wedn);
    for(int i=0;i<periods;i++){
        if(!chk_wedn)
            fprintf(fp,"%s, %s, %s,\n",wed[i].className.toStdString().c_str(),wed[i].Instr.toStdString().c_str(),wed[i].locale.toStdString().c_str());
        else break;
    }
    fprintf(fp,"%d\n",chk_thu);
    for(int i=0;i<periods;i++){
        if(!chk_thu)
            fprintf(fp,"%s, %s, %s,\n",thu[i].className.toStdString().c_str(),thu[i].Instr.toStdString().c_str(),thu[i].locale.toStdString().c_str());
        else break;
    }
    fprintf(fp,"%d\n",chk_fri);
    for(int i=0;i<periods;i++){
        if(!chk_fri)
            fprintf(fp,"%s, %s, %s,\n",fri[i].className.toStdString().c_str(),fri[i].Instr.toStdString().c_str(),fri[i].locale.toStdString().c_str());
        else break;
    }
    fprintf(fp,"%d\n",chk_sat);
    for(int i=0;i<periods;i++){
        if(!chk_sat)
            fprintf(fp,"%s, %s, %s,\n",sat[i].className.toStdString().c_str(),sat[i].Instr.toStdString().c_str(),sat[i].locale.toStdString().c_str());
        else break;
    }
    fclose(fp);
    return 0;
}

//================CUSTOM HELPER FUNCTIONS=================================>
//========================================================================>

void makeroutine::qTimeEdit_toC(QString time,int* hour,int* min,char* quad){
    char* arr2=QstrTOarry(time);
    sscanf(arr2,"%d:%d %2s",hour,min,quad);
    delete[] arr2;
}


char* makeroutine::QstrTOarry(QString qstr){
    std::string cpp=qstr.toStdString();
    char* arr=new char[cpp.length()+1];
    strncpy(arr,cpp.c_str(),cpp.length());
    arr[cpp.length()]='\0';
    return arr;
}

void makeroutine::normal_label(){
    ui->label_no5->setStyleSheet(
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"
        "padding: 2px 2px;"
        "background-color: #FFF2D8;"  // Initial background color
        "color: black;"
        );
}



void makeroutine::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();  // Delete the widget
        }
        delete item;  // Delete the layout item
    }
}

bool makeroutine::isEmptyString(QString str){

    if(str.length()==0){
        return true;
    }
    else return false;
}


void makeroutine::clearClassDats(){
    for(int i=0;i<periods;i++){
        classDatFetch[i]->clear_info();
    }
}


