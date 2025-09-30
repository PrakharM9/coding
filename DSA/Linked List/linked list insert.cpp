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
    print(head);
    return 0;
}