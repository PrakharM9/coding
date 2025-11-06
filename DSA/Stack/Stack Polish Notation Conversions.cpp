#include <bits/stdc++.h>
using namespace std;
class PolishNotations{
  public:
  int priority(char ch){
    if(ch=='^')return 3;
    else if(ch=='*' || ch=='/')return 2;
    else if(ch=='+' || ch=='-')return 1;
    return -1;
  }
  string Infix2Postfix(string s){
    stack<char>st;
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++){
      if((s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z')|| (s[i]>=0 && s[i]<=9)){
        ans+=s[i];
      }
      else if(s[i]=='('){
        st.push(s[i]);
      }
      else if(s[i]==')'){
        while(!st.empty() && st.top()!='('){
          ans+=st.top();
          st.pop();
        }
        st.pop();
      }
      else{
        while(!st.empty() && priority(s[i])<=priority(st.top())){
          ans+=st.top();
          st.pop();
        }
        st.push(s[i]);
      }
    }
    while(!st.empty()){
      ans+=st.top();
      st.pop();
    }
    return ans;
  }
  string Infix2Prefix(string s){
    reverse(s.begin(),s.end());
    int n=s.size();
    for(int i=0;i<n;i++){
      if(s[i]=='(')s[i]=')';
      else if(s[i]==')')s[i]='(';
    }
    stack<char>st;
    string ans=Infix2Postfix(s );
    reverse(ans.begin(),ans.end()); 
    return ans;
  }
  string Postfix2Infix(string s){
    stack<string>st;
    int n=s.size();
    for(int i=0;i<n;i++){
      if(isalnum(s[i]))st.push(string(1,s[i]));
      else {
        string t1=st.top();st.pop();
        string t2=st.top();st.pop();
        string con='('+t2+s[i]+t1+')';
        st.push(con);
      }
    }
    return st.top();
  }
  string Prefix2Infix(string s){
    stack<string>st;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
      if(isalnum(s[i]))st.push(string(1,s[i]));
      else {
        string t1=st.top();st.pop();
        string t2=st.top();st.pop();
        string con='('+t1+s[i]+t2+')';
        st.push(con);
      }
    }
    return st.top();
  }
  string Postfix2Prefix(string s){
    stack<string>st;
    int n=s.size();
    for(int i=0;i<n;i++){
      if(isalnum(s[i]))st.push(string(1,s[i]));
      else {
        string t1=st.top();st.pop();
        string t2=st.top();st.pop();
        st.push(s[i]+t2+t1);
      }
    }
    return st.top();
  }
  string Prefix2Postfix(string s){
    stack<string>st;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
      if(isalnum(s[i]))st.push(string(1,s[i]));
      else{
        string t1=st.top();st.pop();
        string t2=st.top();st.pop();
        st.push(t1+t2+s[i]);
      }
    }
    return st.top();
  }
};
int main()
{
  string str;
  cin>>str;
  PolishNotations pn;
  cout<<pn.Prefix2Postfix(str);
  return 0;
}