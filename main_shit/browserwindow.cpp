#include "browserwindow.h"
#include "ui_browserwindow.h"
#include <QWebEngineView>
#include <QCloseEvent>
#include <StylesSheets.h>
browserWindow::browserWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::browserWindow)
{
    loadThemeFromFile();
    ui->setupUi(this);
    a = new QWebEngineView(this);
    ui->webFrame->layout()->addWidget(a);
    ui->theLink->setStyleSheet(LabelStyleBorderless);
    setStyleSheet(elementsStyle);
    // Connect the destroyed signal to cleanup slot
    connect(a, &QWebEngineView::destroyed, this, &browserWindow::cleanupWebEngine);
    connect(a->page(), &QWebEnginePage::titleChanged, this, &browserWindow::onTitleChanged);
}

void browserWindow::onTitleChanged(const QString &title){
    // Access the title of the loaded website
    QString websiteTitle = title;
    qDebug() << "Website title: " << websiteTitle;
    ui->theLink->setText(websiteTitle);
}

browserWindow::~browserWindow()
{
    delete ui;
    delete a;
}

void browserWindow::closeEvent(QCloseEvent *event)
{
    // Clean up the QWebEngineView before closing the window
    delete a;  // This should stop the QWebEngineProcess
    a = nullptr;
    event->accept();
}

void browserWindow::on_pushButton_clicked()
{
    a->back();
}

void browserWindow::on_pushButton_2_clicked()
{
    a->forward();
}

void browserWindow::cleanupWebEngine()
{
    // Additional cleanup if necessary
    //delete a;
    qDebug() << "QWebEngineView destroyed, process should be cleaned up.";
}
