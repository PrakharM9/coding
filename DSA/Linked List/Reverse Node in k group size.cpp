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
        Node* temp=head,*prev=NULL;
        while(temp){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* getkthNode(Node* head,int k){
        k--;
        Node* temp=head;
        while(temp && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    Node* reverseklist(Node* head,int k){
        Node* temp=head,*prev=NULL;
        while(temp){
            Node* kthNode=getkthNode(temp,k);
            if(kthNode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            Node* front=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(head==temp){
                head=kthNode;
            }
            else{
                prev->next=kthNode;
            }
            prev=temp;
            temp=front;
        }
        return head;
    }
};
int main()
{
    int n,k;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    Solution sol;
    Node* head=sol.convertarr2LL(arr);
    sol.print(head);
    head=sol.reverseklist(head,k);
    sol.print(head);
    return 0;
}