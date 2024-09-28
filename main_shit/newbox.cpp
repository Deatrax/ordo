#include "newbox.h"
#include "materialsnav.h"
#include "ui_newbox.h"
#include "primary_window.h"
#include "StylesSheets.h"
#include "first_run.h"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>

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

void newbox::innit(char *courseName, char* str2,int lineNo)
{
    ui->course_name->setText(courseName);
    if(courseName[strlen(courseName)-1]=='\n') courseName[strlen(courseName)-1]='\0';
    strcpy(arr, courseName);
    strcpy(courseFolderPath,str2);
    lineNum=lineNo;
    if(!directoryExists(courseFolderPath)){
        dirrExists=false;
        ui->pushButton->setText("Repair");

    }
    else{
        dirrExists=true;
        ui->errMsg->hide();
    }
}

newbox::~newbox()
{
    delete ui;
}

//this is the open button
void newbox::on_pushButton_clicked()
{
    if(!dirrExists){
        std::string newpath=selectDirectory();
        qDebug("got the new file path=%s",newpath.c_str());
        std::string output;
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "Confirmation", "Do you want to change the course name according to the name of the folder as well?",
                                      QMessageBox::Yes | QMessageBox::No);

        // Check the user's response and execute code accordingly
        if (reply == QMessageBox::Yes) {
            // Code to execute if "Yes" is clicked
            std::cout << "User clicked Yes!" << std::endl;
            output=getFolderName(newpath);
        } else {
            // Code to execute if "No" is clicked
            std::cout << "User clicked No!" << std::endl;
            output=arr;
        }

        output+=","+newpath+"/";
        qDebug("got the new course data=%s || and the line number is=%d",output.c_str(),lineNum);
        m_mainWindow->updateCourse(output,lineNum);
        return;
    }

    if(activeTab){
        m_mainWindow->gototab(targTab);
        return;
    }
    targTab=m_mainWindow->addtab(arr, courseFolderPath);
    qDebug("value returned upon opening=%d",activeTab);
    activeTab++;
}



std::string newbox::selectDirectory() {
    // Open a QFileDialog to select a directory
    QString dirPath = QFileDialog::getExistingDirectory(
        nullptr,
        "Select Directory",
        "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );

    // Check if a valid directory is selected
    if (dirPath.isEmpty()) {
        std::cerr << "No directory selected!" << std::endl;
        return "";
    }

    // Convert QString to std::string
    std::string directory = dirPath.toStdString();
    return directory;
}

#include <QFileInfo>
#include <QDir>

std::string newbox::getFolderName(const std::string& folderPath) {
    // Convert std::string to QString
    QString qFolderPath = QString::fromStdString(folderPath);

    // Use QFileInfo to extract the folder name
    QFileInfo folderInfo(qFolderPath);

    // Return the folder name using the fileName() method (last component of the path)
    QString folderName = folderInfo.fileName();

    return folderName.toStdString();  // Convert QString to std::string
}
