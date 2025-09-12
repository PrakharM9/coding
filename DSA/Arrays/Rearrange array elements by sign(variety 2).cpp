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
  vector<int>pos,neg;
  for(auto it:arr){
    if(it<0)neg.push_back(it);
    else pos.push_back(it);
  }
  int i=0,endindex=min(pos.size(),neg.size());
  for(;i<endindex;i++){
    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
  }
  int index=2*endindex;
  for(;i<pos.size();i++){
    arr[index++]=pos[i];
  }
  for(;i<neg.size();i++){
    arr[index++]=neg[i];
  }
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}