#include <bits/stdc++.h>
using namespace std;
int countxorsub(vector<int>arr,int k){
    int count=0,n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xr=0;
            for(int k=i;k<=j;k++){
                xr=xr^arr[k];
            }
            if(xr==k)count++;
        }
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
  cout<<"Number of subarrays with Xor K are :"<<countxorsub(arr,k);
  return 0;
}