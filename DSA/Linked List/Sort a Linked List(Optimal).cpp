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
    Node* findmiddle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* list1,Node* list2){
        Node* dummynode=new Node(-1);
        Node* temp=dummynode;
        while(list1 && list2){
            if(list1->data>list2->data){
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
            else{
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
        }
        if(list1)temp->next=list1;
        if(list2)temp->next=list2;
        return dummynode->next;
    }
    Node* mergesort(Node* head){
        if(!head || !head->next)return head;
        Node* middle=findmiddle(head);
        Node* lefthead=head,*righthead=middle->next;
        middle->next=NULL;
        lefthead=mergesort(lefthead);
        righthead=mergesort(righthead);
        return merge(lefthead,righthead);
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
    head=sol.mergesort(head);
    sol.print(head);
    return 0;
}