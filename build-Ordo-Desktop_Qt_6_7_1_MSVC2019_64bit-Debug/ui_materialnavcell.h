/********************************************************************************
** Form generated from reading UI file 'materialnavcell.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALNAVCELL_H
#define UI_MATERIALNAVCELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_materialNavCell
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;
    QLabel *itemName;
    QLineEdit *renameBox;
    QPushButton *renameButton;
    QPushButton *saveButton;
    QPushButton *ItemDeleteButton;
    QPushButton *ItemOpenButton;

    void setupUi(QWidget *materialNavCell)
    {
        if (materialNavCell->objectName().isEmpty())
            materialNavCell->setObjectName("materialNavCell");
        materialNavCell->resize(428, 45);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(materialNavCell->sizePolicy().hasHeightForWidth());
        materialNavCell->setSizePolicy(sizePolicy);
        materialNavCell->setMinimumSize(QSize(0, 45));
        materialNavCell->setStyleSheet(QString::fromUtf8("\n"
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
        horizontalLayout = new QHBoxLayout(materialNavCell);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        container = new QWidget(materialNavCell);
        container->setObjectName("container");
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        itemName = new QLabel(container);
        itemName->setObjectName("itemName");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(itemName->sizePolicy().hasHeightForWidth());
        itemName->setSizePolicy(sizePolicy1);
        itemName->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(itemName);

        renameBox = new QLineEdit(container);
        renameBox->setObjectName("renameBox");
        renameBox->setMaxLength(20);

        horizontalLayout_2->addWidget(renameBox);

        renameButton = new QPushButton(container);
        renameButton->setObjectName("renameButton");
        renameButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(renameButton);

        saveButton = new QPushButton(container);
        saveButton->setObjectName("saveButton");

        horizontalLayout_2->addWidget(saveButton);

        ItemDeleteButton = new QPushButton(container);
        ItemDeleteButton->setObjectName("ItemDeleteButton");
        ItemDeleteButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(ItemDeleteButton);

        ItemOpenButton = new QPushButton(container);
        ItemOpenButton->setObjectName("ItemOpenButton");
        ItemOpenButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(ItemOpenButton);


        horizontalLayout->addWidget(container);


        retranslateUi(materialNavCell);

        QMetaObject::connectSlotsByName(materialNavCell);
    } // setupUi

    void retranslateUi(QWidget *materialNavCell)
    {
        materialNavCell->setWindowTitle(QCoreApplication::translate("materialNavCell", "Form", nullptr));
        itemName->setText(QCoreApplication::translate("materialNavCell", "TextLabel", nullptr));
        renameButton->setText(QCoreApplication::translate("materialNavCell", "rename", nullptr));
        saveButton->setText(QCoreApplication::translate("materialNavCell", "Save", nullptr));
        ItemDeleteButton->setText(QCoreApplication::translate("materialNavCell", "delete", nullptr));
        ItemOpenButton->setText(QCoreApplication::translate("materialNavCell", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class materialNavCell: public Ui_materialNavCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALNAVCELL_H
