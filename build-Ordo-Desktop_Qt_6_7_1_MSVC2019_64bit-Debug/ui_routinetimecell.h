/********************************************************************************
** Form generated from reading UI file 'routinetimecell.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTINETIMECELL_H
#define UI_ROUTINETIMECELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_routineTimeCell
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *class_time;

    void setupUi(QWidget *routineTimeCell)
    {
        if (routineTimeCell->objectName().isEmpty())
            routineTimeCell->setObjectName("routineTimeCell");
        routineTimeCell->resize(109, 81);
        routineTimeCell->setStyleSheet(QString::fromUtf8("border-radius:20px; background-color:#ffebc2;\n"
"\n"
"background-color: #FFFFF0;\n"
"           color: #0d172a;\n"
"           border: 0px solid black;\n"
"           border-radius: 5px;\n"
"		   padding: 5px;\n"
"           margin: 3px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;"));
        horizontalLayout = new QHBoxLayout(routineTimeCell);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        class_time = new QLabel(routineTimeCell);
        class_time->setObjectName("class_time");
        class_time->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(class_time);


        retranslateUi(routineTimeCell);

        QMetaObject::connectSlotsByName(routineTimeCell);
    } // setupUi

    void retranslateUi(QWidget *routineTimeCell)
    {
        routineTimeCell->setWindowTitle(QCoreApplication::translate("routineTimeCell", "Form", nullptr));
        class_time->setText(QCoreApplication::translate("routineTimeCell", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class routineTimeCell: public Ui_routineTimeCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTINETIMECELL_H
