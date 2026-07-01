#include <iostream>
using namespace std;

int majority(int arr[], int n) {
    int count = 0;
    int element;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            count = 1;
            element = arr[i];
        } else if (element == arr[i]) {
            count++;
        } else {
            count--;
        }
    }

    int count1 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            count1++;
        }
    }

    if (count1 > n / 2) {
        return element;
    }
    
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n]; 
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = majority(arr, n);
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "There is no majority element in the array." << endl;
    }

    return 0;
}