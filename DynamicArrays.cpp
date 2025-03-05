//Using new and delete (Raw pointers)
#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size];  // Allocate dynamic array

    // Initialize and print values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
        cout << arr[i] << " ";
    }

    delete[] arr;  // Free memory
    return 0;
}
//Using std::vector
#include <vector>
using namespace std;

int main() {
    vector<int> arr;  // Dynamic array

    // Adding elements dynamically
    for (int i = 0; i < 5; i++) {
        arr.push_back(i * 10);
    }

    // Print array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
//Using unique_ptr (Smart pointer)
#include <memory>
using namespace std;

int main() {
    int size = 5;
    unique_ptr<int[]> arr(new int[size]);  // Smart pointer for dynamic array

    // Initialize and print
    for (int i = 0; i < size; i++) {
        arr[i] = i * 5;
        cout << arr[i] << " ";
    }

    return 0;  // No need to manually delete, unique_ptr handles it
}
//Dynamically Resizing with realloc Equivalent (std::vector)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3};

    // Resize array dynamically
    arr.resize(6); 

    // Assign new values
    for (size_t i = 3; i < arr.size(); i++)
        arr[i] = i * 2;

    // Print array
    for (int num : arr)
        cout << num << " ";

    return 0;
}
//Using std::deque (Dynamic Resizing with Fast Insertions)
#include <deque>
using namespace std;

int main() {
    deque<int> arr;

    // Insert elements
    for (int i = 0; i < 5; i++) {
        arr.push_back(i * 10);
    }

    // Print array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
//Using std::list (Doubly Linked List)
#include <list>
using namespace std;

int main() {
    list<int> arr = {10, 20, 30};

    // Insert elements dynamically
    arr.push_back(40);
    arr.push_back(50);

    // Print list
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
//Manually Resizing a Dynamic Array (new + realloc equivalent)
using namespace std;

int* resizeArray(int* arr, int& size, int newSize) {
    int* newArr = new int[newSize];  // Allocate new array
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];  // Copy old values
    }
    delete[] arr;  // Free old memory
    size = newSize;
    return newArr;
}

int main() {
    int size = 3;
    int* arr = new int[size]{1, 2, 3};

    arr = resizeArray(arr, size, 5);
    arr[3] = 4;
    arr[4] = 5;

    // Print array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;  // Free memory
    return 0;
}
//Implementing a Simple Dynamic Array Class
using namespace std;

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

public:
    DynamicArray(int cap = 2) : capacity(cap), size(0) {
        arr = new int[capacity];
    }

    void push(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* temp = new int[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size++] = value;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;
    da.push(1);
    da.push(2);
    da.push(3);
    da.push(4);
    
    da.print();
    return 0;
}
//Using std::array for Fixed-Size but Dynamically Allocated Arrays
#include <array>
using namespace std;

int main() {
    array<int, 5>* arr = new array<int, 5>{1, 2, 3, 4, 5};

    for (int num : *arr) {
        cout << num << " ";
    }

    delete arr;
    return 0;
}
