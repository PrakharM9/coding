#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>quadlet(vector<int>arr,int target){
  set<vector<int>>st;
  for(int i=0;i<arr.size();i++){
    for(int j=i+1;j<arr.size();j++){
      set<int>hashset;
      for(int k=j+1;k<arr.size();k++){
        long long sum=arr[i]+arr[j];
        sum+arr[k];
        int value=sum-target;
        if(hashset.find(value)!=hashset.end()){
          vector<int>temp={arr[i],arr[j],arr[k],value};
          sort(temp.begin(),temp.end());
          st.insert(temp);
        }
        hashset.insert(arr[k]);
      }
    }
  }
  vector<vector<int>>ans(st.begin(),st.end());
  return ans;
}

int main()
{
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  vector<vector<int>>ans=quadlet(arr,target);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}