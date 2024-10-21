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
    public:
    Node* start=NULL;
    Node* end=NULL;
    int ssize=0;
    void push(int x){
        Node* temp=new Node(x);
        if(start==NULL){
            start=temp;
            end=temp;
        }
        else{
            end->next=temp;
        }
        ssize+=1;
    }
    void pop(){
        if(start==NULL){
            throw runtime_error("Queue Undeflow");
        }
        else{
            start=start->next;
        }
    }
    int top(){
        return start->data;
    }
    int size(){
        return ssize;
    }
};
int main()
{
    return 0;
}