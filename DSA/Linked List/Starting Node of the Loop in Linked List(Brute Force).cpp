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
        temp->next=head->next->next->next;
        return head;
    }
    Node* startingnode(Node* head){
        if(!head || !head->next)return NULL;
        unordered_map<Node*,int>mpp;
        Node* temp=head;
        while(temp){
            if(mpp[temp])return temp;
            mpp[temp]++;
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
    Node* result=sol.startingnode(head);
    if(result)cout<<result->data;
    else cout<<"There is no loop";
    return 0;
}