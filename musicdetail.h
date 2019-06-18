#ifndef MUSICDETAIL_H
#define MUSICDETAIL_H

#include <QDialog>

namespace Ui {
class musicDetail;
}

class musicDetail : public QDialog
{
    Q_OBJECT

public:
    explicit musicDetail(QWidget *parent = nullptr);
    ~musicDetail();

    QString getName();
    QString getURL();
    void setName(QString text);
    void setURL(QString text);
private:
    Ui::musicDetail *ui;
};

#endif // MUSICDETAIL_H
