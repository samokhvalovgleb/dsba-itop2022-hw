#ifndef EDITTING_FORM_H
#define EDITTING_FORM_H

#include "store_model.h"
#include <QWidget>

namespace Ui {
class editting_form;
}

class editting_form : public QWidget
{
    Q_OBJECT

public:
    explicit editting_form(int toEditId, StoreModel *modelForForm, QWidget *parent = nullptr);
    ~editting_form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::editting_form *ui;
    StoreModel *modelForForm;
    int toEditId;

};

#endif // EDITTING_FORM_H
