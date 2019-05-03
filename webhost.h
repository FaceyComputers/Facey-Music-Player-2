#ifndef WEBHOST_H
#define WEBHOST_H

#include <QObject>
#include <QHttpMultiPart>
class webHost : public QObject
{
    Q_OBJECT
public:
    explicit webHost(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WEBHOST_H
