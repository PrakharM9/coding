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
    Node* removenthnode(Node* head,int n){
        Node* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
       }
        temp=head;
        if(count==n){
            Node* newHead=head->next;
            delete(head);
            return newHead;
        }
        int index=count-n;
        count=0;
        while(temp){
            count++;
            if(count==index)break;
            temp=temp->next;
        }
        Node* delEl=temp->next;
        temp->next=temp->next->next;
        delete(delEl);
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
    Solution sol;
    Node* head=sol.convertarr2LL(arr);
    cin>>node;
    head=sol.removenthnode(head,node);
    sol.print(head);
    return 0;
}