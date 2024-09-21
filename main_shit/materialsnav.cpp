#include "materialsnav.h"
#include "qfileinfo.h"
#include "ui_materialsnav.h"
#include <QDir>
#include <QFileDialog>

materialsNav::materialsNav(primary_window *mainwindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::materialsNav)
    , m_mainWindow(mainwindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->addFileButton->hide();

}

materialsNav::~materialsNav()
{
    delete ui;
}


/*    snprintf(subdir,999,"%snotes\\\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%sslides\\\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
    snprintf(subdir,999,"%sbooks\\\0",coursePath);
    ensure_directory_and_open_file(subdir,NULL,"a");
*/


void materialsNav::on_closetab_clicked()
{
    m_mainWindow->closeTab();
}

void materialsNav::innit(char *str){
    snprintf(coursePath,649,"%s\0",str);
    ui->scrollAreaWidgetContents->layout()->setAlignment(Qt::AlignTop);
    //FileHandleDriver(coursePath,courseMaterial_files,courseMaterial_folders,courseMaterial_file_paths,courseMaterial_folder_paths);
}

void materialsNav::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}


void materialsNav::on_subNotesButton_clicked()
{

#ifdef _WIN32
    snprintf(subdir,999,"%snotes\\\0",coursePath);
    qDebug("the file path is:=%s",subdir);
#elif defined(__APPLE__)
    snprintf(subdir,999,"%snotes/\0",coursePath);
#endif
    FileHandleDriver(subdir,courseMaterial_files,courseMaterial_folders,courseMaterial_file_paths,courseMaterial_folder_paths,&fileCount,&folderCount);
    printf("\n-----Files:\n");
    navcell.resize(fileCount);
    //alphaBsort()
    for (int i = 0; i < MAX_FILES && courseMaterial_files[i][0] != '\0'; i++) {
        navcell[i]=new materialNavCell(this);
        navcell[i]->innit(courseMaterial_files[i],courseMaterial_file_paths[i]);
        ui->scrollAreaWidgetContents->layout()->addWidget(navcell[i]);
    }
    ui->stackedWidget->setCurrentIndex(1);
    ui->addFileButton->show();
    lastopened=1;
}


void materialsNav::on_subBooksButton_clicked()
{

#ifdef _WIN32
    snprintf(subdir,999,"%sbooks\\\0",coursePath);
    qDebug("the file path is:=%s",subdir);
#elif defined(__APPLE__)
    snprintf(subdir,999,"%sbooks/\0",coursePath);
#endif
    FileHandleDriver(subdir,courseMaterial_files,courseMaterial_folders,courseMaterial_file_paths,courseMaterial_folder_paths,&fileCount,&folderCount);
    printf("\n-----Files:\n");
    navcell.resize(fileCount);
    //alphaBsort()
    for (int i = 0; i < MAX_FILES && courseMaterial_files[i][0] != '\0'; i++) {
        navcell[i]=new materialNavCell(this);
        navcell[i]->innit(courseMaterial_files[i],courseMaterial_file_paths[i]);
        ui->scrollAreaWidgetContents->layout()->addWidget(navcell[i]);
    }
    ui->stackedWidget->setCurrentIndex(1);
    ui->addFileButton->show();
    // QGroupBox* firstgb=m_mainWindow->formaterialsTabs();
    // animateExpansion(firstgb,ui->scrollAreaWidgetContents);
    lastopened=2;
}


void materialsNav::on_subSlidesButton_clicked()
{

#ifdef _WIN32
    snprintf(subdir,999,"%sslides\\\0",coursePath);
    qDebug("the file path is:=%s",subdir);
#elif defined(__APPLE__)
    snprintf(subdir,999,"%sslides/\0",coursePath);
#endif
    FileHandleDriver(subdir,courseMaterial_files,courseMaterial_folders,courseMaterial_file_paths,courseMaterial_folder_paths,&fileCount,&folderCount);
    printf("\n-----Files:\n");
    qDebug("file count is=%d",fileCount);
    navcell.resize(fileCount);
    //alphaBsort()
    for (int i = 0; i < MAX_FILES && courseMaterial_files[i][0] != '\0'; i++) {
        navcell[i]=new materialNavCell(this);
        navcell[i]->innit(courseMaterial_files[i],courseMaterial_file_paths[i]);
        ui->scrollAreaWidgetContents->layout()->addWidget(navcell[i]);
    }
    ui->stackedWidget->setCurrentIndex(1);
    ui->addFileButton->show();
    lastopened=3;
}


void materialsNav::on_OtherButton_clicked()
{

}


void materialsNav::on_NavVIewButton_clicked()
{

}

void materialsNav::addCell(char filename[],char filepath[]){
    // materialNavCell* navcell=new materialNavCell(this);
    // navcell->innit(filename, filepath);
    // ui->scrollAreaWidgetContents->layout()->addWidget(navcell);

}


void materialsNav::on_materialNavBackButton_clicked()
{
    for (int i = 0; i < MAX_FILES; ++i) {
        memset(courseMaterial_files[i], 0, MAX_NAME_LEN);
        memset(courseMaterial_folders[i], 0, MAX_NAME_LEN);
        memset(courseMaterial_file_paths[i], 0, MAX_PATH_LEN);
        memset(courseMaterial_folder_paths[i], 0, MAX_PATH_LEN);
    }
    /*
    // qDebug("The file count during deletion is=%d", fileCount);
    // // Clear and delete all navcells first
    // for(int i = 0; i < fileCount; i++){
    //     if (navcell.at(i)) {
    //         delete navcell.at(i);
    //     }
    // }*/
    navcell.clear();  // Clear the list after deleting widgets

    // Clear the layout
    deleteAllChildWidgets(ui->scrollAreaWidgetContents->layout());

    // Reset to the first page
    ui->stackedWidget->setCurrentIndex(0);

    // Reset file and folder counts
    fileCount = 0;
    folderCount = 0;
    ui->addFileButton->hide();
}



void materialsNav::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();  // Delete the widget
        }
        delete item;  // Delete the layout item
    }
}

void materialsNav::clearLayout2(QLayout *layout) {
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

void materialsNav::deleteAllChildWidgets(QLayout* layout) {
    if (!layout) {
        return;
    }

    while (layout->count() > 0) {
        QLayoutItem* item = layout->takeAt(0);
        if (item) {
            QWidget* widget = item->widget();
            if (widget) {
                widget->deleteLater();
            }
            delete item;
        }
    }
}

void materialsNav::on_addFileButton_clicked()
{
    QString tmpl=QFileDialog::getOpenFileName(this, "select a template (.tmpl file)", QDir::homePath());


    //QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/home", "Text Files (*.txt)");

    if (!tmpl.isEmpty()) {
        // Get filename and path
        QString fullPath = tmpl;
        QString filename = QFileInfo(fullPath).fileName();

        // Use filename and fullPath as needed
        qDebug() << "Selected file: " << filename;
        qDebug() << "Full path: " << fullPath;

        QString newlocal=subdir+filename;
        std::string filepathCPP=fullPath.toUtf8().constData();
        qDebug()<<"the new location is="<<newlocal<<"\n";
        //qDebug("the subdir is=%s",subdir);
        if (copyORmove) {
            // Copy the file
            if (QFile::copy(fullPath, newlocal)) {
                qDebug() << "File copied successfully!";
            } else {
                qDebug() << "File copy failed!";
            }
        } else {
            // Move the file
            if (rename(filepathCPP.c_str(), newlocal.toStdString().c_str()) == 0) {
                qDebug() << "File moved successfully!";
            } else {
                perror("File move failed");
            }
        }

        switch(lastopened){
        case 1:
            on_materialNavBackButton_clicked();
            on_subNotesButton_clicked();
            break;
        case 2:
            on_materialNavBackButton_clicked();
            on_subBooksButton_clicked();
            break;
        case 3:
            on_materialNavBackButton_clicked();
            on_subSlidesButton_clicked();
            break;
        }
    }
}

#include <QPropertyAnimation>
#include <QGroupBox>

#include <QPropertyAnimation>
#include <QWidget>

void materialsNav::animateExpansion(QGroupBox* firstGroupBox, QWidget* scrollAreaWidgetContents) {
    // Hide the first group box
    firstGroupBox->hide();

    // Get the current geometry of scrollAreaWidgetContents
    QRect startGeometry = scrollAreaWidgetContents->geometry();

    // Calculate the new geometry for scrollAreaWidgetContents after expansion
    QRect endGeometry = startGeometry;
    endGeometry.setTop(startGeometry.top() - firstGroupBox->height()); // Expand upwards

    // Create a property animation for the geometry of scrollAreaWidgetContents
    QPropertyAnimation* animation = new QPropertyAnimation(scrollAreaWidgetContents, "geometry");

    // Set the animation duration (0.5 seconds)
    animation->setDuration(500);

    // Set the start and end values for the geometry
    animation->setStartValue(startGeometry);
    animation->setEndValue(endGeometry);

    // Optionally, set an easing curve for a smooth animation
    animation->setEasingCurve(QEasingCurve::InOutCubic);

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped); // Automatically delete after completion
}

