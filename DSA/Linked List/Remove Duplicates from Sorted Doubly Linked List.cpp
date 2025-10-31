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
    Node* convertarr2DLL(vector<int>arr){
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
    Node* removeDuplicates(Node* head){
        if(!head || !head->next)return head;
        Node* temp=head;
        while(temp && temp->next){
            Node* nextNode=temp->next;
            while(nextNode && nextNode->data==temp->data){
                nextNode=nextNode->next;
            }
            temp->next=nextNode;
            if(nextNode)nextNode->back=temp;
            temp=temp->next;
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
    Node* head=sol.convertarr2DLL(arr);
    head=sol.removeDuplicates(head);
    sol.print(head);
    return 0;
}