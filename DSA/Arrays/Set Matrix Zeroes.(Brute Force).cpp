#include <bits/stdc++.h>
using namespace std;

void markrow(vector<vector<int>>&arr,int i){
    for(int j=0;j<arr[0].size();j++){
        if(arr[i][j]==1){
            arr[i][j]=-1;
        }
    }
}
void markcolumn(vector<vector<int>>&arr,int j){
    for(int i=0;i<arr.size();i++){
        if(arr[i][j]==1){
            arr[i][j]=-1;
        }
    }
}
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
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==0){
            markrow(arr,i);
            markcolumn(arr,j);
        }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==-1){
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