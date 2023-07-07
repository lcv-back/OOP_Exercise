#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Customer {
private:
    string name;
    string address;
    // Call: vector<Order*>orderList; // >= 0
};
class Order {
private:
    string date;
    string status;
    vector<OrderDetail*>myOrderDetailList; // >= 0
    // Call: vector<Payment*>myPaymentList; // >= 1
public:
    void calcTotalPrice() {

    }

    // Call Payment class
};
class OrderDetail {
private:
    int quantity;
    Order* myOrder = new Order;
public:
    void calcPrice() {

    }
};

class Item {
private:
    string itemID;
    float price;
    string description;
    // Call: vector<OrderDetail*>myOrderDetailList; // >= 0
public:
    float getPrice() {
        return price;
    }

    bool isInStock() {

    }
};

class Payment {
private:
    float amount;
};

class Cash : public Payment {
private:
    float cashTendered;
};

class Check : public Payment {
private:
    string name;
    string bankID;
public:
    void authoized() {

    }
};

class Credit : public Payment {
private:
    string number;
    string type;
    string expiredDate;
public:
    void authorized() {

    }
}; 

int main() {

}
