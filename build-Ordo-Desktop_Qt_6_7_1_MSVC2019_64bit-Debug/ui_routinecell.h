/********************************************************************************
** Form generated from reading UI file 'routinecell.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTINECELL_H
#define UI_ROUTINECELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_routineCell
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headUnit;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *name;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Instructor;
    QLabel *location;
    QSpacerItem *separator;

    void setupUi(QWidget *routineCell)
    {
        if (routineCell->objectName().isEmpty())
            routineCell->setObjectName("routineCell");
        routineCell->resize(182, 110);
        routineCell->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(routineCell);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        headUnit = new QWidget(routineCell);
        headUnit->setObjectName("headUnit");
        verticalLayout_3 = new QVBoxLayout(headUnit);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(headUnit);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        name = new QLabel(groupBox);
        name->setObjectName("name");
        name->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(headUnit);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("font-size:9px"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName("horizontalLayout");
        Instructor = new QLabel(groupBox_2);
        Instructor->setObjectName("Instructor");
        Instructor->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(Instructor);

        location = new QLabel(groupBox_2);
        location->setObjectName("location");
        location->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(location);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout->addWidget(headUnit);

        separator = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(separator);


        retranslateUi(routineCell);

        QMetaObject::connectSlotsByName(routineCell);
    } // setupUi

    void retranslateUi(QWidget *routineCell)
    {
        routineCell->setWindowTitle(QCoreApplication::translate("routineCell", "Form", nullptr));
        groupBox->setTitle(QString());
        name->setText(QCoreApplication::translate("routineCell", "TextLabel", nullptr));
        groupBox_2->setTitle(QString());
        Instructor->setText(QCoreApplication::translate("routineCell", "TextLabel", nullptr));
        location->setText(QCoreApplication::translate("routineCell", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class routineCell: public Ui_routineCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTINECELL_H
