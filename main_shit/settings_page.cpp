#include "settings_page.h"
#include "ui_settings_page.h"
#include "StylesSheets.h"
#include "first_run.h"
#include <QSettings>
#include <QDir>
#include <QMessageBox>
#include <algorithm>
#ifdef min
#undef min
#endif



settings_page::settings_page(primary_window *mainwindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::settings_page)
    , m_mainWindow(mainwindow)
{
    //ui->SettingsTabWidget->setCurrentIndex(0);
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

    ui->current_year->setText(m_mainWindow->year);
    ui->currentSemester->setText(m_mainWindow->semester);
    ui->semesterPerYear->setText(QString::number(m_mainWindow->semPerYear));
    ui->SettingsTabWidget->setCurrentIndex(0);
    ui->courseNameGroupBox->hide();

    addstufftocoursebox();

#ifdef _WIN32
    QString tabBarStyle =
        "QTabBar::tab {"
        "   background-color: #f0f0f0;"           // Background color of the tab
        "   border: 1px solid #c0c0c0;"           // Border for each tab
        "   padding: 4px;"                       // Padding inside the tab
        "   margin: 1px;"                         // Margin around the tabs
        "   font-size: 14px;"                     // Font size for the tab text
        "   color: #333;"                         // Text color for the tab
        "}"
        "QTabBar::tab:selected {"
        "   background-color: #FFF2D8;"           // Background color for selected tab
        "   color: #000;"                         // Text color for selected tab
        "   border-bottom:0px ;"        // Prevents border between selected tab and tab content
        "   border-top-left-radius: 5px;"        // Top-left rounded corner
        "   border-top-right-radius: 5px;"       // Top-right rounded corner
        "}"
        "QTabBar::tab:!selected {"
        "   background-color: #f0f0f0;"           // Background for unselected tabs
        "   color: #555;"                         // Text color for unselected tabs
        "}"
        "QTabBar::tab:hover {"
        "   background-color: #e0e0e0;"           // Background on hover
        "   color: #000;"                         // Text color on hover
        "}";

    ui->SettingsTabWidget->tabBar()->setStyleSheet(tabBarStyle);

#endif

    ui->courseSettingExtra->hide();

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

#ifdef _WIN32
    QString appName = "Test app";
    QString appPath = QDir::toNativeSeparators(QCoreApplication::applicationFilePath());

    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    if (flag) {
        settings.setValue(appName, appPath);
    } else {
        settings.remove(appName);
    }

#elif defined(__APPLE__) // macOS specific code
    QString appName = "TestApp";
    QString appPath = QCoreApplication::applicationFilePath();
    QString plistPath = QDir::homePath() + "/Library/LaunchAgents/" + appName + ".plist";

    QFile plistFile(plistPath);
    if (flag) {
        if (plistFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&plistFile);
            out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            out << "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n";
            out << "<plist version=\"1.0\">\n";
            out << "<dict>\n";
            out << "    <key>Label</key>\n";
            out << "    <string>" << appName << "</string>\n";
            out << "    <key>ProgramArguments</key>\n";
            out << "    <array>\n";
            out << "        <string>" << appPath << "</string>\n";
            out << "    </array>\n";
            out << "    <key>RunAtLoad</key>\n";
            out << "    <true/>\n";
            out << "</dict>\n";
            out << "</plist>\n";
            plistFile.close();
        }
    } else {
        if (plistFile.exists()) {
            plistFile.remove();
        }
    }
#endif
}

void settings_page::on_ascendSemesterButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Systray"));
    msgBox.setText(tr("Are you sure you want to ascend to "
                      "the next semester? Doing so will make "
                      "a new folder in the app's home path "
                      "and also change the items visible in "
                      "the meterials tab and move them to \"past cources\""
                      "Doing so will also require the app to ve restarted"));

    msgBox.setStyleSheet(messageboxStyle);

    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No); // Set No as the default button

    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        // User clicked Yes, perform the action
        ascendSemester();
    } else if (ret == QMessageBox::No) {
        // User clicked No, cancel the action
    }
}

void settings_page::ascendSemester(){
    int year=m_mainWindow->year.toInt();
    int semester=m_mainWindow->semester.toInt();

    if(semester==m_mainWindow->semPerYear){
        semester=1;
        year++;
    }
    else semester++;
    char buffer[10];
    // Convert m_mainWindow->semPerYear to string
    std::string str = std::to_string(m_mainWindow->semPerYear);

    // Convert year to string and append
    str += ',' + std::to_string(year);

    // Convert semester to string and append
    str += ',' + std::to_string(semester);

    // Log the resultant string
    qDebug("the resultant line for asension: %s", str.c_str());

    // Preparing for getting the configs file
    char file[260] = "uconfig.spenc";
    make_appData_filePath(file);

    // Open and change the file
    char newline[20];
    std::copy(str.begin(), str.begin() + str.length(), newline);
    newline[19] = '\0';  // Ensure null termination

    replaceLINE(file, 3, newline);

    m_mainWindow->restartApplication();
}


void settings_page::addstufftocoursebox(){

}

void settings_page::on_rollBackSemester_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Systray"));
    msgBox.setText(tr("Are you sure you want to roll back to "
                      "the next semester? Doing so will change  "
                      "the materials tab to the immediate previous semester"
                      "and if the previous semester was not used"
                      "then it will make the previous semsester folder"
                      "Doing so will also require the app to ve restarted"));

    msgBox.setStyleSheet(messageboxStyle);

    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No); // Set No as the default button

    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        // User clicked Yes, perform the action
        rollback_semester();
    } else if (ret == QMessageBox::No) {
        // User clicked No, cancel the action
    }





}

void settings_page::rollback_semester(){
    int year=m_mainWindow->year.toInt();
    int semester=m_mainWindow->semester.toInt();

    if(semester==1){
        semester=m_mainWindow->semPerYear;
        year--;
    }
    else semester--;
    char buffer[10];
    // Convert m_mainWindow->semPerYear to string
    std::string str = std::to_string(m_mainWindow->semPerYear);

    // Convert year to string and append
    str += ',' + std::to_string(year);

    // Convert semester to string and append
    str += ',' + std::to_string(semester);

    // Log the resultant string
    qDebug("the resultant line for asension: %s", str.c_str());

    // Preparing for getting the configs file
    char file[260] = "uconfig.spenc";
    make_appData_filePath(file);
    int cont = std::min(7, static_cast<int>(str.length()));
    // Open and change the file
    char newline[20];
    std::copy(str.begin(), str.begin() + str.length(), newline);
    newline[str.length()] = '\0';  // Ensure null termination

    replaceLINE(file, 3, newline);

    m_mainWindow->restartApplication();
}


void settings_page::on_manualModifyButton_clicked()
{

}

void settings_page::closeEvent(QCloseEvent *event)
{
    m_mainWindow->settingsOpened=false;
    QWidget::closeEvent(event);
}

