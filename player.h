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


private slots:
    void loaded();
private:
    QWebEngineView *playerView;
    QWebEnginePage *playerPage;
    QString url;
    int volume;
};

#endif // PLAYER_H
