#include "deletestore_window.h"
#include "ui_deletestore_window.h"
#include <QMessageBox>

deletestore_window::deletestore_window(StoreModel *modelForDeleting, QWidget *parent) :
    modelForDeleting(modelForDeleting),
    QWidget(parent),
    ui(new Ui::deletestore_window)
{
    ui->setupUi(this);
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
//    for (int i = 0; i < initial.size(); ++i)
//    {
//        if (initial[i].isLetter() || initial.toInt() > modelForDeleting->stores.size())
//        {
//            msgBox.setText("Enter only INT type variable and not bigger then the last ID");
//            msgBox.setStandardButtons(QMessageBox::Close);
//            msgBox.setDefaultButton(QMessageBox::Close);
//            msgBox.setWindowTitle("ERROR");
//            msgBox.exec();
//            flag = false;
//            break;
//        }
//    }
    if (!(modelForDeleting->fieldChecker(initial)) || initial.toInt() > modelForDeleting->stores.size())
    {
        msgBox.setText("Enter only INT type variable and not bigger then the last ID");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        msgBox.setWindowTitle("ERROR");
        msgBox.exec();
        flag = false;
    }

    if (flag)
    {
        toDelete_id = initial.toInt();
        modelForDeleting->deleteData(toDelete_id);
        modelForDeleting->reloadData(modelForDeleting->stores);
        modelForDeleting->percentil();
        this->close();


    }


}




