#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int numerator, denominator;
    
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        if (denominator == 0) {
            throw runtime_error("Error: Division by zero is not allowed!");
        }
        cout << "Result: " << numerator / denominator << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
