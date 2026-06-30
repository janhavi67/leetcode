//you are given an array prices where prices[i] is the price of a given stock on the ith day. 
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

#include <iostream>
#include <algorithm> 
using namespace std;

int maxProfit(int prices[], int n) {
    if (n == 0) return 0; 

    int mini = prices[0];
    int profit = 0;

    for (int i = 0; i < n; i++) {
        int cost = prices[i] - mini;
        profit = max(profit, cost); 
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int prices[n];    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << "Maximum profit is: " << maxProfit(prices, n) << endl;
    
    return 0;
}
