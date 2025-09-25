#include <bits/stdc++.h>
using namespace std;
int kthmissingpositive(vector<int>arr,int k){
    for(auto it:arr){
        if(it<=k)k++;
        else break;
    }
    return k;
}
int main()
{
  int n,k;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>k;
  cout<<"Kth missing positive is "<<kthmissingpositive(arr,k);
}