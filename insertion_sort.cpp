#include <iostream>
using namespace std;
void insertionsort(int arr[],int n){
    for(int i =0; i<=n-1;i++){
        int j =i;
        while(i>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
int main(){
    int n;
    cout<<"enter the size of array :";
    cin>>n;
    int arr[n];
    for(int i =0; i<n;i++){
        cout<<"enter the element " << i+1 << ":";
        cin>> arr[i];
    }
    insertionsort(arr,n);
    cout<<"sorted array is :";
    for(int i=0; i<n;i++){
        cout<<arr[i]<<",";
    }
}