#include "player.h"
#include "mainwindow.h"

player::player(QObject *parent) : QObject(parent)
{
    this->playerView = new QWebEngineView();
    this->playerPage = new QWebEnginePage();
    this->url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ?autoplay=1";
}

player::player()
{
    //this->player = new QWebEnginePage();
    this->playerView = new QWebEngineView();
    this->playerPage = new QWebEnginePage();
    this->url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ?autoplay=1";
    this->volume = 50;
}

player::player(QString URL) :
    url(URL)
{
    //this->player = new QWebEnginePage();
    this->playerView = new QWebEngineView();
    this->playerPage = new QWebEnginePage();
}

player::player(QString URL, int volume) :
    url(URL),
    volume(volume)
{
    //this->player = new QWebEnginePage();
    this->playerView = new QWebEngineView();
    this->playerPage = new QWebEnginePage();
}

QString player::seperateLink(QString url)
{
    /*QString link = "";
    if(url.contains("watch?v="))
    {
    link = url.section(url.count("v=")
    }*/
    return "";
}

void player::play()
{
    //playerPage->setHtml("<iframe width=\"500\" height=\"500\" src=\"" + this->url + "?autoplay=1\" frameborder=\"0\" allow=\"accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>");
    //playerPage->setHtml("<iframe width=\"560\" height=\"315\" src=\"https://www.youtube-nocookie.com/embed/dQw4w9WgXcQ?autoplay=1\" frameborder=\"0\" allow=\"accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>");
    playerPage->setUrl(this->url);
    playerView->setPage(playerPage);
    playerView->show();
    playerView->setVisible(false);
    //connect(playerView, SIGNAL(loadFinished(bool)), this, SLOT(loaded()));
}

void player::checkURL()
{
    playerPage->setUrl(this->url);
    playerView->setPage(playerPage);
    playerView->show();
    playerView->setVisible(false);
    connect(playerView, SIGNAL(loadFinished(bool)), this, SLOT(loaded()));
}

void player::setCurrentTime(double time)
{
    this->currentTime = time;
}

void player::setCurrentLength(double time)
{
    this->currentLength = time;
}

double player::getTimeStamp()
{
    playerPage->runJavaScript("document.getElementById(\"movie_player\").getCurrentTime();", [&](const QVariant &v){
        this->setCurrentTime(v.toDouble());
    });
    return this->currentTime;
}

double player::getLength()
{
    playerPage->runJavaScript("document.getElementById(\"movie_player\").getDuration();", [&](const QVariant &v){
        this->setCurrentLength(v.toDouble());
    });
    return currentLength;
}

void player::loaded()
{
    playerView->setUrl(QUrl(NULL));
    playerPage->setUrl(QUrl(NULL));
    playerView->close();
    emit nameChanged(playerView->title());
    delete playerPage;
    delete playerView;
    this->playerView = new QWebEngineView();
    this->playerPage = new QWebEnginePage();
    //playerView->page()->runJavaScript("alert(\"hello\");");
}


void player::setURL(QString URL)
{
    if(URL.size() == 0)
    {
        this->url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ?autoplay=1";
    }else{
    this->url = URL;
    }
}

void player::setVolume(int volume)
{
    this->volume = volume;
}

void player::stop()
{
    playerView->setUrl(QUrl(""));
    playerPage->setUrl(QUrl(""));
    playerView->close();
    playerView->stop();
}

void player::pause()
{

}
