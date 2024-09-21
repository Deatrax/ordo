/********************************************************************************
** Form generated from reading UI file 'new_routine.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_ROUTINE_H
#define UI_NEW_ROUTINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_routine
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *period_no;
    QLineEdit *class_name;
    QLineEdit *instructor;
    QLineEdit *class_location;

    void setupUi(QWidget *new_routine)
    {
        if (new_routine->objectName().isEmpty())
            new_routine->setObjectName("new_routine");
        new_routine->resize(560, 65);
        new_routine->setStyleSheet(QString::fromUtf8("QWidget{\n"
"           background-color: #FFFFF0;\n"
"           color: #0d172a;\n"
"           border: 0px solid black;\n"
"           border-radius: 10px;\n"
"           padding: 5px;\n"
"           margin: 3px;\n"
"}\n"
"QLineEdit{\n"
"	border:2px solid rgb(59, 59, 59);\n"
"	border-radius: 10px;\n"
"	font-size: 15px;\n"
"  	font-weight: 600;\n"
"  	line-height: 1;\n"
"  	padding: 2px 2px;\n"
"	background:white;\n"
"}"));
        horizontalLayout = new QHBoxLayout(new_routine);
        horizontalLayout->setObjectName("horizontalLayout");
        period_no = new QLabel(new_routine);
        period_no->setObjectName("period_no");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(period_no->sizePolicy().hasHeightForWidth());
        period_no->setSizePolicy(sizePolicy);
        period_no->setMinimumSize(QSize(90, 0));
        period_no->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"font-weight: 600;\n"
"line-height: 1;\n"
"padding: 2px 2px;\n"
"color: black;\n"
"border-radius:10px;"));

        horizontalLayout->addWidget(period_no);

        class_name = new QLineEdit(new_routine);
        class_name->setObjectName("class_name");
        class_name->setMaxLength(21);

        horizontalLayout->addWidget(class_name);

        instructor = new QLineEdit(new_routine);
        instructor->setObjectName("instructor");
        instructor->setMaxLength(15);

        horizontalLayout->addWidget(instructor);

        class_location = new QLineEdit(new_routine);
        class_location->setObjectName("class_location");
        class_location->setMaxLength(15);

        horizontalLayout->addWidget(class_location);


        retranslateUi(new_routine);

        QMetaObject::connectSlotsByName(new_routine);
    } // setupUi

    void retranslateUi(QWidget *new_routine)
    {
        new_routine->setWindowTitle(QCoreApplication::translate("new_routine", "Form", nullptr));
        period_no->setText(QCoreApplication::translate("new_routine", "TextLabel", nullptr));
        class_name->setPlaceholderText(QCoreApplication::translate("new_routine", " Class name", nullptr));
        instructor->setPlaceholderText(QCoreApplication::translate("new_routine", " Instructor", nullptr));
        class_location->setPlaceholderText(QCoreApplication::translate("new_routine", " Building+Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_routine: public Ui_new_routine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_ROUTINE_H
