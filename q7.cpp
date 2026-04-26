#include <iostream>
#include <exception>
using namespace std;

class OutOfBoundsException : public exception {
public:
    const char* what() const throw() {
        return "OutOfBoundsException caught: Invalid index access attempted!";
    }
};

template <typename T>
class SmartArray {
    T* arr;
    int size;
public:
    SmartArray(int s) : size(s) {
        arr = new T[size];
    }
    
    ~SmartArray() {
        delete[] arr;
    }
    
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw OutOfBoundsException();
        }
        return arr[index];
    }
};

int main() {
    SmartArray<int> arr(5);
    cout << "Array size: 5" << endl;
    cout << "Enter elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    try {
        cout << "Accessing index 2: " << arr[2] << endl;
        cout << "Accessing index 5: ";
        cout << arr[5] << endl; 
    } catch (const OutOfBoundsException& e) {
        cout << endl << e.what() << endl;
    }
    
    return 0;
}
