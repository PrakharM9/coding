// This is the optimal solution for negatives but better for positives
#include <bits/stdc++.h>
using namespace std;
int longestsubarraywithsumk(vector<int>arr,long long k){
    map<long long,int>presummap;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==k)maxlen=max(maxlen,i+1);
        int rem=sum-k;
        if(presummap.find(rem)!=presummap.end()){
            int len=i-presummap[rem];
            maxlen=max(maxlen,len);
        }
        // this can be used when values does not include 0
        // presummap[sum]=i;
        if(presummap.find(sum)==presummap.end()){
            presummap[sum]=i;
        }
    }
    return maxlen;
}
int main()
{
    int n;
    long long k;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cout<<longestsubarraywithsumk(arr,k);
  return 0;
}