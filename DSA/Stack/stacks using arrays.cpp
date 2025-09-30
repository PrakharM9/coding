#include <bits/stdc++.h>
using namespace std;
class Stack{
    int top=-1;
    int* stack=nullptr;
    int size;
    public:
    void setsize(int length){
        delete[] stack;
        stack=new int[length];
        size=length;
    }
    void push(int x){
        if(top>size){
            throw runtime_error("Stack Overflow");
        }
        else{
            top++;
            stack[top]=x;
        }
    }
    int topv(){
        if(top==-1){
            throw runtime_error("Stack Underflow");
        }
        return stack[top];
    }
    void pop(){
        if(top==-1){
            throw runtime_error("Stack Underflow"); 
    }
        else{
            top--;
        }
    }
    int sizev(){
        return top+1;
    }
    void print(){
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack st;
    int size;
    cin>>size;
    st.setsize(size);
    st.push(4);
    st.pop();
    st.push(5);
    st.push(6);
    cout<<"size is: "<<st.sizev()<<endl;
    cout<<"top is "<<st.topv()<<endl;
    st.print();
    return 0;
}