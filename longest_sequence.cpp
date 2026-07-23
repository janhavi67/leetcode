#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Brute force approach
bool ls(int arr[], int n, int val) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == val) {
            return true;
        }
    }
    return false;
}

int longest_seq(int arr[], int n) {
    if (n == 0) return 0;
    int longest = 1;
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        int count = 1;
        while(ls(arr, n, x + 1) == true) {
            x = x + 1;
            count = count + 1;
        }
        if(count > longest) {
            longest = count;
        }
    }
    return longest;
}

// Optimal approach 
int long_seq(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    
    int longest = 1;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    for (auto it : s) {
        if (s.find(it - 1) == s.end()) {
            int count = 1;
            int x = it;
            
            while (s.find(x + 1) != s.end()) {
                x = x + 1;
                count = count + 1;
            }
            
            longest = max(longest, count);
        }
    }
    return longest;
}

int main() {
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Brute Force Output: " << longest_seq(arr, n) << endl;
    cout << "Optimal Output: " << long_seq(arr, n) << endl;
    
    return 0;
}