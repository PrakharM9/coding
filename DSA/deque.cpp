#include<bits/stdc++.h>
using namespace std;
void explainDeque(){
    deque<int>dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2);//{1,2}
    dq.push_front(4);//{4,1,2}
    dq.emplace_front(3);//{3,4,1,2}

    dq.pop_back();//{3,4,1}
    dq.pop_front();//{4,1}

    dq.back();//It is used to change the last element in the deque

    dq.front();//It is used to change the front element in the deque

    //rest functions same as vector like begin,end, rbegin, rend,clear, insert, size,swap
}
int main(){

    return 0;
}