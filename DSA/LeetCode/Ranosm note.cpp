#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>mag(26,0);
        vector<int>ransom(26,0);
        for(char ch:magazine){
            mag[ch-'a']+=1;
        }
        for(char ch:ransomNote){
            ransom[ch-'a']+=1;
        }
        for(char ch:ransom){
            if(ransom[ch-'a']!=mag[ch-'a']){
                return false;
            }
        }
        return true;
    }
};
int main()
{
  Solution sol;
  cout<<sol.canConstruct("a","b");
  return 0;
}