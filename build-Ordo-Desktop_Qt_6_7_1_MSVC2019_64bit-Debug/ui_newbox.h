/********************************************************************************
** Form generated from reading UI file 'newbox.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBOX_H
#define UI_NEWBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newbox
{
public:
    QPushButton *pushButton;
    QLabel *course_name;

    void setupUi(QGroupBox *newbox)
    {
        if (newbox->objectName().isEmpty())
            newbox->setObjectName("newbox");
        newbox->resize(184, 243);
        newbox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border-radius:15px;\n"
"	background-color:#ffebc2;\n"
"\n"
"}"));
        pushButton = new QPushButton(newbox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(42, 170, 100, 32));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #fff;\n"
"	border-radius:15px;\n"
"    color:black;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	 background-color: #1e293b;\n"
"	border-radius:15px;\n"
"	color:white;\n"
"}\n"
""));
        course_name = new QLabel(newbox);
        course_name->setObjectName("course_name");
        course_name->setGeometry(QRect(37, 40, 111, 51));
        course_name->setStyleSheet(QString::fromUtf8("	font: 600 13pt \"Segoe UI\" ;\n"
"	color:Black;\n"
""));
        course_name->setAlignment(Qt::AlignCenter);

        retranslateUi(newbox);

        QMetaObject::connectSlotsByName(newbox);
    } // setupUi

    void retranslateUi(QGroupBox *newbox)
    {
        newbox->setWindowTitle(QCoreApplication::translate("newbox", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("newbox", "Open", nullptr));
        course_name->setText(QCoreApplication::translate("newbox", "alhamdullilah", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newbox: public Ui_newbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBOX_H
