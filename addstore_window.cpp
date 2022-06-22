#include "addstore_window.h"
#include "qaction.h"
#include "qmessagebox.h"
#include "ui_addstore_window.h"
#include "mainwindow.h"
#include "store_model.h"

addstore_window::addstore_window(StoreModel *modelForAdding, QWidget *parent) :
    modelForAdding(modelForAdding),
    QWidget(parent),
    ui(new Ui::addstore_window)
{
    ui->setupUi(this);
}

addstore_window::~addstore_window()
{
    delete ui;
}

Store toStore(std::vector<QString> g)
{
    std::vector<QVariant> fin;

    for(int i = 0; i < g.size(); ++i)
        fin.push_back(g[i]);

    return Store(fin);
}

bool forIntegersChecker(const std::vector<QString> &curr)
{
    for (QString i: curr)
    {
        for (QChar j: i)
        {
            if (j.isLetter())
            {
                return false;
                break;
            }

        }
    }

    return true;
}




void addstore_window::on_submitting_clicked()
{
    std::vector<QString> gg;
    QMessageBox msgBox;
    bool flag = true;
    gg.push_back(QString::number(modelForAdding->stores.size() + 1));
    gg.push_back(ui->storeArea_w->text());
    gg.push_back(ui->itemsAvailable_w->text());
    gg.push_back(ui->daylyCustomer_w->text());
    gg.push_back(ui->storeSales_w->text());
    if (!(forIntegersChecker(gg)))
    {
        msgBox.setText("Enter only INT type variable");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        msgBox.setWindowTitle("ERROR");
        msgBox.exec();
        flag = false;

    }

    if (flag)
    {
        toStore(gg);
        modelForAdding->insertData(toStore(gg));
        modelForAdding->percentil();
        modelForAdding->reloadData(modelForAdding->stores);
        this->close();
    }

}

