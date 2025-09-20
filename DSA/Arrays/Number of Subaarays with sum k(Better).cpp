#include <bits/stdc++.h>
using namespace std;
int countsubarr(vector<int>arr,int k){
    int count=0,n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k)count++;
        }
    }
    return count;
}
int main(){
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  cout<<"Count of Subarrays is "<<countsubarr(arr,target);
  return 0;
}