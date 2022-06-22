#ifndef STORE_H
#define STORE_H

#include <QVariant>
#include <vector>

enum class StoreColumns {
    storeId,
    storeArea,
    itemsAvailable,
    daylyCustomers,
    storeSales,
    COUNT
};

class Store {

private:
    int id, area, available, customers, sales;
public:
    Store(const std::vector<QVariant> &data);

    Store();

    std::vector<QVariant> data;

    int storeId() const;

    int randomNumber() const;

    int storeArea() const;

    int itemsAvailable() const;

    int daylyCustomers() const;

    int storeSales() const;

    bool operator==(Store a);

    void setEqual(Store a);

    int id_pub() const {return id;};

    int area_pub() const {return area;};

    int available_pub() const {return available;};

    int customers_pub() const {return customers;};

    int sales_pub() const {return sales;};

};

#endif // STORE_H
