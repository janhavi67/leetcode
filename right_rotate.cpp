//right rotate the array by k positions
#include <iostream>
using namespace std;
void rotate(int arr[],int n,int k){
    k =k%n;
    int temp[n];
    for(int i=n-k;i<n;i++){
        temp[i-n+k]=arr[i];
    }
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }

}

int main(){
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of positions to rotate: ";
    cin>>k;
    rotate(arr,n,k);
    cout<<"The rotated array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

}
