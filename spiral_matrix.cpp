// change matrix into spiral matrix 
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiral(vector<vector<int>>& matrix){
    vector<int> result;
    int n= matrix.size();
    int m=matrix[0].size();
    int top =0 , bottom = n-1;
    int left =0 , right = m-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    cout<<"Enter the elements of the matrix: ";
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<int> result = spiral(matrix);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

