#include <bits/stdc++.h>
using namespace std;
long double minimizemaxdistance(vector<int>arr,int k){
  int n=arr.size();
  vector<int>howMany(n-1,0);
  for(int gasstation=0;gasstation<=k;gasstation++){
    long double maximumval=-1;
    int maxind=-1;
    for(int i=0;i<n-1;i++){
      long double diff=arr[i+1]-arr[i];
      long double sectionlength=diff/(howMany[i]+1);
      if(maximumval<sectionlength){
        maximumval=sectionlength;
        maxind=i;
      }
    }
    howMany[maxind]++;
  }
  long double maxans=-1;
  for(int i=0;i<n-1;i++){
    long double sectionlength=(arr[i+1]-arr[i])/(howMany[i]+1);
    maxans=max(maxans,sectionlength);
  }
  return maxans;
}
int main()
{
  int n,newstation;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>newstation;
  cout<<"Minimum of maximum distance between gas stations is "<<minimizemaxdistance(arr,newstation);
  return 0;
}