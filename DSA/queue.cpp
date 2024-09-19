#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(1);//{1}
    q.push(2);//{1,2}
    q.emplace(4);//{1,2,4}

    q.back()+=5;//{1,2,9}

    cout<<q.back();//9
    cout<<q.front();//1

    q.pop();//{2,9}
    cout<<q.front();//prints 2

    //size swap empty same as stack
    //All operations are happening in o(1) operations
    return 0;
}