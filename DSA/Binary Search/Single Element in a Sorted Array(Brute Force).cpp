#include <bits/stdc++.h>
using namespace std;
int single(vector<int>arr){
  int n=arr.size();
  for(int i=0;i<n;i++){
    if(i==0){
      if(arr[i]!=arr[i+1])return arr[i];
    }
    else if(i==n-1){
      if(arr[i]!=arr[i-1])return arr[i];
    }
    else{
      if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1])return arr[i];
    }
  }
  return -1;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Single ELement is "<<single(arr)<<endl;
  return 0;
}