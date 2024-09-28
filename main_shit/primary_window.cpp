#include "primary_window.h"
#include "FileDropWidget.h"
#include "addtask.h"
#include "newbox.h"
#include "settings_page.h"
#include "ui_primary_window.h"
#include "first_run.h"
#include "upnextelement.h"
#include <iostream>
#include <ostream>
#include <time.h>
#include "makeroutine.h"
#include "materialsnav.h"
#include "browserwindow.h"
#include <QLineEdit>
#include "routinecell.h"
#include "routinetimecell.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include <string.h>
#include "changesemester.h"
#include "StylesSheets.h"
#include <QLabel>
#include <QGroupBox>

//=========GLOBAL VARIABLE SPACE=====>
elinks* MyLink;
courseContainer* corsCont;
newbox** nb;
//===================================>


primary_window::primary_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::primary_window)
{
    loadThemeFromFile();
    ui->setupUi(this);
    loadConfig();
    ui->main_content_stack->setCurrentIndex(0);
    QString QdisplayName=array_toQstr(displayName);
    ui->welcome->setText(" Welcome "+QdisplayName);
    ui->upCommingBackButton->hide();
    setAcceptDrops(true);
    ui->tabWidget_2->removeTab(1);


    // Add custom FileDropWidget to the layout
    QVBoxLayout* layout = new QVBoxLayout;
    FileDropWidget* dropWidget = new FileDropWidget;
    layout->addWidget(dropWidget);
    ui->dropArea->setLayout(layout);


// #ifdef _WIN32
//     ensure_directory_and_open_file()

}

primary_window::~primary_window()
{
    delete ui;
}

int primary_window::loadConfig(){
    //preparing for getting the configs
        char buff[500];
        char file[260]="uconfig.spenc";
        make_appData_filePath(file);
    //open and read the file
        FILE *fp=fopen(file,"rb");
    //getting the display name from line 1 and setting it in UI
        fgets(displayName,127,fp);
        if(displayName[strlen(displayName)-1]=='\n') displayName[strlen(displayName)-1]='\0';
        char profLogo[3];
        sprintf(profLogo,"%c\0",toupper(displayName[0]));
        ui->profile_logo->setText(profLogo);
    //geting the home path of the app for marterials
        fgets(HomePath,255,fp);
        //qstrncpy(HomePath,buff,sizeof(buff));
        if(HomePath[strlen(HomePath)-1]=='\n') HomePath[strlen(HomePath)-2/*this is one of those times when we really wanna ask why it works the way it works*/]='\0';
    //getting the number of semester per year, current year and semester number
        fgets(buff,499,fp);
        char* tok=strtok(buff,",");
        semPerYear=atoi(tok);
        qDebug("got number of sems per year=%d",semPerYear);
        tok=strtok(NULL,",");
        year=tok;
        tok=strtok(NULL,",");
        semester=tok;
        ui->currentYear->setText(year+"-"+semester);
    //testing the homepath and semester path
        qDebug("got the homepath: %s and",HomePath);
        currSemst=(semPerYear*(year.toInt()-1))+semester.toInt();
        #ifdef _WIN32
            qDebug("testing semester path: %sSemester %d\\",HomePath,currSemst);
            sprintf(semesterPath,"%sSemester %d\\",HomePath,currSemst);
            char dummyfilepath[500];
            sprintf(dummyfilepath,"%sSemester %d\\dummyText.txt\0",HomePath,currSemst);
            ensure_directory_and_open_file(semesterPath,dummyfilepath,"w");
            char files[MAX_FILES][MAX_NAME_LEN] = {{0}};
            char folders[MAX_FILES][MAX_NAME_LEN] = {{0}};
            char file_paths[MAX_FILES][MAX_PATH_LEN] = {{0}};
            char folder_paths[MAX_FILES][MAX_PATH_LEN] = {{0}};
            //FileHandleDriver(semesterPath,files,folders,file_paths,folder_paths);
        #elif defined(__APPLE__)
            qDebug("testing semester path: %sSemester %d/",HomePath,currSemst);
            sprintf(semesterPath,"%sSemester %d/",HomePath,currSemst);
            char dummyfilepath[500];
            sprintf(dummyfilepath,"%sSemester %d/dummyText.txt\0",HomePath,currSemst);
            ensure_directory_and_open_file(semesterPath,dummyfilepath,"w");
            char files[MAX_FILES][MAX_NAME_LEN] = {0};
            char folders[MAX_FILES][MAX_NAME_LEN] = {0};
            char file_paths[MAX_FILES][MAX_PATH_LEN] = {0};
            char folder_paths[MAX_FILES][MAX_PATH_LEN] = {0};
            //FileHandleDriver(semesterPath,files,folders,file_paths,folder_paths);
        #endif

        setWindowTitle("Ordo");
        loadMiniRoutine();

    if(fp!=NULL) fclose(fp);
    return 0;
}


void primary_window::loadMiniRoutine(){
    clearLayout(ui->miniRoutineBox->layout());

    int lineNo=0;
    //opening the file
    char file[260]="routineDat.spenc";
    make_appData_filePath(file);
    //this is me testing get_no_of_lines with AppData
    // int lines=get_number_of_lines(file);
    // qDebug("got the number of line:%d",lines);
    FILE* fp=fopen(file,"r");
    if(fp==NULL){
        qDebug("Routine data file does not exist");
        primary_window::makeRoutine();
        return;
    }

    //reading the 1st line containing periods and period times
    char buff[300]="\0";
    fgets(buff,sizeof(buff),fp);
    lineNo++;
    char* tok=strtok(buff,",");
    int periods=atoi(tok);

    //Getting the class times from buff using strtok
    std::vector<classTimeData> timeDat(periods+2);
        //old method: char** timedats=allocate2DArray(periods+2,20);
    qDebug("got the periods:%d+2",periods);
    for(int i=0;i<periods+2;i++){
        tok=strtok(NULL,",");
        // strncpy_s(timedats[i],20,tok,20);
        // qDebug("\t%s",timedats[i]);
        timeDat[i].takeInp(tok);
        qDebug("\t%s",timeDat[i].timeQ.toStdString().c_str());
        if(i==periods) timeDat[i].LunchFlag=1;
        if(i==periods+1) timeDat[i].DayBreak=1;
    }
    //checking the miltime
    for(int i=0;i<periods+2;i++){
        qDebug("corresonding mil time of %s is %d and flag is= lunch:%d,  break:%d",timeDat[i].timeQ.toStdString().c_str(),timeDat[i].milTime,timeDat[i].LunchFlag,timeDat[i].DayBreak);
    }
    //sort  the times
    sortClassTimes(timeDat);

    //get the number of working days from the stored number of weekends and make columns
    fgets(buff,sizeof(buff),fp);
    lineNo++;
    int cols_int=8-atoi(buff);
    qDebug("=====cols_int is:%d\n",cols_int);

    const char* daysOfWeek[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    // Get the current time
    time_t now = time(NULL);

    // Convert it to local time structure
    struct tm *localTime = localtime(&now);

    // Get the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int dayOfWeek = localTime->tm_wday;
    mainCell.resize(periods+2);
    //reading the rest of the data
    //for(int i=0;i<7;i++)
    int i=0;//no of days
    int k=0;//no of cols
    while(k<cols_int-1 && i<7)
    {
        qDebug("at the start of this read iteration, i=%d, k=%d",i,k);
        fgets(buff,sizeof(buff),fp);
        int check=atoi(buff);
        qDebug("got the data: %d",check);
        if(check==1){
            i++;
            continue;
        }

        if(i==dayOfWeek){
            for(int j=0;j<periods+1;j++){
                qDebug("Subiteration: j=%d",j);
                qDebug("this line's time flag is=%d",timeDat[j].LunchFlag);
                if(timeDat[j].LunchFlag){
                    mainCell.at(j)=new routineCell;
                    mainCell.at(j)->initialize("Lunch","","");
                    ui->miniRoutineBox->layout()->addWidget(mainCell.at(j));
                    continue;
                }
                mainCell.at(j)=new routineCell;
                fgets(buff,sizeof(buff),fp);
                char* tok2=strtok(buff,",");
                qDebug("got this:%s",tok2);
                QString buff2=tok2;
                if(buff2=="same" || buff2=="same "){
                    // QSpacerItem* verticalSpacer = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
                    // vbox_cols[i]->addSpacerItem(verticalSpacer);
                    //mainCell.at(j)->setSame();
                    mainCell.at(j)->initialize("Same as\nprevious"," "," ");
                    ui->miniRoutineBox->layout()->addWidget(mainCell.at(j));
                    //mainCell.at(j-1)->peviousOne();
                    continue;
                }
                if(buff2=="free" || buff2=="free " || buff2=="Free " || buff2=="Free"){
                    // QSpacerItem* verticalSpacer = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
                    // vbox_cols[i]->addSpacerItem(verticalSpacer);
                    mainCell.at(j)->setFree();
                    ui->miniRoutineBox->layout()->addWidget(mainCell.at(j));
                    continue;
                }

                tok2=strtok(NULL,",");
                QString buff3=tok2;
                qDebug("got this:%s",tok2);
                tok2=strtok(NULL,",");
                QString buff4=tok2;
                qDebug("got this:%s",tok2);
                mainCell.at(j)->initialize(buff2,buff3,buff4);
                ui->miniRoutineBox->layout()->addWidget(mainCell.at(j));
            }
            break;
        }
        else{
            for(int j=0;j<=periods;j++){
                if(timeDat[j].LunchFlag){
                    continue;
                }
                fgets(buff,sizeof(buff),fp);
            }
        }
        k++;
        i++;
        qDebug("\n====next day====\n");
    }
    fclose(fp);
}








//CHANGING UI PAGES----->

void primary_window::on_home_button_clicked()
{
    ui->main_content_stack->setCurrentIndex(0);
}


void primary_window::on_all_material_button_clicked()
{
    //check if already opened
    ui->main_content_stack->setCurrentIndex(1);
    if(allMaterialsOpened){return;}

    //data file cration failed
    sprintf(coursedatPath,"coursedat%d.spenc",currSemst);
    make_appData_filePath(coursedatPath);
    if(ensure_directory_and_open_file(NULL,coursedatPath,"a")==-1){
        QHBoxLayout* hbl=new QHBoxLayout;
        QLabel* prompt=new QLabel;
        prompt->setText("course data file creation has failed :( \nplease contact dev");
        prompt->setStyleSheet(LabelStyleBorderless);
        prompt->setAlignment(Qt::AlignCenter);
        hbl->addWidget(prompt);
        ui->main_materials_ui->setLayout(hbl);
        return;
    }

    //no course information available
    int nums=get_number_of_lines(coursedatPath);
    qDebug("number of lines in the course file=%d",nums);
    if(nums<1 || nums==-1){
        QHBoxLayout* hbl=new QHBoxLayout;
        QLabel* prompt=new QLabel;
        prompt->setText("Press add to add a course or press settings to get started");
        prompt->setStyleSheet(LabelStyleBorderless);
        prompt->setAlignment(Qt::AlignCenter);
        hbl->addWidget(prompt);
        ui->main_materials_ui->setLayout(hbl);
        return;
    }

    //all checks successfull, procced to ui generation
    layout = new FlowLayout;
    int width = 201;
    int height = 217;

    /*old course fetch and display method
        // char** course_dat=allocate2DArray(nums,256);
        // read_course(course_dat,nums);
        // newbox** nb;
        // nb=(newbox**)malloc(nums*sizeof(newbox));
        // for (int i = 0;i  < nums-1; i++) {
        //     nb[i]=new newbox(this,this);
        //     nb[i]->setFixedWidth(184);
        //     nb[i]->setFixedHeight(243);
        //     nb[i]->settext(course_dat[i+1]);
        //     // Set the stylesheet
        //     //nb->setStyleSheet(style);
        //     layout->addWidget(nb[i]);
        //*/

    corsCont=allocate1DcourseConainer(nums);
    read_course(corsCont,nums,coursedatPath);
    printf("\n=====read ran successfully");

    nb=(newbox**)malloc(nums*sizeof(newbox*));
    if(nb==NULL) return;
    for (int i = 0; i<nums; i++) {
        printf("\ncurrent newbox iteration=%d",i);
        nb[i]=new newbox(this,this);
        printf("\nNewbox created");
        nb[i]->setFixedWidth(184);
        nb[i]->setFixedHeight(243);
        nb[i]->innit(corsCont[i].course_name, corsCont[i].coursePath,(i+1));
        printf("\nnewbox set text is=%s\n\n",corsCont[i].course_name);
        // Set the stylesheet
        //nb->setStyleSheet(style);
        layout->addWidget(nb[i]);
    }

    ui->main_materials_ui->setLayout(layout);
    allMaterialsOpened=true;
    newboxLimit=nums;
    free1DcourseContainer(corsCont);

    /*
       ->course data file path pipeline

        -> all meterials button first make the current course data file courseDat%d.spenc file
        -> then it reads the data in that file and populates 'n' courseContainers corsCont
        -> then it makes 'n' newboxes and initializes them with their individual course name and folder path that was got from the data file earlier

        -> newbox then makes the instance and tab of the course with the folder path

        -> the tab instance object called materialsNav then makes the folder paths of the corresponding folders when their buttons are clicked
        -> then it scans the folder path that it just made to get the files that are in there.
        -> it then adds the n files that were found using cell objects and also passes to them the filepath of the file they each represent

        ->upon clicking the open button in the cells QDesktop serveice opens the file in teh deafault viewer
    */
}



QWidget* primary_window::addtab(QString tabname, char* coursePath )
{
    materialsNav *newtabptr=new materialsNav(this);
    newtabptr->innit(coursePath);
    ui->tabWidget_2->addTab(newtabptr,tabname);
    newtabptr->setAttribute(Qt::WA_DeleteOnClose,true);
    //Add pointer in vector
    //alltabptr.append(newtabptr);
    ui->tabWidget_2->setCurrentIndex(++currentMaterialTabs);
    //return currentMaterialTabs;
    return newtabptr;
}

void primary_window::closeTab(){

    QWidget* currentTab = ui->tabWidget_2->currentWidget();
    int currentIndex= ui->tabWidget_2->indexOf(currentTab);
    ui->tabWidget_2->removeTab(currentIndex);
    qDebug("the current tab materials int is=%d",currentMaterialTabs);
    for(int i=0;i<newboxLimit;i++){
        qDebug("iteration=%d of resetting the newbox system",i);
        if(nb[i]->targTab==currentTab){
            qDebug("nb[%d] was found to have been the box that launched the tab,it has been reset",i);
            nb[i]->activeTab=0;
            nb[i]->targTab=NULL;
            //delete currentTab;
        }
    }
    currentMaterialTabs--;
}

void primary_window::gototab(QWidget* i){
    ui->tabWidget_2->setCurrentWidget(i);
}

//
void primary_window::on_notes_button_clicked()
{
    ui->main_content_stack->setCurrentIndex(2);
}


void primary_window::on_routine_button_clicked()
{
    if(routinePageOpened){
        // ui->main_content_stack->setCurrentIndex(3);
        // return;
        clearLayout2(ui->the_hecking_routine->layout());
    }

    int lineNo=0;
    //opening the file
    char file[260]="routineDat.spenc";
    make_appData_filePath(file);
    //this is me testing get_no_of_lines with AppData
    // int lines=get_number_of_lines(file);
    // qDebug("got the number of line:%d",lines);
    FILE* fp=fopen(file,"r");
    if(fp==NULL){
        qDebug("Routine data file does not exist");
        primary_window::makeRoutine();
        return;
    }

    //reading the 1st line containing periods and period times
    char buff[300]="\0";
    fgets(buff,sizeof(buff),fp);
    lineNo++;
    char* tok=strtok(buff,",");
    int periods=atoi(tok);

    //Getting the class times from buff using strtok
    std::vector<classTimeData> timeDat(periods+2);
        //old method: char** timedats=allocate2DArray(periods+2,20);
    qDebug("got the periods:%d+2",periods);
    for(int i=0;i<periods+2;i++){
        tok=strtok(NULL,",");
        // strncpy_s(timedats[i],20,tok,20);
        // qDebug("\t%s",timedats[i]);
        timeDat[i].takeInp(tok);
        qDebug("\t%s",timeDat[i].timeQ.toStdString().c_str());
        if(i==periods) timeDat[i].LunchFlag=1;
        if(i==periods+1) timeDat[i].DayBreak=1;
    }
    //checking the miltime
    for(int i=0;i<periods+2;i++){
        qDebug("corresonding mil time of %s is %d and flag is= lunch:%d,  break:%d",timeDat[i].timeQ.toStdString().c_str(),timeDat[i].milTime,timeDat[i].LunchFlag,timeDat[i].DayBreak);
    }
    //sort  the times
    sortClassTimes(timeDat);

    //get the number of working days from the stored number of weekends and make columns
    fgets(buff,sizeof(buff),fp);
    lineNo++;
    int cols_int=8-atoi(buff);
    qDebug("=====cols_int is:%d\n",cols_int);

    //get the layout ready from the number of columns obtained
    QHBoxLayout* routine_layout=new QHBoxLayout;
    cols.resize(cols_int);
    vbox_cols.resize(cols_int);
    for(int i=0;i<cols_int;i++){
        cols[i]=new QGroupBox;
        cols[i]->setStyleSheet("border:0px;");
        vbox_cols[i]=new QVBoxLayout;
        vbox_cols[i]->setSpacing(0);
        vbox_cols[i]->setContentsMargins(0,0,0,0);
        cols[i]->setLayout(vbox_cols[i]);
        routine_layout->addWidget(cols[i]);
    }
    //insert the time cells into the time column
    timeCells.resize(periods+1);
    QLabel* timeLabel=new QLabel;
    timeLabel->setText("Times");
    timeLabel->setStyleSheet(
        "border-radius:15px; background-color:#ffebc2;"
        "background-color: #FFFFF0;"
        "color: #0d172a;"
        "border: 0px solid black;"
        //"border-radius: 5px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"/*
        "padding: 5px;"
        "margin: 3px;"*/
        );
    timeLabel->setFixedHeight(20);  // Set the height to 20 pixels
    timeLabel->setAlignment(Qt::AlignCenter);  // Optionally set text alignment
    vbox_cols[0]->addWidget(timeLabel);
    for(int i=0;i<periods+1;i++){
        timeCells[i]=new routineTimeCell;
        timeCells[i]->setCellTime(timeDat[i].timeQ);
        vbox_cols[0]->addWidget(timeCells[i]);
    }

    const char* daysOfWeek[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    // Get the current time
    time_t now = time(NULL);

    // Convert it to local time structure
    struct tm *localTime = localtime(&now);

    // Get the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int dayOfWeek = localTime->tm_wday;
    QSpacerItem* vSpacer[7];
    std::vector<QLabel*> dayLabels(8);
    mainCell.resize((periods+2)*cols_int);
    //reading the rest of the data
    //for(int i=0;i<7;i++)
    int i=0;//no of days
    int k=0;//no of cols
    while(k<cols_int-1 && i<7)
    {
        qDebug("at the start of this read iteration, i=%d, k=%d",i,k);
        fgets(buff,sizeof(buff),fp);
        int check=atoi(buff);
        qDebug("got the data: %d",check);
        if(check==1){
            i++;
            continue;
        }
        dayLabels[i]=new QLabel(this);
        dayLabels[i]->setText(daysOfWeek[i]);
        if(i==dayOfWeek){
            dayLabels[i]->setStyleSheet(
                "border-radius:15px; "
                "background-color: red;"
                "color: #0d172a;"
                "border: 0px solid black;"
                "font-size: 15px;"
                "font-weight: 600;"
                "line-height: 1;"
                );
        }
        else{
            dayLabels[i]->setStyleSheet(
                "border-radius:15px; "
                "background-color:#ffebc2;"
                "background-color: #FFFFF0;"
                "color: #0d172a;"
                "border: 0px solid black;"
                "font-size: 15px;"
                "font-weight: 600;"
                "line-height: 1;"
                );
        }
        dayLabels[i]->setFixedHeight(20);  // Set the height to 20 pixels
        dayLabels[i]->setAlignment(Qt::AlignCenter);  // Optionally set text alignment
        vbox_cols[k+1]->addWidget(dayLabels[i]);
        vSpacer[i]=new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
        vbox_cols[k+1]->addSpacerItem(vSpacer[i]);
        for(int j=0;j<=periods;j++){
            qDebug("Subiteration: j=%d",j);
            qDebug("this line's time flag is=%d",timeDat[j].LunchFlag);
            if(timeDat[j].LunchFlag){
                mainCell.at(k+j)=new routineCell;
                mainCell.at(k+j)->initialize("Lunch","","");
                vbox_cols[k+1]->addWidget(mainCell.at(k+j));
                continue;
            }
            mainCell.at(k+j)=new routineCell;
            fgets(buff,sizeof(buff),fp);
            char* tok2=strtok(buff,",");
            qDebug("got this:%s",tok2);
            QString buff2=tok2;
            if(buff2=="same" || buff2=="same "){
                // QSpacerItem* verticalSpacer = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
                // vbox_cols[i]->addSpacerItem(verticalSpacer);
                mainCell.at(k+j)->setSame();
                vbox_cols[k+1]->addWidget(mainCell.at(k+j));
                mainCell.at(k+j-1)->peviousOne();
                continue;
            }
            if(buff2=="free" || buff2=="free " || buff2=="Free " || buff2=="Free"){
                // QSpacerItem* verticalSpacer = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
                // vbox_cols[i]->addSpacerItem(verticalSpacer);
                mainCell.at(k+j)->setFree();
                vbox_cols[k+1]->addWidget(mainCell.at(k+j));
                continue;
            }

            tok2=strtok(NULL,",");
            QString buff3=tok2;
            qDebug("got this:%s",tok2);
            tok2=strtok(NULL,",");
            QString buff4=tok2;
            qDebug("got this:%s",tok2);
            mainCell.at(k+j)->initialize(buff2,buff3,buff4);
            vbox_cols[k+1]->addWidget(mainCell.at(k+j));
        }
        k++;
        i++;
        qDebug("\n====next day====\n");
    }

    ui->the_hecking_routine->setLayout(routine_layout);
    ui->main_content_stack->setCurrentIndex(3);
    fclose(fp);
    routinePageOpened=true;

    //ui->tuesday1->setStyleSheet("background:rgb(255, 106, 100);border-bottom-left-radius: 10px; border-bottom-right-radius: 10px;");
    //ui->friday7->setStyleSheet("QGroupBox{background:rgb(212, 255, 250);border-radius: 10px;border: 1px solid black;}");
    // char dat[30][4][512];
    // int ret=getRoutine(dat);
    // for (int i = 0; i < 30; i++)
    // {
    //     printf("New class: ");
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf(" %s",dat[i][j]);
    //     }
    //     printf("\n");
    // }

    // routine thing[30];
    // int ret=getRoutine(thing);

    // for (int i = 0; i < 30; i++)
    // {
    //     printf("class %d: %s duration:%d teacher:%s room:%s \n",i+1,thing[i].name,thing[i].dura,thing[i].teacher,thing[i].room);
    // }


}


void primary_window::on_up_coming_button_clicked()
{
    ui->main_content_stack->setCurrentIndex(4);
    clearLayout(ui->upNextArea->layout());
    upcommingMode=1;
    ui->upCommingChangeButton->show();
    ui->upCommingBackButton->hide();


    time_t current_time;
    struct tm *time_info;
    // Get current time
    current_time = time(NULL);
    // Convert time to a human-readable format
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    // Extract month (0-indexed) and add 1 to get 1-based month
    int month = time_info->tm_mon + 1;

    int year = time_info->tm_year + 1900;

    char file[260]="upcoming.md";
    make_appData_filePath(file);
    FILE *sf=fopen(file,"rb");
    if(sf==NULL){
        upnextElement *upnxt=new upnextElement(this);
        ui->upNextArea->layout()->addWidget(upnxt);
        upnxt->settextName("No data found!\n Add using the button above...");
        if(sf!=NULL) fclose(sf);
    }
    else{
        if(sf!=NULL) fclose(sf);
        int num=get_number_of_lines(file);
        int skip=0;
        printf("got no of lines:%d\n",num);
        upcoming* thing = allocate1Dupcoming(num);
        int ret=gettasks(thing,&skip);
        
        unxt.resize(num);
        printf("\n no of lines skiped:%d\n",skip);
        for (int i = 0; i < num; i++)
        {
            if(thing[i].year>=year && (thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month))){
                printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                unxt[i]=new upnextElement(this);
                unxt[i]->settextName(thing[i].name);
                unxt[i]->settextType(thing[i].type);
                unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                unxt[i]->settextRem(thing[i].time);
                unxt[i]->sourceLine=thing[i].lineNum;
                ui->upNextArea->layout()->addWidget(unxt[i]);
            }

        }
        free1Dupcoming(thing);
    }

    ui->upNextArea->layout()->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));

}


void primary_window::on_assignments_button_clicked()
{
    ui->main_content_stack->setCurrentIndex(5);
    ui->main_content_stack->setCurrentIndex(4);
    clearLayout(ui->upNextArea->layout());
    upcommingMode=2;



    time_t current_time;
    struct tm *time_info;
    // Get current time
    current_time = time(NULL);
    // Convert time to a human-readable format
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    // Extract month (0-indexed) and add 1 to get 1-based month
    int month = time_info->tm_mon + 1;

    FILE *sf=fopen("upcoming.md","rb");
    if(sf==NULL){
        upnextElement *upnxt=new upnextElement(this);
        ui->upNextArea->layout()->addWidget(upnxt);

        upnxt->settextName("No data found!\n Add using the button above...");
        if(sf!=NULL) fclose(sf);
    }
    else{
        if(sf!=NULL) fclose(sf);
        int num=get_number_of_lines("upcoming.md");
        int skip=0;
        printf("got no of lines:%d\n",num);
        upcoming* thing = allocate1Dupcoming(num);
        int ret=gettasks(thing,&skip);

        std::vector<upnextElement*> unxt(num);
        printf("\n no of lines skiped:%d\n",skip);
        for (int i = 0; i < num; i++)
        {
            if((thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month)) && strcmp(thing[i].type,"assignment")==0){
                printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                unxt[i]=new upnextElement(this);
                unxt[i]->settextName(thing[i].name);
                unxt[i]->settextType(thing[i].type);
                unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                unxt[i]->settextRem(thing[i].time);
                ui->upNextArea->layout()->addWidget(unxt[i]);
            }

        }
        free1Dupcoming(thing);
    }

    ui->upNextArea->layout()->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));


}


void primary_window::on_google_drive_button_clicked()
{
    ui->link_list->clear();
    ui->main_content_stack->setCurrentIndex(6);
    char file[260]="linkdat.spenc";
    make_appData_filePath(file);
    nums_drive=get_number_of_lines(file);
    MyLink=allocate1D_elink(nums_drive);
    New_readLinks(MyLink,nums_drive);
    ui->current_link->setText("Status: All ok");
    // ui->link_list->addItem(dat[1]);

    // // Add some items to the QListWidget
    // ui->link_list->addItem("youtube.com");
    // ui->link_list->addItem("behance.net");
    // ui->link_list->addItem("mikiyakobayashi.com");

    for (int i = 0; i < nums_drive-1; i++) {

        ui->link_list->addItem(MyLink[i].link_name);
    }
    // Set the stylesheet
    ui->link_list->setStyleSheet(
        "QListWidget {"
        "   font-size: 15px;"
        //"   font-weight: 200;"
        "}"
        "QListWidget::item {"
        "   background-color: #FFFFF0;"
        "   color: #0d172a;"
        "   border: 0px solid black;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   margin: 3px;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: #06A77D;"
        "   color: white;"
        "   border: 1px solid black;"
        "}"
        );
}

//this is the go link button
void primary_window::on_pushButton_5_clicked()
{

    int indx=ui->link_list->currentRow();
    if(indx==-1){
        ui->current_link->setText("Please select a link first");
        return;
    }
    obj=new browserWindow(this);
    connect(obj, &browserWindow::destroyed, this, &primary_window::deleteBrowserInstance);


    //dat[1][strcspn(dat[1], "\n")] = '\0';

    QString url =MyLink[indx].mlink;

    obj->a->load(QUrl::fromUserInput(url));
    obj->show();

}

void primary_window::deleteBrowserInstance()
{
    qDebug("does this work??\n");
    delete obj;
}

//this is change link button
void primary_window::on_pushButton_9_clicked()
{
    if(ui->current_link->text().isEmpty() || ui->link_name->text().isEmpty()){
        ui->current_link->setText("Please fill in the fields");
        return;
    }
    int indx=ui->link_list->currentRow();
    qDebug("the current index is: %d",indx);
    if(indx==-1){
        ui->current_link->setText("Please select a link first");
        return;
    }

    QString link=ui->linkIn->text();
    QString link_nam=ui->link_name->text();

    std::string lnk = link_nam.toUtf8().constData();
    lnk += ","; // Add the comma separator
    lnk += link.toUtf8().constData(); // Append the second string
    char* linkk=allocate1DCharArray(lnk.length()+3);
    strncpy(linkk,lnk.c_str(),lnk.length());
    linkk[lnk.length()]='\0';//get rid of garbage data

    char file[260]="linkdat.spenc";
    make_appData_filePath(file);
    int retn=replaceLINE(file,indx+2,linkk);
    free1DCharArray(linkk);
    on_google_drive_button_clicked(); //refresh page to reflect changes

    if(retn==0) ui->current_link->setText("Link Changed successfully!!");
    else ui->current_link->setText("Link change failed!!");
}

void primary_window::on_addLinkButton_clicked()
{
    if(ui->current_link->text().isEmpty() || ui->link_name->text().isEmpty()){
        ui->current_link->setText("Please fill in the fields");
        return;
    }
    int indx=ui->link_list->currentRow();
    qDebug("the current index is: %d",indx);

    QString link=ui->linkIn->text();
    QString link_nam=ui->link_name->text();

    std::string lnk = link_nam.toUtf8().constData();
    lnk += ","; // Add the comma separator
    lnk += link.toUtf8().constData(); // Append the second string
    char* linkk=allocate1DCharArray(lnk.length()+3);
    strncpy(linkk,lnk.c_str(),lnk.length());
    linkk[lnk.length()]='\0';//get rid of garbage data

    char flnam[500]="linkdat.spenc";
    make_appData_filePath(flnam);
    if(indx==-1){
        indx=get_number_of_lines(flnam)+1;
    }
    else indx=indx+2;
    int retn=addLine(flnam,indx,linkk);
    free1DCharArray(linkk);

    on_google_drive_button_clicked(); //refresh page to reflect changes

    if(retn==0) ui->current_link->setText("Link Added successfully!!");
    else ui->current_link->setText("Link add failed!!");
}

void primary_window::on_removeLink_button_clicked()
{
    int indx=ui->link_list->currentRow();
    if(indx==-1){
        ui->current_link->setText("Please select a link first");
        return;
    }
    char file[260]="linkdat.spenc";
    make_appData_filePath(file);
    int retn=removeLine(file,indx+2);

    on_google_drive_button_clicked(); //refresh page to reflect changes
    if(retn==0) ui->current_link->setText("Link Added successfully!!");
    else ui->current_link->setText("Link add failed!!");
}

void primary_window::on_exams_button_clicked()
{
    ui->main_content_stack->setCurrentIndex(8);
    ui->main_content_stack->setCurrentIndex(5);
    ui->main_content_stack->setCurrentIndex(4);
    clearLayout(ui->upNextArea->layout());
    upcommingMode=3;



    time_t current_time;
    struct tm *time_info;
    // Get current time
    current_time = time(NULL);
    // Convert time to a human-readable format
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    // Extract month (0-indexed) and add 1 to get 1-based month
    int month = time_info->tm_mon + 1;

    FILE *sf=fopen("upcoming.md","rb");
    if(sf==NULL){
        upnextElement *upnxt=new upnextElement(this);
        ui->upNextArea->layout()->addWidget(upnxt);
        upnxt->settextName("No data found!\n Add using the button above...");
        if(sf!=NULL) fclose(sf);
    }
    else{
        if(sf!=NULL) fclose(sf);
        int num=get_number_of_lines("upcoming.md");
        int skip=0;
        printf("got no of lines:%d\n",num);
        upcoming* thing = allocate1Dupcoming(num);
        int ret=gettasks(thing,&skip);

        std::vector<upnextElement*> unxt(num);
        printf("\n no of lines skiped:%d\n",skip);
        for (int i = 0; i < num; i++)
        {
            if((thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month)) && strcmp(thing[i].type,"exam")==0){
                printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                unxt[i]=new upnextElement(this);
                unxt[i]->settextName(thing[i].name);
                unxt[i]->settextType(thing[i].type);
                unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                unxt[i]->settextRem(thing[i].time);
                ui->upNextArea->layout()->addWidget(unxt[i]);
            }

        }

    }

    ui->upNextArea->layout()->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));
}


void primary_window::on_settings_button_clicked()
{
    settings_page* setp=new settings_page(this);

    setp->show();
    ui->main_content_stack->setCurrentIndex(7);

}

//END OF PAGE CHANGING----->


void primary_window::refreshCurrentPage(){
    on_upCommingBackButton_clicked();
}

void primary_window::on_changeRoutine_clicked()
{
    routinePageOpened=false;
    makeroutine *diag=new makeroutine(this);
    diag->show();
}


void primary_window::makeRoutine(){

    makeroutine* window=new makeroutine(this);
    window->show();
}

QString primary_window::array_toQstr(char *ar)
{
    std::string str2=ar;
    QString qstr2;
    qstr2= QString:: fromStdString(str2);

    return qstr2;
}



/// Function to set text of all child QLabels in a QGroupBox to blank
void primary_window::clearAllLabelsInGroupBox(QGroupBox *groupBox) {
    if (groupBox) {
        QList<QLabel *> labels = groupBox->findChildren<QLabel *>();
        for (QLabel *label : labels) {
            label->setText("");
        }
    }
}

/// for deleting only layout with child widgets but no child layout
void primary_window::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();  // Delete the widget
        }
        delete item;  // Delete the layout item
    }
}

/// for deleting target layout with child layouts
void primary_window::clearLayout2(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();  // Delete the widget
        }
        if (item->layout()) {
            clearLayout(item->layout());  // Recursively delete child layouts
        }
        delete item;  // Delete the layout item itself
    }
    delete layout;  // Delete the layout
}

void primary_window::on_addTaskButton_clicked()
{
    addTask *nun=new addTask(this);
    nun->show();
}


void primary_window::on_upCommingChangeButton_clicked()
{
    // size_t limit=unxt.size();
    // for(int i=0;i<5;i++){
    //     //unxt.at(i)->allowChange();
    // }

    ui->main_content_stack->setCurrentIndex(4);
    clearLayout(ui->upNextArea->layout());




    time_t current_time;
    struct tm *time_info;
    // Get current time
    current_time = time(NULL);
    // Convert time to a human-readable format
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    // Extract month (0-indexed) and add 1 to get 1-based month
    int month = time_info->tm_mon + 1;

    int year = time_info->tm_year + 1900;

    char file[260]="upcoming.md";
    make_appData_filePath(file);
    FILE *sf=fopen(file,"rb");
    if(sf==NULL){
        upnextElement *upnxt=new upnextElement(this);
        ui->upNextArea->layout()->addWidget(upnxt);
        upnxt->settextName("No data found!\n Add using the button above...");
        if(sf!=NULL) fclose(sf);
    }
    else{
        if(sf!=NULL) fclose(sf);
        int num=get_number_of_lines(file);
        int skip=0;
        printf("got no of lines:%d\n",num);
        upcoming* thing = allocate1Dupcoming(num);
        int ret=gettasks(thing,&skip);

        unxt.resize(num);
        printf("\n no of lines skiped:%d\n",skip);
        switch(upcommingMode){
            case 1:
                for (int i = 0; i < num; i++)
                {
                    if(thing[i].year>=year && (thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month))){
                        printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                        unxt[i]=new upnextElement(this);
                        unxt[i]->settextName(thing[i].name);
                        unxt[i]->settextType(thing[i].type);
                        unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                        unxt[i]->settextRem(thing[i].time);
                        unxt[i]->sourceLine=thing[i].lineNum;
                        unxt[i]->allowChange();
                        ui->upNextArea->layout()->addWidget(unxt[i]);
                    }
                }
                break;
            case 2:
                for (int i = 0; i < num; i++)
                {
                    if((thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month)) && strcmp(thing[i].type,"assignment")==0){
                        printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                        unxt[i]=new upnextElement(this);
                        unxt[i]->settextName(thing[i].name);
                        unxt[i]->settextType(thing[i].type);
                        unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                        unxt[i]->settextRem(thing[i].time);
                        unxt[i]->allowChange();
                        ui->upNextArea->layout()->addWidget(unxt[i]);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < num; i++)
                {
                    if((thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month)) && strcmp(thing[i].type,"exam")==0){
                        printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                        unxt[i]=new upnextElement(this);
                        unxt[i]->settextName(thing[i].name);
                        unxt[i]->settextType(thing[i].type);
                        unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                        unxt[i]->settextRem(thing[i].time);
                        unxt[i]->allowChange();
                        ui->upNextArea->layout()->addWidget(unxt[i]);
                    }
                }
                break;
        }
        free1Dupcoming(thing);
    }
    ui->upCommingChangeButton->hide();
    ui->upCommingBackButton->show();
    ui->upNextArea->layout()->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));


}

void primary_window::on_upCommingExtraButton_clicked()
{

    //void openPDF(const QString &filePath) {
    QString filePath="C:/Users/PC/Downloads/routine-sec-1.pdf";
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    //}
}


void primary_window::on_upCommingBackButton_clicked()
{
    ui->main_content_stack->setCurrentIndex(4);
    clearLayout(ui->upNextArea->layout());




    time_t current_time;
    struct tm *time_info;
    // Get current time
    current_time = time(NULL);
    // Convert time to a human-readable format
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    // Extract month (0-indexed) and add 1 to get 1-based month
    int month = time_info->tm_mon + 1;

    int year = time_info->tm_year + 1900;

    char file[260]="upcoming.md";
    make_appData_filePath(file);
    FILE *sf=fopen(file,"rb");
    if(sf==NULL){
        upnextElement *upnxt=new upnextElement(this);
        ui->upNextArea->layout()->addWidget(upnxt);
        upnxt->settextName("No data found!\n Add using the button above...");
        if(sf!=NULL) fclose(sf);
    }
    else{
        if(sf!=NULL) fclose(sf);
        int num=get_number_of_lines(file);
        int skip=0;
        printf("got no of lines:%d\n",num);
        upcoming* thing = allocate1Dupcoming(num);
        int ret=gettasks(thing,&skip);

        unxt.resize(num);
        printf("\n no of lines skiped:%d\n",skip);
        switch(upcommingMode){
        case 1:
            for (int i = 0; i < num; i++)
            {
                if(thing[i].year>=year && (thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month))){
                    printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                    unxt[i]=new upnextElement(this);
                    unxt[i]->settextName(thing[i].name);
                    unxt[i]->settextType(thing[i].type);
                    unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                    unxt[i]->settextRem(thing[i].time);
                    unxt[i]->sourceLine=thing[i].lineNum;
                    ui->upNextArea->layout()->addWidget(unxt[i]);
                }
            }
            break;
        case 2:
            for (int i = 0; i < num; i++)
            {
                if((thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month)) && strcmp(thing[i].type,"assignment")==0){
                    printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                    unxt[i]=new upnextElement(this);
                    unxt[i]->settextName(thing[i].name);
                    unxt[i]->settextType(thing[i].type);
                    unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                    unxt[i]->settextRem(thing[i].time);
                    ui->upNextArea->layout()->addWidget(unxt[i]);
                }
            }
            break;
        case 3:
            for (int i = 0; i < num; i++)
            {
                if((thing[i].month>month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month)) && strcmp(thing[i].type,"exam")==0){
                    printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
                    unxt[i]=new upnextElement(this);
                    unxt[i]->settextName(thing[i].name);
                    unxt[i]->settextType(thing[i].type);
                    unxt[i]->settextDeadL(thing[i].date,thing[i].month,thing[i].year);
                    unxt[i]->settextRem(thing[i].time);
                    ui->upNextArea->layout()->addWidget(unxt[i]);
                }
            }
            break;
        }
        free1Dupcoming(thing);
    }
    ui->upCommingChangeButton->show();
    ui->upCommingBackButton->hide();
    ui->upNextArea->layout()->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));
}


void primary_window::on_updateSemesterButton_clicked()
{
    ChangeSemester* inst=new ChangeSemester;
    inst->show();
}


void primary_window::on_addCourseButton_clicked()
{
    ChangeSemester* inst=new ChangeSemester;
    inst->setToAdd();
    //strncpy(inst->coursePath,coursePath,sizeof(coursePath));
    strncpy(inst->semesterPath,semesterPath,strlen(semesterPath)+2);
    inst->semesterPath[strlen(semesterPath)+1]='\0';
    strncpy(inst->coursedatPath,coursedatPath,strlen(coursedatPath)+1);
    inst->coursedatPath[strlen(coursedatPath)+1]='\0';
    // Disable the main window
    this->setEnabled(false);

    // Connect to the windowClosed signal
    connect(inst, &ChangeSemester::windowClosed, this, [=]() {
        this->setEnabled(true);
        resetFlag(1);
        on_all_material_button_clicked();
    });

    inst->show();
}

///
/// \brief primary_window::resetFlag resets the skip ui generation flag for the selected page
/// \param flag 1 for materials, 2 for routine, 3 for external links, 4 for assignemnt, 5 for upcomming, 6 for exams
///
void primary_window::resetFlag(int flag){
    switch(flag){
    case 1:allMaterialsOpened=false;
        clearLayout(layout);
        delete layout;
        break;
    case 2:routinePageOpened=false;
        break;
    case 3:browserPageOpened=false;
        break;
    case 4:assginmentPageOpened=false;
        break;
    case 5:upcommingOpened=false;
        break;
    case 6:examsOpened=false;
        break;
    }
}

QGroupBox* primary_window::formaterialsTabs(){
    ui->allMaterialsPageTopBar->hide();
    return ui->allMaterialsPageTopBar;
}

void primary_window::on_tabWidget_2_currentChanged(int index)
{
    if(ui->tabWidget_2->currentIndex()==0){
        ui->allMaterialsPageTopBar->show();
    }
    else{
        ui->allMaterialsPageTopBar->hide();
    }
}

