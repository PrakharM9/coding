#include <bits/stdc++.h>
using namespace std;
long double minimizemaxdistance(vector<int>arr,int k){
  int n=arr.size();
  priority_queue<pair<long double,int>>pq;
  vector<int>howMany(n-1,0);
  for(int i=0;i<n-1;i++){
    pq.push({(long double)(arr[i+1]-arr[i]),i});
  }
  for(int gasstations=1;gasstations<=k;gasstations++){
    auto top=pq.top();pq.pop();
    int secInd=top.second;
    howMany[secInd]++;
    long double inidiff=arr[secInd+1]-arr[secInd];
    long double newSecLen=inidiff/(long double)(howMany[secInd]+1);
    pq.push({newSecLen,secInd});
  }
  return pq.top().first;
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