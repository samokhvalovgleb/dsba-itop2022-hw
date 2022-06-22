#include "store.h"
#include <cstdlib>

Store::Store() {}



Store::Store(const std::vector<QVariant> &data) : data(data) {
    this->data.push_back(false);
}

int Store::storeId() const {
    return data[(int)StoreColumns::storeId].value<int>();
}

int Store::storeArea() const {
    return data[(int)StoreColumns::storeArea].value<int>();
}

int Store::itemsAvailable() const {
    return data[(int)StoreColumns::itemsAvailable].value<int>();
}

int Store::daylyCustomers() const {
    return data[(int)StoreColumns::daylyCustomers].value<int>();
}

int Store::storeSales() const {
    return data[(int)StoreColumns::storeSales].value<int>();
}

int Store::randomNumber() const {
    return rand();
}

bool Store::operator==(Store a)
{
    if (id == a.id_pub())
        return true;
    return false;
}

void Store::setEqual(Store a)
{
    id = a.id_pub();
    area = a.area_pub();
    available = a.available_pub();
    customers = a.customers_pub();
    sales = a.sales_pub();
}
