#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        bool status=true;
        vector<bool>check(arr.size(),false);
        int value;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                value=arr[i]+arr[j];
                if(value%k==0){
                    cout<<arr[i]<<" "<<arr[j]<<endl;
                    check[i]=true;
                    check[j]=true;
                }
            }
        }
        for(auto it: check){
            if(it==false){
                return false;
            }
        }
        return status;
    }
};
int main()
{
  Solution sol;
  vector<int>vals{-1,-1,-1,-1,2,2,-2,-2};
  sol.canArrange(vals,3);
  return 0;
}