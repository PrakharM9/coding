#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int prod=1,counter=0,prod2=1;
        int index=nums.size()-1;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<3;i++){
            if(nums[i]!=0){
                prod*=nums[i];
                counter++;
            } 
        }
        if(counter<3)prod*=0;
        counter=0;
        while(nums[index]<0 && counter<2){
            if(nums[index]!=0){
                prod2*=nums[index--];
                counter++;
            }
        }
        cout<<prod2<<endl;
        // if(index==0)prod2*=nums[0];
        // else prod2*=0;
        prod2*=nums[0];
        return max(prod,prod2);
    }
};
int main()
{
  Solution sol;
  vector<int>vals{-100,-98,-1,2,3,4};
  cout<<sol.maximumProduct(vals);
  return 0;
}