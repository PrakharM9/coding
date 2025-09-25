#include <bits/stdc++.h>
using namespace std;
int countsubarrays(vector<int>arr,int maxpages){
    int arrsubarrays=0,subarrayscount=1;
    for(auto it:arr){
        if(arrsubarrays+it<=maxpages){
            arrsubarrays+=it;
        }
        else {
            subarrayscount+=1;
            arrsubarrays=it;
        }
    }
    return subarrayscount;
}
int subarrayslargestsum(vector<int>arr,int subarrays){
    if(subarrays>arr.size())return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(countsubarrays(arr,mid)>subarrays)low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
  int n,subarrays;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>subarrays;
  cout<<"Minimum of maximum sum of subarrays is "<<subarrayslargestsum(arr,subarrays);
  return 0;
}