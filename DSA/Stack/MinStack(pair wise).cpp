#include <bits/stdc++.h>
using namespace std;
class St{
    public:
    stack<pair<int,int>>st;
    void push(int val){
        if(st.empty()){
            st.push({val,val});
            return;
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getmin(){
        return st.top().second;
    }
};
int main()
{
  St s;
  s.push(12);
  s.push(15);
  s.push(10);
  cout<<"Minimum is "<<s.getmin()<<endl;
  s.pop();
  cout<<"Top element is "<<s.top()<<endl;
  cout<<"Minimum is "<<s.getmin();
  return 0;
}