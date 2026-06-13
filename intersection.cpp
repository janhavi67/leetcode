#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> intersectionArr;
    
    
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            i++;
        } 
        else if (a[i] > b[j]) {
            j++;
        } 
        else {
            intersectionArr.push_back(a[i]);
            i++;
            j++;
        }
    }

    return intersectionArr;
}

int main(){
    int n1,n2;
    cout<<"Enter size of first array: ";
    cin>>n1;
    vector <int> a(n1);
    cout<<"Enter elements of first array: ";
    for(int i=0; i<n1; i++){
        cin>>a[i];
    }
    cout<<"Enter size of second array: ";
    cin>>n2;
    vector <int> b(n2);
    cout<<"Enter elements of second array: ";
    for(int i=0; i<n2; i++){
        cin>>b[i];
    }
    vector <int> intersectionArr = intersection(a,b);
   
}
