#ifndef FINDCLOSEST_H
#define FINDCLOSEST_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class findClosest;
}

class findClosest : public QWidget
{
    Q_OBJECT

public:
    explicit findClosest(StoreModel *modelForFindingClosest, QWidget *parent = nullptr);
    ~findClosest();

private slots:
    void on_predictButton_clicked();

private:
    Ui::findClosest *ui;
    StoreModel *modelForFindingClosest;
};

#endif // FINDCLOSEST_H
