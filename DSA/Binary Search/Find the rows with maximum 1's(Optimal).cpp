#include <bits/stdc++.h>
using namespace std;
int lowerbound(vector<int>nums,int target){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int rowsmax1s(vector<vector<int>>&matrix){
    int n=matrix.size(),m=matrix[0].size();
    int index=-1,maxcount=-1;
    for(int i=0;i<n;i++){
    int count=m-lowerbound(matrix[i],1);
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