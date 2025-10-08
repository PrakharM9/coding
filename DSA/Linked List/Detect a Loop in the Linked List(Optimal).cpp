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
        temp->next=head->next->next;
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
    bool detectloop(Node* head){
        Node* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
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
    if(!sol.detectloop(head))cout<<"Loop is not present";
    else cout<<"Loop is present"<<endl;
    return 0;
}