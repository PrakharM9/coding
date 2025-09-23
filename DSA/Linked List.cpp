// You are using GCC
#include<iostream>
using namespace std;

struct Node
{
	char data;
	Node* next;
	Node* prev;
	Node(char data1,Node* next1,Node* prev1){
	    data=data1;
	    next=next1;
	    prev=prev1;
	}
	Node(char data1){
	    data=data1;
	    next=nullptr;
	    prev=nullptr;
	}
};

Node* insertAtTail(Node* head, char data)
{
	//Type your code here
	if(head==NULL){
	    return new Node(data);
	}
	Node* current=head;
	while(current->next!=nullptr){
	    current=current->next;
	}
	Node* newnode=new Node(data);
	current->next=newnode;
	newnode->prev=current;
	return head;
}

void display(Node* head)
{
	//Type your code here
	while(head!=NULL){
	    cout<<head->data<<" ";
	    head=head->next;
	}
}

Node* rotateByN(Node* head, int pos)
{
	//Type your code here
	if(pos==0){
	    return head;
	}
	Node* newhead=NULL;
	Node* current=head;
	int count=0;
	while(current->next!=NULL){
	    count++;
	    current=current->next;
	    if(count==pos){
	        break;
	    }
	}
	while(current!=NULL){
	    Node* x=new Node(current->data);
	    if(newhead==NULL){
    	    newhead=x;
	    }
	    else{
	        Node* temp=newhead;
	        while(temp->next!=NULL){
	            temp=temp->next;
	        }
	        temp->next=x;
	        x->prev=temp;
	    }
	    current=current->next;
	}
	current=head;
	count=0;
	while(current!=NULL && count<pos){
	    if(newhead==NULL){
	        newhead=new Node(current->data);
	    }
	    else{
	        Node* temp=current;
	        while(temp->next!=NULL){
	            temp=temp->next;
	        }
	        temp->next=new Node(current->data);
	    }
	    count++;
	    current=current->next;
	}
	return newhead;
}

int main()
{
	Node* head = NULL;
	int n;
	char data;
	cin>>n;
    std::cin.ignore(); // Ignore the newline character

    for (int i = 0; i < n; i++) {
        cin>>data;
        head=insertAtTail(head, data);
    }
	int k;
	cin>>k;
	head=rotateByN(head, k);
	display(head);
	return 0;
}