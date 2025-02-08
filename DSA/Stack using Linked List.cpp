// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=NULL;
    }
};
class Stack{
    public:
    Node* top=NULL;
    void push(int x){
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
    }
    void pop(){
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    void print(){
        Node* current=top;
        while(current){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    void topel(){
        cout<<"Top element is "<<top->data<<endl;
    }
    int size(){
        if(top==NULL)return 0;
        int count=0;
        Node* current=top;
        while(current){
            count++;
            current=current->next;
        }
        return count;
    }
};
int main(){
    int num;
    cin>>num;
    Stack st;
    if(num==0){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    for(int i=0;i<num;i++){
        int value;
        cin>>value;
        st.push(value);
    }
    if(st.size()>0){
        st.print();
        st.topel();
    }
    else{
        cout<<"Stack is empty";
    }
    st.pop();
    if(st.size()>0){
        st.print();
        st.topel();
    }
    else{
        cout<<"Stack is empty";
    }
    return 0;
}