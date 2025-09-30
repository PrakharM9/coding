#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int min,max;
        set<double>vals;
        while(!nums.empty()){
            min=0;
            max=0;
            for(int i=1;i<nums.size();i++){
                if(nums[min]>nums[i]){
                    min=i;
                }
                if(nums[max]<nums[i]){
                    max=i;
                }
            }
            cout<<nums[max]<<" "<<nums[min]<<endl;
            vals.insert((nums[max]+nums[min])/2.0);
            nums.erase(nums.begin()+max);
            if(max>min){
                nums.erase(nums.begin()+min);
            }
            else{
                nums.erase(nums.begin()+(min-1));
            }
        }
        cout<<endl;
        return vals.size();
    }
};
int main()
{
  Solution sol;
  vector<int>nums{10,2,2,0,4,0};
  int num=sol.distinctAverages(nums);
  cout<<num;
  return 0;
}