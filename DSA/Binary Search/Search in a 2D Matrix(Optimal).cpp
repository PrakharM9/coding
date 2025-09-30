#include <bits/stdc++.h>
using namespace std;
bool search2d(vector<vector<int>>&matrix,int element){
    int n=matrix.size(),m=matrix[0].size();
    int low=0,high=(n*m)-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==element)return true;
        else if(matrix[row][col]<element)low=mid+1;
        else high=mid-1;
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