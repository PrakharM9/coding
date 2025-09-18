#include <bits/stdc++.h>
using namespace std;
vector<int>repandmiss(vector<int>arr){
    int n=arr.size();
    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=arr[i];
        S2+=1LL*arr[i]*arr[i];
    }
    long long val1=S-SN;
    long long val2=S2-S2N;
    val2/=val1;
    long long x=(val1+val2)/2;
    long long y=x-val1;
    return {(int)x,(int)y};
}
// here we have solved the question using Maths logic
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>ans=repandmiss(arr);
  cout<<"Repeating number is "<<ans[0]<<" and missing number is "<<ans[1]<<endl;
  return 0;
}