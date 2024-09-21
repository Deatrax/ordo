#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui {
class browserWindow;
}
QT_END_NAMESPACE

class browserWindow : public QMainWindow
{
    Q_OBJECT

public:
    browserWindow(QWidget *parent = nullptr);
    ~browserWindow();
    QWebEngineView *a;

protected:
    void closeEvent(QCloseEvent *event) override; // Override closeEvent

private:
    Ui::browserWindow *ui;


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void cleanupWebEngine();  // Slot for cleanup
    void onTitleChanged(const QString &title);
};

#endif // BROWSERWINDOW_H
