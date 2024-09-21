/********************************************************************************
** Form generated from reading UI file 'materialsnav.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSNAV_H
#define UI_MATERIALSNAV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_materialsNav
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *materialNavBackButton;
    QPushButton *addFileButton;
    QPushButton *closetab;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *subNotesButton;
    QPushButton *subBooksButton;
    QPushButton *subSlidesButton;
    QPushButton *OtherButton;
    QPushButton *NavVIewButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;

    void setupUi(QWidget *materialsNav)
    {
        if (materialsNav->objectName().isEmpty())
            materialsNav->setObjectName("materialsNav");
        materialsNav->resize(596, 433);
        verticalLayout = new QVBoxLayout(materialsNav);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(materialsNav);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("border:0px;"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(361, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        materialNavBackButton = new QPushButton(groupBox);
        materialNavBackButton->setObjectName("materialNavBackButton");
        materialNavBackButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout->addWidget(materialNavBackButton);

        addFileButton = new QPushButton(groupBox);
        addFileButton->setObjectName("addFileButton");
        addFileButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout->addWidget(addFileButton);

        closetab = new QPushButton(groupBox);
        closetab->setObjectName("closetab");
        closetab->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout->addWidget(closetab);


        verticalLayout->addWidget(groupBox);

        stackedWidget = new QStackedWidget(materialsNav);
        stackedWidget->setObjectName("stackedWidget");
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        horizontalLayout_3 = new QHBoxLayout(page_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(171, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(236, 200));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{border:0px;}\n"
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
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        subNotesButton = new QPushButton(groupBox_2);
        subNotesButton->setObjectName("subNotesButton");
        subNotesButton->setStyleSheet(QString::fromUtf8("\n"
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

        verticalLayout_2->addWidget(subNotesButton);

        subBooksButton = new QPushButton(groupBox_2);
        subBooksButton->setObjectName("subBooksButton");
        subBooksButton->setStyleSheet(QString::fromUtf8("\n"
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

        verticalLayout_2->addWidget(subBooksButton);

        subSlidesButton = new QPushButton(groupBox_2);
        subSlidesButton->setObjectName("subSlidesButton");
        subSlidesButton->setStyleSheet(QString::fromUtf8("\n"
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

        verticalLayout_2->addWidget(subSlidesButton);

        OtherButton = new QPushButton(groupBox_2);
        OtherButton->setObjectName("OtherButton");

        verticalLayout_2->addWidget(OtherButton);

        NavVIewButton = new QPushButton(groupBox_2);
        NavVIewButton->setObjectName("NavVIewButton");

        verticalLayout_2->addWidget(NavVIewButton);


        horizontalLayout_3->addWidget(groupBox_2);

        horizontalSpacer_3 = new QSpacerItem(171, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        horizontalLayout_2 = new QHBoxLayout(page_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 576, 359));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(materialsNav);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(materialsNav);
    } // setupUi

    void retranslateUi(QWidget *materialsNav)
    {
        materialsNav->setWindowTitle(QCoreApplication::translate("materialsNav", "Form", nullptr));
        groupBox->setTitle(QString());
        materialNavBackButton->setText(QCoreApplication::translate("materialsNav", "Back", nullptr));
        addFileButton->setText(QCoreApplication::translate("materialsNav", "Add file", nullptr));
        closetab->setText(QCoreApplication::translate("materialsNav", "Close Tab", nullptr));
        groupBox_2->setTitle(QString());
        subNotesButton->setText(QCoreApplication::translate("materialsNav", "Notes", nullptr));
        subBooksButton->setText(QCoreApplication::translate("materialsNav", "Books", nullptr));
        subSlidesButton->setText(QCoreApplication::translate("materialsNav", "Slides", nullptr));
        OtherButton->setText(QCoreApplication::translate("materialsNav", "Other FIles and Subfolders", nullptr));
        NavVIewButton->setText(QCoreApplication::translate("materialsNav", "Open Navigation View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class materialsNav: public Ui_materialsNav {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSNAV_H
