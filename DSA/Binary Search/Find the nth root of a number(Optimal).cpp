#include <bits/stdc++.h>
using namespace std;
long long powerchecker(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m)return 2;
    }
    if(ans==m)return 1;
    return 0;
}
int nthroot(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        long long result=powerchecker(mid,n,m);
        if(result==1)return mid;
        else if(result==0)low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{
  int n,m;
  cin>>n>>m;
  cout<<nthroot(n,m);
  return 0;
}