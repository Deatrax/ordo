/********************************************************************************
** Form generated from reading UI file 'primary_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMARY_WINDOW_H
#define UI_PRIMARY_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_primary_window
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *sidepanel_widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *home_button;
    QPushButton *all_material_button;
    QPushButton *notes_button;
    QPushButton *routine_button;
    QPushButton *up_coming_button;
    QPushButton *assignments_button;
    QPushButton *exams_button;
    QPushButton *google_drive_button;
    QPushButton *settings_button;
    QWidget *main_content_widget;
    QGridLayout *gridLayout_2;
    QStackedWidget *main_content_stack;
    QWidget *home_page;
    QVBoxLayout *verticalLayout_17;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *HomepageTitlebar;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout;
    QLabel *welcome;
    QLabel *label;
    QGroupBox *miniRoutineBox;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QGroupBox *dropArea;
    QWidget *all_materials_page;
    QVBoxLayout *verticalLayout_13;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QGroupBox *allMaterialsPageTopBar;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *updateSemesterButton;
    QPushButton *addCourseButton;
    QTabWidget *tabWidget_2;
    QWidget *main_materials_ui;
    QWidget *tab_2;
    QWidget *notes_page;
    QLabel *label_7;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QWidget *routine_page;
    QVBoxLayout *verticalLayout_12;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *changeRoutine;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *the_hecking_routine;
    QWidget *up_coming_page;
    QVBoxLayout *verticalLayout_81;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_12;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addTaskButton;
    QPushButton *upCommingChangeButton;
    QPushButton *upCommingBackButton;
    QPushButton *upCommingExtraButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_82;
    QScrollArea *bal;
    QWidget *upNextArea;
    QVBoxLayout *verticalLayout_83;
    QWidget *assignments_page;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_13;
    QWidget *google_drive_page;
    QVBoxLayout *verticalLayout_84;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_15;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_36;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_78;
    QSpacerItem *horizontalSpacer_11;
    QListWidget *link_list;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_85;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout_18;
    QPushButton *pushButton_5;
    QLineEdit *linkIn;
    QLineEdit *link_name;
    QPushButton *pushButton_9;
    QPushButton *addLinkButton;
    QPushButton *removeLink_button;
    QSpacerItem *verticalSpacer;
    QLabel *current_link;
    QWidget *settings_page;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_16;
    QWidget *exams_page;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_17;
    QWidget *make_routine;
    QVBoxLayout *verticalLayout_15;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_81;
    QGroupBox *mainRoutine_groupbox_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_73;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_35;
    QPushButton *pushButton_4;
    QWidget *info_widget;
    QLabel *profile_logo;
    QGroupBox *verticalGroupBox1;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_5;
    QLabel *currentYear;

    void setupUi(QMainWindow *primary_window)
    {
        if (primary_window->objectName().isEmpty())
            primary_window->setObjectName("primary_window");
        primary_window->setEnabled(true);
        primary_window->resize(1326, 743);
        primary_window->setMinimumSize(QSize(1326, 743));
        primary_window->setStyleSheet(QString::fromUtf8("background-color: #1e2429;\n"
""));
        centralwidget = new QWidget(primary_window);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sidepanel_widget = new QWidget(centralwidget);
        sidepanel_widget->setObjectName("sidepanel_widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidepanel_widget->sizePolicy().hasHeightForWidth());
        sidepanel_widget->setSizePolicy(sizePolicy);
        sidepanel_widget->setMinimumSize(QSize(243, 650));
        QFont font;
        font.setBold(false);
        sidepanel_widget->setFont(font);
        sidepanel_widget->setStyleSheet(QString::fromUtf8("background-color:black;\n"
""));
        layoutWidget = new QWidget(sidepanel_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 199, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        home_button = new QPushButton(layoutWidget);
        home_button->setObjectName("home_button");
        home_button->setMinimumSize(QSize(0, 30));
        home_button->setCursor(QCursor(Qt::PointingHandCursor));
        home_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(home_button);

        all_material_button = new QPushButton(layoutWidget);
        all_material_button->setObjectName("all_material_button");
        all_material_button->setMinimumSize(QSize(0, 30));
        all_material_button->setCursor(QCursor(Qt::PointingHandCursor));
        all_material_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(all_material_button);

        notes_button = new QPushButton(layoutWidget);
        notes_button->setObjectName("notes_button");
        notes_button->setMinimumSize(QSize(0, 30));
        notes_button->setCursor(QCursor(Qt::PointingHandCursor));
        notes_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(notes_button);

        routine_button = new QPushButton(layoutWidget);
        routine_button->setObjectName("routine_button");
        routine_button->setMinimumSize(QSize(0, 30));
        routine_button->setCursor(QCursor(Qt::PointingHandCursor));
        routine_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(routine_button);

        up_coming_button = new QPushButton(layoutWidget);
        up_coming_button->setObjectName("up_coming_button");
        up_coming_button->setMinimumSize(QSize(0, 30));
        up_coming_button->setCursor(QCursor(Qt::PointingHandCursor));
        up_coming_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(up_coming_button);

        assignments_button = new QPushButton(layoutWidget);
        assignments_button->setObjectName("assignments_button");
        assignments_button->setMinimumSize(QSize(0, 30));
        assignments_button->setCursor(QCursor(Qt::PointingHandCursor));
        assignments_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(assignments_button);

        exams_button = new QPushButton(layoutWidget);
        exams_button->setObjectName("exams_button");
        exams_button->setMinimumSize(QSize(0, 30));
        exams_button->setCursor(QCursor(Qt::PointingHandCursor));
        exams_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(exams_button);

        google_drive_button = new QPushButton(layoutWidget);
        google_drive_button->setObjectName("google_drive_button");
        google_drive_button->setMinimumSize(QSize(0, 30));
        google_drive_button->setCursor(QCursor(Qt::PointingHandCursor));
        google_drive_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font:  20px;\n"
"	color: white;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"	font:  17px;\n"
"	color: white;\n"
"	background-color:rgb(40, 40, 40);\n"
"}"));

        verticalLayout->addWidget(google_drive_button);

        settings_button = new QPushButton(sidepanel_widget);
        settings_button->setObjectName("settings_button");
        settings_button->setGeometry(QRect(40, 560, 149, 38));
        settings_button->setMinimumSize(QSize(0, 0));
        settings_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #fff;\n"
"  border: 0 solid #e2e8f0;\n"
"  border-radius: 5px;\n"
"  color: #0d172a;\n"
"  font-family: \"Basier circle\",-apple-system,system-ui,\"Segoe UI\",Roboto,\"Helvetica Neue\",Arial,\"Noto Sans\",sans-serif,\"Apple Color Emoji\",\"Segoe UI Emoji\",\"Segoe UI Symbol\",\"Noto Color Emoji\";\n"
"  font-size: 20px;\n"
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

        gridLayout->addWidget(sidepanel_widget, 1, 0, 1, 1);

        main_content_widget = new QWidget(centralwidget);
        main_content_widget->setObjectName("main_content_widget");
        main_content_widget->setStyleSheet(QString::fromUtf8("background:rgb(255, 242, 216);\n"
""));
        gridLayout_2 = new QGridLayout(main_content_widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        main_content_stack = new QStackedWidget(main_content_widget);
        main_content_stack->setObjectName("main_content_stack");
        main_content_stack->setStyleSheet(QString::fromUtf8(""));
        home_page = new QWidget();
        home_page->setObjectName("home_page");
        verticalLayout_17 = new QVBoxLayout(home_page);
        verticalLayout_17->setObjectName("verticalLayout_17");
        frame = new QFrame(home_page);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 56));
        frame->setStyleSheet(QString::fromUtf8("border:0px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        HomepageTitlebar = new QLabel(frame);
        HomepageTitlebar->setObjectName("HomepageTitlebar");
        HomepageTitlebar->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;"));
        HomepageTitlebar->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(HomepageTitlebar);


        verticalLayout_17->addWidget(frame);

        frame_7 = new QFrame(home_page);
        frame_7->setObjectName("frame_7");
        sizePolicy1.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy1);
        frame_7->setMinimumSize(QSize(0, 111));
        frame_7->setStyleSheet(QString::fromUtf8("border:0px;"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_7);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(30, -1, 30, -1);
        welcome = new QLabel(frame_7);
        welcome->setObjectName("welcome");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(welcome->sizePolicy().hasHeightForWidth());
        welcome->setSizePolicy(sizePolicy2);
        welcome->setMinimumSize(QSize(0, 0));
        welcome->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(255, 255, 255);\n"
"border-radius:13px;"));
        welcome->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(welcome);

        label = new QLabel(frame_7);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 6);

        verticalLayout_17->addWidget(frame_7);

        miniRoutineBox = new QGroupBox(home_page);
        miniRoutineBox->setObjectName("miniRoutineBox");
        sizePolicy1.setHeightForWidth(miniRoutineBox->sizePolicy().hasHeightForWidth());
        miniRoutineBox->setSizePolicy(sizePolicy1);
        miniRoutineBox->setMinimumSize(QSize(0, 111));
        miniRoutineBox->setStyleSheet(QString::fromUtf8("border:0px;"));
        horizontalLayout_3 = new QHBoxLayout(miniRoutineBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 20, 0, -1);

        verticalLayout_17->addWidget(miniRoutineBox);

        groupBox_2 = new QGroupBox(home_page);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(0, 0));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName("groupBox_7");

        horizontalLayout_5->addWidget(groupBox_7);

        widget = new QWidget(groupBox_2);
        widget->setObjectName("widget");
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        verticalLayout_8->addWidget(label_8);

        dropArea = new QGroupBox(widget);
        dropArea->setObjectName("dropArea");

        verticalLayout_8->addWidget(dropArea);

        verticalLayout_8->setStretch(0, 2);
        verticalLayout_8->setStretch(1, 3);

        horizontalLayout_5->addWidget(widget);

        horizontalLayout_5->setStretch(0, 6);
        horizontalLayout_5->setStretch(1, 2);

        verticalLayout_17->addWidget(groupBox_2);

        main_content_stack->addWidget(home_page);
        all_materials_page = new QWidget();
        all_materials_page->setObjectName("all_materials_page");
        verticalLayout_13 = new QVBoxLayout(all_materials_page);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(5, 5, 5, 5);
        frame_2 = new QFrame(all_materials_page);
        frame_2->setObjectName("frame_2");
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setMinimumSize(QSize(0, 56));
        frame_2->setStyleSheet(QString::fromUtf8("border:0px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:15px;"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_10);


        verticalLayout_13->addWidget(frame_2);

        allMaterialsPageTopBar = new QGroupBox(all_materials_page);
        allMaterialsPageTopBar->setObjectName("allMaterialsPageTopBar");
        sizePolicy1.setHeightForWidth(allMaterialsPageTopBar->sizePolicy().hasHeightForWidth());
        allMaterialsPageTopBar->setSizePolicy(sizePolicy1);
        allMaterialsPageTopBar->setMinimumSize(QSize(0, 56));
        allMaterialsPageTopBar->setStyleSheet(QString::fromUtf8("border:0px;"));
        horizontalLayout_22 = new QHBoxLayout(allMaterialsPageTopBar);
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(856, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_3);

        updateSemesterButton = new QPushButton(allMaterialsPageTopBar);
        updateSemesterButton->setObjectName("updateSemesterButton");
        updateSemesterButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_22->addWidget(updateSemesterButton);

        addCourseButton = new QPushButton(allMaterialsPageTopBar);
        addCourseButton->setObjectName("addCourseButton");
        addCourseButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_22->addWidget(addCourseButton);


        verticalLayout_13->addWidget(allMaterialsPageTopBar);

        tabWidget_2 = new QTabWidget(all_materials_page);
        tabWidget_2->setObjectName("tabWidget_2");
        main_materials_ui = new QWidget();
        main_materials_ui->setObjectName("main_materials_ui");
        tabWidget_2->addTab(main_materials_ui, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget_2->addTab(tab_2, QString());

        verticalLayout_13->addWidget(tabWidget_2);

        main_content_stack->addWidget(all_materials_page);
        notes_page = new QWidget();
        notes_page->setObjectName("notes_page");
        label_7 = new QLabel(notes_page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(370, 220, 351, 161));
        label_7->setStyleSheet(QString::fromUtf8("font: 26pt \"Segoe UI\";\n"
"color:black;"));
        frame_3 = new QFrame(notes_page);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 0, 1081, 56));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        main_content_stack->addWidget(notes_page);
        routine_page = new QWidget();
        routine_page->setObjectName("routine_page");
        verticalLayout_12 = new QVBoxLayout(routine_page);
        verticalLayout_12->setSpacing(5);
        verticalLayout_12->setObjectName("verticalLayout_12");
        frame_4 = new QFrame(routine_page);
        frame_4->setObjectName("frame_4");
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setMinimumSize(QSize(0, 56));
        frame_4->setStyleSheet(QString::fromUtf8("border:0px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 12, -1, 12);
        label_11 = new QLabel(frame_4);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:15px;"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_11);


        verticalLayout_12->addWidget(frame_4);

        groupBox_5 = new QGroupBox(routine_page);
        groupBox_5->setObjectName("groupBox_5");
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        groupBox_5->setMinimumSize(QSize(0, 40));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox{ border:0px solid black;}"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        changeRoutine = new QPushButton(groupBox_5);
        changeRoutine->setObjectName("changeRoutine");
        changeRoutine->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(changeRoutine);

        pushButton_2 = new QPushButton(groupBox_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_12->addWidget(groupBox_5);

        the_hecking_routine = new QGroupBox(routine_page);
        the_hecking_routine->setObjectName("the_hecking_routine");

        verticalLayout_12->addWidget(the_hecking_routine);

        main_content_stack->addWidget(routine_page);
        up_coming_page = new QWidget();
        up_coming_page->setObjectName("up_coming_page");
        verticalLayout_81 = new QVBoxLayout(up_coming_page);
        verticalLayout_81->setObjectName("verticalLayout_81");
        frame_5 = new QFrame(up_coming_page);
        frame_5->setObjectName("frame_5");
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setMinimumSize(QSize(0, 56));
        frame_5->setStyleSheet(QString::fromUtf8("border:0px;\n"
""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:15px;"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_12);


        verticalLayout_81->addWidget(frame_5);

        groupBox_6 = new QGroupBox(up_coming_page);
        groupBox_6->setObjectName("groupBox_6");
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);
        groupBox_6->setMinimumSize(QSize(0, 40));
        groupBox_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QGroupBox{background: #00000000}"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        addTaskButton = new QPushButton(groupBox_6);
        addTaskButton->setObjectName("addTaskButton");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(addTaskButton->sizePolicy().hasHeightForWidth());
        addTaskButton->setSizePolicy(sizePolicy4);
        addTaskButton->setMinimumSize(QSize(65, 0));

        horizontalLayout_4->addWidget(addTaskButton);

        upCommingChangeButton = new QPushButton(groupBox_6);
        upCommingChangeButton->setObjectName("upCommingChangeButton");
        sizePolicy4.setHeightForWidth(upCommingChangeButton->sizePolicy().hasHeightForWidth());
        upCommingChangeButton->setSizePolicy(sizePolicy4);
        upCommingChangeButton->setMinimumSize(QSize(65, 0));

        horizontalLayout_4->addWidget(upCommingChangeButton);

        upCommingBackButton = new QPushButton(groupBox_6);
        upCommingBackButton->setObjectName("upCommingBackButton");
        sizePolicy4.setHeightForWidth(upCommingBackButton->sizePolicy().hasHeightForWidth());
        upCommingBackButton->setSizePolicy(sizePolicy4);
        upCommingBackButton->setMinimumSize(QSize(65, 0));

        horizontalLayout_4->addWidget(upCommingBackButton);

        upCommingExtraButton = new QPushButton(groupBox_6);
        upCommingExtraButton->setObjectName("upCommingExtraButton");
        sizePolicy4.setHeightForWidth(upCommingExtraButton->sizePolicy().hasHeightForWidth());
        upCommingExtraButton->setSizePolicy(sizePolicy4);
        upCommingExtraButton->setMinimumSize(QSize(65, 0));

        horizontalLayout_4->addWidget(upCommingExtraButton);


        verticalLayout_81->addWidget(groupBox_6);

        groupBox_3 = new QGroupBox(up_coming_page);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_82 = new QVBoxLayout(groupBox_3);
        verticalLayout_82->setObjectName("verticalLayout_82");
        bal = new QScrollArea(groupBox_3);
        bal->setObjectName("bal");
        bal->setWidgetResizable(true);
        upNextArea = new QWidget();
        upNextArea->setObjectName("upNextArea");
        upNextArea->setGeometry(QRect(0, 0, 42, 18));
        verticalLayout_83 = new QVBoxLayout(upNextArea);
        verticalLayout_83->setObjectName("verticalLayout_83");
        bal->setWidget(upNextArea);

        verticalLayout_82->addWidget(bal);


        verticalLayout_81->addWidget(groupBox_3);

        main_content_stack->addWidget(up_coming_page);
        assignments_page = new QWidget();
        assignments_page->setObjectName("assignments_page");
        label_3 = new QLabel(assignments_page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(400, 310, 351, 161));
        label_3->setStyleSheet(QString::fromUtf8("font: 26pt \"Segoe UI\";\n"
"color:black;"));
        label_4 = new QLabel(assignments_page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 80, 351, 161));
        label_4->setStyleSheet(QString::fromUtf8("font: 26pt \"Segoe UI\";\n"
"color:black;"));
        frame_6 = new QFrame(assignments_page);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(1, 0, 1081, 56));
        frame_6->setStyleSheet(QString::fromUtf8("border:0px;"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_13 = new QLabel(frame_6);
        label_13->setObjectName("label_13");
        label_13->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:15px;"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_13);

        main_content_stack->addWidget(assignments_page);
        google_drive_page = new QWidget();
        google_drive_page->setObjectName("google_drive_page");
        verticalLayout_84 = new QVBoxLayout(google_drive_page);
        verticalLayout_84->setSpacing(5);
        verticalLayout_84->setObjectName("verticalLayout_84");
        frame_8 = new QFrame(google_drive_page);
        frame_8->setObjectName("frame_8");
        sizePolicy1.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy1);
        frame_8->setStyleSheet(QString::fromUtf8("border:0px;"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_8);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_15 = new QLabel(frame_8);
        label_15->setObjectName("label_15");
        label_15->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:10px;"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_15);


        verticalLayout_84->addWidget(frame_8);

        groupBox_4 = new QGroupBox(google_drive_page);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setStyleSheet(QString::fromUtf8("border: 1px solid #a6a6a6;\n"
"border-radius:15px;"));
        horizontalLayout_36 = new QHBoxLayout(groupBox_4);
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        groupBox_9 = new QGroupBox(groupBox_4);
        groupBox_9->setObjectName("groupBox_9");
        sizePolicy4.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy4);
        groupBox_9->setMinimumSize(QSize(1041, 635));
        groupBox_9->setStyleSheet(QString::fromUtf8("border:0px;"));
        horizontalLayout_78 = new QHBoxLayout(groupBox_9);
        horizontalLayout_78->setObjectName("horizontalLayout_78");
        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_78->addItem(horizontalSpacer_11);

        link_list = new QListWidget(groupBox_9);
        link_list->setObjectName("link_list");
        link_list->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;"));

        horizontalLayout_78->addWidget(link_list);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_78->addItem(horizontalSpacer_6);

        groupBox_8 = new QGroupBox(groupBox_9);
        groupBox_8->setObjectName("groupBox_8");
        sizePolicy4.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy4);
        groupBox_8->setMinimumSize(QSize(250, 608));
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox{ border-radius:20px; background-color:#ffebc2}\n"
""));
        verticalLayout_85 = new QVBoxLayout(groupBox_8);
        verticalLayout_85->setObjectName("verticalLayout_85");
        verticalGroupBox = new QGroupBox(groupBox_8);
        verticalGroupBox->setObjectName("verticalGroupBox");
        sizePolicy1.setHeightForWidth(verticalGroupBox->sizePolicy().hasHeightForWidth());
        verticalGroupBox->setSizePolicy(sizePolicy1);
        verticalGroupBox->setStyleSheet(QString::fromUtf8("border:0px;"));
        verticalLayout_18 = new QVBoxLayout(verticalGroupBox);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(verticalGroupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
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

        verticalLayout_18->addWidget(pushButton_5);

        linkIn = new QLineEdit(verticalGroupBox);
        linkIn->setObjectName("linkIn");
        linkIn->setMinimumSize(QSize(0, 30));
        linkIn->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;"));

        verticalLayout_18->addWidget(linkIn);

        link_name = new QLineEdit(verticalGroupBox);
        link_name->setObjectName("link_name");
        link_name->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;"));

        verticalLayout_18->addWidget(link_name);

        pushButton_9 = new QPushButton(verticalGroupBox);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
"\n"
"\n"
""));

        verticalLayout_18->addWidget(pushButton_9);

        addLinkButton = new QPushButton(verticalGroupBox);
        addLinkButton->setObjectName("addLinkButton");
        addLinkButton->setStyleSheet(QString::fromUtf8("\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
"\n"
"\n"
""));

        verticalLayout_18->addWidget(addLinkButton);

        removeLink_button = new QPushButton(verticalGroupBox);
        removeLink_button->setObjectName("removeLink_button");
        removeLink_button->setStyleSheet(QString::fromUtf8("\n"
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
"  background-color: #221D23;\n"
"  color: #fff;\n"
"}\n"
"\n"
"\n"
""));

        verticalLayout_18->addWidget(removeLink_button);


        verticalLayout_85->addWidget(verticalGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_85->addItem(verticalSpacer);

        current_link = new QLabel(groupBox_8);
        current_link->setObjectName("current_link");
        sizePolicy4.setHeightForWidth(current_link->sizePolicy().hasHeightForWidth());
        current_link->setSizePolicy(sizePolicy4);
        current_link->setMinimumSize(QSize(245, 30));
        current_link->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 10px;\n"
"font-size: 15px;\n"
"  font-weight: 600;\n"
"  line-height: 1;\n"
"  padding: 2px 2px;"));
        current_link->setAlignment(Qt::AlignCenter);

        verticalLayout_85->addWidget(current_link);


        horizontalLayout_78->addWidget(groupBox_8);


        horizontalLayout_36->addWidget(groupBox_9);


        verticalLayout_84->addWidget(groupBox_4);

        main_content_stack->addWidget(google_drive_page);
        settings_page = new QWidget();
        settings_page->setObjectName("settings_page");
        frame_9 = new QFrame(settings_page);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(0, 0, 1081, 56));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_9);
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_16 = new QLabel(frame_9);
        label_16->setObjectName("label_16");
        label_16->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_16);

        main_content_stack->addWidget(settings_page);
        exams_page = new QWidget();
        exams_page->setObjectName("exams_page");
        frame_10 = new QFrame(exams_page);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(0, 0, 1081, 56));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_10);
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_17 = new QLabel(frame_10);
        label_17->setObjectName("label_17");
        label_17->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_17);

        main_content_stack->addWidget(exams_page);
        make_routine = new QWidget();
        make_routine->setObjectName("make_routine");
        verticalLayout_15 = new QVBoxLayout(make_routine);
        verticalLayout_15->setObjectName("verticalLayout_15");
        frame_11 = new QFrame(make_routine);
        frame_11->setObjectName("frame_11");
        sizePolicy1.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy1);
        frame_11->setMinimumSize(QSize(0, 56));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(frame_11);
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_81 = new QLabel(frame_11);
        label_81->setObjectName("label_81");
        label_81->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:black;\n"
"background:rgb(193, 183, 163);\n"
"border-radius:18px;"));
        label_81->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_81);


        verticalLayout_15->addWidget(frame_11);

        mainRoutine_groupbox_2 = new QGroupBox(make_routine);
        mainRoutine_groupbox_2->setObjectName("mainRoutine_groupbox_2");
        mainRoutine_groupbox_2->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(mainRoutine_groupbox_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(361, 222, 342, 221));
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMinimumSize(QSize(342, 221));
        groupBox->setStyleSheet(QString::fromUtf8("border:0px;"));
        verticalLayout_73 = new QVBoxLayout(groupBox);
        verticalLayout_73->setObjectName("verticalLayout_73");
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        sizePolicy4.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy4);
        label_9->setMinimumSize(QSize(200, 150));
        label_9->setStyleSheet(QString::fromUtf8("color:black;\n"
"font:20px;\n"
""));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_73->addWidget(label_9);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy4.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy4);
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_35->addWidget(pushButton_4);


        verticalLayout_73->addLayout(horizontalLayout_35);


        verticalLayout_15->addWidget(mainRoutine_groupbox_2);

        main_content_stack->addWidget(make_routine);

        gridLayout_2->addWidget(main_content_stack, 0, 0, 1, 1);


        gridLayout->addWidget(main_content_widget, 0, 1, 2, 1);

        info_widget = new QWidget(centralwidget);
        info_widget->setObjectName("info_widget");
        sizePolicy1.setHeightForWidth(info_widget->sizePolicy().hasHeightForWidth());
        info_widget->setSizePolicy(sizePolicy1);
        info_widget->setMinimumSize(QSize(0, 93));
        info_widget->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"  stop: 0 black, \n"
"  stop: 1.0 white);\n"
""));
        profile_logo = new QLabel(info_widget);
        profile_logo->setObjectName("profile_logo");
        profile_logo->setGeometry(QRect(20, 20, 51, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MX")});
        font1.setBold(false);
        font1.setItalic(false);
        profile_logo->setFont(font1);
        profile_logo->setStyleSheet(QString::fromUtf8("background: solid red;\n"
"border-radius: 25px;\n"
"font: 30px;\n"
"color: black;\n"
"font-family:Comic Sans MX;"));
        profile_logo->setAlignment(Qt::AlignCenter);
        verticalGroupBox1 = new QGroupBox(info_widget);
        verticalGroupBox1->setObjectName("verticalGroupBox1");
        verticalGroupBox1->setGeometry(QRect(80, 20, 148, 51));
        verticalGroupBox1->setStyleSheet(QString::fromUtf8("background:00000000;\n"
"color:white;\n"
"border:0px;\n"
"font: 12pt \"Segoe UI\";"));
        verticalGroupBox1->setAlignment(Qt::AlignCenter);
        verticalLayout_16 = new QVBoxLayout(verticalGroupBox1);
        verticalLayout_16->setSpacing(4);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalGroupBox1);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_5);

        currentYear = new QLabel(verticalGroupBox1);
        currentYear->setObjectName("currentYear");
        currentYear->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(currentYear);


        gridLayout->addWidget(info_widget, 0, 0, 1, 1);

        primary_window->setCentralWidget(centralwidget);

        retranslateUi(primary_window);

        main_content_stack->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(primary_window);
    } // setupUi

    void retranslateUi(QMainWindow *primary_window)
    {
        primary_window->setWindowTitle(QCoreApplication::translate("primary_window", "SIMS Home", nullptr));
        home_button->setText(QCoreApplication::translate("primary_window", "Home", nullptr));
        all_material_button->setText(QCoreApplication::translate("primary_window", "All Materials", nullptr));
        notes_button->setText(QCoreApplication::translate("primary_window", "Notes", nullptr));
        routine_button->setText(QCoreApplication::translate("primary_window", "Routine", nullptr));
        up_coming_button->setText(QCoreApplication::translate("primary_window", "Upcoming Events", nullptr));
        assignments_button->setText(QCoreApplication::translate("primary_window", "Assignments", nullptr));
        exams_button->setText(QCoreApplication::translate("primary_window", "Exams", nullptr));
        google_drive_button->setText(QCoreApplication::translate("primary_window", "External Links", nullptr));
        settings_button->setText(QCoreApplication::translate("primary_window", "Settings", nullptr));
        HomepageTitlebar->setText(QCoreApplication::translate("primary_window", "<<<Home>>>", nullptr));
        welcome->setText(QCoreApplication::translate("primary_window", "   Morning Sadman", nullptr));
        label->setText(QCoreApplication::translate("primary_window", "TextLabel", nullptr));
        miniRoutineBox->setTitle(QCoreApplication::translate("primary_window", "Today's Routine:", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_7->setTitle(QString());
        label_8->setText(QCoreApplication::translate("primary_window", "Drop files into the box below:", nullptr));
        dropArea->setTitle(QString());
        label_10->setText(QCoreApplication::translate("primary_window", "Materials", nullptr));
        allMaterialsPageTopBar->setTitle(QString());
        updateSemesterButton->setText(QCoreApplication::translate("primary_window", "Semester Settings", nullptr));
        addCourseButton->setText(QCoreApplication::translate("primary_window", "Add Course", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(main_materials_ui), QCoreApplication::translate("primary_window", "Menu", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("primary_window", "Tab 2", nullptr));
        label_7->setText(QCoreApplication::translate("primary_window", "notes fotes", nullptr));
        label_2->setText(QCoreApplication::translate("primary_window", "<<<Notes>>>", nullptr));
        label_11->setText(QCoreApplication::translate("primary_window", "Routine", nullptr));
        groupBox_5->setTitle(QString());
        changeRoutine->setText(QCoreApplication::translate("primary_window", "Change", nullptr));
        pushButton_2->setText(QCoreApplication::translate("primary_window", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("primary_window", "PushButton", nullptr));
        the_hecking_routine->setTitle(QString());
        label_12->setText(QCoreApplication::translate("primary_window", "Up-Coming", nullptr));
        groupBox_6->setTitle(QString());
        addTaskButton->setText(QCoreApplication::translate("primary_window", "Add", nullptr));
        upCommingChangeButton->setText(QCoreApplication::translate("primary_window", "Change", nullptr));
        upCommingBackButton->setText(QCoreApplication::translate("primary_window", "Back", nullptr));
        upCommingExtraButton->setText(QCoreApplication::translate("primary_window", "Button", nullptr));
        groupBox_3->setTitle(QString());
        label_3->setText(QCoreApplication::translate("primary_window", "assignments", nullptr));
        label_4->setText(QCoreApplication::translate("primary_window", "assignemnts", nullptr));
        label_13->setText(QCoreApplication::translate("primary_window", "Assignments", nullptr));
        label_15->setText(QCoreApplication::translate("primary_window", "External Links", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_9->setTitle(QString());
        groupBox_8->setTitle(QString());
        pushButton_5->setText(QCoreApplication::translate("primary_window", "Go link", nullptr));
        linkIn->setPlaceholderText(QCoreApplication::translate("primary_window", "  Enter new link", nullptr));
        link_name->setPlaceholderText(QCoreApplication::translate("primary_window", "  Enter link name", nullptr));
        pushButton_9->setText(QCoreApplication::translate("primary_window", "Change link", nullptr));
        addLinkButton->setText(QCoreApplication::translate("primary_window", "Add Link", nullptr));
        removeLink_button->setText(QCoreApplication::translate("primary_window", "Remove Link", nullptr));
        current_link->setText(QCoreApplication::translate("primary_window", "Status bar", nullptr));
        label_16->setText(QCoreApplication::translate("primary_window", "<<<Settings>>>", nullptr));
        label_17->setText(QCoreApplication::translate("primary_window", "<<<Exams>>>", nullptr));
        label_81->setText(QCoreApplication::translate("primary_window", "<<<Routine>>>", nullptr));
        mainRoutine_groupbox_2->setTitle(QString());
        groupBox->setTitle(QString());
        label_9->setText(QCoreApplication::translate("primary_window", "CLick the button below \n"
"to get started with your first routine!", nullptr));
        pushButton_4->setText(QCoreApplication::translate("primary_window", "PushButton", nullptr));
        profile_logo->setText(QCoreApplication::translate("primary_window", "M", nullptr));
        label_5->setText(QCoreApplication::translate("primary_window", "The current semester", nullptr));
        currentYear->setText(QCoreApplication::translate("primary_window", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class primary_window: public Ui_primary_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMARY_WINDOW_H
