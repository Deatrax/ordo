/********************************************************************************
** Form generated from reading UI file 'materialelement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALELEMENT_H
#define UI_MATERIALELEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>

QT_BEGIN_NAMESPACE

class Ui_materialElement
{
public:

    void setupUi(QGroupBox *materialElement)
    {
        if (materialElement->objectName().isEmpty())
            materialElement->setObjectName("materialElement");
        materialElement->resize(400, 300);

        retranslateUi(materialElement);

        QMetaObject::connectSlotsByName(materialElement);
    } // setupUi

    void retranslateUi(QGroupBox *materialElement)
    {
        materialElement->setWindowTitle(QCoreApplication::translate("materialElement", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class materialElement: public Ui_materialElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALELEMENT_H
