#include <bits/stdc++.h>
using namespace std;
// This code can be used when we have to calculate pascal traingle's row values using brute force
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
    int n;
    cin>>n;
    for(int c=1;c<=n;c++){
        cout<<Ncr(n-1,c-1)<<" ";
    }
    return 0;
}