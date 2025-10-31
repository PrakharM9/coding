#include <bits/stdc++.h>
using namespace std;
vector<int>sort(vector<int>arr){
    int n=arr.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  arr=sort(arr);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}

sl