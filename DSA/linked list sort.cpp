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
int callength(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
Node* sort(Node* head){
    int length=callength(head);
    for(int i=0;i<length-1;i++){ 
        Node* prev=head;
        Node* current=head->next;
        while(current!=NULL){
            if(prev->data>current->data){
                int temp=prev->data;
                prev->data=current->data;
                current->data=temp;
            }
            prev=current;
            current=current->next;
        }
    }
    return head;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    int num,value;
    cin>>num;
    Node* head=nullptr;
    while(num>0){
        cin>>value;
        Node* y=new Node(value);
        if(head==nullptr){
            head=y;
        }
        else{
            Node* current=head;
            while(current->next!=nullptr){
                current=current->next;
            }
            current->next=y;
        }
        num--;
    }
    head=sort(head);
    print(head);
    return 0;
}