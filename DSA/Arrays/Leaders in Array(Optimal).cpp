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
  vector<int>leaders;
  int max=INT_MIN;
  for(int i=n-1;i>=0;i--){
    if(arr[i]>max){
        max=arr[i];
        leaders.push_back(arr[i]);
    }
  }
  for(auto it:leaders){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}