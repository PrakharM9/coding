#include <bits/stdc++.h>
using namespace std;
// Here we have used Kadane's Algorithm for fidninh maximum subarray sum
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  long long max=LONG_MIN,sum=0;
  int start,ansStart=-1,ansEnd=-1;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum>max){
        max=sum;
        ansStart=start;
        ansEnd=i;
    }
    if(sum<0){
        sum=0;
        start=i+1;
    }
  }
  cout<<"Maximum subarray's sum is:"<<max<<endl;
  cout<<"The starting and ending indices are: "<<ansStart<<" and "<<ansEnd;
  return 0;
}