#include "changesemester.h"
#include "ui_changesemester.h"
#include "StylesSheets.h"


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
    QString buff=ui->newCourseName_LE->text();
    char arr[21]={0};
    snprintf(arr,buff.length()+1,"%s",buff.toStdString().c_str());
    //strncpy(arr,buff.toStdString().c_str(),buff.length());

#ifdef _WIN32
    sprintf(coursePath,"%s%s\\",semesterPath,arr);
#elif defined(__APPLE__)
    sprintf(coursePath,"%s%s/",semesterPath,arr);
#endif
    qDebug("the course name is %s\npath is=%s",buff.toStdString().c_str(),coursePath);
    QString output=buff+","+coursePath+",";
    char* arr2=allocate1DCharArray(output.length()+1);
    snprintf(arr2,output.length(),"%s\0",output.toStdString().c_str()); //adding the null terminator
    addLine(coursedatPath,-1,arr2);
    ensure_directory_and_open_file(coursePath,NULL,"a");
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
