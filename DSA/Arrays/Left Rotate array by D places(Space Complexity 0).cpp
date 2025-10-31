#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int>&arr,int s,int e){
  int start=s,end=e;
  while(start<=end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;
  }
}
void leftrotate(vector<int>&arr,int d){
  int n=arr.size();
  d=d%n;
  if(d==0)return;
  rotate(arr,0,d-1);
  rotate(arr,d,n-1);
  rotate(arr,0,n-1);
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