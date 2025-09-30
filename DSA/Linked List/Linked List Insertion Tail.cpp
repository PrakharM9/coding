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
Node* convertarr2LL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* insertAtTail(Node* head, int data){
	if(head==NULL){
	    return new Node(data);
	}
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(data);
    return head;
}

void print(Node* head){
    Node* current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl; 
}
int main()
{
    int num;
    cin>>num;
    vector<int>array(num);
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    Node* head=convertarr2LL(array);
    cout<<"Linked list before Insertion at end:"<<endl;
    print(head);
    int tailel;
    cin>>tailel;
    head=insertAtTail(head,tailel);
    cout<<"Linked list after Insertion at end:"<<endl;
    print(head);
    return 0;
}