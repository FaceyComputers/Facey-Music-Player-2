#include "musicdetail.h"
#include "ui_musicdetail.h"

musicDetail::musicDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::musicDetail)
{
    ui->setupUi(this);
    ui->nameEdit->setVisible(false);
    ui->label_2->setVisible(false);
}

musicDetail::~musicDetail()
{
    delete ui;
}

QString musicDetail::getName()
{
    return ui->nameEdit->text();
}

QString musicDetail::getURL()
{
    return ui->urlEdit->text();
}

void musicDetail::setName(QString text)
{
    ui->nameEdit->setText(text);
}

void musicDetail::setURL(QString text)
{
    ui->urlEdit->setText(text);
}
