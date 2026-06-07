#include <iostream> 
using namespace std;
 int fun(int n){
    if(n<=1){
        return n;
    }
   int last = fun(n-1);
   int slast = fun(n-2);
    return last + slast;

}
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    cout<<fun(n);
    
}