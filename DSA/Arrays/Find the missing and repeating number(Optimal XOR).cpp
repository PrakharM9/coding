#include <bits/stdc++.h>
using namespace std;
vector<int>repandmiss(vector<int>arr){
    long long n=arr.size();
    int xr=0;
    for(int i=0;i<n;i++){
        xr^=arr[i];
        xr^=i+1;
    }
    int number=(xr & ~(xr-1));
    int zero=0,one=0;
    for(int i=0;i<n;i++){
        if((arr[i]&number)!=0){
            one^=arr[i];
        }
        else{
            zero^=arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((i&number)!=0){
            one^=i;
        }
        else{
            zero^=i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==zero)cnt++;
    }
    if(cnt==2)return {zero,one};
    return {zero,one};
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>ans=repandmiss(arr);
  cout<<"Repeating number is "<<ans[0]<<" and Missing number is "<<ans[1]<<endl;
  return 0;
}