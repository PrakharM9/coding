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
  unordered_map<int,int>mpp;
  for(int i=0;i<arr.size();i++){
    mpp[arr[i]]++;
  }
  for(auto it:mpp){
    if(it.second>arr.size()/2) {
        cout<<"Majority element is: "<<it.first;
        return 0;
    }
  }
  cout<<"No Majority element";
  return 0;
}