#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int count0=0,count1=0,count2=0;
  for(int i=0;i<n;i++){
    if(arr[i]==0)count0++;
    else if(arr[i]==1)count1++;
    else count2++;
  }
  for(int i=0;i<count0;i++)arr[i]=0;
  for(int i=count0;i<count0+count1;i++)arr[i]=1;
  for(int i=n-1;i>count1+count0-1;i--)arr[i]=2;
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}