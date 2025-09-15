#include <bits/stdc++.h>
using namespace std;
vector<long long >generateRow(int row){
    long long ans=1;
    vector<long long >res;
    res.push_back(1);
    for(int i=1;i<row;i++){
        ans*=(row-i);
        ans/=i;
        res.push_back(ans);
    }
    return res;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<long long>>arr;
  for(int i=1;i<=n;i++){
    arr.push_back(generateRow(i));
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}