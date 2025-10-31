#include <bits/stdc++.h>
using namespace std;
void leftrotate(vector<int>&arr,int d){
  int n=arr.size();
  d=d%n;
  if(d==0)return;
  vector<int>temp;
  for(int i=0;i<d;i++){
    temp.push_back(arr[i]);
  }
  for(int i=d;i<n;i++){
    arr[i-d]=arr[i];
  }
  int j=0;
  for(int i=n-d;i<n;i++){
    arr[i]=temp[j++];
  }
}
int main()
{
  int n,d;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>d;
  leftrotate(arr,d);
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}