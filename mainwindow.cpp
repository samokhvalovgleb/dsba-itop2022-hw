#include <unordered_set>
#include "about_window.h"
#include "deletestore_window.h"
#include "editstore_window.h"
#include "findclosest.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include "qmessagebox.h"
#include "store.h"
#include "rapidcsv.h"
#include "store_model.h"
#include "logowidget.h"
#include <QList>
#include "addstore_window.h"
#include "ui_addstore_window.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mModel = new StoreModel(this);
    ui->tableView->setModel(mModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    logo = new logoWidget(this);
//    logo->setFixedSize(30,30);
//    ui->gridLayout->addWidget(logo, 0, 0);

}

MainWindow::~MainWindow()
{
    delete ui;
}




std::vector<Store> MainWindow::readCSV(QString csvFile)
{
    rapidcsv::Document doc(csvFile.toStdString());

    int numOfRows = doc.GetRowCount();
    std::vector<QVariant> modelRow;
    std::vector<std::string> row;
    std::vector<Store> modelData;
    std::vector<QVariant> kk;
    for (int rownum = 0; rownum < numOfRows; ++rownum)
    {
        row = doc.GetRow<std::string>(rownum);
        Store curr({QString::fromStdString(row[0]), QString::fromStdString(row[1]), QString::fromStdString(row[2]), QString::fromStdString(row[3]), QString::fromStdString(row[4])});
        modelData.push_back(curr);
    }


    std::vector<Store> result;

    for (auto curr: modelData)
        result.push_back(curr);


    return result;
}


void MainWindow::save_data_function()
{
    auto dir = QFileDialog::getSaveFileName (this, "Save File As", QDir::currentPath ());
    if (!dir.size())
        return;
    save_data(dir);
}

void MainWindow::add_new_row(Store curr)
{
    std::vector<Store> ss;
    for (int i = 0; i < mModel->stores.size(); ++i)
        ss.push_back(mModel->stores[i]);
}



void MainWindow::on_importData_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", QDir::currentPath(), "CSV File(*.csv)");

    mModel->reloadData(readCSV(filename));

    ui->tableView->setModel(mModel);
}


void MainWindow::on_saveData_clicked()
{
    auto dir = QFileDialog::getSaveFileName (this, "Save File As", QDir::currentPath ());
        if (!dir.size ())
          return;
    save_data(dir);
}


void MainWindow::save_data(const QString &dir)
{
    std::ofstream file(dir.toStdString());
    int total_columns = static_cast<int> (StoreColumns::COUNT);
    for (auto &store : mModel->stores)
      {

        for (int i_column = 0; i_column < total_columns; ++i_column)
          {

            file << store.data[i_column].toString().toStdString();
            if (i_column < total_columns - 1)
                file << ",";
            else
                file << "\n";
          }
      }

}


void MainWindow::on_addStore_clicked()
{
    addstore_window *n = new addstore_window(mModel);
    n->setWindowTitle("Adding new row");
    n->show();
}


void MainWindow::on_about_clicked()
{
    about_window *ab = new about_window;
    ab->setWindowTitle("About");
    ab->show();
}


void MainWindow::on_deletting_clicked()
{
    deletestore_window *d = new deletestore_window(mModel);
    d->setWindowTitle("Deleting row");
    d->show();
}


void MainWindow::on_editStore_clicked()
{
    editstore_window *editting_window = new editstore_window(mModel);
    editting_window->setWindowTitle("Editting Store");
    editting_window->show();
}


void MainWindow::on_fiilingBlanks_clicked()
{
    if (mModel->stores.size() < 24)
    {
        QMessageBox msgBox;
        msgBox.setText("You are not allowed to fillna custom data");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        msgBox.setWindowTitle("ERROR");
        msgBox.exec();

    }
    else
    {
        for (int i = 0; i < mModel->stores.size(); ++i)
        {
            bool flag = true;
            for (int j = 1; j < 5; ++j)
                if (!(mModel->isFilled(mModel->stores[i], j)))
                    flag = false;


           if (!flag)
           {
               if (mModel->isEmArea(mModel->stores[i]))
                    mModel->fillna(mModel->stores[i], 1, i);

               if (mModel->isEmAvail(mModel->stores[i]))
                    mModel->fillna(mModel->stores[i], 2, i);

               if (mModel->isEmCustomers(mModel->stores[i]))
                    mModel->fillna(mModel->stores[i], 3, i);

               if (mModel->isEmSales(mModel->stores[i]))
                    mModel->fillna(mModel->stores[i], 4, i);
           }
        }
    }
}


void MainWindow::on_findClosest_clicked()
{
    findClosest *dd = new findClosest(mModel);
    dd->setWindowTitle("Finding Closest");
    dd->show();
}

