#include <iostream>
#include <vector>
using namespace std;
class Address {
    string street;
    string city;
    string district;
    string postalCode;
    string country;
};

class Person {
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    bool hasParkingPass() {
        return true;
    }
protected:
    string name;
    int age;
    float phoneNumber;
    string email;
    Address address;
};

class Student : public Person {
public:
    Student(string n, int a) : Person(n, a) {}
private:
    float studentID;
};

class Lecture {
public:
    Lecture(string n) {
        name = n;
    }
    
    string getName() {
        return name;
    }

private:
    string name;
};

class Professor : public Person {
public:
    Professor(string n, int a) : Person(n, a) {}
    
    void addStudent(Student* student) {
        studentList.push_back(student);
    }
    
    void train(Lecture *lecture) {
        cout << "The professior named " << name 
                << "\nis teaching for " << studentList.size() << " students \nwith lecture: "
                << lecture->getName() << "\n";
    }
    
private:
    vector<Student*> studentList;
    float salary;
};

int main() {
    Professor *tokuda = new Professor("Tokuda", 50);
    tokuda->addStudent(new Student("Vu", 30));
    tokuda->addStudent(new Student("Son", 25));
    tokuda->addStudent(new Student("Yen", 20));
    
    Lecture *lecture = new Lecture("Tinh ke thua trong OOP");
    
    tokuda->train(lecture);
}