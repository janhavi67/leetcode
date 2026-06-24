#include <iostream>
#include <vector>

using namespace std;

int missing_number(const vector<int>& arr, int n) {
    // If the array has 'n' elements, the sequence should go up to n+1.
    // The sum of the first (n+1) natural numbers is (n+1)(n+2)/2
    long long expSum = ((n + 1) * 1LL * (n + 2)) / 2; 
    
    // Changed to long long to prevent overflow for large arrays
    long long ms_sum = 0; 
    
    for(int i = 0; i < n; i++) {
        ms_sum = ms_sum + arr[i];
    }
    
    int ms = expSum - ms_sum;
    return ms;
}

int main() {
    int n;
    cout << "size of array : ";
    cin >> n;
    
    // Using a standard C++ vector instead of a Variable Length Array
    vector<int> arr(n);
    
    cout << "enter the no. : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Capture the return value and print it
    int result = missing_number(arr, n);
    cout << "The missing number is: " << result << endl;
    
    return 0;
}
