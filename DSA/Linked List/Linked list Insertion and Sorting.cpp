#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;   
        next=nullptr;
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
Node* insertHead(Node* head,int value){
    return new Node(value,head);
    
}
Node* insertPosition(Node* head, int el, int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(el, head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break ;
        }
        temp=temp->next;
    }
    return head;
}
Node* insertbeforevalue(Node* head, int el, int val){
    if(head==NULL)return NULL;
    if(head->data==el){
        return new Node(el, head);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break ;
        }
        temp=temp->next;
    }
    return head;
}
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
int main(){
    vector<int> arr={12, 5, 8, 7};
    Node* head=convertArr2LL(arr);
    head=insertPosition(head,100,3);
    head=sort(head);
    print(head);
    head=insertbeforevalue(head,10,8);
    print(head);
    return 0; 
}