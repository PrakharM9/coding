// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

Node* sortedInsert(Node* head_ref, int new_data)
{
    //Type your code here
    Node* head=head_ref;
    Node* x=new Node(new_data);
    if(head==NULL || head->data>=new_data){
        x->next=head;
        return x;
    }
    
    Node* current=head;
    while(current->next!=NULL && current->next->data<new_data){
        current=current->next;
    }
    x->next=current->next;
    current->next=x;
    return head;
}

void printList(Node* head)
{
    //Type your code here
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    Node* head = NULL;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        head=sortedInsert(head, data);
    }

    cin >> data;
    head=sortedInsert(head, data);

    printList(head);

    return 0;
}