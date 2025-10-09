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
    Node* convertnums2LL(vector<int>nums){
        Node* head=new Node(nums[0]);
        Node* temp=head;
        for(int i=1;i<nums.size();i++){
            Node* newEl=new Node(nums[i]);
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
    Node* sortll(Node* head){
        Node* temp=head;
        vector<int>nums;
        while(temp){
            nums.push_back(temp->data);
            temp=temp->next;
        }
        sort(nums.begin(),nums.end());
        temp=head;
        int i=0;
        while(temp){
            temp->data=nums[i++];
            temp=temp->next;
        }
        return head;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    Node* head=sol.convertnums2LL(nums);
    head=sol.sortll(head);
    sol.print(head);
    return 0;
}