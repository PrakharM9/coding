#include <bits/stdc++.h>
using namespace std;
long long maxprodsub(vector<int>arr){
    long long prefix=1,suffix=1,maxprod=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=arr[i];
        suffix*=arr[n-i-1];
        maxprod=max(maxprod,max(prefix,suffix));
    }
    return maxprod;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Maximum Product of Subarrays is "<<maxprodsub(arr);
  return 0;
}