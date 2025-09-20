#include <bits/stdc++.h>
using namespace std;
// here we are using upper bound and lower bound code for the problem
int lowerbound(vector<int>&arr,int target){
    int n=arr.size();
    int answer=n,low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            answer=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return answer;
}
int upperbound(vector<int>&arr,int target){
    int n=arr.size();
    int answer=n,low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            answer=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return answer;
}
int countoccurence(vector<int>&arr,int target){
    int first=lowerbound(arr,target);
    if(first==arr.size() || arr[first]!=target){
        return 0;
    }
    int last=upperbound(arr,target)-1;
    return (last-first+1);
}
int main()
{
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  cout<<"Occurences are "<<countoccurence(arr,target);
  return 0;
}