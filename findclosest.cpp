#include "findclosest.h"
#include "mainwindow.h"
#include "ui_findclosest.h"
#include "store_model.h"

findClosest::findClosest(StoreModel *modelForFindingClosest, QWidget *parent) :
    modelForFindingClosest(modelForFindingClosest),
    QWidget(parent),
    ui(new Ui::findClosest)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0,100000000);
}

findClosest::~findClosest()
{
    delete ui;
}

int user_to_needed(QString totr)
{
    int ind;

    if (totr == "Store ID")
        ind = 0;

    else if (totr == "Store Area")
        ind = 1;

    else if (totr == "Items Available")
        ind = 2;

    else if (totr == "Daily Customers")
       ind = 3;

    else if (totr == "Store Sales")
        ind = 4;

    return ind;
}

int predictor(int index, int target, int value, StoreModel *aModel)
{
    int x;
    int fin;

    fin = aModel->stores[0].data.at(target).toInt();
    x = abs(aModel->stores[0].data.at(index).toInt() - value);

    for(int i = 1; i < aModel->stores.size(); ++i)
    {
        if (abs(aModel->stores[i].data.at(index).toInt() - value) < x)
        {
            x = abs(aModel->stores[i].data.at(index).toInt() - value);
            fin = aModel->stores[i].data.at(target).toInt();
        }
    }

    return fin;
}


void findClosest::on_predictButton_clicked()
{
    int feature, target, feature_value, res;

    feature = user_to_needed(ui->comboBox->currentText());

    target = user_to_needed(ui->comboBox_2->currentText());

    feature_value = (ui->lineEdit->text()).toInt();

    res = predictor(feature, target, feature_value, modelForFindingClosest);
    ui->spinBox->setValue(res);

}



