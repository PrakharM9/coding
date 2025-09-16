#include <bits/stdc++.h>
using namespace std;
int countxorsub(vector<int>arr,int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int xr=0;
        for(int j=i;j<arr.size();j++){
            xr^=arr[j];
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
  cout<<"Number of subarrays with xor as "<<k<<" are: "<<countxorsub(arr,k);
  return 0;
}