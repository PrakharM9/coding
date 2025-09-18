#include <bits/stdc++.h>
using namespace std;
vector<int>repandmiss(vector<int>arr){
    int n=arr.size();
    int hasharr[n+1]={0};
    for(auto it:arr)hasharr[it]++;
    int missing=-1,repeating=-1;
    for(int i=1;i<=n;i++){
        if(hasharr[i]==2)repeating=i;
        else if(hasharr[i]==0)missing=i;

        if(missing!=-1 && repeating!=-1)break;
    }
    return {repeating,missing};
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>ans=repandmiss(arr);
  cout<<"Repeating number is "<<ans[0]<<" and "<<"Missing number is "<<ans[1]<<endl;
  return 0;
}