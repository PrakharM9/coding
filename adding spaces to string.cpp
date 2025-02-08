#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str;
        int index=0;
        int value=spaces[index];
        for(int i=0;i<s.size();i++){
            if(i==value){
                str+=' ';
                index++;
                value=spaces[index];
            }
            str+=s[i];
        }
        return str;
    }
};
int main()
{
  Solution sol;
  vector<int>spaces{1,5,7,9};
  cout<<sol.addSpaces("icodeinpython",spaces);
  return 0;
}