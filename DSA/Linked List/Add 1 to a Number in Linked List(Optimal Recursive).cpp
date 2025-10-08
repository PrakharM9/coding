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
    int helper(Node* head){
        if(head==NULL)return 1;
        int carry=helper(head->next);
        head->data=head->data+carry;
        if(head->data>=10){
            head->data=0;
            return 1;
        }
        return 0;
    }
    Node* addone(Node* head){
        int carry=helper(head);
        if(carry==1){
            Node* newhead=new Node(1,head);
            return newhead;
        }
        return head;
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
    head=sol.addone(head);
    sol.print(head);
    return 0;
}