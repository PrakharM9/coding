#include <bits/stdc++.h>
using namespace std;
vector<int>minmax(vector<int>arr){
    vector<int>ans(2);
    ans[0]=INT_MIN;//for max
    ans[1]=INT_MAX;//for min
    for(auto it:arr){
        if(it>ans[0])ans[0]=it;
        if(it<ans[1])ans[1]=it;
    }
    return ans;
}
bool totaldayscheck(vector<int>arr,int days,int m,int k){
    int bouquet=0,count=0;
    for(auto it:arr){
        if(it<=days)count++;
        else{
            bouquet+=(count/k);
            count=0;
        }
    }
    bouquet+=(count/k);
    if(bouquet>=m)return true;
    return false;
}
int mindays(vector<int>arr,int m,int k){
    int n=arr.size();
    if((m*k)>n)return -1;
    vector<int>vals=minmax(arr);
    int low=vals[1],high=vals[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(totaldayscheck(arr,mid,m,k))high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int m,k;
  cin>>m>>k;
//   m  is number of bouquets and k is the number of flowers
  int result=mindays(arr,m,k);
  if(result!=-1)cout<<result<<endl;
  else cout<<"Bouquets cannot be made";
  return 0;
}