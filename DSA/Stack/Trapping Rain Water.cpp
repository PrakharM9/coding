#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0,leftmax=0,rightmax=0,left=0,right=n-1;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftmax>height[left]){
                    total+=leftmax-height[left];
                }
                else leftmax=height[left];
                left++;
            }
            else{
                if(rightmax>height[right]){
                    total+=rightmax-height[right];
                }
                else{
                    rightmax=height[right];
                }
                right--;
            }
        }
        return total;
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
  int result=sol.trap(arr);
  cout<<"Total water trapped is "<<result;
  return 0;
}