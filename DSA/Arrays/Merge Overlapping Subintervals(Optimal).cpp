#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subintervals(vector<vector<int>>arr){
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int>>arr(n,vector<int>(2));
  for(int i=0;i<n;i++){
    cin>>arr[i][0]>>arr[i][1];
  }
  vector<vector<int>>solution=subintervals(arr);
  for(int i=0;i<solution.size();i++){
    for(int j=0;j<solution[i].size();j++){
        cout<<solution[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}