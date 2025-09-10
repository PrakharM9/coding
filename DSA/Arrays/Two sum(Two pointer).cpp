#include <bits/stdc++.h>
using namespace std;

int main()
{
  int num,target;
  cin>>num;
  vector<int>nums(num);
  for(int i=0;i<num;i++){
    cin>>nums[i];
  }
  cin>>target;
  int left=0,right=num-1;
  int sum;
  while(left<right){
    sum=nums[left]+nums[right];
    if(sum==target){
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(sum<target){
        left++;
    }
    else right--;
  }
  cout<<"No";
  return 0;
}