#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        bool status=true;
        string str,strrev;
        int length=s.size();
        for(int i=0;i<length;i++){
            char ch=s[i];
            if(isalpha(ch)){
                str+=tolower(ch);
            }
        }
        cout<<str<<endl;
        length=str.size();
        for(int i=length-1;i>=0;i--){
            strrev+=str[i];
        }
        cout<<strrev<<endl;
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
    if(sol.isPalindrome(str)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}