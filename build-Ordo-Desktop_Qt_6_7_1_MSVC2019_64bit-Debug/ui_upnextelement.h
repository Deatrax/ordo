/********************************************************************************
** Form generated from reading UI file 'upnextelement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPNEXTELEMENT_H
#define UI_UPNEXTELEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_upnextElement
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *taskName;
    QLabel *taskType;
    QGridLayout *gridLayout;
    QLabel *deadline;
    QLabel *rmDays;
    QLabel *label;
    QLabel *label_4;
    QGroupBox *modButtons;
    QVBoxLayout *verticalLayout_4;
    QPushButton *editTaskButton;
    QPushButton *delete_taskButton;

    void setupUi(QWidget *upnextElement)
    {
        if (upnextElement->objectName().isEmpty())
            upnextElement->setObjectName("upnextElement");
        upnextElement->resize(1010, 105);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upnextElement->sizePolicy().hasHeightForWidth());
        upnextElement->setSizePolicy(sizePolicy);
        upnextElement->setMinimumSize(QSize(1010, 102));
        upnextElement->setStyleSheet(QString::fromUtf8("background:rgb(105, 255, 160);\n"
"border-radius:15px;"));
        verticalLayout = new QVBoxLayout(upnextElement);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(upnextElement);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        taskName = new QLabel(groupBox);
        taskName->setObjectName("taskName");
        taskName->setMinimumSize(QSize(570, 0));
        taskName->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 26pt \"Cascadia Code\";"));

        verticalLayout_3->addWidget(taskName);

        taskType = new QLabel(groupBox);
        taskType->setObjectName("taskType");
        taskType->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font:  \"Cascadia Code\";"));

        verticalLayout_3->addWidget(taskType);


        horizontalLayout->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        deadline = new QLabel(groupBox);
        deadline->setObjectName("deadline");
        deadline->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 15pt \"Cascadia Code\";"));

        gridLayout->addWidget(deadline, 0, 1, 1, 1);

        rmDays = new QLabel(groupBox);
        rmDays->setObjectName("rmDays");
        rmDays->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 15pt \"Cascadia Code\";\n"
"background:rgb(105, 255, 160);\n"
"border-radius:15px;"));

        gridLayout->addWidget(rmDays, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 15pt \"Cascadia Code\";"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 15pt \"Cascadia Code\";"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        modButtons = new QGroupBox(groupBox);
        modButtons->setObjectName("modButtons");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(modButtons->sizePolicy().hasHeightForWidth());
        modButtons->setSizePolicy(sizePolicy1);
        modButtons->setMinimumSize(QSize(88, 0));
        modButtons->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(modButtons);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        editTaskButton = new QPushButton(modButtons);
        editTaskButton->setObjectName("editTaskButton");

        verticalLayout_4->addWidget(editTaskButton);

        delete_taskButton = new QPushButton(modButtons);
        delete_taskButton->setObjectName("delete_taskButton");
        delete_taskButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton:hover {\n"
"  background-color: red;\n"
"  color: #fff;\n"
"}\n"
""));

        verticalLayout_4->addWidget(delete_taskButton);


        horizontalLayout->addWidget(modButtons);


        verticalLayout->addWidget(groupBox);


        retranslateUi(upnextElement);

        QMetaObject::connectSlotsByName(upnextElement);
    } // setupUi

    void retranslateUi(QWidget *upnextElement)
    {
        upnextElement->setWindowTitle(QCoreApplication::translate("upnextElement", "Form", nullptr));
        groupBox->setTitle(QString());
        taskName->setText(QCoreApplication::translate("upnextElement", "LOrem Ipsum", nullptr));
        taskType->setText(QCoreApplication::translate("upnextElement", "NO type!", nullptr));
        deadline->setText(QCoreApplication::translate("upnextElement", "Boom", nullptr));
        rmDays->setText(QCoreApplication::translate("upnextElement", "Dead", nullptr));
        label->setText(QCoreApplication::translate("upnextElement", "Deadline on:", nullptr));
        label_4->setText(QCoreApplication::translate("upnextElement", "Remaining days:", nullptr));
        modButtons->setTitle(QString());
        editTaskButton->setText(QCoreApplication::translate("upnextElement", "Edit", nullptr));
        delete_taskButton->setText(QCoreApplication::translate("upnextElement", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class upnextElement: public Ui_upnextElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPNEXTELEMENT_H
