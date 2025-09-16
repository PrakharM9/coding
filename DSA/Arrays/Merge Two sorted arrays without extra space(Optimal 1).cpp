#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size();
    int m=arr2.size();
    int left=n-1,right=0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else break;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}
int main()
{
    
  int n,m;
  cin>>n;
  vector<int>arr1(n);
  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }
  cin>>m;
  vector<int>arr2(m);
  for(int i=0;i<m;i++){
    cin>>arr2[i];
  }
  merge(arr1,arr2);
  for(auto it:arr1){
    cout<<it<<" ";
  }
  cout<<endl;
  for(auto it:arr2){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}