#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>asteroidcollisions(vector<int>arr){
        stack<int>st;
        for(auto it:arr){
            if(it>0){
                st.push(it);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(it))st.pop();
                if(!st.empty() && st.top()==abs(it))st.pop();
                else if(st.empty() || st.top()<0)st.push(it);
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
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
  vector<int>result=sol.asteroidcollisions(arr);
  for(auto it:result)cout<<it<<" ";
  return 0;
}