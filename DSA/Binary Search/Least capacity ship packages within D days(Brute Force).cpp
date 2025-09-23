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
    int cap=maxelem(arr),sumcap=sum(arr);
    for(int i=cap;i<=sumcap;i++){
        if(calculatedays(arr,i)<=days){
            return i;
        }
    }
    return -1;
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