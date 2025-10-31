#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
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
            newEl->back=temp;
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
    Node* deleteallEl(Node* head,int el){
        Node* temp=head;
        while(temp){
            if(temp->data==el){
                if(temp==head)head=head->next;
                Node* prev=temp->back;
                Node* front=temp->next;
                if(prev)prev->next=front;
                if(front)front->back=prev;
                delete(temp);
                temp=front;
            }
            else temp=temp->next;
        }
        return head;
    }
};
int main()
{
    int n,el;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>el;
    Solution sol;
    Node* head=sol.convertarr2LL(arr);
    cout<<"Before Deleting"<<endl;
    sol.print(head);
    head=sol.deleteallEl(head,el);
    cout<<"After Deleting"<<endl;
    sol.print(head);
    return 0;
}