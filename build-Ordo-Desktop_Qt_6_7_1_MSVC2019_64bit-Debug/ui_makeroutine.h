/********************************************************************************
** Form generated from reading UI file 'makeroutine.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEROUTINE_H
#define UI_MAKEROUTINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_makeroutine
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *routuneSetupStack;
    QWidget *page_no1;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *preriods;
    QLabel *label_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkSunday;
    QCheckBox *checkMonday;
    QCheckBox *checkTuesday;
    QCheckBox *checkWednesday;
    QCheckBox *checkThursday;
    QCheckBox *checkFriday;
    QCheckBox *checkSaturday;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QTimeEdit *lunch_start;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QTimeEdit *daybreak;
    QFrame *line;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_no5;
    QStackedWidget *page1_sideStack;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_12;
    QScrollArea *scrollArea;
    QWidget *times_scroll;
    QWidget *sidePagewithNextButton;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *procceedButton;
    QGroupBox *groupBox_20;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *change_periods_button;
    QPushButton *pushButton;
    QWidget *dump;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *weekNums;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *times_periods_2;
    QWidget *page_no2;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *titlebar_grpbox;
    QVBoxLayout *verticalLayout_7;
    QLabel *titlebar;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *classesStack;
    QWidget *sunday;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_17;
    QLabel *label;
    QScrollArea *scrollArea_5;
    QWidget *sunday_stack;
    QWidget *monday;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_13;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_5;
    QScrollArea *scrollArea_3;
    QWidget *monday_stack;
    QWidget *tuesday;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_9;
    QScrollArea *scrollArea_7;
    QWidget *tuesday_stack;
    QWidget *wednesday;
    QVBoxLayout *verticalLayout_15;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_10;
    QScrollArea *scrollArea_8;
    QWidget *wednesday_stack;
    QWidget *thursday;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox_16;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_11;
    QScrollArea *scrollArea_6;
    QWidget *thrusday_stack;
    QWidget *friday;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_12;
    QScrollArea *scrollArea_2;
    QWidget *friday_stack;
    QWidget *saturday;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_18;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_13;
    QScrollArea *scrollArea_4;
    QWidget *saturday_stack;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Go_backButton;
    QPushButton *Next_dayButton;
    QGroupBox *groupBox_19;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QSpacerItem *verticalSpacer;
    QWidget *final_page;
    QHBoxLayout *horizontalLayout_15;
    QGroupBox *groupBox_21;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_15;
    QGroupBox *groupBox_22;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *previous_page_button;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *makeroutine)
    {
        if (makeroutine->objectName().isEmpty())
            makeroutine->setObjectName("makeroutine");
        makeroutine->resize(857, 551);
        makeroutine->setMinimumSize(QSize(857, 551));
        makeroutine->setMaximumSize(QSize(857, 551));
        makeroutine->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(makeroutine);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        routuneSetupStack = new QStackedWidget(centralwidget);
        routuneSetupStack->setObjectName("routuneSetupStack");
        page_no1 = new QWidget();
        page_no1->setObjectName("page_no1");
        verticalLayout = new QVBoxLayout(page_no1);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(page_no1);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 38));
        groupBox->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;\n"
""));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_7);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(page_no1);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("border:0px;"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setStyleSheet(QString::fromUtf8("border:0px;"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(292, 58));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        horizontalLayout_4->addWidget(label_3);

        preriods = new QSpinBox(groupBox_5);
        preriods->setObjectName("preriods");
        preriods->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 5px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"background:white;\n"
"color:black;"));
        preriods->setMaximum(15);

        horizontalLayout_4->addWidget(preriods);


        verticalLayout_4->addLayout(horizontalLayout_4);

        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_4->addWidget(label_4);

        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;\n"
""));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkSunday = new QCheckBox(groupBox_4);
        checkSunday->setObjectName("checkSunday");

        verticalLayout_2->addWidget(checkSunday);

        checkMonday = new QCheckBox(groupBox_4);
        checkMonday->setObjectName("checkMonday");

        verticalLayout_2->addWidget(checkMonday);

        checkTuesday = new QCheckBox(groupBox_4);
        checkTuesday->setObjectName("checkTuesday");

        verticalLayout_2->addWidget(checkTuesday);

        checkWednesday = new QCheckBox(groupBox_4);
        checkWednesday->setObjectName("checkWednesday");

        verticalLayout_2->addWidget(checkWednesday);

        checkThursday = new QCheckBox(groupBox_4);
        checkThursday->setObjectName("checkThursday");

        verticalLayout_2->addWidget(checkThursday);

        checkFriday = new QCheckBox(groupBox_4);
        checkFriday->setObjectName("checkFriday");

        verticalLayout_2->addWidget(checkFriday);

        checkSaturday = new QCheckBox(groupBox_4);
        checkSaturday->setObjectName("checkSaturday");

        verticalLayout_2->addWidget(checkSaturday);


        verticalLayout_4->addWidget(groupBox_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(292, 58));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        horizontalLayout_7->addWidget(label_6);

        lunch_start = new QTimeEdit(groupBox_5);
        lunch_start->setObjectName("lunch_start");
        lunch_start->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 5px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"background:white;\n"
"color:black;"));

        horizontalLayout_7->addWidget(lunch_start);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(292, 58));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        horizontalLayout_8->addWidget(label_8);

        daybreak = new QTimeEdit(groupBox_5);
        daybreak->setObjectName("daybreak");
        daybreak->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 5px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"background:white;\n"
"color:black;"));

        horizontalLayout_8->addWidget(daybreak);


        verticalLayout_4->addLayout(horizontalLayout_8);


        horizontalLayout_5->addWidget(groupBox_5);

        line = new QFrame(groupBox_2);
        line->setObjectName("line");
        line->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(14, 415));
        line->setStyleSheet(QString::fromUtf8("color:rgb(114, 127, 130);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::Shape::VLine);

        horizontalLayout_5->addWidget(line);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName("groupBox_6");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy3);
        groupBox_6->setMinimumSize(QSize(292, 0));
        groupBox_6->setStyleSheet(QString::fromUtf8("border:0px;"));
        verticalLayout_3 = new QVBoxLayout(groupBox_6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_no5 = new QLabel(groupBox_6);
        label_no5->setObjectName("label_no5");
        sizePolicy.setHeightForWidth(label_no5->sizePolicy().hasHeightForWidth());
        label_no5->setSizePolicy(sizePolicy);
        label_no5->setMinimumSize(QSize(0, 59));
        label_no5->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;\n"
""));

        verticalLayout_3->addWidget(label_no5);

        page1_sideStack = new QStackedWidget(groupBox_6);
        page1_sideStack->setObjectName("page1_sideStack");
        page1_sideStack->setStyleSheet(QString::fromUtf8(""));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayout_10 = new QHBoxLayout(page_2);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        groupBox_8 = new QGroupBox(page_2);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox{ border-radius:20px; background-color:#ffebc2}\n"
"QWidget{ border-radius:20px; background-color:#ffebc2}"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_8);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(groupBox_8);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        times_scroll = new QWidget();
        times_scroll->setObjectName("times_scroll");
        times_scroll->setGeometry(QRect(0, 0, 100, 30));
        scrollArea->setWidget(times_scroll);

        horizontalLayout_12->addWidget(scrollArea);


        horizontalLayout_10->addWidget(groupBox_8);

        page1_sideStack->addWidget(page_2);
        sidePagewithNextButton = new QWidget();
        sidePagewithNextButton->setObjectName("sidePagewithNextButton");
        verticalLayout_6 = new QVBoxLayout(sidePagewithNextButton);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox_7 = new QGroupBox(sidePagewithNextButton);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox{ border-radius:20px; background-color:#ffebc2}"));
        groupBox_7->setAlignment(Qt::AlignCenter);
        horizontalLayout_11 = new QHBoxLayout(groupBox_7);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        procceedButton = new QPushButton(groupBox_7);
        procceedButton->setObjectName("procceedButton");
        sizePolicy2.setHeightForWidth(procceedButton->sizePolicy().hasHeightForWidth());
        procceedButton->setSizePolicy(sizePolicy2);
        procceedButton->setMinimumSize(QSize(195, 0));
        procceedButton->setStyleSheet(QString::fromUtf8("/* CSS */\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
""));

        horizontalLayout_11->addWidget(procceedButton);


        verticalLayout_6->addWidget(groupBox_7);

        page1_sideStack->addWidget(sidePagewithNextButton);

        verticalLayout_3->addWidget(page1_sideStack);

        groupBox_20 = new QGroupBox(groupBox_6);
        groupBox_20->setObjectName("groupBox_20");
        horizontalLayout_14 = new QHBoxLayout(groupBox_20);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        change_periods_button = new QPushButton(groupBox_20);
        change_periods_button->setObjectName("change_periods_button");
        change_periods_button->setStyleSheet(QString::fromUtf8("/* CSS */\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
""));

        horizontalLayout_14->addWidget(change_periods_button);

        pushButton = new QPushButton(groupBox_20);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("/* CSS */\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
""));

        horizontalLayout_14->addWidget(pushButton);


        verticalLayout_3->addWidget(groupBox_20);


        horizontalLayout_5->addWidget(groupBox_6);


        verticalLayout->addWidget(groupBox_2);

        routuneSetupStack->addWidget(page_no1);
        dump = new QWidget();
        dump->setObjectName("dump");
        horizontalLayoutWidget = new QWidget(dump);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(140, 230, 361, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;\n"
""));

        horizontalLayout_3->addWidget(label_2);

        weekNums = new QSpinBox(horizontalLayoutWidget);
        weekNums->setObjectName("weekNums");
        weekNums->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 5px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"background:white;"));
        weekNums->setMaximum(7);

        horizontalLayout_3->addWidget(weekNums);

        groupBox_3 = new QGroupBox(dump);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(520, 150, 274, 343));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{ border-radius:20px; background-color:#ffebc2}"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_3);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        times_periods_2 = new QTextEdit(groupBox_3);
        times_periods_2->setObjectName("times_periods_2");
        times_periods_2->setStyleSheet(QString::fromUtf8("background-color:#ffebc2;\n"
"border: 0px;"));

        horizontalLayout_9->addWidget(times_periods_2);

        routuneSetupStack->addWidget(dump);
        page_no2 = new QWidget();
        page_no2->setObjectName("page_no2");
        verticalLayout_8 = new QVBoxLayout(page_no2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        titlebar_grpbox = new QGroupBox(page_no2);
        titlebar_grpbox->setObjectName("titlebar_grpbox");
        sizePolicy.setHeightForWidth(titlebar_grpbox->sizePolicy().hasHeightForWidth());
        titlebar_grpbox->setSizePolicy(sizePolicy);
        titlebar_grpbox->setMinimumSize(QSize(0, 38));
        titlebar_grpbox->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;\n"
""));
        verticalLayout_7 = new QVBoxLayout(titlebar_grpbox);
        verticalLayout_7->setObjectName("verticalLayout_7");
        titlebar = new QLabel(titlebar_grpbox);
        titlebar->setObjectName("titlebar");
        titlebar->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(titlebar);


        verticalLayout_8->addWidget(titlebar_grpbox);

        groupBox_10 = new QGroupBox(page_no2);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setStyleSheet(QString::fromUtf8("border:0px;"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_10);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        classesStack = new QStackedWidget(groupBox_10);
        classesStack->setObjectName("classesStack");
        sunday = new QWidget();
        sunday->setObjectName("sunday");
        verticalLayout_12 = new QVBoxLayout(sunday);
        verticalLayout_12->setObjectName("verticalLayout_12");
        groupBox_12 = new QGroupBox(sunday);
        groupBox_12->setObjectName("groupBox_12");
        verticalLayout_17 = new QVBoxLayout(groupBox_12);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_17->setContentsMargins(0, 9, 0, 0);
        label = new QLabel(groupBox_12);
        label->setObjectName("label");
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_17->addWidget(label);

        scrollArea_5 = new QScrollArea(groupBox_12);
        scrollArea_5->setObjectName("scrollArea_5");
        scrollArea_5->setWidgetResizable(true);
        sunday_stack = new QWidget();
        sunday_stack->setObjectName("sunday_stack");
        sunday_stack->setGeometry(QRect(0, 0, 16, 16));
        scrollArea_5->setWidget(sunday_stack);

        verticalLayout_17->addWidget(scrollArea_5);


        verticalLayout_12->addWidget(groupBox_12);

        classesStack->addWidget(sunday);
        monday = new QWidget();
        monday->setObjectName("monday");
        verticalLayout_10 = new QVBoxLayout(monday);
        verticalLayout_10->setObjectName("verticalLayout_10");
        groupBox_13 = new QGroupBox(monday);
        groupBox_13->setObjectName("groupBox_13");
        verticalLayout_18 = new QVBoxLayout(groupBox_13);
        verticalLayout_18->setObjectName("verticalLayout_18");
        label_5 = new QLabel(groupBox_13);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_18->addWidget(label_5);

        scrollArea_3 = new QScrollArea(groupBox_13);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        monday_stack = new QWidget();
        monday_stack->setObjectName("monday_stack");
        monday_stack->setGeometry(QRect(0, 0, 50, 16));
        scrollArea_3->setWidget(monday_stack);

        verticalLayout_18->addWidget(scrollArea_3);


        verticalLayout_10->addWidget(groupBox_13);

        classesStack->addWidget(monday);
        tuesday = new QWidget();
        tuesday->setObjectName("tuesday");
        verticalLayout_14 = new QVBoxLayout(tuesday);
        verticalLayout_14->setObjectName("verticalLayout_14");
        groupBox_14 = new QGroupBox(tuesday);
        groupBox_14->setObjectName("groupBox_14");
        verticalLayout_19 = new QVBoxLayout(groupBox_14);
        verticalLayout_19->setObjectName("verticalLayout_19");
        label_9 = new QLabel(groupBox_14);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_19->addWidget(label_9);

        scrollArea_7 = new QScrollArea(groupBox_14);
        scrollArea_7->setObjectName("scrollArea_7");
        scrollArea_7->setWidgetResizable(true);
        tuesday_stack = new QWidget();
        tuesday_stack->setObjectName("tuesday_stack");
        tuesday_stack->setGeometry(QRect(0, 0, 50, 16));
        scrollArea_7->setWidget(tuesday_stack);

        verticalLayout_19->addWidget(scrollArea_7);


        verticalLayout_14->addWidget(groupBox_14);

        classesStack->addWidget(tuesday);
        wednesday = new QWidget();
        wednesday->setObjectName("wednesday");
        verticalLayout_15 = new QVBoxLayout(wednesday);
        verticalLayout_15->setObjectName("verticalLayout_15");
        groupBox_15 = new QGroupBox(wednesday);
        groupBox_15->setObjectName("groupBox_15");
        verticalLayout_20 = new QVBoxLayout(groupBox_15);
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_10 = new QLabel(groupBox_15);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_20->addWidget(label_10);

        scrollArea_8 = new QScrollArea(groupBox_15);
        scrollArea_8->setObjectName("scrollArea_8");
        scrollArea_8->setWidgetResizable(true);
        wednesday_stack = new QWidget();
        wednesday_stack->setObjectName("wednesday_stack");
        wednesday_stack->setGeometry(QRect(0, 0, 50, 16));
        scrollArea_8->setWidget(wednesday_stack);

        verticalLayout_20->addWidget(scrollArea_8);


        verticalLayout_15->addWidget(groupBox_15);

        classesStack->addWidget(wednesday);
        thursday = new QWidget();
        thursday->setObjectName("thursday");
        verticalLayout_13 = new QVBoxLayout(thursday);
        verticalLayout_13->setObjectName("verticalLayout_13");
        groupBox_16 = new QGroupBox(thursday);
        groupBox_16->setObjectName("groupBox_16");
        verticalLayout_21 = new QVBoxLayout(groupBox_16);
        verticalLayout_21->setObjectName("verticalLayout_21");
        label_11 = new QLabel(groupBox_16);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_21->addWidget(label_11);

        scrollArea_6 = new QScrollArea(groupBox_16);
        scrollArea_6->setObjectName("scrollArea_6");
        scrollArea_6->setWidgetResizable(true);
        thrusday_stack = new QWidget();
        thrusday_stack->setObjectName("thrusday_stack");
        thrusday_stack->setGeometry(QRect(0, 0, 50, 16));
        scrollArea_6->setWidget(thrusday_stack);

        verticalLayout_21->addWidget(scrollArea_6);


        verticalLayout_13->addWidget(groupBox_16);

        classesStack->addWidget(thursday);
        friday = new QWidget();
        friday->setObjectName("friday");
        verticalLayout_9 = new QVBoxLayout(friday);
        verticalLayout_9->setObjectName("verticalLayout_9");
        groupBox_17 = new QGroupBox(friday);
        groupBox_17->setObjectName("groupBox_17");
        verticalLayout_22 = new QVBoxLayout(groupBox_17);
        verticalLayout_22->setObjectName("verticalLayout_22");
        label_12 = new QLabel(groupBox_17);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_22->addWidget(label_12);

        scrollArea_2 = new QScrollArea(groupBox_17);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        friday_stack = new QWidget();
        friday_stack->setObjectName("friday_stack");
        friday_stack->setGeometry(QRect(0, 0, 50, 16));
        scrollArea_2->setWidget(friday_stack);

        verticalLayout_22->addWidget(scrollArea_2);


        verticalLayout_9->addWidget(groupBox_17);

        classesStack->addWidget(friday);
        saturday = new QWidget();
        saturday->setObjectName("saturday");
        verticalLayout_11 = new QVBoxLayout(saturday);
        verticalLayout_11->setObjectName("verticalLayout_11");
        groupBox_18 = new QGroupBox(saturday);
        groupBox_18->setObjectName("groupBox_18");
        verticalLayout_23 = new QVBoxLayout(groupBox_18);
        verticalLayout_23->setObjectName("verticalLayout_23");
        label_13 = new QLabel(groupBox_18);
        label_13->setObjectName("label_13");
        label_13->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;\n"
"color:black;"));

        verticalLayout_23->addWidget(label_13);

        scrollArea_4 = new QScrollArea(groupBox_18);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setWidgetResizable(true);
        saturday_stack = new QWidget();
        saturday_stack->setObjectName("saturday_stack");
        saturday_stack->setGeometry(QRect(0, 0, 50, 16));
        scrollArea_4->setWidget(saturday_stack);

        verticalLayout_23->addWidget(scrollArea_4);


        verticalLayout_11->addWidget(groupBox_18);

        classesStack->addWidget(saturday);

        horizontalLayout_2->addWidget(classesStack);

        groupBox_11 = new QGroupBox(groupBox_10);
        groupBox_11->setObjectName("groupBox_11");
        sizePolicy3.setHeightForWidth(groupBox_11->sizePolicy().hasHeightForWidth());
        groupBox_11->setSizePolicy(sizePolicy3);
        groupBox_11->setMinimumSize(QSize(245, 0));
        groupBox_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_16 = new QVBoxLayout(groupBox_11);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalSpacer_2 = new QSpacerItem(20, 6, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_16->addItem(verticalSpacer_2);

        groupBox_9 = new QGroupBox(groupBox_11);
        groupBox_9->setObjectName("groupBox_9");
        sizePolicy.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy);
        groupBox_9->setStyleSheet(QString::fromUtf8("\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
"\n"
""));
        groupBox_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_6 = new QHBoxLayout(groupBox_9);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Go_backButton = new QPushButton(groupBox_9);
        Go_backButton->setObjectName("Go_backButton");

        horizontalLayout_6->addWidget(Go_backButton);

        Next_dayButton = new QPushButton(groupBox_9);
        Next_dayButton->setObjectName("Next_dayButton");

        horizontalLayout_6->addWidget(Next_dayButton);


        verticalLayout_16->addWidget(groupBox_9);

        groupBox_19 = new QGroupBox(groupBox_11);
        groupBox_19->setObjectName("groupBox_19");
        sizePolicy1.setHeightForWidth(groupBox_19->sizePolicy().hasHeightForWidth());
        groupBox_19->setSizePolicy(sizePolicy1);
        groupBox_19->setMinimumSize(QSize(0, 201));
        groupBox_19->setStyleSheet(QString::fromUtf8("border-radius:20px; background-color:#ffebc2"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_19);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_14 = new QLabel(groupBox_19);
        label_14->setObjectName("label_14");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy4);
        label_14->setStyleSheet(QString::fromUtf8("Color:black;\n"
"font-size: 13px;\n"
"font-weight: 600;"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_14);


        verticalLayout_16->addWidget(groupBox_19);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_16->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(groupBox_11);


        verticalLayout_8->addWidget(groupBox_10);

        routuneSetupStack->addWidget(page_no2);
        final_page = new QWidget();
        final_page->setObjectName("final_page");
        horizontalLayout_15 = new QHBoxLayout(final_page);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        groupBox_21 = new QGroupBox(final_page);
        groupBox_21->setObjectName("groupBox_21");
        sizePolicy2.setHeightForWidth(groupBox_21->sizePolicy().hasHeightForWidth());
        groupBox_21->setSizePolicy(sizePolicy2);
        groupBox_21->setMinimumSize(QSize(391, 221));
        groupBox_21->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"background-color: #FFFFF0;\n"
"color:#0d172a;\n"
"border: 0px solid black;\n"
"border-radius: 15px;\n"
" padding: 5px;\n"
" margin: 3px;\n"
"font-size: 15px;\n"
"  	font-weight: 600;\n"
"  	line-height: 1;\n"
"         "));
        verticalLayout_24 = new QVBoxLayout(groupBox_21);
        verticalLayout_24->setObjectName("verticalLayout_24");
        label_15 = new QLabel(groupBox_21);
        label_15->setObjectName("label_15");
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(0, 156));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(label_15);

        groupBox_22 = new QGroupBox(groupBox_21);
        groupBox_22->setObjectName("groupBox_22");
        sizePolicy1.setHeightForWidth(groupBox_22->sizePolicy().hasHeightForWidth());
        groupBox_22->setSizePolicy(sizePolicy1);
        groupBox_22->setMinimumSize(QSize(0, 50));
        groupBox_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
""));
        horizontalLayout_16 = new QHBoxLayout(groupBox_22);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        previous_page_button = new QPushButton(groupBox_22);
        previous_page_button->setObjectName("previous_page_button");

        horizontalLayout_16->addWidget(previous_page_button);

        pushButton_3 = new QPushButton(groupBox_22);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_16->addWidget(pushButton_3);


        verticalLayout_24->addWidget(groupBox_22);


        horizontalLayout_15->addWidget(groupBox_21);

        routuneSetupStack->addWidget(final_page);

        horizontalLayout->addWidget(routuneSetupStack);

        makeroutine->setCentralWidget(centralwidget);

        retranslateUi(makeroutine);

        routuneSetupStack->setCurrentIndex(0);
        page1_sideStack->setCurrentIndex(1);
        classesStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(makeroutine);
    } // setupUi

    void retranslateUi(QMainWindow *makeroutine)
    {
        makeroutine->setWindowTitle(QCoreApplication::translate("makeroutine", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_7->setText(QCoreApplication::translate("makeroutine", "Routine Setup", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_5->setTitle(QString());
        label_3->setText(QCoreApplication::translate("makeroutine", "1. Please enter the highest possible number\n"
"of classes every day", nullptr));
        label_4->setText(QCoreApplication::translate("makeroutine", "2. Please select the weekends below:", nullptr));
        groupBox_4->setTitle(QString());
        checkSunday->setText(QCoreApplication::translate("makeroutine", "Sunday", nullptr));
        checkMonday->setText(QCoreApplication::translate("makeroutine", "Monday", nullptr));
        checkTuesday->setText(QCoreApplication::translate("makeroutine", "Tuesday", nullptr));
        checkWednesday->setText(QCoreApplication::translate("makeroutine", "Wednesday", nullptr));
        checkThursday->setText(QCoreApplication::translate("makeroutine", "Thursday", nullptr));
        checkFriday->setText(QCoreApplication::translate("makeroutine", "Friday", nullptr));
        checkSaturday->setText(QCoreApplication::translate("makeroutine", "Saturday", nullptr));
        label_6->setText(QCoreApplication::translate("makeroutine", "3. When does your lunch start?", nullptr));
        label_8->setText(QCoreApplication::translate("makeroutine", "4. When does your classtime end?", nullptr));
        groupBox_6->setTitle(QString());
        label_no5->setText(QCoreApplication::translate("makeroutine", "5. Press next and then enter the\n"
" strarting time of every period", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("makeroutine", "GroupBox", nullptr));
        groupBox_7->setTitle(QString());
        procceedButton->setText(QCoreApplication::translate("makeroutine", "Next", nullptr));
        groupBox_20->setTitle(QString());
        change_periods_button->setText(QCoreApplication::translate("makeroutine", "Change number", nullptr));
        pushButton->setText(QCoreApplication::translate("makeroutine", "Next", nullptr));
        label_2->setText(QCoreApplication::translate("makeroutine", "Please enter the numebr of working days", nullptr));
        groupBox_3->setTitle(QString());
        times_periods_2->setPlaceholderText(QCoreApplication::translate("makeroutine", "Please enter the starting time for every periods including the lunch time. For example:              8:00-am                                                                   9:30-am                                                                   11:30-am                                                                   1:00-pm                                                                   2:30-pm                                                                   4:00-pm                                                                  Here 1:00 was the strating of the lunch period. The dashes between the time and am/pm are also necessary, if not included then it will not work properly. The numbre of times entered must be same as the number specified in box \"1\". And two additional numbers for ", nullptr));
        titlebar_grpbox->setTitle(QString());
        titlebar->setText(QCoreApplication::translate("makeroutine", "Routine Setup", nullptr));
        groupBox_10->setTitle(QString());
        groupBox_12->setTitle(QString());
        label->setText(QCoreApplication::translate("makeroutine", "Sunday", nullptr));
        groupBox_13->setTitle(QString());
        label_5->setText(QCoreApplication::translate("makeroutine", "Monday", nullptr));
        groupBox_14->setTitle(QString());
        label_9->setText(QCoreApplication::translate("makeroutine", "Tuesday", nullptr));
        groupBox_15->setTitle(QString());
        label_10->setText(QCoreApplication::translate("makeroutine", "Wednesday", nullptr));
        groupBox_16->setTitle(QString());
        label_11->setText(QCoreApplication::translate("makeroutine", "Thursday", nullptr));
        groupBox_17->setTitle(QString());
        label_12->setText(QCoreApplication::translate("makeroutine", "Friday", nullptr));
        groupBox_18->setTitle(QString());
        label_13->setText(QCoreApplication::translate("makeroutine", "Saturday", nullptr));
        groupBox_11->setTitle(QString());
        groupBox_9->setTitle(QString());
        Go_backButton->setText(QCoreApplication::translate("makeroutine", "Go Back", nullptr));
        Next_dayButton->setText(QCoreApplication::translate("makeroutine", "Next", nullptr));
        groupBox_19->setTitle(QString());
        label_14->setText(QCoreApplication::translate("makeroutine", "Enter the name, name of the techer\n"
"/lecturer/instructor and the location\n"
" of the class. Of course you can put any\n"
" name you like. \n"
"\n"
"For classes that span multiple periods, \n"
"put \"same\" in the next period and they\n"
" will be merged as a single class in the \n"
"routine. In case of a free period, \n"
"write \"free\" in the name field. For both of \n"
"these two cases, you can leave the instructor\n"
"field and location field empty.", nullptr));
        groupBox_21->setTitle(QString());
        label_15->setText(QCoreApplication::translate("makeroutine", "Are you sure you want to save?", nullptr));
        groupBox_22->setTitle(QString());
        previous_page_button->setText(QCoreApplication::translate("makeroutine", "No - Back to last page", nullptr));
        pushButton_3->setText(QCoreApplication::translate("makeroutine", "YES!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class makeroutine: public Ui_makeroutine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEROUTINE_H
