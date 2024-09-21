/********************************************************************************
** Form generated from reading UI file 'browserwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSERWINDOW_H
#define UI_BROWSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_browserWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *theLink;
    QPushButton *pushButton_2;
    QWidget *webFrame;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QMainWindow *browserWindow)
    {
        if (browserWindow->objectName().isEmpty())
            browserWindow->setObjectName("browserWindow");
        browserWindow->resize(800, 600);
        centralwidget = new QWidget(browserWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("background:white;"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"/* CSS */\n"
"QPushButton {\n"
"  background-color: #fff;\n"
"  border: 0 solid #e2e8f0;\n"
"  border-radius: 5px;\n"
"  color: #0d172a;\n"
"  font-family: \"Basier circle\",-apple-system,system-ui,\"Segoe UI\",Roboto,\"Helvetica Neue\",Arial,\"Noto Sans\",sans-serif,\"Apple Color Emoji\",\"Segoe UI Emoji\",\"Segoe UI Symbol\",\"Noto Color Emoji\";\n"
"  font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 5px 5px;\n"
"  text-align: center;\n"
"  text-decoration:none #0d172a solid;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: #1e293b;\n"
"  color: #fff;\n"
"}\n"
"\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton);

        theLink = new QLabel(widget_2);
        theLink->setObjectName("theLink");
        theLink->setStyleSheet(QString::fromUtf8("color:black;"));
        theLink->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(theLink);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"/* CSS */\n"
"QPushButton {\n"
"  background-color: #fff;\n"
"  border: 0 solid #e2e8f0;\n"
"  border-radius: 5px;\n"
"  color: #0d172a;\n"
"  font-family: \"Basier circle\",-apple-system,system-ui,\"Segoe UI\",Roboto,\"Helvetica Neue\",Arial,\"Noto Sans\",sans-serif,\"Apple Color Emoji\",\"Segoe UI Emoji\",\"Segoe UI Symbol\",\"Noto Color Emoji\";\n"
"  font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 5px 5px;\n"
"  text-align: center;\n"
"  text-decoration:none #0d172a solid;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: #1e293b;\n"
"  color: #fff;\n"
"}\n"
"\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(widget_2);

        webFrame = new QWidget(centralwidget);
        webFrame->setObjectName("webFrame");
        horizontalLayout_4 = new QHBoxLayout(webFrame);
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        verticalLayout->addWidget(webFrame);

        browserWindow->setCentralWidget(centralwidget);

        retranslateUi(browserWindow);

        QMetaObject::connectSlotsByName(browserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *browserWindow)
    {
        browserWindow->setWindowTitle(QCoreApplication::translate("browserWindow", "The Browser", nullptr));
        pushButton->setText(QCoreApplication::translate("browserWindow", "Back", nullptr));
        theLink->setText(QCoreApplication::translate("browserWindow", "Site Title", nullptr));
        pushButton_2->setText(QCoreApplication::translate("browserWindow", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class browserWindow: public Ui_browserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSERWINDOW_H
