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
pair<int,int> firstandlastoccurence(vector<int>&arr,int target){
    int first=lowerbound(arr,target);
    if(first==arr.size() || arr[first]!=target){
        return {-1,-1};
    }
    int last=upperbound(arr,target)-1;
    return {first,last};
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
  pair<int,int>result=firstandlastoccurence(arr,target);
  if(result.first!=-1){
    cout<<"First occurence is "<<result.first<<" and last occurence is "<<result.second<<endl;
  }
  else{
    cout<<"Element not present";
  }
  return 0;
}