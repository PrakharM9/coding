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
Node* insertBeforeHead(Node* head,int val){
    Node* newhead=new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;
}
Node* insertBeforeTail(Node* head,int value){
    if(head->next==NULL){
       return insertBeforeHead(head,value);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* newNode=new Node(value,nullptr,tail);
    tail->next=newNode;
    return head;
}
Node* insertKthElement(Node* head,int k,int value){
    if(k==1){
        return insertBeforeHead(head,value);
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k)break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(value,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}
int main()
{
    vector<int> arr={12, 5, 8, 7};
    Node* head=convertArr2LL(arr);
    int value,pos;
    cin>>value>>pos;
    head=insertKthElement(head,pos,value);
    print(head);
    return 0;
}