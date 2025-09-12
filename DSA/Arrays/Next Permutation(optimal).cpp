#include <bits/stdc++.h>
using namespace std;
void nextpermuation(vector<int>&arr){
    int ind=-1;
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=arr.size()-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[ind],arr[i]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  nextpermuation(arr);
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}