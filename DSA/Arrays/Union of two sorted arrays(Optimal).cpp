#include <bits/stdc++.h>
using namespace std;
vector<int> uni(vector<int>arr1,vector<int>arr2){
  int n1=arr1.size(),n2=arr2.size();
  int i=0,j=0;
  vector<int>result;
  while(i<n1 && j<n2){
    if(arr1[i]<=arr2[j]){
      if(result.size()==0 || result.back()!=arr1[i]){
        result.push_back(arr1[i]);
      }
      i++;
    }
    else{
      if(result.size()==0 || result.back()!=arr2[j]){
        result.push_back(arr2[j]);
      }
      j++;
    }
  }
  while(i<n1){
    if(result.size()==0 || result.back()!=arr1[i]){
        result.push_back(arr1[i]);
    }
    i++;
  }
  while(j<n2){
    if(result.size()==0 || result.back()!=arr2[j]){
        result.push_back(arr2[j]);
    }
    j++;
  }
  return result;
}
int main()
{
  int n1,n2;
  cin>>n1;
  vector<int>arr1(n1);
  for(int i=0;i<n1;i++){
    cin>>arr1[i];
  }
  cin>>n2;
  vector<int>arr2(n2);
  for(int i=0;i<n2;i++){
    cin>>arr2[i];
  }
  vector<int>arr=uni(arr1,arr2);
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}