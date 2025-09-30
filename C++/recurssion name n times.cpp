#include<bits/stdc++.h>
using namespace std;
string str;
void printer(int i,int n){
    if(i>n){
        return;
    }
    cout<<str<<endl;
    printer(++i,n);
}
int main(){
    int n;
    cin>>n;
    cin>>str;
    printer(1,n);
    return 0;
}