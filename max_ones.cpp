// find the max consecutive ones in a binary array 
#include <iostream>
using namespace std;

int max_ones(int arr[],int n){
    int count = 0;
    int ones = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            if(count>ones){
                ones = count;
            }
        }
        else {
            count =0;
        }
    }
    return ones;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result = max_ones(arr,n);
    cout<<"Max consecutive ones: "<<result<<endl;
}