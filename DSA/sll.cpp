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
Node* inserthead(Node* head,int value){
    Node* current=head;
    Node* temp=new Node(value);
    temp->next=head;
    return temp;
}
void printll(Node* head){
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
    printll(head);
    int headel;
    cin>>headel;
    head=inserthead(head,headel);
    printll(head);
    return 0;
}