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
class Stack{
    public:
    Node* topel=NULL;
    int tsize=0;
    void push(int x){
        Node* temp=new Node(x);
        temp->next=topel;
        topel=temp;
        tsize+=1;
    }
    void pop(){
        Node* temp=topel;
        topel=topel->next;
        delete temp;
        tsize-=1;
    }
    int top(){
        return topel->data; 
    }
    int size(){
        return tsize;
    }
};
int main()
{
    return 0;
}