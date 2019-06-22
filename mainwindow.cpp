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
    isMusicPlaying = false;
    connect(clockSync, SIGNAL(timeout()), this, SLOT(timeSync()));
    clockSync->start(1000);
    currentSong = 0;
}

void MainWindow::timeSync() //Time is synced here
{
    int hour = QTime::currentTime().hour();
    int minute = QTime::currentTime().minute();
    int second = QTime::currentTime().second();

    if(this->isMusicPlaying == false)
    {
        for(QTime time : startTimeList)
        {
            if(time.hour() == hour && time.minute() == minute && time.second() == second && currentSong < musicList.size())
            {
                isMusicPlaying = true;
                ui->musicList->setCurrentRow(currentSong);
                players->setURL(musicList.at(currentSong)->getURL());
                players->play();
            }
        }
        ui->statusLabel->setText("Current Time: " + QString::number(hour) + ":" + QString::number(minute) + ":" + QString::number(second));
    }else{
        for(QTime time : endTimeList)
        {
            if(time.hour() == hour && time.minute() == minute && time.second() == second)
            {
                isMusicPlaying = false;
                players->stop();
                currentSong++;
                if(currentSong < musicList.size())
                {
                    currentSong = 0;
                }
                ui->musicList->setCurrentRow(currentSong);
            }
        }
        ui->timeProgressBar->setMaximum(players->getLength());
        ui->timeProgressBar->setValue(players->getTimeStamp());
        ui->statusLabel->setText("Current Time: " + QString::number(hour) + ":" + QString::number(minute) + ":" + QString::number(second) + " Current Video: " + videoName);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    musicDetail getDetail;
    if(getDetail.exec() == QDialog::Accepted)
    {
        musicItem *item = new musicItem(getDetail.getName(), getDetail.getURL());
        musicList.append(item);
        players->setURL(getDetail.getURL());
        players->checkURL();
        currentItem = item;
        this->setWindowTitle("Please wait... Fetching YouTube Video...");
        ui->statusLabel->setText("Please wait... Fetching YouTube Video...");
        clockSync->stop();
        connect(players, SIGNAL(nameChanged(QString)), this, SLOT(getTitle(QString)));
    }
}

void MainWindow::getTitle(QString name)
{
    musicList.at(musicList.indexOf(currentItem))->setName(name);
    updateUiList();
    disableButtons();
    this->setWindowTitle("Facey Music Player");
    clockSync->start();
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
        QListWidgetItem *widgets = new QListWidgetItem(this->startTimeList.at(a).toString("hh:mm:ss") + " - " + this->endTimeList.at(a).toString("hh:mm:ss"));
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
    if(setDetail.exec() == QDialog::Accepted)
    {
    musicList.replace(ui->musicList->currentRow(), new musicItem(setDetail.getName(), setDetail.getURL()));
    updateUiList();
    disableButtons();
    }
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
    this->videoName = musicList.at(ui->musicList->currentRow())->getName();
    isMusicPlaying = true;
    players->play();
}

void MainWindow::on_stopButton_clicked()
{
    players->stop();
    disableButtons();
    isMusicPlaying = false;
}

void MainWindow::on_addTimeButton_clicked() //https://stackoverflow.com/questions/29571205/error-lnk2019-unresolved-external-symbol-c-in-qt-platform
{
    scheduleDetail getDetail;
    if(getDetail.exec() == QDialog::Accepted)
    {
    startTimeList.append(getDetail.getStartTime());
    endTimeList.append(getDetail.getEndTime());
    updateUiList();
    }
}
