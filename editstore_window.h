#ifndef EDITSTORE_WINDOW_H
#define EDITSTORE_WINDOW_H

#include "store_model.h"
#include <QWidget>

namespace Ui {
class editstore_window;
}

class editstore_window : public QWidget
{
    Q_OBJECT

public:
    explicit editstore_window(StoreModel *modelForEditing, int value = 0, QWidget *parent = nullptr);
    ~editstore_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::editstore_window *ui;
    StoreModel *modelForEditing;
    int value;
};

#endif // EDITSTORE_WINDOW_H
