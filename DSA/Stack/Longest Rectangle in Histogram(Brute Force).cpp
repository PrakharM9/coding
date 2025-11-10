#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
  vector<int>findnse(vector<int>nums){
    int n=nums.size();
    vector<int>nse(n,-1);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
      while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
      if(!st.empty())nse[i]=st.top();
      st.push(i);
    }
    return nse;
  }
  vector<int>findpse(vector<int>arr){
    stack<int>st;
    int n=arr.size();
    vector<int>pse(n,-1);
    for(int i=0;i<n;i++){
      while(!st.empty()&& arr[st.top()]>=arr[i])st.pop();
      if(!st.empty())pse[i]=st.top();
      st.push(i);
    }
    return pse;
  }
  int longestrectangle(vector<int>nums){
    int maxrect=0;
    vector<int>pse=findpse(nums);
    vector<int>nse=findnse(nums);
    for(int i=0;i<nums.size();i++){
      maxrect=max(maxrect,(nums[i]*(nse[i]-pse[i]-1)));
    }
    return maxrect;
  }
};
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  Solution sol;
  cout<<"Maximum area of rectangle is "<<sol.longestrectangle(arr);
  return 0;
}