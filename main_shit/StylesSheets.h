#ifndef STYLESSHEETS_H
#define STYLESSHEETS_H

#include<QString>

extern QString listWidgetStyleSheet;
extern QString buttonStyle;
extern QString elementsStyle;
extern QString islandStyle;
extern QString LabelStyleBordered;
extern QString LabelStyleBorderless;
extern QString mainBG;
extern QString messageboxStyle;

void loadThemeFromFile();  // Function to load the theme and apply it

#endif // STYLESSHEETS_H
