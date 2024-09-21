/********************************************************************************
** Form generated from reading UI file 'course_item.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSE_ITEM_H
#define UI_COURSE_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Course_Item
{
public:

    void setupUi(QWidget *Course_Item)
    {
        if (Course_Item->objectName().isEmpty())
            Course_Item->setObjectName("Course_Item");
        Course_Item->resize(400, 300);

        retranslateUi(Course_Item);

        QMetaObject::connectSlotsByName(Course_Item);
    } // setupUi

    void retranslateUi(QWidget *Course_Item)
    {
        Course_Item->setWindowTitle(QCoreApplication::translate("Course_Item", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Course_Item: public Ui_Course_Item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSE_ITEM_H
