#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string trim(string t,int index){
        string st;
        for(int i=0;i<index;i++){
            st+=t[i];
        }
        for(int i=index+2;i<t.length();i++){
            st+=t[i];
        }
        return st;
    }
    int minLength(string s) {
      int len=s.size(),con=1;
        for(int i=0;i<len;i++){
            if((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')){
                s=trim(s,i);
            }
        }
        if((s[len-2]=='A' && s[len-1]=='B') || (s[len-2]=='C' && s[len-1]=='D')){
          s=trim(s,len-2);
        }
        return s.length();
    }
};
int main()
{
  string str;
  cin>>str;
  Solution sol;
  int length=sol.minLength(str);
  cout<<length;
  return 0;
}