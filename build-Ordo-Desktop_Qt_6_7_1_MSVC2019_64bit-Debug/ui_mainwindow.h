/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *notes;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../../Downloads/Picsart_24-04-24_18-25-17-205.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #1e2429;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(250, 400));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"            background-color: floralwhite;"));
        groupBox->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 190, 60));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(190, 60));
        label->setStyleSheet(QString::fromUtf8("font: 26pt \"Georgia\";\n"
"text-align:center;\n"
"color: black;"));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 220, 131, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username = new QLineEdit(layoutWidget);
        username->setObjectName("username");
        username->setMinimumSize(QSize(0, 10));
        username->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));
        username->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(username);

        password = new QLineEdit(layoutWidget);
        password->setObjectName("password");
        password->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));
        password->setMaxLength(16);
        password->setEchoMode(QLineEdit::Password);
        password->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(password);

        notes = new QLabel(groupBox);
        notes->setObjectName("notes");
        notes->setGeometry(QRect(40, 170, 171, 41));
        notes->setStyleSheet(QString::fromUtf8("\n"
"color:black;\n"
""));
        notes->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(85, 321, 81, 21));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:#7ac28d;\n"
"border-radius:5px;"));

        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SIMS login", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("MainWindow", "username", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "password", nullptr));
        notes->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
