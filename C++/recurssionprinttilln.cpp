#include<bits/stdc++.h>
using namespace std;
void printer(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    printer(++i,n);
}
int main(){
    int n;
    cin>>n;
    printer(1,n);
    return 0;
}
