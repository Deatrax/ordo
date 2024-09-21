/********************************************************************************
** Form generated from reading UI file 'addtask.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASK_H
#define UI_ADDTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addTask
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLineEdit *name;
    QLineEdit *type;
    QLineEdit *day;
    QLineEdit *month;
    QLineEdit *year;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *addTask)
    {
        if (addTask->objectName().isEmpty())
            addTask->setObjectName("addTask");
        addTask->resize(896, 183);
        addTask->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 15pt \"Cascadia Code\";\n"
"background:rgb(105, 255, 160);\n"
"border-radius:15px;"));
        horizontalLayout = new QHBoxLayout(addTask);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(addTask);
        groupBox->setObjectName("groupBox");
        name = new QLineEdit(groupBox);
        name->setObjectName("name");
        name->setGeometry(QRect(11, 34, 281, 31));
        name->setStyleSheet(QString::fromUtf8("background:white;\n"
"font: 15px;\n"
""));
        name->setAlignment(Qt::AlignCenter);
        type = new QLineEdit(groupBox);
        type->setObjectName("type");
        type->setGeometry(QRect(372, 34, 165, 31));
        type->setStyleSheet(QString::fromUtf8("background:white;\n"
"font: 15px;\n"
""));
        type->setAlignment(Qt::AlignCenter);
        day = new QLineEdit(groupBox);
        day->setObjectName("day");
        day->setGeometry(QRect(620, 34, 81, 31));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(day->sizePolicy().hasHeightForWidth());
        day->setSizePolicy(sizePolicy);
        day->setMinimumSize(QSize(5, 0));
        day->setStyleSheet(QString::fromUtf8("background:white;\n"
"font: 15px;\n"
""));
        day->setAlignment(Qt::AlignCenter);
        month = new QLineEdit(groupBox);
        month->setObjectName("month");
        month->setGeometry(QRect(706, 34, 81, 31));
        sizePolicy.setHeightForWidth(month->sizePolicy().hasHeightForWidth());
        month->setSizePolicy(sizePolicy);
        month->setMinimumSize(QSize(5, 0));
        month->setStyleSheet(QString::fromUtf8("background:white;\n"
"font: 15px;\n"
""));
        month->setAlignment(Qt::AlignCenter);
        year = new QLineEdit(groupBox);
        year->setObjectName("year");
        year->setGeometry(QRect(792, 34, 71, 31));
        year->setStyleSheet(QString::fromUtf8("background:white;\n"
"font: 15px;\n"
""));
        year->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(355, 95, 89, 30));
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
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 30, 62, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 40, 62, 20));

        horizontalLayout->addWidget(groupBox);


        retranslateUi(addTask);

        QMetaObject::connectSlotsByName(addTask);
    } // setupUi

    void retranslateUi(QWidget *addTask)
    {
        addTask->setWindowTitle(QCoreApplication::translate("addTask", "Form", nullptr));
        groupBox->setTitle(QString());
        name->setPlaceholderText(QCoreApplication::translate("addTask", "name of assignment", nullptr));
        type->setPlaceholderText(QCoreApplication::translate("addTask", "assignment/exam", nullptr));
        day->setPlaceholderText(QCoreApplication::translate("addTask", "day", nullptr));
        month->setPlaceholderText(QCoreApplication::translate("addTask", "month", nullptr));
        year->setPlaceholderText(QCoreApplication::translate("addTask", "year", nullptr));
        pushButton->setText(QCoreApplication::translate("addTask", "Save", nullptr));
        label->setText(QCoreApplication::translate("addTask", "Type", nullptr));
        label_2->setText(QCoreApplication::translate("addTask", "Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addTask: public Ui_addTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASK_H
