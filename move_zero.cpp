//move all the zeros to the end of sorted array 
#include <iostream>
#include <vector>
using namespace std;

//brute force approach :
int moveZeros(int arr[],int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        } 
    }
    int x = temp.size();
    for(int i=0;i<x;i++){
        arr[i]=temp[i];
    }
    for(int i=x;i<n;i++){
        arr[i]=0;
    }
    return arr[n];
}

//optimal approach : 
int move_zeros(int arr[],int n){
    int j =-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr[n];
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    move_zeros(arr,n);
    cout<<"The array after moving zeros to the end is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}