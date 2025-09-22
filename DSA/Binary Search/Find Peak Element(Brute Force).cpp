#include <bits/stdc++.h>
using namespace std;
int peakel(vector<int>arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(((i==0) || arr[i]>arr[i-1]) && ((i==n-1) || arr[i]>arr[i+1]))return arr[i];
    }
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Peak Element is "<<peakel(arr);
  return 0;
}