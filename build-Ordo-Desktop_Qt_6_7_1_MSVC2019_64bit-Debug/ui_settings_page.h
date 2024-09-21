/********************************************************************************
** Form generated from reading UI file 'settings_page.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_PAGE_H
#define UI_SETTINGS_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings_page
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *MainSettingsContents;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *SettingsTabWidget;
    QWidget *SettingsTab1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGroupBox *GeneralSettignsTitleBar_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *displayNameLabel;
    QLineEdit *DisplayNameLineEdit;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QWidget *SettingsTab2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *GeneralSettignsTitleBar;

    void setupUi(QWidget *settings_page)
    {
        if (settings_page->objectName().isEmpty())
            settings_page->setObjectName("settings_page");
        settings_page->resize(577, 369);
        settings_page->setMinimumSize(QSize(577, 369));
        settings_page->setMaximumSize(QSize(577, 369));
        horizontalLayout = new QHBoxLayout(settings_page);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MainSettingsContents = new QGroupBox(settings_page);
        MainSettingsContents->setObjectName("MainSettingsContents");
        horizontalLayout_2 = new QHBoxLayout(MainSettingsContents);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        SettingsTabWidget = new QTabWidget(MainSettingsContents);
        SettingsTabWidget->setObjectName("SettingsTabWidget");
        SettingsTabWidget->setLayoutDirection(Qt::LeftToRight);
        SettingsTabWidget->setElideMode(Qt::ElideNone);
        SettingsTabWidget->setTabsClosable(false);
        SettingsTabWidget->setTabBarAutoHide(false);
        SettingsTab1 = new QWidget();
        SettingsTab1->setObjectName("SettingsTab1");
        verticalLayout_2 = new QVBoxLayout(SettingsTab1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, 0);
        label_2 = new QLabel(SettingsTab1);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 29));
        label_2->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        GeneralSettignsTitleBar_2 = new QGroupBox(SettingsTab1);
        GeneralSettignsTitleBar_2->setObjectName("GeneralSettignsTitleBar_2");
        verticalLayout_3 = new QVBoxLayout(GeneralSettignsTitleBar_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(GeneralSettignsTitleBar_2);
        groupBox->setObjectName("groupBox");
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(50, -1, 50, -1);
        displayNameLabel = new QLabel(groupBox);
        displayNameLabel->setObjectName("displayNameLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(displayNameLabel->sizePolicy().hasHeightForWidth());
        displayNameLabel->setSizePolicy(sizePolicy1);
        displayNameLabel->setMinimumSize(QSize(95, 0));
        displayNameLabel->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;\n"
""));
        displayNameLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(displayNameLabel);

        DisplayNameLineEdit = new QLineEdit(groupBox);
        DisplayNameLineEdit->setObjectName("DisplayNameLineEdit");

        horizontalLayout_3->addWidget(DisplayNameLineEdit);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addWidget(GeneralSettignsTitleBar_2);

        SettingsTabWidget->addTab(SettingsTab1, QString());
        SettingsTab2 = new QWidget();
        SettingsTab2->setObjectName("SettingsTab2");
        verticalLayout = new QVBoxLayout(SettingsTab2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(SettingsTab2);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 29));
        label->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        GeneralSettignsTitleBar = new QGroupBox(SettingsTab2);
        GeneralSettignsTitleBar->setObjectName("GeneralSettignsTitleBar");

        verticalLayout->addWidget(GeneralSettignsTitleBar);

        SettingsTabWidget->addTab(SettingsTab2, QString());

        horizontalLayout_2->addWidget(SettingsTabWidget);


        horizontalLayout->addWidget(MainSettingsContents);


        retranslateUi(settings_page);

        SettingsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settings_page);
    } // setupUi

    void retranslateUi(QWidget *settings_page)
    {
        settings_page->setWindowTitle(QCoreApplication::translate("settings_page", "Form", nullptr));
        MainSettingsContents->setTitle(QString());
        label_2->setText(QCoreApplication::translate("settings_page", "General Settings", nullptr));
        GeneralSettignsTitleBar_2->setTitle(QString());
        groupBox->setTitle(QString());
        displayNameLabel->setText(QCoreApplication::translate("settings_page", "Change Display Name", nullptr));
        pushButton->setText(QCoreApplication::translate("settings_page", "PushButton", nullptr));
        SettingsTabWidget->setTabText(SettingsTabWidget->indexOf(SettingsTab1), QCoreApplication::translate("settings_page", "General", nullptr));
        label->setText(QCoreApplication::translate("settings_page", "General Settings", nullptr));
        GeneralSettignsTitleBar->setTitle(QString());
        SettingsTabWidget->setTabText(SettingsTabWidget->indexOf(SettingsTab2), QCoreApplication::translate("settings_page", "Tab 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settings_page: public Ui_settings_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_PAGE_H
