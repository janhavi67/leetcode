#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    // Dynamically allocate a temporary array of the exact size needed
    int* temp = new int[high - low + 1]; 
    
    int left = low;
    int right = mid + 1;
    int k = 0; // Index tracker for the temp array
    
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp[k] = arr[left];
            left++;
        }
        else {
            temp[k] = arr[right];
            right++;
        } 
        k++;
    }
    
    while (left <= mid){
        temp[k] = arr[left];
        left++;
        k++;
    }
    
    while(right <= high){
        temp[k] = arr[right];
        right++;
        k++;
    }
    
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    
}

void merge_sort(int arr[], int low, int high){
    if(low >= high){ 
        return;
    }
    int mid = low + (high - low) / 2; 
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void ms(int arr[], int n){
    merge_sort(arr, 0, n - 1);
}

int main(){
    int n;
    cout <<"enter the size of array :";
    cin>> n;
    int arr[n];
    cout<<"enter the elemnts of array : ";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    ms(arr,n);
    cout<<"sorted array is :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}