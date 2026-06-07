#include <iostream>
using namespace std;

void fun(int i , string &s) {
    if(i>= s.size()/2){
        cout <<"palindrome"<< endl;
        return;
}


if(s[i] != s[s.size()-i-1]) {
    cout <<"not palindrome"<< endl;
    return;
}

fun(i+1,s);
}
int main(){
    string s;
    cout <<" enter a string : " ;
    cin >>s;

    fun(0,s);
}