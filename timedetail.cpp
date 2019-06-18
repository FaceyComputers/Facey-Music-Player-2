#include "timedetail.h"
#include "ui_timedetail.h"

timeDetail::timeDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeDetail)
{
    ui->setupUi(this);
}

timeDetail::~timeDetail()
{
    delete ui;
}

void timeDetail::setTime(QTime start, QTime end)
{
    ui->startTime->setTime(start);
    ui->endTime->setTime(end);
}

void timeDetail::setStartTime(QTime time)
{
    ui->startTime->setTime(time);
}

void timeDetail::setEndTime(QTime time)
{
    ui->endTime->setTime(time);
}

QTime timeDetail::getStartTime()
{
    return ui->startTime->time();
}

QTime timeDetail::getEndTime()
{
    return ui->endTime->time();
}


