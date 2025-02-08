#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        for(int i=1;i<s.size();i++){
            int index1=-1,index2=-1;
            for(int j=i-1;j>=0;j--){
                if(s[j]==s[i]){
                    index1=j;
                    break;
                }
            }
            for(int k=i+1;k<s.size();k++){
                if(s[k]==s[i]){
                    index2=k;
                    break;
                }
            }
            if(index1!=-1 && index2!=-1){
                s.erase(i,1);
                i--;
            }
        }
        return s.size();
    }
};
int main()
{
  Solution sol;
  cout<<sol.minimumLength("abaacbcbb");
  return 0;
}