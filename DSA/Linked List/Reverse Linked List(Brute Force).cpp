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
        Node* temp=head;
        stack<int>st;
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
    cout<<"Before Reversal: "<<endl;
    sol.print(head);
    head=sol.reverse(head);
    cout<<"After Reversal: "<<endl;
    sol.print(head);
    return 0;
}