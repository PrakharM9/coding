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
    Node* removenthnode(Node* head, int node){
        Node* fast=head;
        while(node--)fast=fast->next;
        Node* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        if(!fast)return head->next;
        Node* delNode=slow->next;
        slow->next=slow->next->next;
        delete(delNode);
        return head;
    }
};
int main()
{
    int n,node;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>node;
    Solution sol;
    Node* head=sol.convertarr2LL(arr);
    head=sol.removenthnode(head,node);
    sol.print(head);
    return 0;
}