/* Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one */

#include <iostream>
using namespace std;
int singleNumber(int arr[],int n){
    int xorr =0;
    for(int i=0;i<n;i++){
        xorr=xorr^arr[i];
    }
    return xorr;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The single number is: "<<singleNumber(arr,n);
}