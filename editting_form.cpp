#include "editting_form.h"
#include "ui_editting_form.h"


editting_form::editting_form(int toEditId, StoreModel *modelForForm, QWidget *parent) :
    toEditId(toEditId),
    modelForForm(modelForForm),
    QWidget(parent),
    ui(new Ui::editting_form)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0,100000000);
    ui->spinBox_2->setRange(0,10000000);
    ui->spinBox_3->setRange(0,1000000000);
    ui->spinBox_4->setRange(0,100000000);
    for (int i = 0; i < modelForForm->stores.size(); ++i)
    {
        if (modelForForm->stores[i].storeId() == toEditId)
        {
            ui->spinBox->setValue(modelForForm->stores[i].storeArea());
            ui->spinBox_2->setValue(modelForForm->stores[i].itemsAvailable());
            ui->spinBox_3->setValue(modelForForm->stores[i].daylyCustomers());
            ui->spinBox_4->setValue(modelForForm->stores[i].storeSales());
        }
    }
}

editting_form::~editting_form()
{
    delete ui;
}

void editting_form::on_pushButton_clicked()
{
    std::vector<QVariant> woId;
    int toEditArea, toEditAvailable, toEditCustomers, toEditSales;

    woId.push_back((ui->spinBox->text()).toInt());
    woId.push_back((ui->spinBox_2->text()).toInt());
    woId.push_back((ui->spinBox_3->text()).toInt());
    woId.push_back((ui->spinBox_4->text()).toInt());
    modelForForm->changeById(toEditId, woId[0].toInt(), woId[1].toInt(), woId[2].toInt(), woId[3].toInt());

    this->close();
}

