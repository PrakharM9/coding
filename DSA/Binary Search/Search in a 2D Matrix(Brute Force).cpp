#include <bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>>&matrix,int element){
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==element)return true;
        }
    }
    return false;
}
int main()
{
  int n,m,element;
  cin>>n>>m;
  vector<vector<int>>matrix(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>matrix[i][j];
    }
  }
  cin>>element;
  if(search(matrix,element)){
    cout<<"Element is present"<<endl;
  }
  else cout<<"Element not present"<<endl;
  return 0;
}