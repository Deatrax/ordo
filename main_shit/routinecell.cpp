#include "routinecell.h"
#include "ui_routinecell.h"

routineCell::routineCell(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::routineCell)
{
    ui->setupUi(this);
    // Assuming `separator` is a QSpacerItem* in your UI
    ui->separator->changeSize(0, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

    // After changing the size, update the layout to apply the changes
    //ui->invalidate();  // Replace `layout()` with your layout's name if different

    // ui->headUnit->setStyleSheet(
    //     "border-radius:15px; background-color:#ffebc2;"
    //     "background-color: #FFFFF0;"
    //     "color: #0d172a;"
    //     "border: 0px solid black;"
    //     "border-radius: 5px;"
    //     "font-size: 15px;"
    //     "font-weight: 600;"
    //     "line-height: 1;"/*
    //     "padding: 5px;"
    //     "margin: 3px;"*/
    //     );


    //ui->headUnit->setContentsMargins(9,9,9,9);
    // ui->groupBox->setStyleSheet(
    //     "QGroupBox{"
    //     "padding: 0px;"
    //     "margin: 0px;"
    //     "}"
    //     );
    // ui->groupBox_2->setStyleSheet(
    //     "QGroupBox{"
    //     "padding: 0px;"
    //     "margin: 0px;"
    //     "}"
    //     );
}

routineCell::~routineCell()
{
    delete ui;

}

void routineCell::initialize(char nam[],char ins[],char loca[]){

    name=nam;
    inst=ins;
    Locl=loca;

    ui->name->setText(name);
    ui->Instructor->setText(inst);
    ui->location->setText(Locl);
    ui->headUnit->setStyleSheet(
        "border-radius:15px; background-color:#ffebc2;"
        "background-color: #FFFFF0;"
        "color: #0d172a;"
        "border: 0px solid black;"
        //"border-radius: 5px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"/*
        "padding: 5px;"
        "margin: 3px;"*/
        );
    ui->separator->changeSize(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
}

void routineCell::initialize(QString nam,QString ins,QString loca){
    name=nam;
    inst=ins;
    Locl=loca;

    ui->name->setText(name);
    ui->Instructor->setText(inst);
    ui->location->setText(Locl);
    ui->headUnit->setStyleSheet(
        "border-radius:15px; background-color:#ffebc2;"
        "background-color: #FFFFF0;"
        "color: #0d172a;"
        "border: 0px solid black;"
        //"border-radius: 5px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"/*
        "padding: 5px;"
        "margin: 3px;"*/
        );
    ui->separator->changeSize(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
}

void routineCell::setSame(){

    ui->name->setText("");
    ui->Instructor->setText("");
    ui->location->setText("");
    ui->headUnit->setStyleSheet(
        "border-bottom-left-radius:15px;"
        "border-bottom-right-radius:15px;"
        "border-top-left-radius:0px;"
        "border-top-right-radius:0px;"
        " background-color:#ffebc2;"
        "background-color: #FFFFF0;"
        "color: #0d172a;"
        "border: 0px solid black;"
        //"border-radius: 5px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"/*
        "padding: 5px;"
        "margin: 3px;"*/
        );
    ui->separator->changeSize(0, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);
}

void routineCell::setFree(){

    ui->name->setText("");
    ui->Instructor->setText("");
    ui->location->setText("");
    setStyleSheet(
        // "border-radius:; "
        // "background-color:;"
        // "background-color: ;"
        // "color: ;"
        // "border: ;"
        // "border-radius: 5px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"
    );
}

void routineCell::peviousOne(){

    ui->headUnit->setStyleSheet(
        "border-bottom-left-radius:0px;"
        "border-bottom-right-radius:0px;"
        "border-top-left-radius:15px;"
        "border-top-right-radius:15px;"
        " background-color:#ffebc2;"
        "background-color: #FFFFF0;"
        "color: #0d172a;"
        "border: 0px solid black;"
        //"border-radius: 5px;"
        "font-size: 15px;"
        "font-weight: 600;"
        "line-height: 1;"/*
        "padding: 5px;"
        "margin: 3px;"*/
        );
    ui->separator->changeSize(0, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);
}
