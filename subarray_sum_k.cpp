#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;
        
        // Base case: A prefix sum of 0 has occurred 1 time
        prefixSumCount[0] = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            
            // Check if there is a prefix sum that we can subtract from currentSum to get k
            int neededSum = currentSum - k;
            if (prefixSumCount.find(neededSum) != prefixSumCount.end()) {
                count += prefixSumCount[neededSum];
            }
            
            // Add the currentSum to the hash map
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
int main(){
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    vector<int> nums;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int result = subarraySum(nums, k);
    cout<<"The number of continuous subarrays that sum to "<<k<<" is: "<<result;
}