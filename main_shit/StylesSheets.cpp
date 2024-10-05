#include "StylesSheets.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "functions/everything.c"

QString listWidgetStyleSheet;
QString buttonStyle;
QString elementsStyle;
QString islandStyle;
QString LabelStyleBordered;
QString LabelStyleBorderless;
QString mainBG;
QString messageboxStyle;
void applyLightTheme();
void applyDarkTheme();

void loadThemeFromFile() {
    // Open the configuration file that stores the user's theme choice
    char flnam[300] = "theme.txt";
    make_appData_filePath(flnam);
    QString flnamStr = flnam;
    qDebug() << "Theme file path: " << flnamStr;

    QFile file(flnamStr);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open theme.txt, using default theme";
        // Fallback to default theme
        applyLightTheme();
        return;
    }

    QTextStream in(&file);
    QString theme = in.readLine().trimmed();  // Trimmed to remove any extra spaces/newlines
    file.close();

    qDebug() << "Theme read from file: " << theme;

    if (theme == "light") {
        applyLightTheme();
    } else if (theme == "dark") {
        applyDarkTheme();
    } else {
        qDebug() << "Unknown theme, using default (light)";
        applyLightTheme();
    }
}

void applyDarkTheme(){
    NULL;
}

void applyLightTheme() {
    listWidgetStyleSheet =
        "QListWidget {"
        "   font-size: 15px;"
        //"   font-weight: 200;"
        "}"
        "QListWidget::item {"
        "   background-color: #FFFFF0;"
        "   color: #0d172a;"
        "   border: 0px solid black;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   margin: 3px;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: #06A77D;"
        "   color: white;"
        "   border: 1px solid black;"
        "}";

    buttonStyle =
        "QPushButton {"
        "background-color: #fff;"
        "border: 0 solid #e2e8f0;"
        "border-radius: 5px;"
        "color: #0d172a;"
        "font-family: 'Basier circle',-apple-system,system-ui,'Segoe UI',Roboto,'Helvetica Neue',Arial,'Noto Sans',sans-serif,'Apple Color Emoji','Segoe UI Emoji','Segoe UI Symbol','Noto Color Emoji';"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"
        "padding: 5px 5px;"
        "text-align: center;"
        "text-decoration:none #0d172a solid;"
        "}"

        "QPushButton:hover {"
        "background-color: #221D23;"
        "color: #fff;"
        "}";

    elementsStyle =
        "border-radius:15px; "
        "background-color: #FFFFF0;"
        "color: #0d172a;"
        "border: 0px solid black;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;";

    islandStyle =
        "border-radius:20px; "
        "background-color:#ffebc2";

    LabelStyleBordered =
        "border:2px solid black;"
        "border-radius: 10px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"
        "padding: 2px 2px;"
        "color:black";

    LabelStyleBorderless =
        "border:0px solid black;"
        "border-radius: 10px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"
        "padding: 2px 2px;"
        "color:black;"
        "background:#FFFFF0";

    mainBG = "background:#FFF2D8";

    messageboxStyle=
        "QMessageBox {"
                "    font-size: 15px;"
                "    font-weight: 600;"
                "    line-height: 1;"
                "    padding: 2px 2px;"
                "    color: black;"
                "background:#FFF2D8"
                "}";
}

// Similarly, add applyDarkTheme()
