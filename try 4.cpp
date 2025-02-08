#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        vector<char>vals1;
        for(char it:str1){
            vals1.push_back(it);
        }
        int count=0;
        for(char it:str2){
            char ch=vals1[count]+1;
            if(vals1[count]!=it && vals1[count]+1!=it){
                return false;
            }
            count++;
        }
        return true;
    }
};
int main()
{
  Solution sol;
  cout<<sol.canMakeSubsequence("abc","ad");
  return 0;
}