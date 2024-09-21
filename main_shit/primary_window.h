#ifndef PRIMARY_WINDOW_H
#define PRIMARY_WINDOW_H

#include "browserwindow.h"
#include "flowlayout.h"
#include "qgroupbox.h"
#include <QMainWindow>
#include "qboxlayout.h"
#include "qgroupbox.h"
#include "routinecell.h"
#include "routinetimecell.h"
#include "upnextelement.h"

namespace Ui {
class primary_window;
}

class primary_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit primary_window(QWidget *parent = nullptr);
    ~primary_window();

    void printRoutine();

    QString array_toQstr(char *ar);
    void clearAllLabelsInGroupBox(QGroupBox *groupBox);

    browserWindow *obj;
    int nums_drive;

    QString upper="background:rgb(194, 203, 255);border-top-left-radius: 10px; border-top-right-radius: 10px;";
    QString lower="background:rgb(194, 203, 255);border-bottom-left-radius: 10px; border-bottom-right-radius: 10px;";
    QString normalstyle="QLabel{background:rgb(212, 255, 250)}QGroupBox{	background:rgb(212, 255, 250);	border-radius: 10px;border: 1px solid black;}";
    QString todayStyle="QGroupBox{background:rgb(255, 60, 60); border-radius: 10px; border: 1px solid black;}QLabel{background:rgb(255, 60, 60); border-radius: 10px;font: 20px;color:black;  }";



    class classCellData{
        int lineNo;
        char name[23]="\0";
        char inst[17]="\0";
        char locale[17]="\0";
        //qtring, array functio etc etc;
    };
    class classTimeData {
    public:
        QString timeQ;
        int milTime;
        int LunchFlag=0;
        int DayBreak=0;

        // Not a Constructor to initialize the time
        void takeInp(const QString& time) {
            timeQ = time;
            milTime = convertToMilitaryTime(timeQ);
        }
        static bool compareByMilTime(const classTimeData& a, const classTimeData& b) {
            return a.milTime < b.milTime;
        }
    private:
        // Function to convert time to military format
        int convertToMilitaryTime(const QString& time) {
            QStringList parts = time.split(' ');
            if (parts.size() != 2) return -1; // Invalid format

            QStringList timeParts = parts[0].split(':');
            if (timeParts.size() != 2) return -1; // Invalid format

            int hours = timeParts[0].toInt();
            int minutes = timeParts[1].toInt();
            QString period = parts[1].toUpper(); // Convert period to uppercase

            if (period == "PM" && hours != 12) {
                hours += 12;
            } else if (period == "AM" && hours == 12) {
                hours = 0;
            }

            return hours * 100 + minutes;
        }
    };
    void sortClassTimes(std::vector<classTimeData>& classTimes) {
        std::sort(classTimes.begin(), classTimes.end(), classTimeData::compareByMilTime);
    }


    std::vector<routineTimeCell*> timeCells;
    std::vector<QGroupBox*> cols;
    std::vector<QVBoxLayout*> vbox_cols;
    std::vector<routineCell*> mainCell;
    std::vector<upnextElement*> unxt;
    //std::vector <QString> timeDats;
    //#define QCstr toStdString().c_str();
    bool allMaterialsOpened=false;
    bool routinePageOpened=false;
    bool browserPageOpened=false;
    bool assginmentPageOpened=false;
    bool upcommingOpened=false;
    bool examsOpened=false;
    int upcommingMode=0;
    char displayName[127];
    QString year;
    QString semester;
    char HomePath[256];
    char semesterPath[512];
    int semPerYear;
    int currSemst;
    char coursedatPath[550];
    int currentMaterialTabs=0;
    int newboxLimit=0;
    FlowLayout *layout;


    void clearLayout(QLayout *layout);
    QWidget *addtab(QString tabname, char* coursePath );
    void closeTab();
    void deleteBrowserInstance();
    void makeRoutine();
    void clearLayout2(QLayout *layout);
    int loadConfig();
    void resetFlag(int flag);
    void gototab(QWidget* i);

    QGroupBox *formaterialsTabs();
    void loadMiniRoutine();
    void refreshCurrentPage();
private slots:
    void on_home_button_clicked();

    void on_all_material_button_clicked();

    void on_notes_button_clicked();

    void on_routine_button_clicked();

    void on_up_coming_button_clicked();

    void on_assignments_button_clicked();

    void on_google_drive_button_clicked();

    void on_settings_button_clicked();

    void on_exams_button_clicked();

    void on_changeRoutine_clicked();

    void on_addTaskButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_addLinkButton_clicked();

    void on_removeLink_button_clicked();

    void on_upCommingChangeButton_clicked();

    void on_upCommingExtraButton_clicked();

    void on_upCommingBackButton_clicked();

    void on_updateSemesterButton_clicked();

    void on_addCourseButton_clicked();

    void on_tabWidget_2_currentChanged(int index);

private:
    Ui::primary_window *ui;
};

#endif // PRIMARY_WINDOW_H
