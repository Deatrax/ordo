QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    #functions\everything.c \
    StylesSheets.cpp \
    addtask.cpp \
    changesemester.cpp \
    course_item.cpp \
    first_run.cpp \
    main.cpp \
    mainwindow.cpp \
    flowlayout.cpp \
    makeroutine.cpp \
    materialelement.cpp \
    materialnavcell.cpp \
    materialsnav.cpp \
    modifycoursecell.cpp \
    new_routine.cpp \
    newbox.cpp \
    primary_window.cpp \
    routineunit.cpp \
    settings_page.cpp \
    upnextelement.cpp \
    browserwindow.cpp \
    routinecell.cpp \
    routinetimecell.cpp \
    FileDropWidget.cpp

HEADERS += \
    StylesSheets.h \
    addtask.h \
    changesemester.h \
    course_item.h \
    first_run.h \
    mainwindow.h \
    flowlayout.h \
    makeroutine.h \
    materialelement.h \
    materialnavcell.h \
    materialsnav.h \
    modifycoursecell.h \
    new_routine.h \
    newbox.h \
    primary_window.h \
    routineunit.h \
    settings_page.h \
    upnextelement.h \
    browserwindow.h \
    routinecell.h \
    routinetimecell.h \
    FileDropWidget.h

FORMS += \
    addtask.ui \
    changesemester.ui \
    course_item.ui \
    first_run.ui \
    mainwindow.ui \
    makeroutine.ui \
    materialelement.ui \
    materialnavcell.ui \
    materialsnav.ui \
    modifycoursecell.ui \
    new_routine.ui \
    newbox.ui \
    primary_window.ui \
    routineunit.ui \
    settings_page.ui \
    upnextelement.ui \
    browserwindow.ui \
    routinecell.ui \
    routinetimecell.ui \

RESOURCES += \
    images/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
