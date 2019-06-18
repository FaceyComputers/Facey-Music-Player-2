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

private:
    Ui::musicDetail *ui;
};

#endif // MUSICDETAIL_H
