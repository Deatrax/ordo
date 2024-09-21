#include "newbox.h"
#include "materialsnav.h"
#include "ui_newbox.h"
#include "primary_window.h"
#include "StylesSheets.h"

newbox::newbox(primary_window *mainwindow, QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::newbox)
    , m_mainWindow(mainwindow)  // Correct placement of the initializer list
{
    loadThemeFromFile();
    ui->setupUi(this);
    setStyleSheet(islandStyle);
    // Assuming you want to initialize `arr` somewhere here
    // Initialize arr if needed, for example: strcpy(arr, "default");

    // Connecting the button's clicked signal to the slot
    //connect(ui->pushButton, &QPushButton::clicked, this, &newbox::on_pushButton_clicked);
}

void newbox::innit(char *str, char* str2)
{
    ui->course_name->setText(str);
    if(str[strlen(str)-1]=='\n') str[strlen(str)-1]='\0';
    strcpy(arr, str);
    strcpy(courseFolderPath,str2);
}

newbox::~newbox()
{
    delete ui;
}

//this is the open button
void newbox::on_pushButton_clicked()
{
    if(activeTab){
        m_mainWindow->gototab(targTab);
        return;
    }
    targTab=m_mainWindow->addtab(arr, courseFolderPath);
    qDebug("value returned upon opening=%d",activeTab);
    activeTab++;
}
