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
    Node* reversedoubly(Node* head){
        if(!head || !head->next)return head;
        stack<int>st;
        Node* temp=head;
        while(temp){
            st.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            temp->data=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
    Node* convertArr2LL(vector<int> &arr){
        Node* head=new Node(arr[0]);
        Node* mover=head;
        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],nullptr,mover);
            mover->next=temp;
            mover=temp;
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
};
int main()
{
    vector<int>arr={15,12,9,6,3};
    Solution sol;
    Node* head=sol.convertArr2LL(arr);
    cout<<"Before Reversing Doubly Linked List:"<<endl;
    sol.print(head);
    Node* newhead=sol.reversedoubly(head);
    cout<<"After Reversing Doubly Linked List:"<<endl;
    sol.print(newhead);
    return 0;
}