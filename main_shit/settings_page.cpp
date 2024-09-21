#include "settings_page.h"
#include "qtabbar.h"
#include "ui_settings_page.h"
#include "StylesSheets.h"

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
}
settings_page::~settings_page(){
    delete ui;
}
