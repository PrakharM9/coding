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
      if(it<0)pos.push_back(it);
      else neg.push_back(it);
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}