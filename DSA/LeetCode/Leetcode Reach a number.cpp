#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int reachNumber(int target) {
            int count=0,num=0;
            target=abs(target);
            while(true){
                if(num>=target && ((num-target)%2==0))return count;
                count++;
                num+=count;
            }
        }
    };
int main()
{
  Solution sol;
  cout<<sol.reachNumber(0)<<endl; 
  return 0;
}