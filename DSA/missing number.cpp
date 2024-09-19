#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int element,length=nums.size();
        int diff=(nums[length-1]-nums[0])/(length);
        for(int i=0;i<length-1;i++){
            if((nums[0]+i*diff)!=nums[i]){
                element=nums[i];
            }
        }
        return element;
    }
};
int main()
{
    v
    return 0;
}