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
    fin.push_back("NaN");


    for(int i = 0; i < g.size(); ++i)
        fin.push_back(g[i]);

    return Store(fin);
}




void addstore_window::on_submitting_clicked()
{
    std::vector<QString> gg;
    QMessageBox msgBox;
    bool flag = true;
    gg.push_back(ui->storeArea_w->text());
    gg.push_back(ui->itemsAvailable_w->text());
    gg.push_back(ui->daylyCustomer_w->text());
    gg.push_back(ui->storeSales_w->text());
    for (QString i: gg)
    {
        if (i != "")
        {
            for (QChar j : i)
            {
                if (j.isLetter())
                {

                    msgBox.setText("Enter only INT type variable");
                    msgBox.setStandardButtons(QMessageBox::Close);
                    msgBox.setDefaultButton(QMessageBox::Close);
                    msgBox.setWindowTitle("ERROR");
                    msgBox.exec();
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
            break;
    }

    if (flag)
    {
        toStore(gg);

        modelForAdding->insertData(toStore(gg));
    }

    this->close();
}

