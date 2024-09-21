#ifndef MATERIALSNAV_H
#define MATERIALSNAV_H

#include "primary_window.h"
#include "qlistwidget.h"
#include <QWidget>
#include "first_run.h"
#include "materialnavcell.h"

namespace Ui {
class materialsNav;
}

class materialsNav : public QWidget
{
    Q_OBJECT

public:
    explicit materialsNav(primary_window *mainwindow, QWidget *parent = nullptr);
    ~materialsNav();

    void loadFolders();
    char coursePath[650];
    void innit(char *str);
    char subdir[1000]={0};
    char courseMaterial_files[MAX_FILES][MAX_NAME_LEN] = {{0}};
    char courseMaterial_folders[MAX_FILES][MAX_NAME_LEN] = {{0}};
    char courseMaterial_file_paths[MAX_FILES][MAX_PATH_LEN] = {{0}};
    char courseMaterial_folder_paths[MAX_FILES][MAX_PATH_LEN] = {{0}};
    int fileCount=0;
    int folderCount=0;
    std::vector<materialNavCell*> navcell;
    bool copyORmove=true;
    int lastopened;

    void addCell(char filename[], char filepath[]);
    void clearLayout(QLayout *layout);
    void clearLayout2(QLayout *layout);
    void deleteAllChildWidgets(QLayout *layout);
    void animateExpansion(QGroupBox *firstGroupBox, QWidget *scrollAreaWidgetContents);
private slots:
    void on_closetab_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_subNotesButton_clicked();

    void on_materialNavBackButton_clicked();

    void on_subBooksButton_clicked();

    void on_subSlidesButton_clicked();

    void on_OtherButton_clicked();

    void on_NavVIewButton_clicked();

    void on_addFileButton_clicked();

private:
    Ui::materialsNav *ui;
    primary_window *m_mainWindow;
};

#endif // MATERIALSNAV_H
