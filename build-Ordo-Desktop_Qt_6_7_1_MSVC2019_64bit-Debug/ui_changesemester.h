/********************************************************************************
** Form generated from reading UI file 'changesemester.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESEMESTER_H
#define UI_CHANGESEMESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeSemester
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *PageNo;
    QWidget *settingsPage;
    QWidget *addPage;
    QHBoxLayout *horizontalLayout;
    QGroupBox *AddCourseCentreBox;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *newCourseName_LE;
    QGroupBox *groupBox_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveCourseButton;

    void setupUi(QMainWindow *ChangeSemester)
    {
        if (ChangeSemester->objectName().isEmpty())
            ChangeSemester->setObjectName("ChangeSemester");
        ChangeSemester->resize(492, 289);
        centralwidget = new QWidget(ChangeSemester);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PageNo = new QStackedWidget(centralwidget);
        PageNo->setObjectName("PageNo");
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        PageNo->addWidget(settingsPage);
        addPage = new QWidget();
        addPage->setObjectName("addPage");
        horizontalLayout = new QHBoxLayout(addPage);
        horizontalLayout->setObjectName("horizontalLayout");
        AddCourseCentreBox = new QGroupBox(addPage);
        AddCourseCentreBox->setObjectName("AddCourseCentreBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddCourseCentreBox->sizePolicy().hasHeightForWidth());
        AddCourseCentreBox->setSizePolicy(sizePolicy);
        AddCourseCentreBox->setMinimumSize(QSize(250, 200));
        AddCourseCentreBox->setLayoutDirection(Qt::LeftToRight);
        AddCourseCentreBox->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        verticalLayout_2 = new QVBoxLayout(AddCourseCentreBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(AddCourseCentreBox);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        newCourseName_LE = new QLineEdit(groupBox);
        newCourseName_LE->setObjectName("newCourseName_LE");
        newCourseName_LE->setMaxLength(20);
        newCourseName_LE->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(newCourseName_LE);


        verticalLayout_2->addWidget(groupBox);

        groupBox_3 = new QGroupBox(AddCourseCentreBox);
        groupBox_3->setObjectName("groupBox_3");

        verticalLayout_2->addWidget(groupBox_3);

        widget = new QWidget(AddCourseCentreBox);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 33));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, -1, 0, 5);
        saveCourseButton = new QPushButton(widget);
        saveCourseButton->setObjectName("saveCourseButton");
        sizePolicy.setHeightForWidth(saveCourseButton->sizePolicy().hasHeightForWidth());
        saveCourseButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(saveCourseButton);


        verticalLayout_2->addWidget(widget);


        horizontalLayout->addWidget(AddCourseCentreBox);

        PageNo->addWidget(addPage);

        verticalLayout->addWidget(PageNo);

        ChangeSemester->setCentralWidget(centralwidget);

        retranslateUi(ChangeSemester);

        PageNo->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ChangeSemester);
    } // setupUi

    void retranslateUi(QMainWindow *ChangeSemester)
    {
        ChangeSemester->setWindowTitle(QCoreApplication::translate("ChangeSemester", "MainWindow", nullptr));
        AddCourseCentreBox->setTitle(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("ChangeSemester", "Course Name", nullptr));
        groupBox_3->setTitle(QString());
        saveCourseButton->setText(QCoreApplication::translate("ChangeSemester", "Save Course", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeSemester: public Ui_ChangeSemester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESEMESTER_H
