#ifndef STORE_MODEL_H
#define STORE_MODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "store.h"
#include <map>
#include <cmath>

class StoreModel : public QAbstractTableModel {
    Q_OBJECT
public:
    std::vector<Store> stores;
    int current_maximum;
    Store *selectedStore = new Store();

    StoreModel(QObject *parent, const std::vector<Store> &data);

    StoreModel(QObject *parent);

    void reloadData(const std::vector<Store> &data);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void changeById(const int &idToChange, const int &storeAreaTo, const int &itemsAvailableTo, const int &dailyCustomersTo, const int &storeSalesTo);

    void insertData(const Store curr);

    void fillna(const Store store, const int column, const int row);

    bool isFilled(const Store store, const int curr);

    void deleteData(const int &pos);

    void deleteMarkedData(const int pos);

    void changeBy();

    void percentil();

    void valueChanged(int value);

    bool fieldChecker(QString field);

    bool isEmArea(const Store &st);

    bool isEmAvail(const Store &st);

    bool isEmCustomers(const Store &st);

    bool isEmSales(const Store &st);

    bool forIntegersChecker(const std::vector<QString> &curr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    int _sliderData = 0;


};


struct sortingByParameter
{
    int k;
    Store store_initial;
    sortingByParameter(Store store_in, int p): store_initial(store_in), k(p) {
    };


    inline bool operator() (const Store& store1, const Store& store2)
    {

        return (abs(store_initial.data.at(k).toInt() - store1.data.at(k).toInt()) < abs(store_initial.data.at(k).toInt() - store2.data.at(k).toInt()));
    }

};

#endif // STORE_MODEL_H
