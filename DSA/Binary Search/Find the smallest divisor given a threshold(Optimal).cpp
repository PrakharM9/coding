#include <bits/stdc++.h>
using namespace std;
int maxelem(vector<int>arr){
    int maxel=INT_MIN;
    for(auto it:arr){
        if(it>maxel)maxel=it;
    }
    return maxel;
}
int sumDivisors(vector<int>arr,int divisor){
    int sum=0;
    for(auto it:arr){
        sum+=ceil((double)it/(double)divisor);
    }
    return sum;
}
int smallestdivisor(vector<int>arr,int threshold){
    if(arr.size()>threshold)return -1;
    int low=0,high=maxelem(arr);
    while(low<=high){
        int mid=(low+high)/2;
        if(sumDivisors(arr,mid)<=threshold){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
int main()
{
  int n,threshold;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>threshold;
  int result=smallestdivisor(arr,threshold);
  if(result!=-1){
    cout<<"Smallest divisor is "<<result;
  }else cout<<"Divisor not possible";
  return 0;
}