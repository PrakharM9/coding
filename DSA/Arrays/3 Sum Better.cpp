#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>triplet(vector<int>nums){
    set<vector<int>>st;
    for(int i=0;i<nums.size();i++){
        set<int>hashset;
        for(int j=i+1;j<nums.size();j++){
            int third=-(nums[i]+nums[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int>temp={nums[i],nums[j],third};
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<vector<int>>ans= triplet(arr);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}