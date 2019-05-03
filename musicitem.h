#ifndef MUSICITEM_H
#define MUSICITEM_H

#include <QObject>

class musicItem : public QObject
{
    Q_OBJECT
public:
    explicit musicItem(QObject *parent = nullptr);

    musicItem(QString name, QString url);

    QString getName();

    void setName(QString name);

    QString getURL();

    void setURL(QString url);

signals:

public slots:

private:
    QString name;
    QString url;
    QString ip;
};


#endif // MUSICITEM_H
