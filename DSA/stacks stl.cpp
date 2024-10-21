#include <bits/stdc++.h>
using namespace std;
int main(){
    //All operations in stack are of o(1) operations
    stack<int>st;//It works on the concept of LIFO(Last In first out) where the last element is the one which will be the first one to come out
    st.push(1);//{1}
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.push(4);//{4,3,2,1}
    st.emplace(5);//{5,4,3,2,1}

    cout<<st.top();//5
    st.pop();
    cout<<st.top();//4
    cout<<st.size();//4
    cout<<st.empty();//Answer will  be 0 as stack is not empty 
    stack<int>st1,st2;
    st1.swap(st2);
    return 0;
}