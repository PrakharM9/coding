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
// Node* removeHead(Node* head){
//     if(head==NULL) return head;
//     Node* temp=head;
//     head=head->next;
//     delete temp;
//     return head;
// }
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
// Node* deleteHead(Node* head){
//     Node* temp=head;
//     head=head->next;
//     free(temp);
//     return head;
// }
int main(){
    vector<int> arr={12, 5 , 8, 7};
    Node* head=convertArr2LL(arr);
    // head=removeHead(head);
    head=deleteTail(head);
    print(head);
    return 0;
}