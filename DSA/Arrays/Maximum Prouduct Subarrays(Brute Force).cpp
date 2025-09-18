#include <bits/stdc++.h>
using namespace std;
int maxprod(vector<int>arr){
    int count=0,n=arr.size(),maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<arr.size();j++){
            int prod=1;
            for(int k=i;k<j;k++){
                prod*=arr[k];
            }
            maxi=max(maxi,prod);
        }
    }
    return maxi;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Maximum product subarrays is "<<maxprod(arr);
  return 0;
}