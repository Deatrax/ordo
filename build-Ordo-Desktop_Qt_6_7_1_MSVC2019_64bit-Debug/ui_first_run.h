/********************************************************************************
** Form generated from reading UI file 'first_run.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_RUN_H
#define UI_FIRST_RUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_first_run
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *login_box;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *password;
    QPushButton *user_create;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *stuff_box;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QPushButton *home_dir_button;
    QLabel *home_dir;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *get_display_name;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QPushButton *template_button;
    QLabel *template_slec;
    QPushButton *letsGO_button;
    QLabel *hide_box;
    QGroupBox *paadding;
    QPushButton *start_button;
    QLabel *introText;

    void setupUi(QMainWindow *first_run)
    {
        if (first_run->objectName().isEmpty())
            first_run->setObjectName("first_run");
        first_run->resize(765, 483);
        first_run->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {background-image:url(C/Users/PC/Downloads/Qtbackground_img.png);}"));
        centralwidget = new QWidget(first_run);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(25, 22, 51);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(97, 41, 571, 400));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(571, 400));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"            background-color: floralwhite;"));
        groupBox->setAlignment(Qt::AlignCenter);
        login_box = new QGroupBox(groupBox);
        login_box->setObjectName("login_box");
        login_box->setGeometry(QRect(40, 160, 151, 141));
        login_box->setStyleSheet(QString::fromUtf8("border:3px solid black"));
        verticalLayout_2 = new QVBoxLayout(login_box);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(login_box);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 20));
        label->setStyleSheet(QString::fromUtf8("font: 14px  \"Georgia\";\n"
"color: black;\n"
"border: 0px;"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        username = new QLineEdit(login_box);
        username->setObjectName("username");
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);
        username->setMinimumSize(QSize(123, 10));
        username->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));
        username->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(username);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        password = new QLineEdit(login_box);
        password->setObjectName("password");
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setMinimumSize(QSize(123, 0));
        password->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));
        password->setMaxLength(16);
        password->setEchoMode(QLineEdit::Password);
        password->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(password);


        verticalLayout_2->addLayout(horizontalLayout_4);

        user_create = new QPushButton(groupBox);
        user_create->setObjectName("user_create");
        user_create->setGeometry(QRect(73, 310, 81, 21));
        sizePolicy.setHeightForWidth(user_create->sizePolicy().hasHeightForWidth());
        user_create->setSizePolicy(sizePolicy);
        user_create->setMinimumSize(QSize(81, 21));
        user_create->setMaximumSize(QSize(81, 21));
        user_create->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:#7ac28d;\n"
"	border-radius:5px;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(152, 243, 175);\n"
"	border-radius:5px;\n"
"}"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 571, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(190, 60));
        label_2->setStyleSheet(QString::fromUtf8("font: 26pt \"Georgia\";\n"
"text-align:center;\n"
"color: black;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        horizontalLayoutWidget_5 = new QWidget(groupBox);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(0, 90, 571, 44));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(horizontalLayoutWidget_5);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 14px  \"Georgia\";\n"
"color: black;\n"
"border: 0px;"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName("radioButton");

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName("radioButton_2");

        horizontalLayout->addWidget(radioButton_2);


        horizontalLayout_6->addWidget(groupBox_2);

        stuff_box = new QGroupBox(groupBox);
        stuff_box->setObjectName("stuff_box");
        stuff_box->setGeometry(QRect(223, 160, 301, 176));
        verticalLayout = new QVBoxLayout(stuff_box);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_3 = new QLabel(stuff_box);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 18px  \"Georgia\";\n"
"color: black;\n"
"border: 0px;"));

        horizontalLayout_7->addWidget(label_3);

        home_dir_button = new QPushButton(stuff_box);
        home_dir_button->setObjectName("home_dir_button");
        sizePolicy.setHeightForWidth(home_dir_button->sizePolicy().hasHeightForWidth());
        home_dir_button->setSizePolicy(sizePolicy);
        home_dir_button->setMinimumSize(QSize(76, 0));
        home_dir_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(217, 217, 217);\n"
"	color:black;\n"
"	border-radius:5px;\n"
"	border: 1px solid black;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(150, 150, 150);\n"
"	border-radius:5px;\n"
"	border: 1px solid white;\n"
"}"));

        horizontalLayout_7->addWidget(home_dir_button);


        verticalLayout->addLayout(horizontalLayout_7);

        home_dir = new QLabel(stuff_box);
        home_dir->setObjectName("home_dir");
        home_dir->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));

        verticalLayout->addWidget(home_dir);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_5 = new QLabel(stuff_box);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 18px  \"Georgia\";\n"
"color: black;\n"
"border: 0px;"));

        horizontalLayout_9->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_9);

        get_display_name = new QLineEdit(stuff_box);
        get_display_name->setObjectName("get_display_name");
        get_display_name->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));
        get_display_name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(get_display_name);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_9 = new QLabel(stuff_box);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font: 18px  \"Georgia\";\n"
"color: black;\n"
"border: 0px;"));

        horizontalLayout_8->addWidget(label_9);

        template_button = new QPushButton(stuff_box);
        template_button->setObjectName("template_button");
        sizePolicy.setHeightForWidth(template_button->sizePolicy().hasHeightForWidth());
        template_button->setSizePolicy(sizePolicy);
        template_button->setMinimumSize(QSize(76, 0));
        template_button->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(217, 217, 217);\n"
"	color:black;\n"
"	border-radius:5px;\n"
"	border: 1px solid black;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(150, 150, 150);\n"
"	border-radius:5px;\n"
"	border: 1px solid white;\n"
"}"));

        horizontalLayout_8->addWidget(template_button);


        verticalLayout->addLayout(horizontalLayout_8);

        template_slec = new QLabel(stuff_box);
        template_slec->setObjectName("template_slec");
        template_slec->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;\n"
"border-radius:5px;\n"
"border: 2px black;"));
        template_slec->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(template_slec);

        template_slec->raise();
        home_dir->raise();
        get_display_name->raise();
        letsGO_button = new QPushButton(groupBox);
        letsGO_button->setObjectName("letsGO_button");
        letsGO_button->setGeometry(QRect(240, 340, 90, 30));
        sizePolicy.setHeightForWidth(letsGO_button->sizePolicy().hasHeightForWidth());
        letsGO_button->setSizePolicy(sizePolicy);
        letsGO_button->setMinimumSize(QSize(90, 30));
        letsGO_button->setMaximumSize(QSize(90, 30));
        letsGO_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border: 3px solid rgb(40, 101, 191);\n"
"	/*border: 3px solid qlineargradient( x1:0, y1:0.5,x2:1,y2:0.5,\n"
"		stop: 0 #6C1AD6,\n"
"		stop: 0.25 #4FCFD8,\n"
"		stop: 0.71 #EBE32F,\n"
"		stop: 1.0 #F51919\n"
"	);*/\n"
"	background: rgb(49, 51, 56);\n"
"	font: 600 14pt \"Segoe UI\" ;\n"
"	color:white;\n"
"}\n"
"QPushButton:hover{\n"
"	color: white;\n"
"	background-color:rgb(114, 119, 130);\n"
"}"));
        hide_box = new QLabel(groupBox);
        hide_box->setObjectName("hide_box");
        hide_box->setEnabled(true);
        hide_box->setGeometry(QRect(20, 90, 531, 281));
        hide_box->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background:white;"));
        paadding = new QGroupBox(groupBox);
        paadding->setObjectName("paadding");
        paadding->setEnabled(true);
        paadding->setGeometry(QRect(120, 190, 120, 80));
        paadding->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background:white;"));
        start_button = new QPushButton(paadding);
        start_button->setObjectName("start_button");
        start_button->setGeometry(QRect(10, 30, 90, 30));
        sizePolicy.setHeightForWidth(start_button->sizePolicy().hasHeightForWidth());
        start_button->setSizePolicy(sizePolicy);
        start_button->setMinimumSize(QSize(90, 30));
        start_button->setMaximumSize(QSize(90, 30));
        start_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border: 3px solid rgb(40, 101, 191);\n"
"	/*border: 3px solid qlineargradient( x1:0, y1:0.5,x2:1,y2:0.5,\n"
"		stop: 0 #6C1AD6,\n"
"		stop: 0.25 #4FCFD8,\n"
"		stop: 0.71 #EBE32F,\n"
"		stop: 1.0 #F51919\n"
"	);*/\n"
"	background: rgb(49, 51, 56);\n"
"	font: 600 14pt \"Segoe UI\" ;\n"
"	color:white;\n"
"}\n"
"QPushButton:hover{\n"
"	color: white;\n"
"	background-color:rgb(114, 119, 130);\n"
"}"));
        introText = new QLabel(groupBox);
        introText->setObjectName("introText");
        introText->setGeometry(QRect(240, 210, 231, 41));
        introText->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background:white;\n"
"font: 600 12pt \"Segoe UI\" ;\n"
"	color:black;"));
        first_run->setCentralWidget(centralwidget);

        retranslateUi(first_run);

        QMetaObject::connectSlotsByName(first_run);
    } // setupUi

    void retranslateUi(QMainWindow *first_run)
    {
        first_run->setWindowTitle(QCoreApplication::translate("first_run", "Welcome to SIMS", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("first_run", "Create Primary User", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("first_run", "username", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("first_run", "4-digit pin", nullptr));
        user_create->setText(QCoreApplication::translate("first_run", "Create", nullptr));
        label_2->setText(QCoreApplication::translate("first_run", "Welcome", nullptr));
        groupBox_2->setTitle(QString());
        radioButton->setText(QCoreApplication::translate("first_run", "Personal Use", nullptr));
        radioButton_2->setText(QCoreApplication::translate("first_run", "Multi user", nullptr));
        label_3->setText(QCoreApplication::translate("first_run", "\342\200\242 Set home directory", nullptr));
        home_dir_button->setText(QCoreApplication::translate("first_run", "Select file", nullptr));
        home_dir->setText(QString());
        label_5->setText(QCoreApplication::translate("first_run", "\342\200\242 Set your preferred display name", nullptr));
        get_display_name->setPlaceholderText(QCoreApplication::translate("first_run", "type display name here", nullptr));
        label_9->setText(QCoreApplication::translate("first_run", "\342\200\242 Upload preset template", nullptr));
        template_button->setText(QCoreApplication::translate("first_run", "Select", nullptr));
        template_slec->setText(QCoreApplication::translate("first_run", "none selected", nullptr));
        letsGO_button->setText(QCoreApplication::translate("first_run", "Let's Go!", nullptr));
        hide_box->setText(QString());
        paadding->setTitle(QString());
        start_button->setText(QCoreApplication::translate("first_run", "START!", nullptr));
        introText->setText(QCoreApplication::translate("first_run", "Let's Get Started \n"
"with your Experience!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class first_run: public Ui_first_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_RUN_H
