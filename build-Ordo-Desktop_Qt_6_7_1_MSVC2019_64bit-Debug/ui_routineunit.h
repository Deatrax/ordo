/********************************************************************************
** Form generated from reading UI file 'routineunit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTINEUNIT_H
#define UI_ROUTINEUNIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>

QT_BEGIN_NAMESPACE

class Ui_routineUnit
{
public:

    void setupUi(QGroupBox *routineUnit)
    {
        if (routineUnit->objectName().isEmpty())
            routineUnit->setObjectName("routineUnit");
        routineUnit->resize(400, 300);

        retranslateUi(routineUnit);

        QMetaObject::connectSlotsByName(routineUnit);
    } // setupUi

    void retranslateUi(QGroupBox *routineUnit)
    {
        routineUnit->setWindowTitle(QCoreApplication::translate("routineUnit", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class routineUnit: public Ui_routineUnit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTINEUNIT_H
