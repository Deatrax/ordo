#include "new_routine.h"
#include "qgraphicseffect.h"
#include "qpropertyanimation.h"
#include "qtimer.h"
#include "ui_new_routine.h"

new_routine::new_routine(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::new_routine)
{
    ui->setupUi(this);
}

new_routine::~new_routine()
{
    delete ui;
}

void new_routine::set_period(QString str){

    ui->period_no->setText(str);
}

void new_routine::get_info()
{
    class_name=ui->class_name->text();
    instructor=ui->instructor->text();
    location=ui->class_location->text();
}

void new_routine::clear_info(){

    ui->class_name->clear();
    ui->class_location->clear();
    ui->instructor->clear();
}

void new_routine::warn(){
    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(ui->class_name);
    ui->class_name->setGraphicsEffect(effect);

    QPropertyAnimation* animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(1000); // Duration in milliseconds
    animation->setLoopCount(2);   // Number of flashes (2 flashes = 4 opacity changes)
    animation->setKeyValueAt(0, 1.0);   // Fully visible
    animation->setKeyValueAt(0.5, 0.0); // Fully invisible
    animation->setKeyValueAt(1, 1.0);   // Fully visible again

    // Change the background color to red during the animation
    QTimer::singleShot(100, [this]() {
        ui->class_name->setStyleSheet(
            "border:2px solid rgb(59, 59, 59);"
            "border-radius: 10px;"
            "font-size: 15px;"
            "font-weight: 600;"
            "line-height: 1;"
            "padding: 2px 2px;"
            "background:red;"
            );
    });

    // Reset the background color back to normal after the animation finishes
    connect(animation, &QPropertyAnimation::finished, this, [this]() {
        ui->class_name->setStyleSheet(
            "border:2px solid rgb(59, 59, 59);"
            "border-radius: 10px;"
            "font-size: 15px;"
            "font-weight: 600;"
            "line-height: 1;"
            "padding: 2px 2px;"
            "background:white;"
            );
    });

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
