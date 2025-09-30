#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    int priority;
    Node* next;
    Node(int val,int p){
        data=val;
        priority=p;
        next=nullptr;
    }
};
class priority_q{
    private:
    Node* head;
    public:
    priority_q(){
        head=nullptr;
    }
    void push(int x,int priority){
        Node* newNode=new Node(x,priority);
        if(head==NULL || head->priority>priority){
            newNode->next=head;
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL && temp->next->priority<=priority){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    void pop(){
        if(head==NULL){
            cout<<"No element to pop"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        cout<<"Element poped is "<<temp->data<<endl;
        delete temp;
    }
    void top(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Top element is: "<<head->data<<endl;
    }
    void size(){
        int count=0;
        Node* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        cout<<"Size is "<<count<<endl;
    }
};
int main(){
    priority_q pq;
    pq.push(10,0);
    pq.push(12,1);
    pq.push(15,5);
    pq.push(14,3);
    pq.push(13,2);
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    return 0;
}