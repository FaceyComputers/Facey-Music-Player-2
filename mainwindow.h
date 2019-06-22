#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scheduledetail.h"
#include <QMainWindow>
#include <QDebug>
#include <QListWidgetItem>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTime>
#include "musicitem.h"
#include "webhost.h"
#include "musicdetail.h"
#include <iostream>
#include "player.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateUiList();
public slots:
    void timeSync();
private slots:
    void getTitle(QString name);

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_editButton_clicked();

    void on_musicList_itemClicked(QListWidgetItem *item);

    void on_playButton_clicked();

    void on_stopButton_clicked();

    void on_addTimeButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<musicItem*>musicList;
    QList<QTime>startTimeList;
    QList<QTime>endTimeList;
    player *players;
    QTimer *clockSync;
    QTime *time;
    QFile file;
    QString videoName;
    musicItem *currentItem;
    bool isMusicPlaying;
    int currentSong;
    void disableButtons();
};

#endif // MAINWINDOW_H
