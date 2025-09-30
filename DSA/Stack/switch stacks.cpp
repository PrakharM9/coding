#include<bits/stdc++.h>
using namespace std;
class Stack{
    int tops=-1;
    int* stack=nullptr;
    int csize;
    public:
    void setsize(int length){
        delete[] stack;
        stack=new int[length];
        csize=length;
    }
    void push(int x){
        if(tops>=csize){
            cout<<"Stack Overflow";
            return;
        }
        tops++;
        stack[tops]=x;
        cout<<"Element Enqueued is "<<x<<endl;
    }
    void pop(){
        if(tops==-1){
            cout<<"Stack Underflow";
            return;
        }
        int element=stack[tops];
        tops--;
        cout<<"Dequeued element is: "<<element<<endl;
    }
    void  top(){
        if(tops==-1){
            cout<<"Stack is Empty";
            return;
        }
        cout<<"Element on top is "<<stack[tops]<<endl;
    }
    int size(){
        return tops+1;
    }
};
int main(){
    int num;
    cin>>num;
    Stack st;
    st.setsize(num);
    bool status=false;
    while(true){
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            int value;
            cin>>value;
            st.push(value);
            break;
            case 2:
            st.pop();
            break;
            case 3:
            st.top();
            break;
            case 4:
            status=true;
            break;
            deafult:
            cout<<"Invalid Option"<<endl;
            break;
        }
        if(status){
            break;
        }
    }
    return 0;
}