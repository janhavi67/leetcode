#include <iostream> 
#include <map>
#include <vector>
using namespace std;

int longestSubarray(vector<int> a, long long k){
    map<long long, int> preSumMap;
    long long sum =0;
    int maxlen =0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(sum ==k){
            maxlen =max(maxlen,i+1);
        }
        int rem =sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i-preSumMap[rem];
            maxlen =max(maxlen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] =i;
        }
    }
    return maxlen;
}
int longest(int arr[], int n , long long k){
    int left =0, right =0;
    long long sum =0;
    int maxlen =0;
    while(right<n){
        sum += arr[right];
        while(sum>k && left <=right){
            sum -= arr[left];
            left++;
        }
        if(sum ==k){
            maxlen =max(maxlen,right-left+1);
        }
    }
    return maxlen;

}
int main(){
    int n;
    long long k;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter value of k: ";
    cin>>k;
    cout<<"The length of longest subarray with sum "<<k<<" is: "<<longestSubarray(a,k);
    cout<<"\nThe length of longest subarray with sum "<<k<<" is: "<<longest(a.data(),n,k);
}