#include "store_model.h"
#include <cmath>
#include <algorithm>

StoreModel::StoreModel(QObject* parent)
    : QAbstractTableModel(parent)
{

}

StoreModel::StoreModel(QObject *parent, const std::vector<Store> &data)
    : QAbstractTableModel(parent) {
    reloadData(data);
}

void StoreModel::reloadData(const std::vector<Store> &data) {
    stores = data;
    emit layoutChanged();
}

int StoreModel::rowCount(const QModelIndex &parent) const {
    return stores.size();
}

int StoreModel::columnCount(const QModelIndex &parent) const {
    return (int)StoreColumns::COUNT;
}

QVariant StoreModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const Store &store = stores.at(index.row());
        return store.data[index.column()];
    }

    return {};
}

bool StoreModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        Store &store = stores.at(index.row());
        store.data[index.column()] = value;
        return true;
    }

    return false;
}

void StoreModel::insertData(Store curr)
{
    stores.push_back(curr);
    emit layoutChanged();
}

void StoreModel::deleteData(int pos)
{
    for (int i = 0; i < stores.size(); ++i)
    {
        if (stores[i].data[0].toInt() == pos)
            stores.erase(stores.begin() + (i));
    }
    emit layoutChanged();
}


void StoreModel::changeById(const int &idToChange, const int &storeAreaTo, const int &itemsAvailableTo, const int &dailyCustomersTo, const int &storeSalesTo)
{
    Store obj;
    std::vector<QVariant> new_store;
    for (int i = 0; i < stores.size(); ++i)
    {
        if (stores[i].storeId() == idToChange)
        {
            new_store.push_back(idToChange);
            new_store.push_back(storeAreaTo);
            new_store.push_back(itemsAvailableTo);
            new_store.push_back(dailyCustomersTo);
            new_store.push_back(storeSalesTo);
            obj = Store(new_store);
            auto it = stores.begin() + i;
            stores.erase(it);
            stores.insert(it, obj);
        }
    }

    emit layoutChanged();

}

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<T> vec(first, last);
    return vec;
}




void StoreModel::fillna(Store store, const int column, const int row)
{
    int temp = std::min((int)stores.size(), 24);
    std::vector<Store> new_stores;
    new_stores = stores;

    for(int i = 1; i < 5; ++i)
    {
        if (i == column)
            continue;
        else
        {
            std::sort(new_stores.begin(), new_stores.end(), sortingByParameter(store, i));
            new_stores = slice(new_stores, 0, std::min(temp, (int)new_stores.size()));
            temp = std::max(temp / i, 1);
        }
    }

    Store obj = store;

    if (new_stores.size() > 1)
    {
        store.data[column] = new_stores[1].data.at(column).toInt();
        stores[row] = store;
    }
    else
    {
        store.data[column] = new_stores[0].data.at(column).toInt();
        stores[row] = store;
    }


    emit layoutChanged();
}



bool StoreModel::isFilled(const Store store, const int curr)
{
    if (store.data.at(curr).toInt())
        return true;
    return false;
}

bool StoreModel::isEmArea(const Store &store)
{
    if (store.data.at(1) == "")
        return true;
    return false;
}

bool StoreModel::isEmAvail(const Store &store)
{
    if (store.data.at(2) == "")
        return true;
    return false;

}

bool StoreModel::isEmCustomers(const Store &store)
{
    if (store.data.at(3) == "")
        return true;
    return false;
}

bool StoreModel::isEmSales(const Store &store)
{
    if (store.data.at(4) == "")
        return true;
    return false;
}



QVariant StoreModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole || orientation == Qt::Vertical)
    {
        StoreColumns column = (StoreColumns)section;
        switch (column) {
        case StoreColumns::storeId:
            return "Store ID";
        case StoreColumns::storeArea:
            return "Store Area";
        case StoreColumns::itemsAvailable:
            return "Items Available";
        case StoreColumns::daylyCustomers:
            return "Daily Customer Count";
        case StoreColumns::storeSales:
            return "Store Sales";
        case StoreColumns::COUNT:
            return {};
        }
    }
    return {};
}
