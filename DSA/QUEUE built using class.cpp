#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
class Queue{
    Node* start=NULL;
    Node* end=NULL;
    int csize=0;
    public:
    void push(int x){
        Node* temp=new Node(x);
        if(start==NULL){
            start=temp;
            end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        csize++;
    }
    int pop(){
        if(start==NULL){
            throw runtime_error("Queue Undeflow");
        }
        Node* temp=start;
        int value=temp->data;
        start=start->next;
        csize--;
        delete temp;
        return value;
    }
    int top(){
        if(start==NULL){
            throw runtime_error("Queue Undeflow");
        }
        return start->data;
    }
    int size(){
        return csize;
    }
    void print(){
        Node* current=start;
        while(current){
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
int main()
{
    int num;
    Queue q;
    cin>>num;
    for(int i=0;i<num;i++){
        int value;
        cin>>value;
        q.push(value);
    }
    cout<<q.pop()<<endl;
    cout<<q.top()<<endl;
    q.print();
    return 0;
}