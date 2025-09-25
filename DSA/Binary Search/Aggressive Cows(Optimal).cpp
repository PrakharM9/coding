#include <bits/stdc++.h>
using namespace std;
bool canbeplaced(vector<int>arr,int dist,int cows){
    int last=arr[0],count=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=dist){
            count++;
            last=arr[i];
        }
        if(count>=cows)return true;
    }
    return false;
}
int aggressivecows(vector<int>arr,int cows){
    sort(arr.begin(),arr.end());
    int low=1,high=arr[arr.size()-1]-arr[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(canbeplaced(arr,mid,cows))low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main()
{
  int n,cows;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
//   Here arr have positions and cows represents number of cows
  cin>>cows;
  cout<<aggressivecows(arr,cows);
  return 0;
}