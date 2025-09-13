#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>arr(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
  }
  vector<int>row(n,0);
  vector<int>col(m,0);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==0){
            row[i]=1;
            col[j]=1;
        }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(row[i]==1 || col[j]==1){
            arr[i][j]=0;
        }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}