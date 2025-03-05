
//Declaration of array
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5}; // Static array of size 5

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}
//Input and output of an array
int main() {
    int arr[5];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//Finding the Maximum and Minimum in an Array
int main() {
    int arr[5] = {10, 50, 30, 20, 40};
    int maxVal = arr[0], minVal = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    return 0;
}
//Searching for an element (Linear Search)
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key;
    
    cout << "Enter number to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            found = true;
            cout << "Element found at index: " << i << endl;
            break;
        }
    }

    if (!found) {
        cout << "Element not found" << endl;
    }

    return 0;
}
//Sorting an array (Bubble sort)
int main() {
    int arr[5] = {50, 20, 40, 10, 30};
    int n = 5;

    // Bubble Sort of an Algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//Reversing an Array
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout << "Reversed array: ";
    for (int i = 4; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
//2D Array (Matrix Input and output)
/int main() {
    int matrix[3][3];

    cout << "Enter 3x3 matrix values: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//Matrix Addition
int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int sum[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Sum of Matrices: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//Finding a transpose of a Matrix
int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transpose[3][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose of Matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//Merging two sorted arrays
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    while (i < n1)
        merged[k++] = arr1[i++];
    
    while (j < n2)
        merged[k++] = arr2[j++];
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int merged[8];

    mergeArrays(arr1, arr2, 4, 4, merged);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < 8; i++) {
        cout << merged[i] << " ";
    }
    return 0;
}
//Rotate Array to the right (by one position)
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int last = arr[4];

    for (int i = 4; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;

    cout << "Rotated Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//Finding Frequency of each element in array
int main() {
    int arr[10] = {1, 2, 3, 2, 1, 4, 5, 3, 2, 4};
    int freq[10] = {0};

    for (int i = 0; i < 10; i++) {
        freq[arr[i]]++;
    }

    cout << "Element Frequencies:\n";
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            cout << i << " appears " << freq[i] << " times\n";
            freq[i] = 0; // Reset to avoid duplicate prints
        }
    }

    return 0;
}
//Prefix sum array 
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int prefixSum[5];

    prefixSum[0] = arr[0];
    for (int i = 1; i < 5; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    cout << "Prefix Sum Array: ";
    for (int i = 0; i < 5; i++) {
        cout << prefixSum[i] << " ";
    }

    return 0;
}
//Binary search for Sorted arrays
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key = 30;

    int result = binarySearch(arr, 5, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found\n";

    return 0;
}
