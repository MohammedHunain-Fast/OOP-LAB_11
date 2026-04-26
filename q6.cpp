#include <iostream>
#include <exception>
using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() const throw() {
        return "InvalidAgeException caught: Age must be between 1 and 119";
    }
};

class InvalidSalaryException : public exception {
public:
    const char* what() const throw() {
        return "InvalidSalaryException caught: Salary must be positive";
    }
};

class InvalidHeightException : public exception {
public:
    const char* what() const throw() {
        return "InvalidHeightException caught: Height must be positive";
    }
};

int main() {
    try {
        int age;
        cout << "Enter age: ";
        cin >> age;
        if (age <= 0 || age >= 120) throw InvalidAgeException();
        
        double salary;
        cout << "Enter salary: ";
        cin >> salary;
        if (salary <= 0) throw InvalidSalaryException();
        
        double height;
        cout << "Enter height: ";
        cin >> height;
        if (height <= 0) throw InvalidHeightException();
        
    } catch (const InvalidAgeException& e) {
        cout << e.what() << endl;
    } catch (const InvalidSalaryException& e) {
        cout << e.what() << endl;
    } catch (const InvalidHeightException& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
