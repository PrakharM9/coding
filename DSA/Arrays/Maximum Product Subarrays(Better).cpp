#include <bits/stdc++.h>
using namespace std;
long long maxprod(vector<int>arr){
    int n=arr.size();
    long long maxprod=INT_MIN;
    for(int i=0;i<n;i++){
        long long prod=1;
        for(int j=i;j<n;j++){
            prod*=arr[j];
            maxprod=max(maxprod,prod);
        }
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
  cout<<"Maximum Product of Subarrays is "<<maxprod(arr);
  return 0;
}