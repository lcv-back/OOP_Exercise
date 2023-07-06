#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
public:
    virtual void run() = 0;
};

class Car : public Vehicle {
    void run() override {
        cout << "car";
    }
};

class Pickup : public Vehicle {
    void run() override {
        cout << "pickup";
    }
};

class Motorbike : public Vehicle {
    void run() override {
        cout << "motorbike";
    }
};

class Skateboard : public Vehicle {
    void run() override {
        cout << "skateboard";
    }
};

class Person {

};

void solution(Person *person, vector<Vehicle*> vehicleList, int numOfDays) {
    for (int i = 0; i < numOfDays; i++) {
        cout << "Day " << i + 1 << ": A ";
        vehicleList[i]->run();
        cout << " is running...!";
        cout << endl;
    }

    if (numOfDays >= 3) {
        for (int i = 0; i < numOfDays; i++) {
            cout << "Day " << i + 1 + 3 << ": A ";
            vehicleList[i]->run();
            cout << " is running...!";
            cout << endl;
        }
    } 
}

int main() {
    vector<Vehicle*> vehicleList;
    vehicleList.push_back(new Car());
    vehicleList.push_back(new Motorbike());
    vehicleList.push_back(new Pickup());
    Person* person = new Person;
    
    int numOfDays = 0;
    numOfDays = 6;
    solution(person, vehicleList, numOfDays);
    
    cout << "\nAfter adding Skateboard vehicle:\n";
    vehicleList.push_back(new Skateboard());
    solution(person, vehicleList, numOfDays);
}
