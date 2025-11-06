#include <bits/stdc++.h>
using namespace std;
vector<int>nextgreater(vector<int>nums){
    stack<int>st;
    int n=nums.size();
    vector<int>nge(n);
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i%n])st.pop();
        if(i<n)nge[i]=st.empty()?-1:st.top();
        st.push(nums[i%n]);
    }
    return nge;
}
int main()
{
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  vector<int>result=nextgreater(nums);
  for(auto it:result){
    cout<<it<<" ";
  }
  return 0;
}