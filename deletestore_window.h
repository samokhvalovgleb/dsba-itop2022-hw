#ifndef DELETESTORE_WINDOW_H
#define DELETESTORE_WINDOW_H

#include "store_model.h"
#include <QWidget>

namespace Ui {
class deletestore_window;
}

class deletestore_window : public QWidget
{
    Q_OBJECT

public:
    explicit deletestore_window(StoreModel *modelForDeleting, QWidget *parent = nullptr);
    ~deletestore_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletestore_window *ui;
    StoreModel *modelForDeleting;
};

#endif // DELETESTORE_WINDOW_H
