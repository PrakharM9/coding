#include <bits/stdc++.h>
using namespace std;
int maxelem(vector<int>arr){
    int maxel=INT_MIN;
    for(auto it:arr)if(maxel<it)maxel=it;
    return maxel;
}
int sum(vector<int>arr){
    int s=0;
    for(auto it:arr)s+=it;
    return s;
}
int calculatedays(vector<int>arr,int capacity){
    int day=1,load=0;
    for(int i=0;i<arr.size();i++){
        if(load+arr[i]<=capacity){
            load+=arr[i];
        }
        else{
            day+=1;
            load=arr[i];
        }
    }
    return day;
}
int leastcapacity(vector<int>arr,int days){
    int low=maxelem(arr),high=sum(arr);
    while(low<=high){
        int mid=(low+high)/2;
        if(calculatedays(arr,mid)<=days)high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main()
{
  int n,days;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>days;
  cout<<"Least capacity to ship packages is within " <<days<<" days is "<<leastcapacity(arr,days)<<endl;
  return 0;
}