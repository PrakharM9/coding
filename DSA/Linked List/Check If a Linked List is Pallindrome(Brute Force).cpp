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
    bool pallindrome(Node* head){
        if(!head || !head->next)return head;
        stack<int>st;
        Node* temp=head;
        while(temp){
            st.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->data!=st.top())return false;
            temp=temp->next;
            st.pop();
        }
        return true;
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
    if(sol.pallindrome(head)){
        cout<<"Linked list is pallindrome"<<endl;
    }
    else cout<<"Linked list is not pallindrome"<<endl;
    return 0;
}