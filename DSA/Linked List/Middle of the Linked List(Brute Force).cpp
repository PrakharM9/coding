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
        cout<<"Middle is "<<head->data;
    }
    Node* middle(Node* head){
        Node* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        int mid=(count/2)+1;
        temp=head;
        while(temp){
            mid--;
            if(mid==0)break;
            temp=temp->next;
        }
        return temp;
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
    Node* mid=sol.middle(head);
    sol.print(mid);
    return 0;
}