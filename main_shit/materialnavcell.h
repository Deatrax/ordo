#ifndef MATERIALNAVCELL_H
#define MATERIALNAVCELL_H

#include <QWidget>

namespace Ui {
class materialNavCell;
}

class materialNavCell : public QWidget
{
    Q_OBJECT

public:
    explicit materialNavCell(QWidget *parent = nullptr);
    ~materialNavCell();
    QString targetFile;

    void innit(char *filename, char *filepath);
private slots:
    void on_renameButton_clicked();

    void on_ItemDeleteButton_clicked();

    void on_ItemOpenButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::materialNavCell *ui;
};

#endif // MATERIALNAVCELL_H
