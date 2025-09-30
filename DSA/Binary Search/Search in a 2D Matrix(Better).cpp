#include <bits/stdc++.h>
using namespace std;
bool bs(vector<int>&array,int element){
    int low=0,high=array.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(array[mid]==element)return true;
        else if(array[mid]<element)low=mid+1;
        else high=mid-1;
    }
    return false;
}
bool search2d(vector<vector<int>>&matrix,int element){
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=element && element<=matrix[i][m-1]){
            return bs(matrix[i],element);
        }
    }
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