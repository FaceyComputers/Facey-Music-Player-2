#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->players = new player(this);
    clockSync = new QTimer(this);
    time = new QTime();
    connect(clockSync, SIGNAL(timeout()), this, SLOT(timeSync()));
    clockSync->start(1000);
}

void MainWindow::timeSync() //Time is synced here
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    musicDetail getDetail;
    getDetail.exec();
    musicList.append(new musicItem(getDetail.getName(), getDetail.getURL()));
    updateUiList();
    disableButtons();
}

void MainWindow::updateUiList()
{
    for(int a = 0; a < this->musicList.size(); a++) //Clears the list
    {
        delete ui->musicList->takeItem(a);
    }
    for(int a = 0; a < this->startTimeList.size(); a++)
    {
        delete ui->scheduleList->takeItem(a);
    }

    ui->musicList->clear();
    ui->scheduleList->clear();

    for(int a = 0; a < this->musicList.size(); a++) //Adds to the list
    {
        QListWidgetItem *widgets = new QListWidgetItem(this->musicList.at(a)->getName());
        widgets->setToolTip(this->musicList.at(a)->getURL());
        ui->musicList->addItem(widgets);
    }
    for(int a = 0; a < this->startTimeList.size(); a++) //Adds to the list
    {
        QListWidgetItem *widgets = new QListWidgetItem(this->startTimeList.at(a).toString("hh:ms") + " - " + this->endTimeList.at(a).toString("hh:ms"));
        ui->scheduleList->addItem(widgets);
    }
}

void MainWindow::on_removeButton_clicked()
{
    musicList.removeAt(ui->musicList->currentRow());
    updateUiList();
    disableButtons();
}

void MainWindow::on_editButton_clicked()
{
    musicDetail setDetail;
    setDetail.setName(musicList.at(ui->musicList->currentRow())->getName());
    setDetail.setURL(musicList.at(ui->musicList->currentRow())->getURL());
    setDetail.exec();
    musicList.replace(ui->musicList->currentRow(), new musicItem(setDetail.getName(), setDetail.getURL()));
    updateUiList();
    disableButtons();
}

void MainWindow::disableButtons()
{
    ui->editButton->setEnabled(false);
    ui->removeButton->setEnabled(false);
    ui->moveButton->setEnabled(false);
    ui->playButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
}

void MainWindow::on_musicList_itemClicked(QListWidgetItem *item)
{
    ui->editButton->setEnabled(true);
    ui->removeButton->setEnabled(true);
    ui->moveButton->setEnabled(true);
    ui->playButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
}

void MainWindow::on_playButton_clicked()
{
    players->setURL(musicList.at(ui->musicList->currentRow())->getURL());
    players->play();
}

void MainWindow::on_stopButton_clicked()
{
    players->stop();
    disableButtons();

}

void MainWindow::on_addTimeButton_clicked() //https://stackoverflow.com/questions/29571205/error-lnk2019-unresolved-external-symbol-c-in-qt-platform
{
    scheduleDetail getDetail;
    getDetail.exec();
    startTimeList.append(getDetail.getStartTime());
    endTimeList.append(getDetail.getEndTime());
    updateUiList();
}
