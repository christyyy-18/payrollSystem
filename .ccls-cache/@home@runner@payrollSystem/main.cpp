#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee {
private:
    int emp_id;
    string name;
    double hours_worked;
    double hourly_rate;

public:
    void getEmployeeData() {
        cout << "Enter employee ID: ";
        cin >> emp_id;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter hours worked: ";
        cin >> hours_worked;
        cout << "Enter hourly rate: ";
        cin >> hourly_rate;
    }

    double calculateSalary() {
        if (hours_worked <= 40) {
            return hours_worked * hourly_rate;
        } else {
            double overtime_hours = hours_worked - 40;
            return (40 * hourly_rate) + (overtime_hours * 1.5 * hourly_rate);
        }
    }

    void generatePayStub() {
        double salary = calculateSalary();
        cout << "\nPay Stub:" << endl;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Name: " << name << endl;
        cout << "Hours Worked: " << hours_worked << endl;
        cout << "Hourly Rate: $" << fixed << setprecision(2) << hourly_rate << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};

int main() {
    Employee emp;
    emp.getEmployeeData();
    emp.generatePayStub();
    return 0;
}