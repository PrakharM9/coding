#include <bits/stdc++.h>
using namespace std;

int countxorsub(vector<int>arr,int k){
    int count=0,xr=0,n=arr.size();
    map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<n;i++){
        xr^=arr[i];
        int x=xr^k;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;
}
int main()
{
  int n,k;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>k;
  cout<<"Number of subarrays with xor as "<<k<<" are:"<<countxorsub(arr,k);
  return 0;
}