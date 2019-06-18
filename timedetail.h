#ifndef TIMEDETAIL_H
#define TIMEDETAIL_H

#include <QDialog>

namespace Ui {
class timeDetail;
}

class timeDetail : public QDialog
{
    Q_OBJECT

public:
    explicit timeDetail(QWidget *parent = nullptr);
    ~timeDetail();

private:
    Ui::timeDetail *ui;
};

#endif // TIMEDETAIL_H
