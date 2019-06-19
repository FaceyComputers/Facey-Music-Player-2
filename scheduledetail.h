#ifndef SCHEDULEDETAIL_H
#define SCHEDULEDETAIL_H

#include <QDialog>
#include <QTime>

namespace Ui {
class scheduleDetail;
}

class scheduleDetail : public QDialog
{
    Q_OBJECT

public:
    explicit scheduleDetail(QWidget *parent = nullptr);
    ~scheduleDetail();

    void setTime(QTime start, QTime end);
    void setStartTime(QTime time);
    void setEndTime(QTime time);
    QTime getStartTime();
    QTime getEndTime();
private:
    Ui::scheduleDetail *ui;
};

#endif // SCHEDULEDETAIL_H
