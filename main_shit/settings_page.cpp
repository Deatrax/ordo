#include "settings_page.h"
#include "ui_settings_page.h"
#include "StylesSheets.h"
#include "first_run.h"
#include <QSettings>
#include <QDir>
#include <QMessageBox>



settings_page::settings_page(primary_window *mainwindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::settings_page)
    , m_mainWindow(mainwindow)
{
    loadThemeFromFile();
    ui->setupUi(this);
    setStyleSheet(mainBG);
    setWindowTitle("Ordo Settings");

    // char file[260]="uconfig.spenc";
    // make_appData_filePath(file);
    //ui->SettingsTabWidget->tabBar()->hide();
    ui->displayNameLabel->setText("Fuck your name");
    ui->DisplayNameLineEdit->setStyleSheet(LabelStyleBorderless);
    if(m_mainWindow->trayEnabled==true){
        ui->trayCheckBox->setChecked(true);
    }
    else ui->trayCheckBox->setChecked(false);

    if(m_mainWindow->loginEnabled==true){
        ui->loginCheckBox->setChecked(true);
    }
    else ui->loginCheckBox->setChecked(false);
}
settings_page::~settings_page(){
    delete ui;
}

void settings_page::on_loginCheckBox_clicked(bool checked)
{
    if(checked!=m_mainWindow->loginEnabled){
        setAutoStartWindows(checked);
        //preparing for getting the configs file
        char file[260]="uconfig.spenc";
        make_appData_filePath(file);
        //open and change the file
        if(checked==false){
            char newline[]="login disabled";
            replaceLINE(file,5,newline);
            m_mainWindow->loginEnabled=false;
        }
        else{
            char newline[]="login enabled";
            replaceLINE(file,5,newline);
            m_mainWindow->loginEnabled=true;
        }
    }

}


void settings_page::on_trayCheckBox_clicked(bool checked)
{
    if(checked!=m_mainWindow->trayEnabled){
        //preparing for getting the configs file
        char file[260]="uconfig.spenc";
        make_appData_filePath(file);
        //open and change the file
        if(checked==false){
            char newline[]="tray disabled";
            replaceLINE(file,4,newline);
            m_mainWindow->trayEnabled=false;
            m_mainWindow->trayVisibility(false);
        }
        else{
            char newline[]="tray enabled";
            replaceLINE(file,4,newline);
            m_mainWindow->trayEnabled=true;
            m_mainWindow->trayVisibility(true);
        }
    }
    else if(checked==m_mainWindow->trayEnabled) return;
}


void settings_page::setAutoStartWindows(bool flag) {
    QString appName = "Test app";
    QString appPath = QDir::toNativeSeparators(QCoreApplication::applicationFilePath());

    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    if (flag) {
        settings.setValue(appName, appPath);
    } else {
        settings.remove(appName);
    }
}
