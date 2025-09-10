#include <bits/stdc++.h>
using namespace std;
int subarraywithsumk(vector<int>arr,int k){
    long long sum=arr[0];
    int maxlen=0;
    int n=arr.size();
    int left=0,right=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    return maxlen;
}
int main()
{
  int n,k;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>k;
  cout<<subarraywithsumk(arr,k);
  return 0;
}