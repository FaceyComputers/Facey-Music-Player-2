#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

class fileManager : public QObject
{
    Q_OBJECT
public:
    explicit fileManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FILEMANAGER_H