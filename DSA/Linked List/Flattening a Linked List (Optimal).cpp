#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    Node(int data1,Node* next1,Node* child1){
        data=data1;
        next=next1;
        child=child1;
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
    Node* merge(Node* head1,Node* head2){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        while(head1 && head2){
            if(head1->data>head2->data){
                res->child=head2;
                head2=head2->child;
            }
            else{
                res->child=head1;
                head1=head1->child;
            }
            res=res->child;
            res->next=NULL;
        }
        if(head1)res->child=head1;
        if(head2)res->child=head2;
        if(dummyNode->child){
            dummyNode->child->next = NULL;
        }
        return dummyNode->child;
    }
    Node* flattenlist(Node* head){
        if(!head || !head->next)return head;
        Node* mergedhead=flattenlist(head->next);
        head=merge(head,mergedhead);
        return head;
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