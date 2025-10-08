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
    Node* reverse(Node* head){
        if(!head || !head->next)return head;
        Node* prev=NULL;
        Node* temp=head;
        while(temp){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* addone(Node* head){
        head=reverse(head);
        Node* temp=head;
        int carry=1;
        while(temp){
            temp->data=temp->data+carry;
            if(temp->data<10){
                carry=0;
                break;
            }
            else{
                carry=1;
                temp->data=0;
            }
            temp=temp->next;
        }
        if(carry==1){
            head=reverse(head);
            Node* newhead=new Node(1,head);
            return newhead;
        }
        head=reverse(head);
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