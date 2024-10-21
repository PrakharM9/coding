#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int* queue=nullptr;
    int tsize;
    int csize=0;
    int start=-1,end=-1;
    public:
    void setsize(int length){
        delete[] queue;
        queue=new int[length];
        tsize=length;
    }
    void push(int x){
        if(csize==tsize){
            throw runtime_error("Queue Overflow");
        }
        else if(csize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%tsize;
        }
        queue[end]=x;
        csize-=1;
    }
    void pop(){
        if(csize==0){
            throw runtime_error("Queue Underflow");
        }
        else if(csize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%tsize;
        }
        csize-=1;
    }
    int top(){
        if(csize==0){
            throw runtime_error("Queue Underflow");
        }
        return queue[start];
    }
    int size(){
        return csize;
    }
};
int main()
{
    int num;
    cin>>num;
    Queue q;
    q.setsize(num);
    return 0;
}