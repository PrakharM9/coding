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
class Solution{
    public:
    Node* convertarr2LL(vector<int>arr){
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newEl=new Node(arr[i]);
            temp->next=newEl;
            temp=newEl;
        }
        return head;
    }
    void print(Node* head){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    Node* sortll(Node* head){
        Node* zerohead=new Node(-1);
        Node* onehead=new Node(-1);
        Node* twohead=new Node(-1);
        Node* zero=zerohead;
        Node* one=onehead;
        Node* two=twohead;
        Node* temp=head;
        while(temp){
            if(temp->data==0){
                Node* newnode=new Node(0);
                zero->next=newnode;
                zero=newnode;
            }
            else if(temp->data==1){
                Node* newnode=new Node(1);
                one->next=newnode;
                one=newnode;
            }
            else{
                Node* newnode=new Node(2);
                two->next=newnode;
                two=newnode;
            }
            temp=temp->next;
        }
        zero->next=(onehead->next)?onehead->next:twohead->next;
        one->next=twohead->next;
        two->next=NULL;
        Node* newhead=zerohead->next;
        delete(zerohead);
        delete(onehead);
        delete(twohead);
        return newhead;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    Node* head=sol.convertarr2LL(arr);
    head=sol.sortll(head);
    sol.print(head);
    return 0;
}