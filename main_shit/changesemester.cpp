#include "changesemester.h"
#include "ui_changesemester.h"
#include "StylesSheets.h"
#include <QFileDialog>
#include <iostream>

ChangeSemester::ChangeSemester(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChangeSemester)
{
    loadThemeFromFile();
    ui->setupUi(this);
    setStyleSheet(elementsStyle);
    ui->saveCourseButton->setStyleSheet(buttonStyle);
    ui->AddCourseCentreBox->setStyleSheet(islandStyle);
    ui->newCourseName_LE->setStyleSheet(LabelStyleBordered);
    ui->addFolderButton->setStyleSheet(buttonStyle);
}

ChangeSemester::~ChangeSemester()
{
    delete ui;
}

void ChangeSemester::setToAdd(){
    ui->PageNo->setCurrentIndex(1);
}

void ChangeSemester::on_saveCourseButton_clicked()
{
    //check if user want to add existing folder
    if(customFolderadded==true){
        customFolderFunction();
        return;
    }

    //get the course name from the line edit
    QString buff=ui->newCourseName_LE->text();
    char arr[21]={0};
    snprintf(arr,buff.length()+1,"%s",buff.toStdString().c_str());
    //strncpy(arr,buff.toStdString().c_str(),buff.length());

    //make the course path
#ifdef _WIN32
    sprintf(coursePath,"%s%s\\",semesterPath,arr);
#elif defined(__APPLE__)
    sprintf(coursePath,"%s%s/",semesterPath,arr);
#endif

    //add the course name and the course path to the data file and call ensure to make the directory
    qDebug("the course name is %s\npath is=%s",buff.toStdString().c_str(),coursePath);
    QString output=buff+","+coursePath+",";
    char* arr2=allocate1DCharArray(output.length()+1);
    snprintf(arr2,output.length(),"%s\0",output.toStdString().c_str()); //adding the null terminator
    addLine(coursedatPath,-1,arr2);
    ensure_directory_and_open_file(coursePath,NULL,"a");

    //make the subdictories notes, books, slides
    char subdir[1000]={0};
#ifdef _WIN32
    snprintf(subdir,999,"%snotes\\\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%sslides\\\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%sbooks\\\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
#elif defined(__APPLE__)
    snprintf(subdir,999,"%snotes/\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%sslides/\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%sbooks/\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
#endif
    free(arr2);
    close();
    //addLine(coursePath,-1,arr);
}

#include <QCloseEvent>

void ChangeSemester::closeEvent(QCloseEvent *event) {
    emit windowClosed();  // Emit the signal when the window is closed
    QMainWindow::closeEvent(event);  // Call the base class implementation
}

void ChangeSemester::on_addFolderButton_clicked()
{
    customFolder=selectDirectory();
    if(customFolder==""){
        customFolderadded=false;
    }
    else{
        customFolderadded=true;
         ui->customFolderMsg->setText("Custom folder added\n If the subfolders dosen't\n then they will be created ");
    }
}


void ChangeSemester::customFolderFunction(){
    QString buff=ui->newCourseName_LE->text();
    char courseName[21]={0};
    snprintf(courseName,buff.length()+1,"%s",buff.toStdString().c_str());
    //strncpy(arr,buff.toStdString().c_str(),buff.length());
    std::string output=courseName;
    output+=","+customFolder+"/";
    char* arr2=allocate1DCharArray(output.length()+4);
    snprintf(arr2,(output.length()+1),"%s\0",output.c_str()); //adding the null terminator
    addLine(coursedatPath,-1,arr2);
    free1DCharArray(arr2);
    char subdir[1000]={0};
    snprintf(subdir,999,"%s/notes/\0",customFolder.c_str());
    qDebug("sub dir was=%s",subdir);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%s/slides/\0",customFolder.c_str());
    qDebug("sub dir was=%s",subdir);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%s/books/\0",customFolder.c_str());
    qDebug("sub dir was=%s",subdir);
    ensure_directory_and_open_file(subdir,NULL,"a");
    close();
}


std::string ChangeSemester::selectDirectory() {
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
