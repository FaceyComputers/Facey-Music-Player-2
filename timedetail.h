#ifndef TIMEDETAIL_H
#define TIMEDETAIL_H

#include <QDialog>
#include <QTime>

namespace Ui {
class timeDetail;
}

class timeDetail : public QDialog
{
    Q_OBJECT

public:
    explicit timeDetail(QWidget *parent = nullptr);
    ~timeDetail();

    void setTime(QTime start, QTime end);

    void setStartTime(QTime time);

    void setEndTime(QTime time);

    QTime getStartTime();

    QTime getEndTime();

private:
    Ui::timeDetail *ui;
};

#endif // TIMEDETAIL_H
