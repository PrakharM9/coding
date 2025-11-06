#include <bits/stdc++.h>
using namespace std;
class St{
    private:
    stack<int>st;
    int mini=INT_MAX;
    public:
    void push(int val){
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val>mini)st.push(val);
            else{
                st.push(2*val-mini);
                mini=val;
            }
        }
    }
    void pop(){
        if(st.empty())return;
        int x=st.top();st.pop();
        if(x<mini)mini=2*mini-x;
    }
    int top(){
        if(st.empty())return -1;
        int x=st.top();
        if(mini<x)return x;
        return mini;
    }
    int getmin(){
        return mini;
    }
};
int main()
{
    St s;
    s.push(12);
    s.push(15);
    s.push(10);
    cout<<"Minimum element is "<<s.getmin()<<endl;
    s.pop();
    cout<<"Minimum element is "<<s.getmin()<<endl;
    s.push(10);
    cout<<"Top element is "<<s.top();
    return 0;
}