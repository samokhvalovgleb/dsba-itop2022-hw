#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlineedit.h"
#include <QMainWindow>
#include <store.h>
#include <store_model.h>
#include <QMetaType>

Q_DECLARE_METATYPE(Store);
Q_DECLARE_METATYPE(std::vector<std::string>);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class logoWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    logoWidget *logo;


public:
    MainWindow(QWidget *parent = nullptr);
    std::vector<Store> readCSV(QString csvFile);
    void save_data (const QString &dir);
    void add_new_row(Store curr);
    ~MainWindow();


public slots:
    void save_data_function();



private slots:
    void on_importData_clicked();

    void on_saveData_clicked();

    void on_addStore_clicked();

    void on_about_clicked();

    void on_deletting_clicked();

    void on_editStore_clicked();

    void on_fiilingBlanks_clicked();

    void on_findClosest_clicked();

private:
    QString getValueAt(int x, int y);
    Ui::MainWindow *ui;
    StoreModel *mModel = nullptr
            ;
};
#endif // MAINWINDOW_H
