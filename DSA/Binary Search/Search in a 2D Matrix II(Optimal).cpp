#include <bits/stdc++.h>
using namespace std;
bool search2d(vector<vector<int>>&matrix,int element){
    int n=matrix.size(),m=matrix[0].size();
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==element)return true;
        else if(matrix[row][col]<element)row++;
        else col--;
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
  if(search2d(matrix,element)){
    cout<<"Element is present"<<endl;
  }
  else cout<<"Element not present"<<endl;
  return 0;
}