#ifndef ADDSTORE_WINDOW_H
#define ADDSTORE_WINDOW_H

#include "mainwindow.h"
#include "qtableview.h"
#include "store_model.h"
#include <QWidget>

namespace Ui {
class addstore_window;
}

class addstore_window : public QWidget
{
    Q_OBJECT

public:
    explicit addstore_window(StoreModel *modelForAdding, QWidget *parent = nullptr);

    ~addstore_window();


private slots:
    void on_submitting_clicked();

private:
    Ui::addstore_window *ui;
    StoreModel *modelForAdding;
};

#endif // ADDSTORE_WINDOW_H
