#include "deletestore_window.h"
#include "ui_deletestore_window.h"
#include <QMessageBox>

deletestore_window::deletestore_window(StoreModel *modelForDeleting, QWidget *parent) :
    modelForDeleting(modelForDeleting),
    QWidget(parent),
    ui(new Ui::deletestore_window)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(3);
}

deletestore_window::~deletestore_window()
{
    delete ui;
}

void deletestore_window::on_pushButton_clicked()
{
    QMessageBox msgBox;
    int toDelete_id;
    QString initial;
    bool flag = true;
    initial = ui->lineEdit->text();
    for (int i = 0; i < initial.size(); ++i)
    {
        if (initial[i].isLetter() || initial.toInt() > 896)
        {
            msgBox.setText("Enter only INT type variable from [1; 897]");
            msgBox.setStandardButtons(QMessageBox::Close);
            msgBox.setDefaultButton(QMessageBox::Close);
            msgBox.setWindowTitle("ERROR");
            msgBox.exec();
            flag = false;
            break;
        }
    }
    if (flag)
    {
        toDelete_id = initial.toInt();
        modelForDeleting->deleteData(toDelete_id);
    }

    this->close();
}

