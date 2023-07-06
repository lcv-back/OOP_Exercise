// Exercise about polyphirsm - Oriented Object Programming

#include <iostream>
#include <string>
using namespace std;

// Initiative super class Employee and 3 subclass HR, Coder and Business
class Employee {
public:
    Employee() {
        nameEmployee = "";
        basisSalary = 15.0; // unit: x.000.000
        experienceYear = 0;
    }

    virtual void setBasisSalary(float salary) {
        basisSalary = salary;
    }

    virtual float getBasisSalary() {
        return basisSalary;
    }

    virtual void setName(string name) {
        nameEmployee = name;
    }

    virtual string getName() {
        return nameEmployee;
    }

    virtual void setExperienceYear(int year) {
        experienceYear = year;
    }

    virtual int getExperienceYear() {
        return experienceYear;
    }
private:
    string nameEmployee;
    float basisSalary;
    int experienceYear;
};

class HR : public Employee {

};

class codeEngineer : public Employee {

};

class businessEmpl : public Employee {
public:
    void setDoneContract(int done) {
        doneContract = done;
    }

    int getDoneContract() {
        return doneContract;
    }
private:
    int doneContract;
};

// Intiative function 4 with ability statistic salary of employees
void statisticSalary(Employee* employeeList[], int numberEmployee) {
    for (int i = 0; i < numberEmployee; i++) {
        cout << "Name: " << employeeList[i]->getName() << endl;
        cout << "Salary: " << employeeList[i]->getBasisSalary() << " trieu" << endl;
        cout << "Experiences: " << employeeList[i]->getExperienceYear() << " years" << endl;
        cout << "-------------------------------------------" << endl;
    }
}

void modifyInformation(Employee* employeeList[], int numberEmployee, string inforWantModify, string nameOriginal ,string nameMod, float salMod, int exMod) {
        if (inforWantModify.compare("Salary") == 0) {
            for (int i = 0; i < numberEmployee; i++) {
                if ((employeeList[i]->getName()).compare(nameOriginal) == 0) {
                    employeeList[i]->setBasisSalary(salMod);
                }
            }
        } else if (inforWantModify.compare("Experience Years") == 0) {
            for (int i = 0; i < numberEmployee; i++) {
                if ((employeeList[i]->getName()).compare(nameOriginal) == 0) {
                    employeeList[i]->setExperienceYear(exMod);
                }
            }
        } else { // Name
            for (int i = 0; i < numberEmployee; i++) {
                if ((employeeList[i]->getName()).compare(nameOriginal) == 0) {
                    employeeList[i]->setName(nameMod);
                }
    }
        }
}

// Initiative function addtion with add name, add salary and add experiences year
void addOneEmployee(Employee* employeeList[], int numberEmployee, Employee* employeeWantAdd) {
    employeeList[numberEmployee] = employeeWantAdd;
}

int main() {
    Employee* hr = new HR();
    Employee* coder = new codeEngineer();
    Employee* business = new businessEmpl();
    Employee* myEmp = new Employee();

    Employee* employeeList[3];
    employeeList[0] = hr;
    employeeList[1] = coder;
    employeeList[2] = business;

    // Statistic salary of employees
    float basisSalaryOfHR = hr->getBasisSalary();
    hr->setBasisSalary(basisSalaryOfHR);

    float basisSalaryOfCoder = 1.15*(coder->getBasisSalary());
    coder->setBasisSalary(basisSalaryOfCoder);

    // Down-casting of business class
    ((businessEmpl *)business)->setDoneContract(12);
    int doneContract = ((businessEmpl *)business)->getDoneContract();
    float basisSalaryOfBusiness = ((((float)doneContract/100) + 1.0) * business->getBasisSalary());
    business->setBasisSalary(basisSalaryOfBusiness);

    // Statistic name of employees
    hr->setName("Human Resouces");
    coder->setName("Coder");
    business->setName("Business");

    // Statistic experiences year of employees
    hr->setExperienceYear(5);
    coder->setExperienceYear(4);
    business->setExperienceYear(6);

    // Function 4
    // statisticSalary(employeeList, 3);

    // Function 1. add
    
    Employee* hrToAdd = new HR();
    Employee* employeeListToAdd[4];

    for (int i = 0; i < 3; i++) {
        employeeListToAdd[i] = employeeList[i];
    }
    employeeListToAdd[3] = hrToAdd;

    float basisSalaryOfHRToAdd = hrToAdd->getBasisSalary();
    hrToAdd->setBasisSalary(basisSalaryOfHRToAdd);
    hrToAdd->setName("Human Resouces 1");
    hrToAdd->setExperienceYear(7);
    addOneEmployee(employeeListToAdd, 4, employeeListToAdd[3]);

    // Variables for null value
    string nameNull = "";
    float salaryNull = 0.0;
    int experienceNull = 0;

    // Example for modify name: modifyInformation(employeeListToAdd, 4, "Name", "Human Resouces", "Le Cong Vi", 0, 0);
    // Example for modify salary: modifyInformation(employeeListToAdd, 4, "Salary", "Coder", nameNull, 20, experienceNull);
    // Examples for modify experience years: modifyInformation(employeeListToAdd, 4, "Experience Years", "Human Resouces 1", nameNull, salaryNull, 10);
    statisticSalary(employeeListToAdd, 4);
}
