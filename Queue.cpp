#include <bits/stdc++.h>
using namespace std;
class Stack{
    int top=-1;
    int* queue=nullptr;
    int size;
    int csize=0,start=-1,end=-1;
    public:
    void setsize(int length){
        delete[] queue;
        queue=new int[length];
        size=length;
    }
    void push(int x){
        if(csize==size){
            throw runtime_error(" Queue overflow");
        }
        else if(csize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
        }
        queue[end]=x;
        csize++;
    }
    void pop(){
        int element=queue[start];
        if(csize==0){
            throw runtime_error("queue is empty");
        }
        else if(csize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%size;
        }
        csize--;
    }
    int topv(){
        if(csize==0){
            throw runtime_error("queue is empty");
        }
        return queue[start];
    }
    int sizev(){
        return csize;
    }
};
int main()
{
    
    return 0;
}