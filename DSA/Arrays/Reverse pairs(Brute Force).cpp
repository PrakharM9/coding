#include <bits/stdc++.h>
using namespace std;
int reversepairs(vector<int>arr,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j])count++;
        }
    }
    return count;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Total Reverse Pairs are "<<reversepairs(arr,n);
  return 0;
}