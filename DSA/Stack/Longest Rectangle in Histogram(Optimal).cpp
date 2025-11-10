#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
  int longestrectangle(vector<int>nums){
    stack<int>st;
    int n=nums.size();
    int longrect=0;
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            int elementindex=st.top();
            st.pop();
            int nse=i,pse=st.empty()?-1:st.top();
            longrect=max(longrect,(nums[elementindex]*(nse-pse-1)));
        }
        st.push(i);
    }
    while(!st.empty()){
        int nse=n,elementindex=st.top();
        st.pop();
        int pse=(st.empty())?-1:st.top();
        longrect=max(longrect,(nums[elementindex]*(nse-pse-1)));
    }
    return longrect;
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