#include "musicdetail.h"
#include "ui_musicdetail.h"

musicDetail::musicDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::musicDetail)
{
    ui->setupUi(this);
}

musicDetail::~musicDetail()
{
    delete ui;
}
