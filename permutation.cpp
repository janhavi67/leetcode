#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void next_permutation(vector<int> &nums){
    int n=nums.size();
    int i=n-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j=n-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());

}
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    next_permutation(nums);
    cout<<"Next permutation: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}