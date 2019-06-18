#include "player.h"

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
    this->url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ?autoplay=1";
    this->volume = 50;
}

player::player(QString URL) :
    url(URL)
{
    //this->player = new QWebEnginePage();
    this->playerView = new QWebEngineView();
}

player::player(QString URL, int volume) :
    url(URL),
    volume(volume)
{
    //this->player = new QWebEnginePage();
    this->playerView = new QWebEngineView();
}

void player::play()
{
    playerPage->setHtml("<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/eQED3tF8wuw?autoplay=1&mute=0\" frameborder=\"0\" allow=\"accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>");
    playerView->setPage(playerPage);
    playerView->show();
    //playerView->load(QUrl(this->url));
    //playerHost->page()->runJavaScript("alert(\"Hello World\");");
    //playerView->show();
}

void player::loaded()
{
    //playerView->page()->runJavaScript("alert(\"hello\");");
}

void player::setURL(QString URL)
{
    this->url = URL;
}

void player::setVolume(int volume)
{
    this->volume = volume;
}

void player::stop()
{
    //this->player->();
}

void player::pause()
{

}
