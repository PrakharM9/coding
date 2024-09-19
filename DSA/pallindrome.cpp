#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        bool status=true;
        char ch;
        string str,strrev;
        int length=s.size();
        for(int i=0;i<length;i++){
            ch=tolower(s[i]);
            if(ch>='a' && ch<='z'){
                str+=ch;
            }
        }
        for(int i=length-1;i>=0;i--){
            strrev+=str[i];
        }
        for(int i=0;i<length;i++){
            if(str[i]!=strrev[i]){
                status=false;
                break;
            }
        }
        return status;
    }
};
int main(){
    Solution sol;
    string str;
    getline(cin,str);
    cout<<sol.isPalindrome(str);
    return 0;
}