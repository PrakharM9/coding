#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<vector<int>>arr(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
  }
  vector<vector<int>>ans(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        ans[j][n-i-1]=arr[i][j];
        // In the above line we have form the relation in both the matrices
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}