#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> indexed_nums(n);
    
    // Store values along with their original indices
    for(int i = 0; i < n; i++) {
        indexed_nums[i] = {nums[i], i};
    }
    
    // Sort based on the values
    sort(indexed_nums.begin(), indexed_nums.end());
    
    int left = 0, right = n - 1;
    while(left < right) {
        int current_sum = indexed_nums[left].first + indexed_nums[right].first;
        
        if(current_sum == target) {
            return {indexed_nums[left].second, indexed_nums[right].second};
        }
        else if(current_sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    
    return {}; // Return empty if no solution is found
}

int main() {
    int n, target;
    
    cout<< "Enter the size of array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout<< "Enter the target sum: ";
    cin >> target;
    
    vector<int> result = twoSum(nums, target);

    if(!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << " are: " 
             << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers found that add up to " << target << endl;
    }
    
    return 0;
}