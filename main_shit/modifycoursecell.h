#ifndef MODIFYCOURSECELL_H
#define MODIFYCOURSECELL_H

#include "primary_window.h"
#include <QWidget>

namespace Ui {
class modifyCourseCell;
}

class modifyCourseCell : public QWidget
{
    Q_OBJECT

public:
    explicit modifyCourseCell(primary_window *mainwindow,QWidget *parent);
    ~modifyCourseCell();

    char arr[50];
    char courseFolderPath[650];
    int activeTab=0;
    QWidget* targTab;
    std::string selectDirectory();

    void init(char *courseName, char *str2, int lineNo);
    void renameCourse();
private slots:
    void on_SaveNameButton_clicked();

private:
    char** coursedatpath;
    Ui::modifyCourseCell *ui;
    int lineNum;
    bool dirrExists;
    std::string getFolderName(const std::string &folderPath);
    primary_window *m_mainWindow;
};

#endif // MODIFYCOURSECELL_H
