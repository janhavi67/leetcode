//rotate matrix by 90 degrees
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>rotate(vector<vector<int>>& matrix){
    int n=matrix.size();
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}
int main(){
    int n;;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    cout<<"Enter the elements of matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>result=rotate(matrix);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}