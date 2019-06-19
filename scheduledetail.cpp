#include "scheduledetail.h"
#include "ui_scheduledetail.h"

scheduleDetail::scheduleDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scheduleDetail)
{
    ui->setupUi(this);
}

scheduleDetail::~scheduleDetail()
{
    delete ui;
}

void scheduleDetail::setTime(QTime start, QTime end)
{
    ui->startTime->setTime(start);
    ui->endTime->setTime(end);
}

void scheduleDetail::setStartTime(QTime time)
{
    ui->startTime->setTime(time);
}

void scheduleDetail::setEndTime(QTime time)
{
    ui->endTime->setTime(time);
}

QTime scheduleDetail::getStartTime()
{
    return ui->startTime->time();
}

QTime scheduleDetail::getEndTime()
{
    return ui->endTime->time();
}
