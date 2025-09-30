#include <bits/stdc++.h>
using namespace std;
int rowsmax1s(vector<vector<int>>&matrix){
  int index=-1,maxcount=-1;
  for(int i=0;i<matrix.size();i++){
    int count=0;
    for(int j=0;j<matrix[0].size();j++){
      if(matrix[i][j]==1)count++;
    }
    if(count>maxcount){
      maxcount=count;
      index=i;
    }
  }
  return index;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>matrix(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>matrix[i][j];
    }
  }
  cout<<"Row with maximum 1 is "<<rowsmax1s(matrix)+1;
  return 0;
}