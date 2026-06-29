// Given an integer array nums, find the subarray with the largest sum, and return its sum.
#include <iostream>
#include <climits>
using namespace std;

int max_array(int arr[],int n){
    long long max_sum = INT_MIN;
    long long sum =0;
    for(int i=0;i<n;i++){
        sum =sum + arr[i];
        if(sum>max_sum){
            max_sum =sum;
        }
        if(sum<0){
            sum =0;
        }
    }
    return max_sum;
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum subarray sum is : "<<max_array(arr,n);
}