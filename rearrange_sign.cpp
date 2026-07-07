//u are given a 0-indexed integer array nums of even length consisting of an equal number of +ve and -ve integers.
//Every consecutive pair of integers have opposite signs.
//For all integers with the same sign, the order in which they were present in nums is preserved.
//The rearranged array begins with a positive integer.

#include <iostream>
#include <vector>
using namespace std;

//brute force approach
vector<int> rearrange(vector<int> nums) {
    vector<int> pos, neg;
    for (int i=0;i<nums.size();i++) {
        if (nums[i] > 0) {
            pos.push_back(nums[i]);
        } else {
            neg.push_back(nums[i]);
        }
    }
    for(int i=0;i<pos.size();i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
    return nums;
}

//optimal approach : 
vector <int> rearrange_optimal(vector<int>nums){
    vector<int> result(nums.size());
    int positive =0, negative =1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            result[positive]=nums[i];
            positive +=2;
        }
        else{
            result[negative]=nums[i];
            negative +=2;
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> result = rearrange(nums);
    cout<<"The rearranged array is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    vector<int> result_optimal = rearrange_optimal(nums);
    cout<<"\nThe rearranged array using optimal approach is: ";
    for(int i=0;i<result_optimal.size();i++){
        cout<<result_optimal[i]<<" ";
    }
}


        
    

 