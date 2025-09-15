#include <bits/stdc++.h>
using namespace std;
// This code can be used when we have to calculate pascal traingle's particular index value
long long Ncr(int n,int r){
    // Here we are calculating ncr
    long long res=1;
    for(int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main()
{
    // Here we will be given index and row and column start from 1
    int n,m;
    cin>>n>>m;
    cout<<Ncr(n-1,m-1);
    return 0;
}