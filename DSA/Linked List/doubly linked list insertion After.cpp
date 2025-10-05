#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* insertAfterHead(Node* head,int val){
    if(head==NULL)return head;
    if(head->next==NULL){
        Node* newnode=new Node(val);
        head->next=newnode;
        newnode->back=head;
        return head;
    }
    Node* newNode=new Node(val,head->next,head);
    head->next->back=newNode;
    head->next=newNode;
    return head;
}
Node* insertAfterTail(Node* head,int value){
    if(head==NULL)return new Node(value);
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* newNode=new Node(value,nullptr,tail);
    tail->next=newNode;
    return head;
}
Node* insertKthElement(Node* head,int k,int value){
    if(head==NULL)return head;
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k)break;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return NULL;
    }
    Node *newnode=new Node(value,temp->next,temp);
    if(temp->next!=NULL){
        temp->next->back=newnode;
    }
    temp->next=newnode;
    return head;
}
int main()
{
    vector<int> arr={12,10,15};
    Node* head=convertArr2LL(arr);
    head=insertAfterHead(head,5);
    print(head);
    return 0;
}