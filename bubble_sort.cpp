#include <iostream>
using namespace std;
void bubblesort(int arr[], int n){
    for(int i = n-1; i>=0;i--){
        for(int j=0; j<= i-1; j++){
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
                }
        }
    }
}
int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"enter the element " << i+1 << ":";
        cin>> arr[i];
    }
    bubblesort(arr,n);
    cout<<"sorted array is :" ;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"," ;
    }

    
}