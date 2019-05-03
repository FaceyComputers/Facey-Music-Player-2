#include "musicitem.h"

musicItem::musicItem(QObject *parent) : QObject(parent)
{

}

musicItem::musicItem(QString name, QString url) :
    name(name),
    url(url)
{

}

QString musicItem::getName()
{
    return this->name;
}

void musicItem::setName(QString name)
{
    this->name = name;
}

QString musicItem::getURL()
{
    return this->url;
}

void musicItem::setURL(QString url)
{
    this->url = url;
}
