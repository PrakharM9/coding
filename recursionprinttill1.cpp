#include<bits/stdc++.h>
using namespace std;
void printer(int i,int n){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    printer(--i,n);
}
int main(){
    int n;
    cin>>n;
    printer(n,n);
    return 0;
}