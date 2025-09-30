#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        for(int i=0;i<start.size();i++){
            int index=i;
            if(start[i]=='L'){
                while(index>0 && start[index-1]=='_'){
                    swap(start[index-1],start[index]);
                    index--;
                }
            }
            else if(start[i]=='R'){
                while(index<start.size()-1 && start[index+1]=='_'){
                    swap(start[index],start[index+1]);
                    index++;
                }
            }
         }
          cout<<start<<" "<<target<<endl;
        return start==target;
    }
};
int main()
{
  Solution sol;
  cout<<sol.canChange("_L__R__R_","L______RR");
  return 0;
}