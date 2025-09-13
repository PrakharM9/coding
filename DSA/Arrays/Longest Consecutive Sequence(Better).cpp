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
  sort(arr.begin(),arr.end());
  int longest=1,lastsmaller=INT_MIN,count=1;
  for(int i=0;i<n;i++){
    if(arr[i]-1==lastsmaller){
        lastsmaller=arr[i];
        count++;
    }
    else if(arr[i]!=lastsmaller){
        lastsmaller=arr[i];
        count=1;
    }
    longest=max(longest,count);
  }
  cout<<"Longest common sequence is of length: "<<longest;
  return 0;
}