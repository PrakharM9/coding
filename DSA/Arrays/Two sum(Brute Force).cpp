#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]+arr[j]==target){
            cout<<"Indices are: "<<i<<" and "<<j<<endl;
            return 0;
        }
    }
  }
  return 0;
}