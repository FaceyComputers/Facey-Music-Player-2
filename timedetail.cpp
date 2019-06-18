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
