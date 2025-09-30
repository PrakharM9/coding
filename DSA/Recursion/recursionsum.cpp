#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}
int main(){
    int num;
    cin>>num;
    cout<<sum(num);
    return 0;
}