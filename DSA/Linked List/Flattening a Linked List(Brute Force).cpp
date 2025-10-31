#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        child=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    }
};
class Solution{
    public:
    Node* convertchildll(vector<int>arr){
        if(arr.size()==0)return NULL;
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newEl=new Node(arr[i]);
            temp->next=newEl;
            newEl->child=temp;
            temp=newEl;
        }
        return head;
    }
    void print(Node* head){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->child;
        }
        cout<<endl;
    }
    void printOriginalLinkedList(Node* head, int depth) {
        while (head != nullptr) {
            Node* temp=head;
            while(temp){
                cout<<temp->data;
                temp=temp->child;
                if(temp)cout<<" ->";
            }
            if(head->next)cout<<endl;
            head = head->next;
        }
    }
    Node* convertarr2LL(vector<int>arr){
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newEl=new Node(arr[i]);
            temp->child=newEl;
            temp=newEl;
        }
        return head;
    }
    Node* flattenlist(Node* head){
        if(!head || !head->next)return head;
        vector<int>arr;
        Node* temp=head;
        while(temp){
            Node* temp2=temp;
            while(temp2){
                arr.push_back(temp2->data);
                temp2=temp2->child;
            }
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        Node* newhead=convertarr2LL(arr);
        return newhead;
    }
};
int main()
{
    
    Node* head=new Node(3);
    Node* temp=head;
    temp->next=new Node(2);
    temp=temp->next;
    temp->child=new Node(10);
    temp->next=new Node(1);
    temp=temp->next;
    temp->child=new Node(7);
    temp->child->child=new Node(11);
    temp->child->child->child=new Node(12);
    temp->next=new Node(4);
    temp=temp->next;
    temp->child=new Node(9);
    temp->next=new Node(5);
    temp=temp->next;
    temp->child=new Node(5);
    temp->child=new Node(6);
    temp->child->child=new Node(8);
    Solution sol;
    cout<<"Original Linked List"<<endl;
    sol.printOriginalLinkedList(head,0);
    cout<<endl;
    cout<<"Flattened Linked List"<<endl;
    head=sol.flattenlist(head);
    sol.print(head);
    return 0;
}