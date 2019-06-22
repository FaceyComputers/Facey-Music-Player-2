#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWebEngineView>
#include <QWebEnginePage>

class player : public QObject
{
    Q_OBJECT
public:
    explicit player(QObject *parent = nullptr);
    player();
    player(QString URL);
    player(QString URL, int volume);
    void play();
    void setURL(QString URL);
    void setVolume(int volume);
    void stop();
    void pause();
    void checkURL();
    //QTime getTimeStamp();
    double getTimeStamp();
    double getLength();
private slots:
    void loaded();
signals:
    void nameChanged(QString);
private:
    QWebEngineView *playerView;
    QWebEnginePage *playerPage;
    QString url;
    int volume;
    double currentTime;
    double currentLength;
    QString seperateLink(QString url);
    void setCurrentTime(double time);
    void setCurrentLength(double time);
};

#endif // PLAYER_H
